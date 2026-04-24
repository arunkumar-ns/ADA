#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of objects: ";
    cin >> n;

    int p[n], w[n];
    float x[n], ratio[n];

    // Input profits
    cout << "Enter profits:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Input weights
    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    int M;
    cout << "Enter capacity of knapsack: ";
    cin >> M;

    float P = 0; // total profit

    // Step 1: find p[i]/w[i]
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)p[i] / w[i];
    }

    // Step 2: sort in decreasing order of ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // swap ratio
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap profit
                int t1 = p[i];
                p[i] = p[j];
                p[j] = t1;

                // swap weight
                int t2 = w[i];
                w[i] = w[j];
                w[j] = t2;
            }
        }
    }

    // Initialize x[i] = 0
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    // Step 3: greedy selection
    for (int i = 0; i < n; i++) {
        if (w[i] <= M) {
            x[i] = 1;
            M = M - w[i];
            P = P + p[i];
        } else {
            x[i] = (float)M / w[i];
            P = P + (p[i] * x[i]);
            M = 0;
            break;
        }
    }

    // Output results
    cout << "\nFractions taken (x[i]):\n";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }

    cout << "\nMaximum Profit = " << P << endl;

    return 0;
}