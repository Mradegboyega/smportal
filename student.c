#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_GRADES 5

struct Student {
    char name[50];
    int id;
    int grades[MAX_GRADES];
    int numGrades;
};

void printStudentDetails(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Grades: ");
    for (int i = 0; i < student.numGrades; i++) {
        printf("%d ", student.grades[i]);
    }
    printf("\n");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. View Student Details\n");
        printf("3. Calculate Average Grade\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numStudents < MAX_STUDENTS) {
                    struct Student newStudent;
                    printf("Enter student name: ");
                    scanf(" %[^\n]", newStudent.name);
                    printf("Enter student ID: ");
                    scanf("%d", &newStudent.id);
                    printf("Enter the number of grades: ");
                    scanf("%d", &newStudent.numGrades);
                    printf("Enter %d grades: ", newStudent.numGrades);
                    for (int i = 0; i < newStudent.numGrades; i++) {
                        scanf("%d", &newStudent.grades[i]);
                    }
                    students[numStudents] = newStudent;
                    numStudents++;
                    printf("Student added successfully.\n");
                } else {
                    printf("Maximum number of students reached.\n");
                }
                break;

            case 2:
                if (numStudents > 0) {
                    int searchId;
                    printf("Enter student ID to view details: ");
                    scanf("%d", &searchId);
                    int found = 0;
                    for (int i = 0; i < numStudents; i++) {
                        if (students[i].id == searchId) {
                            printStudentDetails(students[i]);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Student not found.\n");
                    }
                } else {
                    printf("No students available.\n");
                }
                break;

            case 3:
                if (numStudents > 0) {
                    int searchId;
                    printf("Enter student ID to calculate average grade: ");
                    scanf("%d", &searchId);
                    int found = 0;
                    for (int i = 0; i < numStudents; i++) {
                        if (students[i].id == searchId) {
                            int sum = 0;
                            for (int j = 0; j < students[i].numGrades; j++) {
                                sum += students[i].grades[j];
                            }
                            double average = (double)sum / students[i].numGrades;
                            printf("Average grade: %.2lf\n", average);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Student not found.\n");
                    }
                } else {
                    printf("No students available.\n");
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}
