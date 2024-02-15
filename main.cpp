#include "header.h"

int main() {
    //Creates a new student
    Student* Daniel = new Student("Daniel Salameh", 191102671);
    Daniel->printDetails();

    //Creates a new course and prints out its details
    Course Course1("CS1C", "Coding class", "Mr. Salameh");
    Course1.print();

    //Adds student to course and prints roster
    Course1.addStudent(Daniel);
    Course1.printStudents();

    //Creates a new assignment
    Assignment* Assignment1 = new Assignment("Homework 1", "Create a thing", 100.00);
    Assignment1->print();

    //Adds assignment to course and prints scores
    Course1.addAssignment(Assignment1);
    Course1.printAssignments();
    Course1.printFinalGrades();
    Daniel->printGrades();

    //Grades student on assignment and reprints scores
    Course1.gradeStudent(Daniel, Assignment1, 90.0);
    Course1.printFinalGrades();
    Daniel->printGrades();

    //Tries to add existing student/assignment
    Course1.addStudent(Daniel);
    Course1.addAssignment(Assignment1);

    //Adds more assignments (to check grade averaging)
    Assignment* Assignment2 = new Assignment("Homework 2", "Create a thing again", 100.00);
    Assignment* Assignment3 = new Assignment("Homework 3", "Build something", 100.00);
    Course1.addAssignment(Assignment2);
    Course1.addAssignment(Assignment3);
    Course1.gradeStudent(Daniel, Assignment2, 85.0);
    Course1.gradeStudent(Daniel, Assignment3, 100.00);
    Course1.printStudentsGrades(Daniel);

    //Add more students to class
    Student* Dorrin = new Student("Dorrin Sep", 191100000);
    Course1.addStudent(Dorrin);

    Course1.printStudents();
    Course1.printFinalGrades();
    Course1.printStudentsGrades(Dorrin);

    //Creates new course and adds same students to it
    Course Course2("PS21", "Model United Nations", "Ms. Dory");
    Course2.addStudent(Daniel);
    Course2.addStudent(Dorrin);

    Assignment* Assignment4 = new Assignment("What is the UN?", "Group assignment addressing what the UN is and if we need it today", 25.00);
    Assignment* Assignment5 = new Assignment("2 minute UN speech", "Prepare a 2 minute speech on whether the UN is relevant in the 21st century", 25.0);
    Course2.addAssignment(Assignment4);
    Course2.addAssignment(Assignment5);
    Course2.gradeStudent(Dorrin, Assignment4, 25.0);
    Course2.gradeStudent(Dorrin, Assignment5, 20.0);
    Course2.gradeStudent(Daniel, Assignment4, 10.0);
    Course2.gradeStudent(Daniel, Assignment5, 12.0);

    Course2.print();
    Course2.printStudentsGrades(Daniel);
    Course2.printStudentsGrades(Dorrin);

    Daniel->printGrades();
    Dorrin->printGrades();

    return 0;
}