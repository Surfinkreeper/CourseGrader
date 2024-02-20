#include "header.h"

Student::Student(   const string name,
                    const int id    )
                    : name(name), id(id) {}

Student::~Student() {}

void Student::printDetails() {
    cout << "Name: " << name << "\tID: " << id << endl;
}

string const Student::getName() {
    return name;
}

void Student::printGrades() {
    if( grademap.empty() ) {
        cout << "Student does not have an grades at the moment." << endl;
        return;
    }
    cout <<  name << ": " << endl;
    for (auto& pair : grademap) {
        cout << pair.first << ": " << pair.second->getLetterGrade() << endl;
    }
    cout << endl;
}

void Student::addGradebook(string courseName, Gradebook* gbook) {
    grademap[courseName] = gbook;
    return;
}

bool Student::isAssignmentInStudent(string courseName, Assignment* assignment) {
    if( grademap[courseName]->isAssignmentInGradebook(assignment) ) {
        return true;
    }
    else {
        return false;
    }
}

void Student::print() {
    printDetails();
    printGrades();
}