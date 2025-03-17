#ifndef CREEPS_H
#define CREEPS_H

#include "globals.h"
#include <queue>
#include <iostream>
#include <map>
#include <vector>

#include "raylib.h"

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
struct Enemy {
    int hp = {1};
    Color color = {RED};
};
const int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
bool isValid(Position& _position);
void bfs(Position _start);


#endif // CREEPS_H
