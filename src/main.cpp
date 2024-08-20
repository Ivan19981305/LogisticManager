#include <iostream>
#include "OrderTests.h"
#include "Graph.h"

int main() {
    Graph g(5); // Граф с 5 городами
    g.addEdge(0, 1, 10); 
    g.addEdge(0, 3, 30);
    g.addEdge(0, 4, 100);
    g.addEdge(1, 2, 50);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 60);
    runTests();
    return 0;
}