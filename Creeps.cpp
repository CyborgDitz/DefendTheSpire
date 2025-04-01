#include "Creeps.h"
#include <stack>
#include "raylib.h"

const int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
std::vector<Creep> creeps;
int moveCreepsCallCount = 0;

bool IsOnSpire(const Position& position) {
    return grid[position.y][position.x].type == SPIRE;
}

bool IsPositionValid(const Position& position) {
    if (!InBounds(position)) return false;
    const Tile& tile = grid[position.y][position.x];
    return (tile.type == EMPTY || tile.type == SPIRE);
}

std::map<int, Position> BreadthFirstPath(const Position& start) {
    double startTime = GetTime();  // Start timing

    std::queue<Node> nodeQueue;
    std::map<Position, Position> cameFrom;
    std::map<int, Position> path;
    nodeQueue.push(Node(start, 0));
    std::map<Position, bool> visited;
    visited[start] = true;

    Position spirePosition;
    bool found = false;

    while (!nodeQueue.empty()) {
        Node currentNode = nodeQueue.front();
        nodeQueue.pop();

        if (IsOnSpire(currentNode.position)) {
            spirePosition = currentNode.position;
            found = true;
            break;
        }

        for (const auto& dir : DIRECTIONS) {
            Position nextPos = { currentNode.position.x + dir[1], currentNode.position.y + dir[0] };
            if (IsPositionValid(nextPos) && visited.find(nextPos) == visited.end()) {
                nodeQueue.push(Node(nextPos, currentNode.distance + 1));
                visited[nextPos] = true;
                cameFrom[nextPos] = currentNode.position;
            }
        }
    }

    if (!found) return {};

    std::stack<Position> pathStack;
    Position current = spirePosition;
    while (current != start) {
        pathStack.push(current);
        current = cameFrom[current];
    }

    int step = 0;
    while (!pathStack.empty()) {
        path[step++] = pathStack.top();
        pathStack.pop();
    }

    double endTime = GetTime();  // End timing
   printf("BreadthFirstPath execution time: %.6f seconds\n", endTime - startTime);
    return path;
}

void SpawnCreep(const Position& position) {
    double startTime = GetTime();  // Start timing

    for (int i = 0; i <999; i++) {
        Creep newCreep(position);
 //std::cout << i << << "creeps" << std::endl;
        if (!newCreep.path.empty()) {
            creeps.push_back(newCreep);
            grid[position.y][position.x].type = CREEP;
        }
    }
    Creep newCreep(position);
    newCreep.path = BreadthFirstPath(position);

    if (!newCreep.path.empty()) {
        creeps.push_back(newCreep);
        grid[position.y][position.x].type = CREEP;
    }

    double endTime = GetTime();  // End timing
    //printf("SpawnCreep execution time: %.6f seconds\n", endTime - startTime);
}

bool WeirdMove(Creep& creep) {
    for (const auto& dir : DIRECTIONS) {
        Position nextPos = { creep.position.x + dir[1], creep.position.y + dir[0] };

        if (IsPositionValid(nextPos)) {
            grid[creep.position.y][creep.position.x].type = EMPTY;
            creep.position = nextPos;
            grid[creep.position.y][creep.position.x].type = CREEP;
            return true;
        }
    }
    return false;
}

void MoveCreeps(float deltaTime) {
    double startTime = GetTime();  // Start timing
    moveCreepsCallCount++;  // Increment call count at the beginning

    for (auto creepPos = creeps.begin(); creepPos != creeps.end();) {
        Creep& creep = *creepPos;

        if (creep.path.empty() || creep.pathStep >= creep.path.size() || !IsPositionValid(creep.path[creep.pathStep])) {
            creep.path = BreadthFirstPath(creep.position);
            creep.pathStep = 0;
        }

        if (!creep.path.empty() && creep.pathStep < creep.path.size()) {
            grid[creep.position.y][creep.position.x].type = EMPTY;
            creep.position = creep.path[creep.pathStep++];
            grid[creep.position.y][creep.position.x].type = CREEP;
        } else {
            if (!WeirdMove(creep)) {
                ++creepPos;
                continue;
            }
        }

        if (IsOnSpire(creep.position)) {
            creepPos = creeps.erase(creepPos);
        } else {
            ++creepPos;
        }
    }

    double endTime = GetTime();  // End timing
  //  printf("MoveCreeps execution time: %.6f seconds, Call count: %d\n", endTime - startTime, moveCreepsCallCount);
}
