#ifndef CREEPS_H
#define CREEPS_H

#include "globals.h"
#include <queue>
#include <iostream>
#include <map>
#include <vector>
#include "raylib.h"
//todo movement
struct Position {
    int x, y;

    bool operator<(const Position& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};
struct Node {
    Position position;
    int distance;

    Node(Position _position, int _distance) :
        position(_position), distance(_distance) {}
};

struct Creep {
    Position position;
    int hp;
    Color color;

    Creep(Position _position, int _hp = 1, Color _color = RED) :
        position(_position), hp(_hp), color(_color) {}
};


bool IsValid(const Position& _position);
void BreathFirst(Position _start);


extern std::vector<Creep> creeps;

#endif // CREEPS_H
