#include <iostream>
using namespace std;

#define MAX 10

// Function to print permutation
void printPermutation(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

// Function to find largest Mobile Component
int findMC(int a[], int dir[], int n)
{
    int mc = 0;

    for (int i = 0; i < n; i++)
    {
        // LEFT direction
        if (dir[i] == -1 && i != 0)
        {
            if (a[i] > a[i - 1] && a[i] > mc)
            {
                mc = a[i];
            }
        }

        // RIGHT direction
        if (dir[i] == 1 && i != n - 1)
        {
            if (a[i] > a[i + 1] && a[i] > mc)
            {
                mc = a[i];
            }
        }
    }

    return mc;
}

// Function to find position of MC
int findPosition(int a[], int n, int mc)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mc)
        {
            return i;
        }
    }

    return -1;
}

// Johnson Trotter Function
void johnsonTrotter(int n)
{
    int a[MAX];
    int dir[MAX];

    int mc, pos, temp;

    // Initialize permutation and direction
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;

        // Initially all LEFT
        dir[i] = -1;
    }

    // Print first permutation
    printPermutation(a, n);

    while (1)
    {
        // Step 1 : Find largest MC
        mc = findMC(a, dir, n);

        // If no MC exists stop
        if (mc == 0)
        {
            break;
        }

        // Find position of MC
        pos = findPosition(a, n, mc);

        // Step 2 : Swap with adjacent integer
        if (dir[pos] == -1)
        {
            // Swap elements
            temp = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = temp;

            // Swap directions
            temp = dir[pos];
            dir[pos] = dir[pos - 1];
            dir[pos - 1] = temp;

            pos = pos - 1;
        }
        else
        {
            // Swap elements
            temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;

            // Swap directions
            temp = dir[pos];
            dir[pos] = dir[pos + 1];
            dir[pos + 1] = temp;

            pos = pos + 1;
        }

        // Step 3 : Reverse directions
        for (int i = 0; i < n; i++)
        {
            if (a[i] > mc)
            {
                dir[i] = -dir[i];
            }
        }

        // Print permutation
        printPermutation(a, n);
    }
}

int main()
{
    int n;

    cout << "Enter n : ";
    cin >> n;

    johnsonTrotter(n);

    return 0;
}
