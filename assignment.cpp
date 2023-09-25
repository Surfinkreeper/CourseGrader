#include "header.h"

Assignment::Assignment() {
    name = "BLANK ASSIGNMENT";
    description = "N/A";
    totalPoints = 0.0;
}

Assignment::Assignment(string n) : Assignment() {
    name = n;
}

Assignment::Assignment(string n, string desc) : Assignment(n) {
    description = desc;
}

Assignment::Assignment(string n, string desc, double total) : Assignment(n,desc) {
    totalPoints = total;
}

double const Assignment::getTotalPoints() {
    return totalPoints;
}

void Assignment::print() {
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Total points: " << totalPoints << endl << endl;
}