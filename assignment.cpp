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
    if( total < 0.0 ) {
        cout << "Total points cant be less than 0. Total score set to 1" << endl;
        totalPoints = 1;
    }
    else {
        totalPoints = total;
    }
}

double const Assignment::getTotalPoints() {
    return totalPoints;
}

string const Assignment::getName() {
    return name;
}

void Assignment::print() {
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Total points: " << totalPoints << endl << endl;
}