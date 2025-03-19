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
        Position newPos(creep.position.x + dx, creep.position.y + dy);
        if (IsPositionValid(newPos)) {
            creep.position = newPos;
        }
    }
}


void BreadthFirst(Position& start) {
    std::queue<Node> frontier;
    std::map<Position, bool> visited;

    frontier.push(Node(start, 0));
    visited[start] = true;

    while (!frontier.empty()) {
        Node current = frontier.front();
        frontier.pop();

        std::cout << "Position (" << current.position.x << ", " << current.position.y
                  << ") Distance: " << current.distance << std::endl;

        if (IsOnSpire(current.position)) {

            MoveCreeps(current.position.x,current.position.y);
            return;
        }

        for (int i = 0; i < 4; ++i) {
            Position nextPosition(current.position.x + DIRECTIONS[i][1], current.position.y + DIRECTIONS[i][0]);

            if (IsPositionValid(nextPosition) && visited.find(nextPosition) == visited.end()) {
                frontier.push(Node(nextPosition, current.distance + 1));
                visited[nextPosition] = true;
            }
        }
    }
}