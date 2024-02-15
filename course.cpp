#include "header.h"

Course::Course( const string name,
                const string description,
                const string instructor ) 
                : name(name), description(description), instructor(instructor) {}

void const Course::printStudents() {
    if( students.empty() ) {
        cout << "Course has no students at the moment." << endl;
        return;
    }
    cout << "Course Roster: " << endl;
    for (auto& pair : students) {
        pair.first->printDetails();
    }
    cout << endl;
}

void const Course::printAssignments() {
    if( assignments.empty() ) {
        cout << "Course has no assignments at the moment." << endl;
        return;
    }
    cout << name << " Assignments: " << endl;
    for (auto& assignment : assignments) {
        assignment->print();
    }
    cout << endl;
}

void const Course::printFinalGrades() {
    if( assignments.empty() || students.empty() ) {
        cout << "Course has no students and/or no assignments." << endl;
    }
    else {
        cout << "____________________" << endl;
        cout << name << " Final Grades:" << endl;
        for(const auto& pair : students ) {
            pair.first->printDetails();
            cout << "Grade: " << pair.second->getLetterGrade() << endl;
        }
        cout << "____________________" << endl << endl;
    }
}

void const Course::printStudentsGrades(Student* student) {
    if( !isStudentInCourse(student) ) {
        cout << "Student is not in this course." << endl;
    }
    else {
        cout << "____________________" << endl;
        cout << student->getName() << "'s Scores in " << name << ":\n";
        students[student]->printScores();
        cout << "____________________" << endl << endl;
    }
}

void const Course::printDetails() {
    cout << "Instructor: " << instructor << endl;
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl << endl;
}

void Course::addStudent(Student* addedStudent) {
    if( isStudentInCourse(addedStudent) ) {
        cout << "Student is already in the course." << endl;
        return;
    }
    else {
        Gradebook* classGradebook = new Gradebook; //created new gradebook for this course
        students[addedStudent] = classGradebook; //adds student into roster as well as new gradebook
        addedStudent->addGradebook(name, classGradebook); //gives student a pointer to the same gradebook; key is the course name
    }
    return;
}

void Course::addAssignment(Assignment* addedAssignment) {
    if( isAssignmentInCourse(addedAssignment) ) {
        cout << "Assignment is already in the course." << endl;
        return;
    }
    else {
        assignments.push_back(addedAssignment); //adds assignment to class list
        for (auto& pair : students) {
            if( !pair.first->isAssignmentInStudent(name, addedAssignment) ) //makes sure student doesnt already have assignment
            {
                pair.second->addEntry(addedAssignment, 0); //automatically grades students a 0
            }
        }
    }
    return;
}

void Course::gradeStudent(Student* gradingStudent, Assignment* gradingAssignment, double score) {
    students[gradingStudent]->setScore(gradingAssignment, score);
    return;
}

void Course::print() {
    cout << "____________________" << endl;
    printDetails();
    printStudents();
    printAssignments();
    printFinalGrades();
    cout << "____________________" << endl;
}

bool Course::isStudentInCourse(Student* checkStudent) {
    if( students.find(checkStudent) == students.end() ) {
        return false; //false if student is not in the course
    }
    else {
        return true; //true if student is already in the course
    }
}

bool Course::isAssignmentInCourse(Assignment* checkAssignment) {
    if( find(assignments.begin(), assignments.end(), checkAssignment) == assignments.end() ) {
        return false; //false if assignment is not in the course
    }
    else {
        return true; //true if assignment is already in the course
    }
}