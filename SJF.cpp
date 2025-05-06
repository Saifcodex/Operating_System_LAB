#include <iostream>
using namespace std;

int main() 
{
    int time, burst_time[10], at[10], sum_burst_time = 0, smallest, n, i;
    int completion_time[10],turnaround_time[10], waiting_time[10];
    int sumt = 0, sumw = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Arrival time for process P" << i + 1 << ": ";
        cin >> at[i];
        cout << "Burst time for process P" << i + 1 << ": ";
        cin >> burst_time[i];
        sum_burst_time += burst_time[i];
    }

    burst_time[n+1] = 9999;

    for (time = 0; time < sum_burst_time;)
    {
        smallest = n+1;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && burst_time[i] > 0 && burst_time[i] < burst_time[smallest])
            {
                smallest = i;
            }
        }
        completion_time[smallest]=time + burst_time[smallest];
        turnaround_time[smallest]=completion_time[smallest]-at[smallest];
        waiting_time[smallest]=turnaround_time[smallest]-burst_time[smallest];

        cout << "P[" << smallest + 1 << "]\t|\t" <<completion_time[smallest]<< "\t|\t" << turnaround_time[smallest] <<"\t|\t" <<waiting_time[smallest]<< endl;
        sumt += time + burst_time[smallest] - at[smallest];
        sumw += time - at[smallest];
        time += burst_time[smallest];
        burst_time[smallest] = 0;
    }
    return 0;
}
