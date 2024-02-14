/************************************************************************
 * CourseGrader
 * Project by Daniel Salameh
 * 
 * This program keeps track of multiple courses and multiple students. Students are able to attend multiple courses at the same time.
 * You are able to grade students on assignments throught he course class as well as track the gradebook. Students have their own profiles
 * that can be accessed and display the student's grades for the classes they are in.
 * 
*************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Course;
class Student;
class Assignment;
class Gradebook;

class Course {
    public:
        // Constructors
        Course();
        Course(string instruct);
        Course(string instruct, string n);
        Course(string instruct, string n, string desc);
        // Accessors / Print
        void const printStudents();
        void const printAssignments();
        void const printFinalGrades();
        void const printStudentsGrades(Student* student);
        void const printDetails();

        void addStudent(Student* addedStudent);
        void addAssignment(Assignment* addedAssignment);
        void gradeStudent(Student* student, Assignment* assignment, double score);

        void print();
    private:
        string instructor;
        string name;
        string description;
        unordered_map<Student*,Gradebook*> students; //Acts as roster and gradebook holder
        vector<Assignment*> assignments;
        bool isStudentInCourse(Student* checkStudent);
        bool isAssignmentInCourse(Assignment* checkAssignment);
};

class Student {
    public:
        // Constructors
        Student();
        Student(string n);
        Student(string n, int num);
        // Accessors / Print
        string const getName();
        void printDetails();
        void printGrades();

        void addGradebook(string const courseName, Gradebook* const gbook);
        bool isAssignmentInStudent(string const courseName, Assignment* const assignment);

        void print();
    private:
        string name;
        int id;
        unordered_map<string,Gradebook*> grademap;
};
class Assignment {
    public:
        // Constructors
        Assignment();
        Assignment(string n);
        Assignment(string n, string desc);
        Assignment(string n, string desc, double total);
        // Accessors / Print
        double const getTotalPoints();
        string const getName();

        void print();
    private:
        string name;
        string description;
        double totalPoints;
};

class Gradebook {
    public:
        // Constructors
        Gradebook();

        void addEntry(Assignment* key, double score);
        char getLetterGrade();
        bool isAssignmentInGradebook(Assignment* const assignment);
        void setScore(Assignment* gradingAssignment, double score);

        void const printScores();
    private:
        vector<pair<Assignment*, double>> grades;
        // Helper function
        double getPercent();
};

#endif

