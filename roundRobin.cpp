#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n];    // rt = remaining time
    int ct[n], tat[n], wt[n];
    bool done[n] = {0};

    cout << "Enter Arrival Time and Burst Time:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];   // remaining time initially = burst time
        done[i] = false;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int currentTime = 0, completed = 0;

    while (completed < n) {
        bool executedAny = false;

        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= currentTime) {

                executedAny = true;

                // If remaining time > time quantum
                if (rt[i] > tq) {
                    rt[i] -= tq;
                    currentTime += tq;
                }
                // If remaining time <= time quantum → process finishes
                else {
                    currentTime += rt[i];
                    rt[i] = 0;
                    ct[i] = currentTime;
                    tat[i] = ct[i] - at[i];
                    wt[i]  = tat[i] - bt[i];
                    done[i] = true;
                    completed++;
                }
            }
        }

        // If no process executed in this cycle → jump to next arrival
        if (!executedAny) {
            int nextArrival = 9999;
            for (int i = 0; i < n; i++)
                if (!done[i] && at[i] < nextArrival)
                    nextArrival = at[i];

            currentTime = nextArrival;
        }
    }

    cout << "\nAT\tBT\tCT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << "\n";
    }

    return 0;
}