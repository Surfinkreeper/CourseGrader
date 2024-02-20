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
    private:
        string name, description, instructor;
        unordered_map<Student*,Gradebook*> students; //Acts as roster and gradebook holder
        vector<Assignment*> assignments;
        bool isStudentInCourse(Student* checkStudent);
        bool isAssignmentInCourse(Assignment* checkAssignment);
    public:
        // Constructor/Deconstructor
        Course( const string name = "BLANK NAME",
                const string description = "BLANK DESC",
                const string instructor = "BLANK INSTRUCTOR");
        ~Course();
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
};

class Student {
    private:
        string name;
        int id;
        unordered_map<string,Gradebook*> grademap;
    public:
        // Constructor/Deconstructor
        Student(const string name = "John Doe",
                const int id = 0    );
        ~Student();
        // Accessors / Print
        string const getName();
        void printDetails();
        void printGrades();

        void addGradebook(string const courseName, Gradebook* const gbook);
        bool isAssignmentInStudent(string const courseName, Assignment* const assignment);

        void print();
};
class Assignment {
    private:
        string name;
        string description;
        double totalPoints;
    public:
        // Constructor/Deconstructor
        Assignment( const string name = "BLANK NAME",
                    const string description = "BLANK DESCRIPTION",
                    double total = 1.0);
        ~Assignment();
        // Accessors / Print
        double const getTotalPoints();
        string const getName();

        void print();
};

class Gradebook {
    private:
        vector<pair<Assignment*, double>> grades;
        // Helper function
        double getPercent();
    public:
        // Constructor/Deconstructor
        Gradebook();
        ~Gradebook();

        void addEntry(Assignment* key, double score);
        char getLetterGrade();
        bool isAssignmentInGradebook(Assignment* const assignment);
        void setScore(Assignment* gradingAssignment, double score);

        void const printScores();
};

#endif

