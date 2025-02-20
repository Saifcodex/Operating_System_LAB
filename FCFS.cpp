#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int size;
    cout << "Enter the data size: ";
    cin >> size;

    int Arrival[size];
    int Burst[size];

    cout<<"Enter Arrival times: "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>Arrival[i];
    }

    cout<<"Enter Burst time: "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>Burst[i];
    }

    cout<<"Arrival times: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<Arrival[i]<<' ';
    }
    cout<<endl;

    cout<<"Burst times: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<Burst[i]<<' ';
    }
    cout<<endl;

    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(Arrival[j]>Arrival[j+1]) 
            {
                swap(Arrival[j],Arrival[j+1]);
                swap(Burst[j],Burst[j+1]);
            }
        }
    }

    cout<<"Sorted Arrival times: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<Arrival[i]<<' ';
    }
    cout<<endl;

    cout<<"Sorted Burst times: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<Burst[i]<<' ';
    }
    cout<<endl;

    int completion[size];
    int s=0;
    for(int i=0; i<size; i++)
    {
        s=Burst[i]+s;
        completion[i]=s;
    }
    cout<<"Completion Time: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<completion[i]<<' ';
    }
    cout<<endl;

    int turn_around[size];
    for(int i=0; i<size; i++)
    {
        turn_around[i] = completion[i]-Arrival[i];
    }
    cout<<"Turn Around Time: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<turn_around[i]<<' ';
    }
    cout<<endl;

    int waiting[size];
    for(int i=0; i<size; i++)
    {
        waiting[i] = turn_around[i] -Burst[i];
    }
    cout<<"Waitng and Responsive Time: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<waiting[i]<<' ';
    }
    cout<<endl;
    return 0;
}