#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() 
{
    int n, head;
    cout<<"INPUT"<<endl;
    cout << "Enter number of disk requests: ";
    cin >> n;
    vector<int> requests(n);
    cout << "Enter the request sequence:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> requests[i];
    }
    cout << "Enter the initial head position: ";
    cin >> head;
    requests.push_back(head);
    sort(requests.begin(), requests.end());
    int headIndex = 0;
    for (int i = 0; i < requests.size(); i++) 
    {
        if (requests[i] == head) 
        {
            headIndex = i;
            break;
        }
    }
    vector<int> seekSequence;
    for (int i = headIndex; i < requests.size(); i++) 
    {
        if (requests[i] != 0)
        {
            seekSequence.push_back(requests[i]);
        }
    }
    for (int i = headIndex - 1; i >= 0; i--) 
    {
        if (requests[i] != 0)
        {
            seekSequence.push_back(requests[i]);
        }
    }
    int totalMovement = 0;
    cout<<"OUTPUT\n";
    cout << "Seek Sequence: ";
    for (int i = 0; i < seekSequence.size(); i++)
    {
        cout << seekSequence[i] << " ";
        if (i > 0)
        {
            totalMovement += abs(seekSequence[i] - seekSequence[i - 1]);
        }
    }
    cout << "\nTotal Seek Operations : " << totalMovement<<endl ;
    return 0;
}
