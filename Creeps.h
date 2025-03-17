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
    Position position;
    int hp;
    Color color;

    Enemy(Position _position, int _hp = 1, Color _color = RED) :
        position(_position), hp(_hp), color(_color) {}
};

const int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };


bool isValid(Position& _position);
void bfs(Position _start);
const std::vector<Enemy> enemies;

#endif // CREEPS_H
