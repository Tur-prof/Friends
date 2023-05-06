#include "Graph.h"
#include <iostream>
#include <string>

Graph::Graph()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}

void Graph::addVertex(int id, std::string name)
{
    vertexes[vertexCount] = id;
    humans[vertexCount] = Human(id, name);
    vertexCount++;
}

void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

void Graph::findMinDistancesFloyd()
{
    // инициализаци матрицы
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // путь до самой себя равен 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // если ребра нет
                }
                else {
                    weights[i][j] = matrix[i][j]; // если ребро есть
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) // итерации по k
    {
        int ck = vertexes[k]; // возьмем номер вершины
        for (int i = 0; i < vertexCount; i++)
        {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++)
            {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // пересчет мматрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    for (int i = 0; i < vertexCount; i++)
    {
        // вывод всех минимальных путей от вершины '0'
        if (i != vertexCount - 1)
        {
            std::cout << "V" << i << ": " << weights[0][vertexes[i]] << ", ";
        }
        else
        {
            std::cout << "V" << i << ": " << weights[0][vertexes[i]];
        }
    }
    std::cout << std::endl;
}

void Graph::findPairOfDistance(int distance)
{
    bool find[SIZE]{ 0 };
    for (int i = 0; i < SIZE; i++) {
        find[i] = 1;
        for (int j = 0; j < SIZE; j++) {
            if (i != j && !find[j])
            if (weights[i][j] <= distance) {
                std::cout << humans[i]._name << " - " << humans[j]._name << std::endl;
            }
        }
    }
}

bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}

bool Graph::vertexExists(int v)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == v)
            return true;
    return false;
}
