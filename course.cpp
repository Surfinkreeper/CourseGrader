#include "header.h"

Course::Course() {
    instructor = "BLANK COURSE";
    name = "BLANK COURSE";
    description = "BLANK COURSE";
}

Course::Course(string instruct) : Course() {
    instructor = instruct;
}

Course::Course(string instruct, string n) : Course(instruct) {
    name = n;
}

Course::Course(string instruct, string n, string desc) : Course(instruct, n) {
    description = desc;
}

void const Course::printStudents() {
    if( students.empty() ) {
        cout << "Course has no students at the moment." << endl;
        return;
    }
    cout << "Course Roster: " << endl;
    for (auto& student : students) {
        student->printDetails();
    }
    cout << endl;
}

void const Course::printAssignments() {
    if( assignments.empty() ) {
        cout << "Course has no assignments at the moment." << endl;
        return;
    }
    cout << "Course Assignments: " << endl;
    for (auto& assignment : assignments) {
        assignment->print();
    }
    cout << endl;
}

void Course::addStudent(Student* addedStudent) {
    students.push_back(addedStudent);
    //NOT DONE
}