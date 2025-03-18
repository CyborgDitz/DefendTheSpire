//
// Created by sebba on 2025-03-14.
//

#include "Creeps.h"
constexpr extern int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
std::vector<Creep> creeps;
bool IsValid(Position& _position) {
    return InBounds(_position.y, _position.x) &&
           (grid[_position.y][_position.x].type == EMPTY || grid[_position.y][_position.x].type == SPIRE);
}

void BreathFirst(Position _start) {
    std::queue<Node> frontier;
    std::map<Position, bool> visited;

    frontier.push(Node(_start, 0));
    visited[_start] = true;

    while (!frontier.empty()) {
        Node current = frontier.front();
        frontier.pop();

        std::cout << "Position (" << current.position.x << ", " << current.position.y
                  << ") Distance: " << current.distance << std::endl;

        for (int i = 0; i < 4; ++i) {
            Position nextPosition(current.position.x + DIRECTIONS[i][1], current.position.y + DIRECTIONS[i][0]);

            if (IsValid(nextPosition) && visited.find(nextPosition) == visited.end()) {
                frontier.push(Node(nextPosition, current.distance + 1));
                visited[nextPosition] = true;
            }
        }
    }
}
