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
        Course();
        Course(string instruct);
        Course(string instruct, string n);
        Course(string instruct, string n, string desc);
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
        unordered_map<Student*,Gradebook*> students; //acts as roster and gradebook holder
        vector<Assignment*> assignments;
        bool isStudentInCourse(Student* checkStudent);
        bool isAssignmentInCourse(Assignment* checkAssignment);
};

class Student {
    public:
        Student();
        Student(string n);
        Student(string n, int num);
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
        Assignment();
        Assignment(string n);
        Assignment(string n, string desc);
        Assignment(string n, string desc, double total);
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
        Gradebook();
        void addEntry(Assignment* key, double score);
        char getLetterGrade();
        bool isAssignmentInGradebook(Assignment* const assignment);
        void setScore(Assignment* gradingAssignment, double score);
        void const printScores();
    private:
        vector<pair<Assignment*, double>> grades;
        double getPercent();
};

#endif

