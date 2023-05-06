#include "Graph.h"
#include <iostream>
    

int main() {

    setlocale(LC_ALL, "ru");

    int distance;

    Graph graph;

    graph.addVertex(0, "Олег");
    graph.addVertex(1, "Никита");
    graph.addVertex(2, "Настя");
    graph.addVertex(3, "Ваня");
    graph.addVertex(4, "Женя");

    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 1);

    graph.findMinDistancesFloyd();

    while (true)
    {
        std::cout << "Введите длину рукопожатия:   (0 - Выход)" << std::endl;
        std::cin >> distance;

        if (distance == 0) break;
        graph.findPairOfDistance(distance);
    }
    return 0;
}