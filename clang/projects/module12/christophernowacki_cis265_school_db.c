// Christopher Nowacki
// CIS 265
// Module 12: School Database -- Student Lookup

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for Student
typedef struct {
    int id;
    char name[50];
    char major[50];
    char campus[25];
} Student;

// Enumeration for campuses
typedef enum {
    Downtown, East, West, Unknown
} Campus;

// Function to convert campus string to enum
Campus getCampusEnum(const char* campus) {
    if (strcmp(campus, "Downtown Campus") == 0) return Downtown;
    if (strcmp(campus, "East Campus") == 0) return East;
    if (strcmp(campus, "West Campus") == 0) return West;
    return Unknown;
}

// Function to load students from file
int loadStudents(Student students[]) {
    FILE *file = fopen("student_database.txt", "r");  
    if (!file) {
        perror("Error opening file");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%d, %49[^,], %49[^,], %24[^\n]", &students[count].id, students[count].name, students[count].major, students[count].campus) == 4) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to display all students
void displayStudents(Student students[], int count) {
    printf("\nAll Students:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Major: %s, Campus: %s\n", students[i].id, students[i].name, students[i].major, students[i].campus);
    }
}

// Function to search student by ID
int searchStudent(Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Found Student: ID: %d, Name: %s, Major: %s, Campus: %s\n", students[i].id, students[i].name, students[i].major, students[i].campus);
            return 1;
        }
    }
    return 0;
}

// Function to count students per campus
void countStudentsPerCampus(Student students[], int count) {
    int downtownCount = 0, eastCount = 0, westCount = 0;

    for (int i = 0; i < count; i++) {
        Campus campus = getCampusEnum(students[i].campus);
        switch (campus) {
            case Downtown: downtownCount++; break;
            case East: eastCount++; break;
            case West: westCount++; break;
            default: break;
        }
    }

    printf("East Campus: %d students\n", eastCount);
    printf("West Campus: %d students\n", westCount);
    printf("Downtown Campus: %d students\n", downtownCount);
}

int main() {
    Student students[100];
    int count = loadStudents(students);
    char choice;

    do {
        printf("\nMenu:\n");
        printf("D - Display all students\n");
        printf("S - Search by student ID\n");
        printf("C - Count students per campus\n");
        printf("Q - Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'D':
            case 'd':
                displayStudents(students, count);
                break;
            case 'S':
            case 's':
                printf("Enter student ID: ");
                int id;
                scanf("%d", &id);
                if (!searchStudent(students, count, id)) {
                    printf("Student ID does not exist.\n");
                }
                break;
            case 'C':
            case 'c':
                countStudentsPerCampus(students, count);
                break;
            case 'Q':
            case 'q':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}
