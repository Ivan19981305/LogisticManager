#include "Graph.h"

Graph::Graph(int vertices) : numVertices(vertices) {
    adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
}

void Graph::addEdge(int src, int dest, int weight) {
    adjacencyMatrix[src][dest] = weight;
    adjacencyMatrix[dest][src] = weight; // Для неориентированного графа
}

std::vector<int> Graph::shortestPath(int src, int dest) {
    std::vector<int> dist(numVertices, INT_MAX);
    std::vector<bool> visited(numVertices, false);
    std::vector<int> prev(numVertices, -1); // Для восстановления пути

    dist[src] = 0;

    for (int count = 0; count < numVertices - 1; ++count) {
        int minDist = INT_MAX, u = -1;
        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && adjacencyMatrix[u][v] && dist[u] != INT_MAX && 
                dist[u] + adjacencyMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjacencyMatrix[u][v];
                prev[v] = u; 
            }
        }
    }

    // Восстановление пути
    std::vector<int> path;
    for (int at = dest; at != -1; at = prev[at]) {
        path.insert(path.begin(), at);
    }
    return path; 
}