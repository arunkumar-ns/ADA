#include <iostream>
using namespace std;

#define MAX 10

int indegree[MAX];

// Function for Topological Sort
void topologicalSort(int graph[MAX][MAX], int V)
{
    int i, j;

    // Step 1 : Calculate indegree
    for (i = 0; i < V; i++)
    {
        indegree[i] = 0;
    }

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (graph[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    int count = 0;

    cout << "Topological Order : ";

    // Step 2 : Repeat until all vertices processed
    while (count < V)
    {
        for (i = 0; i < V; i++)
        {
            // Vertex with indegree 0
            if (indegree[i] == 0)
            {
                cout << i << " ";

                // Mark visited
                indegree[i] = -1;

                // Decrease indegree of adjacent vertices
                for (j = 0; j < V; j++)
                {
                    if (graph[i][j] == 1)
                    {
                        indegree[j]--;
                    }
                }

                count++;
            }
        }
    }

    cout << endl;
}

int main()
{
    int V, i, j;

    int graph[MAX][MAX];

    cout << "Enter number of vertices : ";
    cin >> V;

    cout << "Enter adjacency matrix :\n";

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    topologicalSort(graph, V);

    return 0;
}
