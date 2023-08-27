#include <stdio.h>
#include <stdlib.h>

struct student {
  char name[100];
  int id;
  float grades[5];
};

int main() {
  struct student *students = NULL;
  int num_students = 0;
  int choice;

  // Initialize arrays or linked lists to store student information
  students = malloc(sizeof(struct student));

  do {
    // Display menu options
    printf("Welcome to the Student Grade Management System\n");
    printf("1. Add student\n");
    printf("2. Search student\n");
    printf("3. Calculate average grade\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Switch (user's choice)
    switch (choice) {
      case 1:
        // Prompt for student name, ID, and grades
        printf("Enter student name: ");
        scanf("%s", students[num_students].name);
        printf("Enter student ID: ");
        scanf("%d", &students[num_students].id);
        for (int i = 0; i < 5; i++) {
          printf("Enter grade %d: ", i + 1);
          scanf("%f", &students[num_students].grades[i]);
        }
        num_students++;
        printf("Student added successfully\n");
        break;
      case 2:
        // Prompt for student's ID or name
        printf("Enter student ID or name: ");
        scanf("%s", buffer);
        
        // Search for student information
        for (int i = 0; i < num_students; i++) {
          if (strcmp(students[i].name, buffer) == 0 || students[i].id == atoi(buffer)) {
            // If student is found:
            printf("Student details (name, ID, grades):\n");
            printf("%s %d %.2f %.2f %.2f %.2f %.2f\n", students[i].name, students[i].id, students[i].grades[0], students[i].grades[1], students[i].grades[2], students[i].grades[3], students[i].grades[4]);
            break;
          }
        }
        if (i == num_students) {
          // Else:
          printf("Student not found\n");
        }
        break;
      case 3:
        // Prompt for student's ID or name
        printf("Enter student ID or name: ");
        scanf("%s", buffer);
        
        // Search for student information
        for (int i = 0; i < num_students; i++) {
          if (strcmp(students[i].name, buffer) == 0 || students[i].id == atoi(buffer)) {
            // If student is found:
            float average = 0;
            for (int j = 0; j < 5; j++) {
              average += students[i].grades[j];
            }
            printf("Average grade: %.2f\n", average / 5);
            break;
          }
        }
        if (i == num_students) {
          // Else:
          printf("Student not found\n");
        }
        break;
      case 4:
        // Display "Exiting the program"
        printf("Exiting the program\n");
        // Exit loop
        break;
      default:
        // Display "Invalid choice"
        printf("Invalid choice\n");
        break;
    }

    // Display newline
    printf("\n");
  } while (choice != 4);

  // Free memory
  free(students);

  return 0;
}
