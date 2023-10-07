
#include <stdio.h>
#include <string.h>
#include <json-c/json.h>

#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define FILENAME "users.json"

int checkUser(const char* username) {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        return -1; // File error
    }

    char buffer[2048];
    fread(buffer, 2048, 1, fp);
    fclose(fp);

    struct json_object *parsed_json;
    struct json_object *users;
    struct json_object *user;

    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, "users", &users);

    int n_users = json_object_array_length(users);
    for (int i = 0; i < n_users; i++) {
        user = json_object_array_get_idx(users, i);
        if (strcmp(json_object_get_string(user), username) == 0) {
            return 1; // User found
        }
    }
    return 0; // User not found
}

void getPassword(char *password) {
  char ch;
  int i = 0;

  while ((ch = getchar()) != '\n' && ch != EOF);

  // printf("Enter password: ");

  while (1) {
    ch = getchar(); // Read character from stdin

    if (ch == '\n' || ch == '\r') { // Check for Enter
      password[i] = '\0';
      break;
    } else if (i < MAX_PASSWORD - 1) {
        printf("*");
        password[i] = ch;
        i++;
    }
  }
}

int validatePassword(const char* username, const char* password) {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        return -1; // File error
    }

    char buffer[2048];
    fread(buffer, 2048, 1, fp);
    fclose(fp);

    struct json_object *parsed_json;
    struct json_object *stored_password;

    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, username, &stored_password);

    if (strcmp(json_object_get_string(stored_password), password) == 0) {
        return 1; // Password matches
    } else {
        return 0; // Password doesn't match
    }
}

void createAccount() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

    printf("Enter desired username: ");
    scanf("%s", username);

    if (checkUser(username) == 1) {
        printf("Username already exists!\n");
        return;
    }

    printf("Enter password for new user %s: ", username);
    scanf("%s", password);

    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    char buffer[2048];
    fread(buffer, 2048, 1, fp);
    fclose(fp);

    struct json_object *parsed_json;
    struct json_object *users;

    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, "users", &users);

    json_object_array_add(users, json_object_new_string(username));
    json_object_object_add(parsed_json, username, json_object_new_string(password));

    fp = fopen(FILENAME, "w");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(fp, "%s", json_object_to_json_string(parsed_json));
    fclose(fp);

    printf("Account created successfully!\n");
}

int main() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

    while (1) {
        printf("Enter username, 'new' to create an account, or 'exit' to quit: ");
        scanf("%s", username);
        clearBuffer(); // Clear input buffer

        if (strcmp(username, "exit") == 0) {
            return 0;
        } else if (strcmp(username, "new") == 0) {
            createAccount();
        } else {
            int userExists = checkUser(username);
            if (userExists == 1) {
                printf("Enter password: ");
                getPassword(password);

                int result = validatePassword(username, password);
                if (result == 1) {
                    printf("Login successful!\n");
                    printf("sys_admin rails your pussy.\n");
                    return 0;
          // Here, you can transition to the main application features
                } else if (result == 0) {
                    printf("Incorrect password!\n");
                } else {
                    printf("Error reading file.\n");
                }
            } else if (userExists == 0) {
                printf("No such user.\n");
            } else {
                printf("Error reading file.\n");
            }
        }
    }

    return 0;
}
