#include "Creeps.h"
#include <chrono>
#include <stack>


bool IsOnSpire(const Position& position) {
    return grid[position.y][position.x].type == SPIRE;
}

bool IsPositionValid(const Position& position) {
    if (!InBounds(position)) return false;
    const Tile& tile = grid[position.y][position.x];
    return (tile.type == EMPTY || tile.type == SPIRE);
}

std::map<int, Position> BreadthFirstPath(const Position& start) {
    auto startTime = std::chrono::high_resolution_clock::now();

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

            if (IsPositionValid(nextPos) && !visited.contains(nextPos)) {
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

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = endTime - startTime;
    std::cout << "BreadthFirstPath execution time: " << elapsed.count() << " seconds\n";

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

void RecalculatePath(Creep& creep) {
    std::cout << "Recalculating path for creep at (" << creep.position.x << ", " << creep.position.y << ")\n";
    creep.path = BreadthFirstPath(creep.position);
    creep.pathStep = 0;
}

void HandleCreepReachedSpire(std::vector<Creep>::iterator& creepPos) {
    std::cout << "Creep reached the spire at (" << creepPos->position.x << ", " << creepPos->position.y << ")\n";
    creepPos = creeps.erase(creepPos);
}

void MoveCreeps(float deltaTime) {
    auto startTime = std::chrono::high_resolution_clock::now();

    for (auto creepPos = creeps.begin(); creepPos != creeps.end();) {
        Creep& creep = *creepPos;
        creep.moveTimer += deltaTime;

        if (creep.moveTimer < MOVE_TIMER) {
            ++creepPos;
            continue;
        }

        creep.moveTimer = 0.0f;

        if (creep.path.empty() || !IsPositionValid(creep.path[creep.pathStep])) {
            RecalculatePath(creep);
            continue;
        }

        if (creep.pathStep >= creep.path.size()) {
            if (!WeirdMove(creep)) {
                ++creepPos;
                continue;
            }
        }

        creep.position = creep.path[creep.pathStep++];
        grid[creep.position.y][creep.position.x].type = CREEP;

        if (IsOnSpire(creep.position)) {
            HandleCreepReachedSpire(creepPos);
            continue;
        }

        ++creepPos;
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = endTime - startTime;
    std::cout << "MoveCreeps Execution Time: " << elapsed.count() << " seconds\n";
}
