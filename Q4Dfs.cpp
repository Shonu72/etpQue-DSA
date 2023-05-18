// DFS algorithm in C++

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

// Initialize graph
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex)
{
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main()
{
    Graph g(10);
    g.addEdge(1, 6);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 7);
    g.addEdge(7, 3);
    g.addEdge(7, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 6);
    g.addEdge(6, 4);
    g.addEdge(4, 3);
    g.addEdge(5, 3);
    g.addEdge(5, 4);
    g.addEdge(5, 8);
    g.addEdge(8, 4);
    g.addEdge(8, 9);
    g.addEdge(9, 5);
    g.addEdge(9, 7);

    g.DFS(1);

    return  0;
}