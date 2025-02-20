#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int size;
    cout << "Enter the Process number: ";
    cin >> size;
    int Arrival[size];
    int Burst[size];
    cout<<"Enter Arrival times: "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>Arrival[i];
    }
    cout<<"Enter Burst times: "<<endl;
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
    completion[0]=Burst[0];
    int s=completion[0];
    int count=1;
    while(1)
    {
        if((s-count)<3)
        {
            swap(Arrival[count],Arrival[count+1]);
            swap(Burst[count],Burst[count+1]);
            s=s+Burst[count];
            if(s>size) s=size;
            count++;
        }
        else
        {
            for(int i=0; i<size-count; i++) 
            {    
                for(int j=count; j<size-i-1; j++) 
                {
                    if(Burst[j]>Burst[j+1]) 
                    {
                        swap(Burst[j],Burst[j+1]);
                        swap(Arrival[j],Arrival[j+1]);
                    }
                }
            }
            break;
        }
    }
    cout<<"Sorted Arrival times based on burst time: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<Arrival[i]<<' ';
    }
    cout<<endl;
    cout<<"Sorted Burst times based on burst time: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<Burst[i]<<' ';
    }
    cout<<endl;
    int init=Burst[0];
    for(int i=1; i<size; i++)
    {
        init = init +Burst[i];
        completion[i]=init;
    }
    cout<<"Completion Time "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<completion[i]<<' ';
    }
    cout<<endl;
    int tat[size];
    for(int i=0; i<size; i++)
    {
        tat[i]=completion[i]-Arrival[i];
    }
    cout<<"Turn Around Time "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<tat[i]<<' ';
    }
    cout<<endl;

    int wat[size];
    for(int i=0; i<size; i++)
    {
        wat[i]=tat[i]-Burst[i];
    }
    cout<<"Waiting Time "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<wat[i]<<' ';
    }
    cout<<endl;  
    return 0;
}