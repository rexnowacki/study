/* global window, document */

(function () {
  var CORRECT_CLASS = 'lrn_correct';
  var INCORRECT_CLASS = 'lrn_incorrect';
  var IN_BROWSER = typeof window !== 'undefined';
  /* global LearnosityAmd */

  var desmosInstances = [];
  if (IN_BROWSER) {
    window.__cleanupLearnosityDesmosInstances = function () {
      var activeInstances = [];
      desmosInstances.forEach(function (api) {
        var elt = api._calc.rootElt;
        if (document.body.contains(elt)) {
          activeInstances.push(api);
        } else {
          api.destroy();
        }
      });
      desmosInstances = activeInstances;
    };
  }

  function isValidState(state) {
    if (!state) return false;
    if (typeof state === 'string') {
      try {
        state = JSON.parse(state);
      } catch (e) {
        return false;
      }
    }
    if (typeof state !== 'object') return false;
    return state.hasOwnProperty('graph') && state.hasOwnProperty('expressions');
  }

  LearnosityAmd.define(
    ['jquery-v1.10.2', 'underscore-v1.5.2'],
    function ($, _) {
      function Question(init, lrnUtils) {
        this.init = init;
        this.question = init.question;
        this.variables = this.question.graph_variables;

        if (IN_BROWSER) {
          this.init.events.on('validate', this.onValidate.bind(this));

          this.helperExpressions = {};
          this.elt = document.createElement('div');
          var calcElt = $('<div>').addClass('calculator_wrapper');
          init.$el.addClass('desmos_learnosity_item');

          calcElt.addClass('calculator');

          if (this.isInitialStateGraph()) {
            calcElt.css('width', '810px');
            calcElt.css('height', '480px');
          } else {
            calcElt.css('width', this.question.graph_width + 'px');
            calcElt.css('height', this.question.graph_height + 'px');
            calcElt.addClass('lrn_response_input_wrapper');
          }
          this.calcElt = calcElt;
          this.elt.appendChild(calcElt[0]);

          if (this.question.instant_feedback) {
            var $instantContainer = $('<div>');
            this.elt.appendChild($instantContainer[0]);
            lrnUtils.renderComponent('CheckAnswerButton', $instantContainer[0]);
          }

          var opts = this.getConfig();

          var self = this;

          //first, look for a persisted graph state (either because of reload, or because initial_state was set)
          var initialState = this.getSavedGraphState();

          //load the desmos API and the calc state in parallel. once both are done, we're here.
          var onLoad = function () {
            if (
              !window.Desmos || //require that Desmos is loaded
              (!initialState && self.question.graph_url) || //if there's a graph to load, load it
              self.calc //don't run this twice
            )
              return;
            self.init.$el.html(self.elt);
            self.calc = window.Desmos.GraphingCalculator(calcElt[0], opts);
            desmosInstances.push(self.calc);
            self.setupCalculator(initialState);
            self.initialState = initialState;
            init.events.trigger('ready');
          };
          if (!initialState) {
            if (!this.question.graph_url) {
              onLoad();
            } else {
              $.getJSON(this.question.graph_url).done(function (msg) {
                initialState = msg.state;
                onLoad();
              });
            }
          }
          this.loadDesmos(onLoad);
        } else {
          init.events.trigger('ready');
        }
      }

      Question.prototype.showExampleAnswer = function () {
        if (this.exampleAnswerShowing) return;
        if (!this.question.hasOwnProperty('correct_answer')) return;
        if (!this.initialState) return;
        this.exampleAnswerShowing = true;

        var answerElt = $('<div>').addClass('lrn_correctAnswers');
        answerElt.append($('<span>').text('Example Correct Answer'));
        var answerCalcElt = $('<div>');
        answerCalcElt.css('width', this.question.graph_width + 'px');
        answerCalcElt.css('height', this.question.graph_height + 'px');
        answerElt.append(answerCalcElt);
        var answerCalc = window.Desmos.GraphingCalculator(answerCalcElt[0], {
          expressions: false,
          settingsMenu: false,
          zoomButtons: false,
          lockViewport: true,
          branding: false,
          border: false,
          disableMouseInteractions: true
        });
        desmosInstances.push(answerCalc);
        if (isValidState(this.initialState)) {
          answerCalc.setState(this.initialState);
        }
        answerCalc.setExpressions(
          this.computeExpChanges(
            this.question.correct_answer,
            this.findAllSliders(this.initialState)
          )
        );
        this.elt.appendChild(answerElt[0]);
      };

      Question.prototype.getConfig = function () {
        if (this.isInitialStateGraph()) {
          //if we start without a graph (e.g. blank question), allow pasting a graph link
          if (!this.question.graph_url) {
            return {
              zoomButtons: false,
              lockViewport: true,
              pasteGraphLink: true,
              pauseWhenOffscreen: true,
              editOnWeb: true,
              actions: true
            };
          }
          return {
            zoomButtons: false,
            lockViewport: true,
            pauseWhenOffscreen: true,
            editOnWeb: true,
            actions: true
          };
        }
        return {
          expressions: !!this.question.expressions_list,
          settingsMenu: false,
          zoomButtons: false,
          lockViewport: true,
          branding: false,
          border: false,
          disableMouseInteractions: this.init.state === 'review',
          pauseWhenOffscreen: true
        };
      };

      Question.prototype.isInitialStateGraph = function () {
        //response & "correct_answer" buth should have initial_state. It defaults to "false", but exists.
        return !this.question.hasOwnProperty('initial_state');
      };

      Question.prototype.loadDesmos = function (callback) {
        if (window.Desmos) return callback();

        var head = document.getElementsByTagName('head')[0];
        var script = document.createElement('script');

        script.src =
          'https://www.desmos.com/api/v1.8/calculator.js?apiKey=dcb31709b452b1cf9dc26972add0fda6';
        script.onload = callback;
        head.appendChild(script);
      };

      //Note: this method is tested in learnosity-api-usage -- if you make changes here change that test as well!
      //The goal of this method is to
      //find and store slider values as latex: value pairs
      //so that the "correct answer" & response graphs can just store those changes instead of an entire state
      Question.prototype.findAllSliders = function (state) {
        if (!window.Desmos || !state || !state.expressions) return {};

        // As of v1.8, the internal dependencies we need should be available on `window.Desmos.Private` and should NOT
        // be obtained using `Desmos.require()`, because we will be removing that.
        // In v1.7 and before, `Desmos.require()` is available.
        const desmosPrivate = window.Desmos.Private || {};
        var Parser = desmosPrivate.Parser || window.Desmos.require('parser');
        var parse = Parser.parse;

        var extractSliderValueFromLatex =
          desmosPrivate.extractSliderValueFromLatex;
        if (!extractSliderValueFromLatex) {
          try {
            extractSliderValueFromLatex = window.Desmos.require(
              'core/graphing-calc/extract-slider-value-from-latex'
            ).extractSliderValueFromLatex;
          } catch (e) {
            extractSliderValueFromLatex = window.Desmos.require(
              'graphing-calc/models/expression'
            ).extractSliderValueFromLatex;
          }
        }

        var returns = {};
        for (var i = 0; i < state.expressions.list.length; i++) {
          var exp = state.expressions.list[i];
          if (!exp.latex) continue;
          var value = extractSliderValueFromLatex(exp.latex);
          if (!isNaN(value)) {
            var parsed = parse(exp.latex);
            var name = this.normalizeLatex(parsed.getExports()[0]);
            returns[name] = {
              value: value,
              id: exp.id,
              index: i
            };
          }
        }
        return returns;
      };

      //remember any sliders that have changed.
      //this means that the rest of the state (axes, stepSize, etc etc etc) will be untouched.
      //reason this is ok: the only things that can change here are from moving movable points.
      //
      //Note: this method is tested in learnosity-api-usage -- if you make changes here change that test as well!
      Question.prototype.getSliderValues = function (state) {
        var newExps = this.findAllSliders(state);
        var sliderValues = {};
        for (var name in newExps) {
          sliderValues[name] = newExps[name].value;
        }
        return sliderValues;
      };

      Question.prototype.generateModificationResponse = function () {
        var response = {
          variable_values: {}
        };

        for (var name in this.variables) {
          response.variable_values[name] =
            this.helperExpressions[name].numericValue;
        }

        response.slider_values = this.getSliderValues(this.calc.getState());

        if (this.question.success_condition) {
          response.additional_success_condition =
            this.successConditionHelper.numericValue === 1;
        }
        return response;
      };

      //this takes a graph state and adds a dynamic_content dictionary if any variables are of the form y=\operatorname{var}_{(a-z)*}
      Question.prototype.extractDynamicContent = function (graphState) {
        var sliders = this.findAllSliders(graphState);

        var regex = /V\_\{([a-z]*)\}/;
        graphState.dynamic_content = {};
        for (var key in sliders) {
          var match = key.match(regex);
          if (match) {
            //the '{' + '{' is to avoid the template trying to do interpolation
            graphState.dynamic_content[key] =
              '{' + '{var:' + match[1] + '}' + '}';
          }
        }
        return graphState;
      };
      //this takes a graph state with a dynamic_content dictionary and rehydrates those values into the graph.
      Question.prototype.injectDynamicContent = function (graphState) {
        if (!graphState || !graphState.dynamic_content) return graphState;
        var dynamic_content = graphState.dynamic_content;

        var sliders = this.findAllSliders(graphState);
        for (var key in sliders) {
          var sliderInfo = sliders[key];
          //the value has been replaced by dynamic_content
          if (dynamic_content[key] && dynamic_content[key][0] !== '{') {
            graphState.expressions.list[sliderInfo.index].latex =
              key + '=' + dynamic_content[key];
          }
        }
        delete graphState.dynamic_content;
        return graphState;
      };

      Question.prototype.onChange = function () {
        this.clearValidation();
        var response;
        if (this.isInitialStateGraph()) {
          response = this.extractDynamicContent(this.calc.getState());
        } else {
          response = this.generateModificationResponse();
        }
        this.init.events.trigger('changed', response);
      };

      Question.prototype.getSavedGraphState = function () {
        //persisting from prior usage
        if (this.isInitialStateGraph() && this.init.response) {
          return this.init.response;
        }

        //check if there's an "initial_state" set by the author
        if (this.question.initial_state) {
          return this.injectDynamicContent(this.question.initial_state);
        }

        //there's no savedGraphState. load it off of www directly.
        return undefined;
      };

      //different historical versions of findAllSliders conflict
      //
      //  used to be that we'd store a_1 and a_{10}, \theta_1
      //  now when we generate latex, it looks like a_{1} and a_{10} and \theta_{1}, while identifiers
      //  look like a_1, a_10, and theta_1.
      //
      //this method can take in any of those and always spits out the normalized, most verbose, latex version
      // (e.g. a_{1}, a_{10}, and \theta_{1}).
      //note: this logic is similar to identifierToLatex in label.ts,
      //but doesn't assume normalization initially
      Question.prototype.normalizeLatex = function (name) {
        var pieces = name.split('_');

        let out = '';
        if (pieces[0].length > 1 && pieces[0][0] != '\\') out += '\\';
        out += pieces[0];
        if (pieces[1]) {
          if (pieces[1][0] === '{') {
            out += '_' + pieces[1];
          } else {
            out += '_{' + pieces[1] + '}';
          }
        }
        return out;
      };

      //this generates the kind of object we can send into setExpressions
      //it ignores any expressions that aren't defined in the current graph
      //
      //note: this is tested in learnosity-api-usage. copy this there if you change it here!
      Question.prototype.computeExpChanges = function (
        response,
        initialStateSliders
      ) {
        if (!response || !response.slider_values) return [];

        var toChange = {};
        for (var name in response.slider_values) {
          toChange[this.normalizeLatex(name)] = response.slider_values[name];
        }
        var expChanges = [];
        for (name in initialStateSliders) {
          //note: this should be a no-op. Just being extra safe.
          var latex = this.normalizeLatex(name);

          if (toChange.hasOwnProperty(latex)) {
            expChanges.push({
              id: initialStateSliders[name].id,
              latex: latex + '=' + toChange[latex]
            });
          }
        }
        return expChanges;
      };

      Question.prototype.setupCalculator = function (initialState) {
        if (isValidState(initialState)) {
          this.calc.setState(initialState);
        }

        //function_definition is for questions that fundamentally rely on the author to define a function
        if (this.question.hasOwnProperty('function_definition')) {
          this.calc.setExpression({
            id: 'functiondefinition',
            latex: this.question.function_definition,
            hidden: true
          });
        }
        if (!this.isInitialStateGraph()) {
          var initialStateSliders = this.findAllSliders(initialState);
          var expChanges = this.computeExpChanges(
            this.init.response,
            initialStateSliders
          );
          if (expChanges.length > 0) this.calc.setExpressions(expChanges);
        }
        this.hookUpHelpers();
        if (!this.isInitialStateGraph()) {
          this.calc._calc.evaluator.notifyWhenSynced(this.onChange.bind(this));
        }
      };

      Question.prototype.onValidate = function (args) {
        if (args.showCorrectAnswers) {
          this.showExampleAnswer();
        }
        var validationClass = this.init.getFacade().isValid()
          ? CORRECT_CLASS
          : INCORRECT_CLASS;
        this.calcElt.addClass(validationClass);
      };

      Question.prototype.clearValidation = function () {
        [CORRECT_CLASS, INCORRECT_CLASS].map(
          function (klass) {
            if (this.calcElt.hasClass(klass)) this.calcElt.removeClass(klass);
          }.bind(this)
        );
      };

      Question.prototype.hookUpHelpers = function () {
        for (var name in this.variables) {
          this.helperExpressions[name] = this.calc.HelperExpression({
            latex: this.variables[name]
          });
        }
        if (this.question.success_condition) {
          var latex = this.question.success_condition;
          //this could be a simple condition or a compound one.
          //if it's simple, wrap it in {}. otherwise, just read off its value
          if (!latex.match(/\\left\\{/))
            latex = '\\left\\{' + latex + '\\right\\}';
          this.successConditionHelper = this.calc.HelperExpression({
            latex: latex
          });
        }
        if (this.isInitialStateGraph()) {
          this.calc.observeEvent('change', this.onChange.bind(this));
        } else {
          var onChangeAfterSync = function () {
            this.calc._calc.evaluator.notifyWhenSynced(
              this.onChange.bind(this)
            );
          }.bind(this);
          //this should capture clickable objects
          this.calc.observeEvent('change', onChangeAfterSync);
          //movable point events don't register until mouseup, which makes demos bad
          this.calc.observeEvent('userMovedPoint', onChangeAfterSync);
        }
      };

      function Scorer(question, response) {
        this.question = question;
        this.response = response;
      }

      Scorer.prototype.approxEqual = function (source, target, tolerance) {
        return Math.abs(source - target) < tolerance;
      };

      //necessary as of question API v2.117.0 in order to actually validate
      Scorer.prototype.canValidateResponse = function () {
        return true;
      };

      Scorer.prototype.isValid = function () {
        if (!this.response) return false;

        //check the additional condition
        if (
          this.question.success_condition &&
          !this.response.additional_success_condition
        ) {
          return false;
        }

        for (var name in this.question.graph_variables) {
          //check against "correct answer" graph
          if (
            this.question.correct_answer &&
            this.question.correct_answer.variable_values &&
            this.question['dcg_match_' + name] &&
            this.question.correct_answer.variable_values[name] !==
              this.response.variable_values[name] &&
            //we ignore checkboxes if success_condition is written
            !this.question.success_condition
          ) {
            return false;
          }
        }
        return true;
      };

      var getValidResponse = function (question) {
        return (
          (_.isObject(question) &&
            _.isObject(question.validation) &&
            question.validation.valid_response) ||
          {}
        );
      };

      Scorer.prototype.maxScore = function () {
        var validResponse = getValidResponse(this.question);
        return validResponse.score || 1;
      };

      Scorer.prototype.score = function () {
        return this.isValid() ? this.maxScore() : 0;
      };

      return {
        Question: Question,
        Scorer: Scorer
      };
    }
  );
})();
