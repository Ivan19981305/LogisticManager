#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <climits> // Для INT_MAX

class Graph {
public:
    Graph(int vertices);
    void addEdge(int src, int dest, int weight);
    std::vector<int> shortestPath(int src, int dest);

private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;
};

#endif // GRAPH_H