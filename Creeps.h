#ifndef CREEPS_H
#define CREEPS_H

#include "globals.h"
#include <queue>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include "raylib.h"

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
    std::map<int, Position> path;
    int pathStep;
    float moveTimer;

    Creep(Position position, int hp = 1, Color color = RED) :
        position(position), hp(hp), color(color), pathStep(0), moveTimer(0.0f) {}
};

std::map<int, Position> BreadthFirstPath(const Position& start);
bool IsPositionValid(const Position& position);
bool IsOnSpire(const Position& position);

void SpawnCreep(const Position& position);
void MoveCreeps(float deltaTime);


extern std::vector<Creep> creeps;
extern const int DIRECTIONS[4][2];

#endif // CREEPS_H