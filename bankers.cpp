#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[n][m], max[n][m], need[n][m], avail[m];
    int done[n] = {0}, safe[n], count = 0;

    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "Enter Max Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "Enter Available Resources:\n";
    for (int i = 0; i < m; i++)
        cin >> avail[i];

    // Calculate Need Matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Safety Algorithm
    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!done[i]) {
                bool canRun = true;

                for (int j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                        canRun = false;

                if (canRun) {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safe[count++] = i;
                    done[i] = 1;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "\nSystem is NOT in safe state!";
            return 0;
        }
    }

    cout << "\nSafe Sequence: ";
    for (int i = 0; i < n; i++)
        cout << "P" << safe[i] << " ";

    cout << "\nSystem is in SAFE state.\n";
    return 0;
}