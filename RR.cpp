#include<iostream>
#include<queue>
using namespace std;
struct Process
{
    int ArrivalTime;
    int BurstTime;
    int CompletionTime;
    int ResponseTime;
    int TurnaroundTime;
    int WaitingTime;
};
void calculationtime(Process processes[], int n, int TimeQuantum)
{
     int cpuget[n] = {0} ;
     int remainingTime[n];
     for (int i = 0; i < n; i++)
     {
         remainingTime[i] = processes[i].BurstTime;
     }
     queue<int> p;
     p.push(0);
     int ct=0;
     cpuget[0]=processes[0].ArrivalTime;
     while(!p.empty())
     {

          int deq_p = p.front();
          if(deq_p!=0 && cpuget[deq_p]==0)
          {
               cpuget[deq_p] = ct;
          }
          p.pop();
          if(remainingTime[deq_p]>TimeQuantum)
          {
               remainingTime[deq_p]=remainingTime[deq_p]-TimeQuantum;
               ct =ct + TimeQuantum;
          }
          else
          {
               ct = ct + remainingTime[deq_p];
               processes[deq_p].CompletionTime = ct;
               remainingTime[deq_p]=0;
          }
          if(ct<=processes[n-1].ArrivalTime)
          {
               for(int i=ct-TimeQuantum+1 ; i<=ct; i++)
               {
                    for(int j=1; j<n;  j++)
                    {
                         if(processes[j].ArrivalTime==i) 
                         {
                              p.push(j);
                              break;
                         } 
                    }
               }
          }
          if(remainingTime[deq_p]>0)
          {
               p.push(deq_p);
          }
     }
     for(int i=0; i<n; i++)
     {
          processes[i]. ResponseTime = cpuget[i]-processes[i].ArrivalTime;
     }
     for(int i=0; i<n; i++)
     {
          processes[i].TurnaroundTime = processes[i].CompletionTime - processes[i].ArrivalTime;
     }
     for(int i=0; i<n; i++)
     {
          processes[i].WaitingTime = processes[i].TurnaroundTime - processes[i].BurstTime;
     }
}
void input(Process processes[],int n)
{
     cout<<"Input"<<endl;
     for(int i=0; i<n; i++)
     {
          cout<<"Arrival time: "<<processes[i].ArrivalTime<<" Burst Time: "<<processes[i].BurstTime<<endl;
     }
}
void output(Process processes[], int n)
{
     cout<<"Result"<<endl;
     for(int i=0; i<n; i++)
     {
          cout<<"Completion time: "<<processes[i].CompletionTime<<endl;
     }
     cout<<endl;
     for(int i=0; i<n; i++)
     {
          cout<<"Response time: "<<processes[i].ResponseTime<<endl;
     }
     cout<<endl;
     for(int i=0; i<n; i++)
     {
          cout<<"Turn Around time: "<<processes[i].TurnaroundTime<<endl;
     }
     cout<<endl;
     for(int i=0; i<n; i++)
     {
          cout<<"Waiting time: "<<processes[i].WaitingTime<<endl;
     }
     cout<<endl;
     
}
int main()
{
     int n, TimeQuantum;
     cout << "Enter the number of Process : ";
     cin >> n;
     cout << "Enter the Time Quantum : ";
     cin >> TimeQuantum;
     Process processes[n];
     cout << "Enter the Processes Details"<<endl;
     for (int i = 0; i < n; i++)
     {
         cout << "Arrival Time ";
         cin >> processes[i].ArrivalTime;
         cout << "Burst Time ";
         cin >> processes[i].BurstTime;
     }
     input(processes,n);
     calculationtime(processes,n,TimeQuantum);
     output(processes,n);
     return 0;
}