#include<iostream>
using namespace std;

int main(){
    cout<<"Enter no. of Processes : ";
    int n;
    cin>>n;

    int at[n], bt[n], ct[n], wt[n], tat[n], done[n]={0};

    cout<<"Enter AT, BT for each process : ";
    for(int i=0; i<n; i++){
        cout<<"\nP "<<i+1<<" : ";
        cin>>at[i]>>bt[i];
    }

    int currentTime = 0, completed = 0;

    while(completed < n){
        int minBT = 9999;
        int idx = -1;

        // find shortest arrived process
        for(int i=0; i<n; i++){
            if(!done[i] && at[i] <= currentTime && bt[i] < minBT){
                minBT = bt[i];
                idx = i;
            }
        }

        // if no process is available, jump to next arrival
        if(idx == -1){
            int nextArrival = 9999;
            for(int i=0; i<n; i++){
                if(!done[i] && at[i] < nextArrival)
                    nextArrival = at[i];
            }
            currentTime = nextArrival; 
            continue;
        }

        // Now execute this selected process
        ct[idx]  = currentTime + bt[idx];
        tat[idx] = ct[idx] - at[idx];
        wt[idx]  = tat[idx] - bt[idx];

        currentTime = ct[idx];
        done[idx] = 1;
        completed++;
    }

    cout<<"\n\nAT\tBT\tCT\tWT\tTAT\n";
    for(int i=0; i<n; i++){
        cout<<at[i]<<"\t"
            <<bt[i]<<"\t"
            <<ct[i]<<"\t"
            <<wt[i]<<"\t"
            <<tat[i]<<"\n";
    }
}