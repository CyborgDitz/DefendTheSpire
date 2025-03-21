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

            // Only proceed if the next position is valid
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

        if (creep.path.empty() || !IsPositionValid(creep.path[creep.pathStep])) {
            std::cout << "Recalculating path for creep at position ("
                      << creep.position.x << ", " << creep.position.y << ")\n";

            creep.path = BreadthFirstPath(creep.position);
            creep.pathStep = 0;

        if (!creep.path.empty()) {
            if (creep.pathStep < creep.path.size()) {
                grid[creep.position.y][creep.position.x].type = EMPTY;
                creep.position = creep.path[creep.pathStep++];
                grid[creep.position.y][creep.position.x].type = CREEP;
            }
        } else {

            bool moved = false;
            for (const auto& dir : DIRECTIONS) {
                Position nextPos = { creep.position.y + dir[1], creep.position.x + dir[1] };

                if (IsPositionValid(nextPos)) {
                    grid[creep.position.y][creep.position.x].type = EMPTY;
                    creep.position = nextPos;
                    grid[creep.position.y][creep.position.x].type = CREEP;
                    moved = true;
                    break;
                }
            }

            if (!moved) {
                ++creepPos;
                continue;
            }
        }

            creep.moveTimer = 0.0f;

            if (IsOnSpire(creep.position)) {
                std::cout << "Creep reached the spire at position ("
                          << creep.position.x << ", " << creep.position.y << ")\n";
                creepPos = creeps.erase(creepPos);
            } else {
                ++creepPos;
            }
        }
    }
}