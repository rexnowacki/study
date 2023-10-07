
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

int main() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

    while (1) {
        printf("Enter username or 'exit' to quit: ");
        scanf("%s", username);

        if (strcmp(username, "exit") == 0) {
            return 0;
        }

        int userExists = checkUser(username);
        if (userExists == 1) {
            printf("Enter password: ");
            scanf("%s", password);

            int result = validatePassword(username, password);
            if (result == 1) {
                printf("Login successful!\n");
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

    return 0;
}

