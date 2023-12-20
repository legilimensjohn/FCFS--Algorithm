#include <iostream>
using namespace std;

int main() {

    int n, bt[n], wt[n], tat[n], avwt = 0, avtat = 0, at[n];

    cout << "Kindly specify the overall count of processes: ";
    cin >> n;

    cout << "\nPlease provide the arrival time and duration for all processes individually!\n";

    for (int i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "] Arrival Time: ";
        cin >> at[i];
        cout << "P[" << i + 1 << "] Burst Time: ";
        cin >> bt[i];
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = 0;
        for (int j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        wt[i] -= at[i];
    }

    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time";

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        cout << "\nP[" << i + 1 << "]\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }

    avwt /= n;
    avtat /= n;

    cout << "\n\nThe Average Waiting Time: " << avwt;
    cout << "\nThe Average Turnaround Time: " << avtat;

    return 0;

}
