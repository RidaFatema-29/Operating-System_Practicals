#include<iostream>
using namespace std;

int main() {
    int n;
    int at[10], bt[10], ct[10], wt[10], tat[10];

    cout << "Enter no. of processes : ";
    cin >> n;

    cout << "Enter Arrival time and Burst time for each process : ";
    for (int i = 0; i < n; i++) {
        cout << "\nProcess " << i+1 << " : ";
        cin >> at[i] >> bt[i];
    }

    int currentTime = 0;

    // FIRST PROCESS
    if (currentTime < at[0]) {
        currentTime = at[0];
    }

    wt[0] = currentTime - at[0];
    currentTime += bt[0];
    ct[0] = currentTime;
    tat[0] = ct[0] - at[0];

    // REMAINING PROCESSES
    for (int i = 1; i < n; i++) {

        if (currentTime < at[i]) {
            currentTime = at[i];
        }

        wt[i] = currentTime - at[i];
        currentTime += bt[i];
        ct[i] = currentTime;
        tat[i] = ct[i] - at[i];
    }

    cout << "\nArrival\t Burst\t Waiting\t TurnAround\t Completion\n";
    for (int i = 0; i < n; i++) {
        cout << at[i] << "\t" 
             << bt[i] << "\t" 
             << wt[i] << "\t\t" 
             << tat[i] << "\t\t" 
             << ct[i] << "\n";
    }

    return 0;
}