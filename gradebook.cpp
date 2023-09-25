#include "header.h"

Gradebook::Gradebook() {
}

void Gradebook::addEntry(Assignment key, double score) {
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

double Gradebook::getPercent() {
    double earnedPoints = 0;
    double totalPoints = 0;
    for (auto& pair : grades) {
        earnedPoints += pair.second;
        totalPoints += pair.first.getTotalPoints();
    }
    return ( earnedPoints / totalPoints ) * 100;
}