#include <iostream>
using namespace std;

int main() {
    int n;
    int at[10], bt[10], pr[10];
    int ct[10], wt[10], tat[10], done[10] = {0};

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Arrival Time, Burst Time, Priority (lower number = higher priority):\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> at[i] >> bt[i] >> pr[i];
    }

    int currentTime = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int bestPriority = 9999;

        // Select highest priority among arrived processes
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= currentTime) {
                if (pr[i] < bestPriority) {
                    bestPriority = pr[i];
                    idx = i;
                }
            }
        }

        // If no process has arrived yet
        if (idx == -1) {
            int nextArrival = 9999;
            for (int i = 0; i < n; i++)
                if (!done[i] && at[i] < nextArrival)
                    nextArrival = at[i];

            currentTime = nextArrival;
            continue;
        }

        // Calculate metrics
        ct[idx] = currentTime + bt[idx];
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        currentTime = ct[idx];
        done[idx] = 1;
        completed++;
    }

    // Output table
    cout << "\nAT\tBT\tPR\tWT\tTAT\tCT\n";
    for (int i = 0; i < n; i++) {
        cout << at[i] << "\t"
             << bt[i] << "\t"
             << pr[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << "\t"
             << ct[i] << "\n";
    }

    return 0;
}