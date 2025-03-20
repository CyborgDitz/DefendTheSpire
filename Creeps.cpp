#include "Creeps.h"
#include <stack>
constexpr extern int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
std::vector<Creep> creeps;
Position creepPathing;

bool IsOnSpire(const Position& position) {
    return grid[position.y][position.x].type == SPIRE;
}
bool IsPositionValid(const Position& position) {
    if (!InBounds(position))
        return false;
    const Tile& tilePosition = grid[position.y][position.x];
    return tilePosition.type == EMPTY || tilePosition.type == SPIRE;
}
void MoveCreeps(const int dx, const int dy) {
    for (Creep& creep : creeps) {
        const Tile& tileCreepPosition = grid[creep.position.y][creep.position.x];
        Position newPos(creep.position.x + dx, creep.position.y + dy);

        std::cout <<"NewPosition: " << newPos.x << ", " << newPos.y << tileCreepPosition.type << std::endl;
        if (IsPositionValid(newPos)) {
            creep.position = newPos;
        }
        std::cout << "Current position; " << creep.position.x << ", " << creep.position.y << tileCreepPosition.type << std::endl;
    }
}


void BreadthFirst(const Position& start) {
    std::queue<Node> node;
    std::map<Position, bool> visited;
    std::map<Position, Position> predecessors; // To track the path

    node.push(Node(start, 0));
    visited[start] = true;

    bool foundSpire = false;
    Position spirePosition;

    while (!node.empty()) {
        Node currentNode = node.front();
        node.pop();

        std::cout << "Position (" << currentNode.position.x << ", " << currentNode.position.y
                  << ") Distance: " << currentNode.distance << std::endl;

        if (IsOnSpire(currentNode.position)) {
            spirePosition = currentNode.position;  // Record the spire position
            foundSpire = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            Position nextPosition(currentNode.position.x + DIRECTIONS[i][1], currentNode.position.y + DIRECTIONS[i][0]);

            if (IsPositionValid(nextPosition) && visited.find(nextPosition) == visited.end()) {
                node.push(Node(nextPosition, currentNode.distance + 1));
                visited[nextPosition] = true;
                predecessors[nextPosition] = currentNode.position;  // Record the predecessor
            }
        }
    }

    if (foundSpire) {
        std::stack<Position> path;
        Position current = spirePosition;

        while (current != start) {
            path.push(current);
            current = predecessors[current];
        }

        path.push(start);

        std::cout << "Path to spire: ";
        while (!path.empty()) {
            Position creepPathing = path.top();
            path.pop();
            std::cout << "(" << creepPathing.x << ", " << creepPathing.y << ") ";
        }
        std::cout << std::endl;

        // Optionally, move the creeps to follow the path
        // Here you would probably want to move the creeps step-by-step, but this example prints the path
    }
}
