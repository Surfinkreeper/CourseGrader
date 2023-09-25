#include "header.h"

Student::Student() {
    name = "John Doe";
    id = 000000000;
}

Student::Student(string n) {
    name = n;
    id = 000000000;
}

Student::Student(string n, int num) {
    name = n;
    id = num;
}

void Student::printDetails() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << endl;
}

/*
void Student::printGrades() {
    if( grademap.empty() ) {
        cout << "Student does not have an grades at the moment." << endl;
        return;
    }
    for (auto& pair : grademap) {
        cout << pair.first << ": " << pair.second->getLetterGrade() << endl;
    }
    cout << endl;
}
*/

void Student::print() {
    printDetails();
    //printGrades();
}