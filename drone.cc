#include "drone.h"
#include <string>
using namespace std;

Drone::Drone() {
    cur = Position {0, 0};
    dir = 0;
    numSteps = 0;
}

Drone::~Drone() {
    cur = Position {0, 0};
    dir = 0;
    numSteps = 0;
}

void Drone::forward(int steps) {
    if (dir == 0) {
        Position pos {0,steps};
        cur += pos;
    } else if (dir == 1) {
        Position pos {steps,0};
        cur += pos;
    } else if (dir == 2) {
        Position pos {0,-steps};
        cur += pos;
    } else if (dir == 3) {
        Position pos {-steps, 0};
        cur += pos;
    }
    numSteps += steps;
}

void Drone::backward(int steps) {
    if (dir == 0) {
        Position pos {0,steps};
        cur -= pos;
    } else if (dir == 1) {
        Position pos {steps,0};
        cur -= pos;
    } else if (dir == 2) {
        Position pos {0,-steps};
        cur -= pos;
    } else if (dir == 3) {
        Position pos {-steps, 0};
        cur -= pos;
    }
    numSteps += steps;
}

void Drone::left() {
    if (dir == 0) {
        dir = 3;
    } else if (dir == 1) {
        dir = 0;
    } else if (dir == 2) {
        dir = 1;
    } else if (dir == 3) {
        dir = 2;
    }
}

void Drone::right() {
    if (dir == 0) {
        dir = 1;
    } else if (dir == 1) {
        dir = 2;
    } else if (dir == 2) {
        dir = 3;
    } else if (dir == 3) {
        dir = 0;
    }
}

Position Drone::getPosition() const {
    return cur;
}

int Drone::getDirection() const {
    return dir;
}

int Drone::getTotalDistance() const {
    return numSteps;
}

int Drone::getManhattanDistance() const {
    return cur.getManhattanDistance();
}

ostream &operator<<(ostream &out, const Drone &drone) {
    int direction = drone.getDirection();
    
    if (direction == 0) {
        out << "Current position: " << drone.getPosition() << ", Facing North";
    } else if (direction == 1) {
        out << "Current position: " << drone.getPosition() << ", Facing East";
    } else if (direction == 2) {
        out << "Current position: " << drone.getPosition() << ", Facing South";
    } else if (direction == 3) {
        out << "Current position: " << drone.getPosition() << ", Facing West";
    }
    return out;
}


