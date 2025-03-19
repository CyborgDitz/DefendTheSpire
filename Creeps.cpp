#include "Creeps.h"

constexpr extern int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
std::vector<Creep> creeps;


bool IsOnSpire(Position& position) {
    return grid[position.y][position.x].type == SPIRE;
}
bool IsPositionValid(Position& position) {
    if (!InBounds(position.y, position.x))
        return false;

    // Check if the tile is traversable (not a wall or other blocking object)
    TileType type = grid[position.y][position.x].type;
    return type == EMPTY || type == SPIRE;
}
void MoveCreeps(Position& targetPosition) {
    for (auto& creep : creeps) {
        // Simple movement logic - move towards target
        // In a real game, you'd want more sophisticated movement
        int dx = targetPosition.x - creep.position.x;
        int dy = targetPosition.y - creep.position.y;

        // Move in the direction of the largest difference
        if (abs(dx) > abs(dy)) {
            creep.position.x += (dx > 0) ? 1 : -1;
        } else {
            creep.position.y += (dy > 0) ? 1 : -1;
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

        for (int i = 0; i < 4; ++i) {
            Position nextPosition(current.position.x + DIRECTIONS[i][1], current.position.y + DIRECTIONS[i][0]);

            if (IsPositionValid(nextPosition) && visited.find(nextPosition) == visited.end()) {
                frontier.push(Node(nextPosition, current.distance + 1));
                visited[nextPosition] = true;
                
                if (IsOnSpire(nextPosition)) {
                    MoveCreeps(nextPosition);
                }
            }
        }
    }
}