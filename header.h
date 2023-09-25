#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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
        void printStudents();
        void printAssignments();
    private:
        string instructor;
        string name;
        string desc;
        vector<Student> students;
        vector<Assignment> assignments;
};

class Student {
    public:
        Student();
        Student(string n);
        Student(string n, int num);
        void printDetails();
        //void printGrades();
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
        double getTotalPoints();
        void print();
    private:
        string name;
        string description;
        double totalPoints;
};

class Gradebook {
    public:
        Gradebook();
        void addEntry(Assignment key, double score);
        char getLetterGrade();
    private:
        vector<pair<Assignment, double>> grades;
        double getPercent();
};

#endif

