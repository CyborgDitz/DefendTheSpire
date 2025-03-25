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

    explicit Creep(Position position, int hp = 1, Color color = RED) :
        position(position), hp(hp), color(color), pathStep(0), moveTimer(0.0f) {}
};

std::map<int, Position> BreadthFirstPath(const Position& start);
bool IsOnSpire(const Position& position);
bool IsPositionValid(const Position& position);
void RecalculatePath(Creep& creep);
bool WeirdMove(Creep& creep);
void HandleCreepReachedSpire(std::vector<Creep>::iterator& creepPos);
void SpawnCreep(const Position& position);
void MoveCreeps(float deltaTime);

constexpr float MOVE_TIMER = 1.0f;
constexpr int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

inline std::vector<Creep> creeps;

#endif // CREEPS_H