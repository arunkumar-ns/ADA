#include <iostream>
#include <cstring>
using namespace std;

#define INF 9999999

int main() {
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    int G[V][V];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> G[i][j];
        }
    }

    int no_edge = 0;
    bool selected[V];
    memset(selected, false, sizeof(selected));

    selected[0] = true;

    int x, y;

    cout << "\nEdge : Weight\n";

    while (no_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << G[x][y] << endl;

        selected[y] = true;
        no_edge++;
    }

    return 0;
}