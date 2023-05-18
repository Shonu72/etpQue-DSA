#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void DFS(vector<int> adj[], int start)
{
    bool visited[start + 1] = {false}; // Create an array to mark visited vertices
    stack<int> s;                      // Create a stack for DFS

    s.push(start); // Push the starting vertex onto the stack

    while (!s.empty())
    {
        int curr = s.top(); // Get the top element of the stack
        s.pop();            // Pop the top element

        // If vertex is not visited, mark it as visited and print it
        if (!visited[curr])
        {
            visited[curr] = true;
            cout << curr << " ";
        }

        // Add adjacent vertices of current vertex to the stack
        for (int v : adj[curr])
        {
            if (!visited[v])
            {
                s.push(v);
            }
        }
    }
}

int main()
{
    int n = 9, m = 16; // Input number of vertices and edges

    vector<int> adj[n + 1]; // Create vector array for adjacency list

    // Add edges
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(6);
    adj[6].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[2].push_back(7);
    adj[7].push_back(2);
    adj[3].push_back(6);
    adj[6].push_back(3);
    adj[5].push_back(3);
    adj[3].push_back(5);
    adj[5].push_back(4);
    adj[4].push_back(5);
    adj[4].push_back(3);
    adj[3].push_back(4);
    adj[5].push_back(8);
    adj[8].push_back(5);
    adj[6].push_back(4);
    adj[4].push_back(6);
    adj[7].push_back(3);
    adj[3].push_back(7);
    adj[7].push_back(5);
    adj[5].push_back(7);
    adj[8].push_back(4);
    adj[4].push_back(8);
    adj[8].push_back(9);
    adj[9].push_back(8);
    adj[9].push_back(5);
    adj[5].push_back(9);
    adj[9].push_back(7);
    adj[7].push_back(9);

    DFS(adj, 1); // Call DFS function with starting vertex as 1

    return 0;
}
