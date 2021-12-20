#include "position.h"
using namespace std;

// initialize a new position with gievn ew and ns
Position::Position(int ew, int ns) {
    this->ew = ew;
    this->ns = ns;
}

// Adds rhs.ew to this position's ew and
// rhs.ns to this position's ns
// add up ew and ns separately and return the new position
Position & Position::operator+=(const Position &rhs) {
    ew = ew + rhs.ew;
    ns = ns + rhs.ns;
    return *this;
} 

// Subtracts rhs.ew from this position's ew and
// rhs.ns from this position's ns
// subtract ew and ns separately and return the new position
Position & Position::operator-=(const Position &rhs) {
    ew = ew - rhs.ew;
    ns = ns - rhs.ns;
    return *this;
}

int Position::getEW() const {
    return ew;
}

int Position::getNS() const {
    return ns;
}

// Calculates the Manhattan distance of the this position to the origin
// (the absolute north-south displacement plus the absolute east-west displacement)
int Position::getManhattanDistance() const {
    int tmpEW = 0;
    if (ew < 0) {
        tmpEW = -ew;
    } else {
        tmpEW = ew;
    }
    int tmpNS = 0;
    if (ns < 0) {
        tmpNS = -ns;
    } else {
        tmpNS = ns;
    }
    return tmpNS + tmpEW;
}

// Prints the current values of the position to out in the format:
// (ew,ns)
ostream& operator<<(ostream &out, const Position &pos) {
    out << "(" << pos.getEW() << "," << pos.getNS() << ")";
}

