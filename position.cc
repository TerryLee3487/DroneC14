#include "position.h"
using namespace std;

Position::Position(int ew, int ns) {
    this->ew = ew;
    this->ns = ns;
}
Position & Position::operator+=(const Position &rhs) {
    ew = ew + rhs.ew;
    ns = ns + rhs.ns;
    return *this;
} 

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

ostream& operator<<(ostream &out, const Position &pos) {
    out << "(" << pos.getEW() << "," << pos.getNS() << ")";
}