#include "header.h"

Gradebook::Gradebook() {}

Gradebook::~Gradebook() {}

void Gradebook::addEntry(Assignment* key, double score) {
    grades.push_back(make_pair(key,score));
}

char Gradebook::getLetterGrade() {
    double percent = getPercent();
    if (percent >= 90.0) {
        return 'A';
    } else if (percent >= 80.0) {
        return 'B';
    } else if (percent >= 70.0) {
        return 'C';
    } else if (percent >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

bool Gradebook::isAssignmentInGradebook(Assignment* assignment) {
    bool found = false;
    for(const auto& pair : grades) {
        if( assignment->getName() == pair.first->getName() ) {
            found = true;
        }
    }
    return found;
}

void Gradebook::setScore(Assignment* gradingAssignment, double score) {
    // Checks if already there
    if( !isAssignmentInGradebook(gradingAssignment) ) {
        cout << "Assignment is not is student's gradebook." << endl;
    }
    // Sets score
    else {
        for(auto& pair : grades) {
        if( gradingAssignment->getName() == pair.first->getName() ) {
            pair.second = score;
            }
        }
    }
}

void const Gradebook::printScores() {
    for(const auto& pair : grades) {
        cout << pair.first->getName() << ":\t";
        cout << pair.second << "/" << pair.first->getTotalPoints() << "\t";
        cout << pair.second / pair.first->getTotalPoints() * 100 << "%" << endl; 
    }
}

double Gradebook::getPercent() {
    double earnedPoints = 0;
    double totalPoints = 0;
    for (auto& pair : grades) {
        earnedPoints += pair.second;
        totalPoints += pair.first->getTotalPoints();
    }
    return ( earnedPoints / totalPoints ) * 100;
}