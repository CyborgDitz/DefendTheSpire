#ifndef CREEPS_H
#define CREEPS_H

#include "globals.h"
#include <queue>
#include <iostream>
#include <map>
#include <vector>
#include "raylib.h"
//todo movement

struct Node {
    Position position;
    int distance;

    Node(Position position, int distance) :
        position(position), distance(distance) {}
};

struct Creep {
    Position position;
    int hp;
    Color color;

    Creep(Position position, int hp = 1, Color color = RED) :
        position(position), hp(hp), color(color) {}
};

void BreadthFirst(const Position& start);
void MoveCreeps(int dx, int dy);

extern std::vector<Creep> creeps;

#endif // CREEPS_H
