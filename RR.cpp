#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Process 
{
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int startTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    bool isStarted;
};
int main() 
{
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter Time Quantum: ";
    cin >> timeQuantum;
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) 
    {
        cout << "\nProcess " << i + 1 << " Arrival Time: ";
        cin >> processes[i].arrivalTime;

        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> processes[i].burstTime;

        processes[i].remainingTime = processes[i].burstTime;
        processes[i].isStarted = false;
    }
    queue<int> q;
    int time = 0;
    int completed = 0;
    vector<bool> inQueue(n, false);
    q.push(0);
    inQueue[0] = true;
    while (completed < n) 
    {
        int idx = q.front();
        q.pop();
        if (!processes[idx].isStarted)
        {
            processes[idx].startTime = max(time, processes[idx].arrivalTime);
            time = processes[idx].startTime;
            processes[idx].isStarted = true;
        }
        if (processes[idx].remainingTime > timeQuantum)
        {
            processes[idx].remainingTime -= timeQuantum;
            time += timeQuantum;
        }
        else
        {
            time += processes[idx].remainingTime;
            processes[idx].remainingTime = 0;
            processes[idx].completionTime = time;
            processes[idx].turnAroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
            processes[idx].waitingTime = processes[idx].turnAroundTime - processes[idx].burstTime;
            completed++;
        }
        for (int i = 0; i < n; i++) 
        {
            if (i != idx && !inQueue[i] && processes[i].arrivalTime <= time && processes[i].remainingTime > 0) 
            {
                q.push(i);
                inQueue[i] = true;
            }
        }
        if (processes[idx].remainingTime > 0) 
        {
            q.push(idx);
        }
        if (q.empty()) 
        {
            for (int i = 0; i < n; i++) 
            {
                if (processes[i].remainingTime > 0) 
                {
                    q.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
        }
    }
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "P" << i + 1 << "\t"
             << processes[i].arrivalTime << "\t"
             << processes[i].burstTime << "\t"
             << processes[i].completionTime << "\t"
             << processes[i].turnAroundTime << "\t"
             << processes[i].waitingTime << "\n";
    }
    return 0;
}
