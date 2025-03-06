#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Process
{
    int id, arrivalTime, burstTime, priority, remainingTime, completionTime, waitingTime, turnAroundTime, startTime;
};
void priorityScheduling(vector<Process> &processes, int n)
{
    int completed = 0, currentTime = 0, prev = -1;
    int maxPriority = INT_MIN, maxIndex = -1;
    vector<bool> isCompleted(n, false);
    while (completed != n)
    {
        maxPriority = INT_MIN;
        maxIndex = -1;
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && !isCompleted[i])
            {
                if (processes[i].priority > maxPriority ||(processes[i].priority == maxPriority && processes[i].arrivalTime < processes[maxIndex].arrivalTime))
                {
                    maxPriority = processes[i].priority;
                    maxIndex = i;
                }
            }
        }
        if (maxIndex == -1)
        {
            currentTime++;
        }
        else
        {
            if (prev != maxIndex)
            {
                processes[maxIndex].startTime = (processes[maxIndex].startTime == -1) ? currentTime : processes[maxIndex].startTime;
            }
            processes[maxIndex].remainingTime--;
            if (processes[maxIndex].remainingTime == 0)
            {
                processes[maxIndex].completionTime = currentTime + 1;
                processes[maxIndex].turnAroundTime = processes[maxIndex].completionTime - processes[maxIndex].arrivalTime;
                processes[maxIndex].waitingTime = processes[maxIndex].turnAroundTime - processes[maxIndex].burstTime;
                isCompleted[maxIndex] = true;
                completed++;
            }
            prev = maxIndex;
            currentTime++;
        }
    }
    cout << "ID\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t" << processes[i].arrivalTime << "\t" << processes[i].burstTime << "\t"
             << processes[i].priority << "\t\t" << processes[i].completionTime << "\t"
             << processes[i].turnAroundTime << "\t" << processes[i].waitingTime << endl;
    }
}
int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter Process ID, Arrival Time, Burst Time, and Priority:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processes[i].id >> processes[i].arrivalTime >> processes[i].burstTime >> processes[i].priority;
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].startTime = -1;
    }
    priorityScheduling(processes, n);
    return 0;
}
