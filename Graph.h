#pragma once
#include <string>

#define SIZE 10
#define VERYBIGINT 100000000

class Graph {
public:
    Graph();
    // добавление вершины
    void addVertex(int vnumber, std::string name);
    // добавление ребра
    void addEdge(int v1, int v2, int weight);
    // поиск всех минимальных расстояний
    void findMinDistancesFloyd();
    // вывод всех друзей с заданной длиной рукопожатия
    void findPairOfDistance(int distance);

private:
    struct Human {
        int _id;
        std::string _name;

        Human(int id, std::string name) {
            _id = id;
            _name = name;
        }
        Human() {
            _id = VERYBIGINT;
            _name = "";
        }
    };

    Human humans[SIZE];
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);

    int matrix[SIZE][SIZE]; // матрица смежности
    int weights[SIZE][SIZE]; //матрица кратчайших путей

    int vertexes[SIZE]; // хранилище вершин
    int vertexCount; // количество добавленных вершин
};


