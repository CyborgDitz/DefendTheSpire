#include "Creeps.h"

constexpr extern int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
std::vector<Creep> creeps;


bool IsOnSpire(Position& position) {
    return grid[position.y][position.x].type == SPIRE;
}
bool IsPositionValid(Position& position) {
    if (!InBounds(position.y, position.x))
        return false;
    Tile& tile = grid[position.y][position.x];
    return tile.type == EMPTY || tile.type == SPIRE;
}
void MoveCreeps(int dx, int dy) {
    for (Creep& creep : creeps) {
        Tile& tile = grid[creep.position.y][creep.position.x];
        Position newPos(creep.position.x + dx, creep.position.y + dy);

        std::cout <<"NewPosition: " << newPos.x << ", " << newPos.y << tile.type << std::endl;
        if (IsPositionValid(newPos)) {
            creep.position = newPos;
        }
        std::cout << "Current position; " << creep.position.x << ", " << creep.position.y << tile.type << std::endl;
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
            MoveCreeps(currentNode.position.x, currentNode.position.y);
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
