#include "header.h"

Assignment::Assignment( const string name,
                        const string description,
                        double total    )
                        : name(name), description(description) {
    if( total < 0.0 ) {
        cout << "Total points cant be less than 0. Total score set to 1" << endl;
        total = 1;
    }
    totalPoints = total;
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