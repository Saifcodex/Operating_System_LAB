#include<iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout<<"number of input: ";
    cin>>n;
    int rq[n];
    cout<<"Response Sequence: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>rq[i];
    }
    cout<<"Response Sequence"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<rq[i]<<' ';
    }
    cout<<endl;
    int head;
    cout<<"Enter the head : ";
    cin>>head;
    int sequence = 0 ;
    for(int i=0; i<n; i++)
    {
        sequence = sequence + abs(head - rq[i]);
        head = rq[i];
    }
    cout<<"Sequence number: "<<sequence<<endl;
    return 0;
}