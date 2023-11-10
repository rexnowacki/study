# Enable Powerlevel10k instant prompt. Should stay close to the top of ~/.zshrc.
# Initialization code that may require console input (password prompts, [y/n]
# confirmations, etc.) must go above this block; everything else may go below.
if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
fi

# Path to your oh-my-zsh installation.
export ZSH="$HOME/.oh-my-zsh"

# ZSH theme 
# junkfood is good
ZSH_THEME="powerlevel10k/powerlevel10k"

# zsh plugins 
plugins=(
	zsh-autosuggestions
	zsh-syntax-highlighting
	git
)

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh

source $ZSH/oh-my-zsh.sh
# default text editor 
export EDITOR="nvim"

# popmail stuff
export POP_SMTP_USERNAME=nowacki.chris@gmail.com
export POP_SMTP_PASSWORD=zkoleavyjzwxjihf

# Aliases

alias l="exa -l --icons --group-directories-first"
alias ls="l"
# custom aliases
alias bat="batcat"
alias precalc="open ~/study/trig/book/precalc.pdf"
# cr() {
#  g++ "$1" -o temp_out && ./temp_out
#  rm temp_out
#}
# CUSTOM COMPILER ALIAS
cr() {
  if [[ -z "$1" ]]; then
    echo "Usage: cr <source_file.c|cpp>"
    return 1
  fi

  local outfile="temp_out_$RANDOM"
  local extension="${1##*.}"
  local compiler

  if [[ "$extension" == "cpp" ]]; then
    compiler="g++"
  elif [[ "$extension" == "c" ]]; then
    compiler="gcc"
  else
    echo "Unsupported file extension. Use .c for C and .cpp for C++."
    return 1
  fi

  if "$compiler" "$1" -o "$outfile"; then
    ./"$outfile"
    rm "$outfile"
  else
    echo "Compilation failed."
    return 1
  fi
}
pi() {
  xmodmap -e "keycode 108 = dead_greek"
}
# When popOs retiling gets stuck.
retile() {
  gnome-extensions disable pop-shell@system76.com && gnome-extensions enable pop-shell@system76.com
}

# study stream aliases
# Requires https://github.com/caarlos0/timer to be installed. spd-say should ship with your distro


function custom_cat() {
    local file="$1"

    # If the file doesn't exist, print an error and return
    if [[ ! -f $file ]]; then
        echo "Error: $file does not exist."
        return 1
    fi

    # Check the file extension
    local extension="${file##*.}"

    # If it's a markdown file, use 'glow'
    if [[ $extension == "md" ]]; then
        glow "$file"
    else
        # Otherwise, use 'bat'
        bat "$file"
    fi
}

alias cat="custom_cat"

declare -A pomo_options
pomo_options["study"]="45"
pomo_options["break"]="10"

pomodoro () {
  if [ -n "$1" -a -n "${pomo_options["$1"]}" ]; then
  val=$1
  echo $val | lolcat
  timer ${pomo_options["$val"]}m
  spd-say "'$val' session done"
  fi
}

alias wo="pomodoro 'study'"
alias br="pomodoro 'break'"
alias pls="please"

alias monoff='xset dpms force off'


pmail() {
    pop < ~/message.md --from "nowacki.chris@gmail.com" --to "nowacki.chris@gmail.com" --subject "$1" --attach "$1".mp3
}

# CPP / CLANG
alias newc="echo -e '// Christopher Nowacki\n// CIS 265\n// Project Name\n\n#include <stdio.h>' > start.c"
alias newcpp="echo -e '// Christopher Nowacki\n// CIS 278\n// Project Name\n\n#include <iostream>\nusing namespace std;' > start.cpp"

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion


if [[ -f ~/.banner ]]; then
    cat ~/.banner | lolcat
fi
