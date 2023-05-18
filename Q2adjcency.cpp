#include <iostream>
using namespace std;

class Graph
{
private:
    bool **adjMatrix;
    int numVertices;

public:
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix = new bool *[numVertices];
        for (int i = 1; i <= numVertices; i++)
        {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 1; j <= numVertices; j++)
                adjMatrix[i][j] = false;
        }
    }

    // Add edges
    void addEdge(int i, int j)
    {
        adjMatrix[i][j] = true;
    }

    // Remove edges
    void removeEdge(int i, int j)
    {
        adjMatrix[i][j] = false;
    }

    // Print the martix
    void toString()
    {
        for (int i = 1; i <= numVertices; i++)
        {
            for (int j = 1; j <= numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }

    ~Graph()
    {
        for (int i = 1; i <= numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.addEdge(5, 4);

    g.toString();
}