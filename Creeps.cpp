#include "Creeps.h"
#include <stack>

const int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
std::vector<Creep> creeps;
constexpr float MOVE_TIMER = 1.0f;

bool IsOnSpire(const Position& position) {
    return grid[position.y][position.x].type == SPIRE;
}

bool IsPositionValid(const Position& position) {
    if (!InBounds(position)) return false;
    const Tile& tile = grid[position.y][position.x];

    return (tile.type == EMPTY || tile.type == SPIRE);
}


std::map<int, Position> BreadthFirstPath(const Position& start) {
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

    return path;
}

void SpawnCreep(const Position& position) {
    Creep newCreep(position);
    newCreep.path = BreadthFirstPath(position);

    if (!newCreep.path.empty()) {
        creeps.push_back(newCreep);
        grid[position.y][position.x].type = CREEP;
    }
}
void MoveCreeps(float deltaTime) {
    for (auto creepPos = creeps.begin(); creepPos != creeps.end();) {
        Creep& creep = *creepPos;
        creep.moveTimer += deltaTime;

        if (creep.moveTimer < MOVE_TIMER) {
            ++creepPos;
            continue;
        }

        if (creep.path.empty() || creep.path.find(creep.pathStep) == creep.path.end() ||
            !IsPositionValid(creep.path[creep.pathStep])) {
            creep.path = BreadthFirstPath(creep.position);
            creep.pathStep = 0;
            }

        if (creep.path.empty()) {
            creep.moveTimer = 0.0f;
            ++creepPos;
            continue;
        }

        grid[creep.position.y][creep.position.x].type = EMPTY;
        creep.position = creep.path[creep.pathStep++];
        grid[creep.position.y][creep.position.x].type = CREEP;

        creep.moveTimer = 0.0f;

        if (IsOnSpire(creep.position)) {
            std::cout << "Creep reached the spire!" << std::endl;
            creepPos = creeps.erase(creepPos);
        } else {
            ++creepPos;
        }
    }
}