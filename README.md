Initialize arrays or linked lists to store student information

Display "Welcome to the Student Grade Management System"

Repeat:
    Display menu options
    Get user's choice
    
    Switch (user's choice):
        Case 1:
            Prompt for student name, ID, and grades
            Store student information
            Display "Student added successfully"
        
        Case 2:
            Prompt for student's ID or name
            Search for student information
            If student is found:
                Display student details (name, ID, grades)
            Else:
                Display "Student not found"
        
        Case 3:
            Prompt for student's ID or name
            Search for student information
            If student is found:
                Calculate average grade for the student
                Display average grade
            Else:
                Display "Student not found"
        
        Case 4:
            Display "Exiting the program"
            Exit loop
        
        Default:
            Display "Invalid choice"
    
    Display newline
    
Until user chooses to exit
