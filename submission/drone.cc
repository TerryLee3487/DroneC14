#include "drone.h"
#include <string>
using namespace std;

// Initializes a drone in the position (0,0)
Drone::Drone() {
    cur = Position {0, 0};
    dir = 0;
    numSteps = 0;
}

// Destructor
Drone::~Drone() {
    cur = Position {0, 0};
    dir = 0;
    numSteps = 0;
}

// Moves the drone forward by the number of steps in the current direction
// steps must be a positive number
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

// Moves the drone backward by the number of steps in the current direction
// steps must be a positive number
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

// Turns the drone 90 degrees left
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

// Turns the drone 90 degrees right
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

// Returns the current position  
Position Drone::getPosition() const {
    return cur;
}

// Returns the current direction
int Drone::getDirection() const {
    return dir;
}

// Returns the total number of steps walked by the drone
int Drone::getTotalDistance() const {
    return numSteps;
}

// Returns the Manhattan distance of the current position to the origin
int Drone::getManhattanDistance() const {
    return cur.getManhattanDistance();
}

// Prints the current status of the drone to out in the format:
// Current position: (ew,ns), Facing <direction>
// where <direction> is North, East, South, or West
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


