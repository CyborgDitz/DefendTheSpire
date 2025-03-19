#include "Creeps.h"

constexpr extern int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
std::vector<Creep> creeps;


bool IsOnSpire(Position& position) {
    return grid[position.y][position.x].type == SPIRE;
}
bool IsPositionValid(Position& position) {
    if (!InBounds(position.y, position.x))
        return false;
    TileType type = grid[position.y][position.x].type;
    return type == EMPTY || type == SPIRE;
}
void MoveCreeps(int dx, int dy) {
    for (Creep& creep : creeps) {
        TileType type = grid[creep.position.y][creep.position.x].type;
        Position newPos(creep.position.x + dx, creep.position.y + dy);

        std::cout << creep.position.x + dx<< ", " << creep.position.y + dy <<
            type << std::endl;
        if (IsPositionValid(newPos)) {
            creep.position = newPos;
        }
        std::cout << creep.position.x << ", " << creep.position.y << type<< std::endl;
    }
}


void BreadthFirst(Position& start) {
    std::queue<Node> node;
    std::map<Position, bool> visited;

    node.push(Node(start, 0));
    visited[start] = true;

    while (!node.empty()) {
        Node currentNode = node.front();
        node.pop();

        std::cout << "Position (" << currentNode.position.x << ", " << currentNode.position.y
                  << ") Distance: " << currentNode.distance << std::endl;

        if (IsOnSpire(currentNode.position)) {

            MoveCreeps(currentNode.position.x,currentNode.position.y);
            return;
        }

        for (int i = 0; i < 4; ++i) {
            Position nextPosition(currentNode.position.x + DIRECTIONS[i][1], currentNode.position.y + DIRECTIONS[i][0]);

            if (IsPositionValid(nextPosition) && visited.find(nextPosition) == visited.end()) {
                node.push(Node(nextPosition, currentNode.distance + 1));
                visited[nextPosition] = true;
            }
        }
    }
}