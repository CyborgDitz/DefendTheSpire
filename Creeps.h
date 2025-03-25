#ifndef CREEPS_H
#define CREEPS_H

#include "globals.h"
#include <queue>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include "raylib.h"


struct Node;
struct Creep;


std::map<int, Position> BreadthFirstPath(const Position& start);
bool IsPositionValid(const Position& position);
bool IsOnSpire(const Position& position);

void SpawnCreep(const Position& position);
void MoveCreeps(float deltaTime);


extern std::vector<Creep> creeps;
extern const int DIRECTIONS[4][2];

#endif // CREEPS_H
