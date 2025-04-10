#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() 
{
    int n, head, disk_size=200, direction;
    cout << "Enter number of requests: ";
    cin >> n;
    vector<int> requests(n);
    cout << "Enter request sequence: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> requests[i];
    }
    cout << "Enter initial head position: ";
    cin >> head;
    cout << "Enter direction (0 = Left, 1 = Right): ";
    cin >> direction;
    requests.push_back(head);
    sort(requests.begin(), requests.end());
    int index = find(requests.begin(), requests.end(), head) - requests.begin();
    vector<int> sequence;
    int total_movement = 0;
    if (direction == 1) 
    { 
        
        for (int i = index; i < requests.size(); i++) 
        {
            sequence.push_back(requests[i]);
        }
        
        if (sequence.back() != disk_size - 1)
            sequence.push_back(disk_size - 1);

        for (int i = index - 1; i >= 0; i--) 
        {
            sequence.push_back(requests[i]);
        }

    } 
    else 
    {
        for (int i = index; i >= 0; i--) 
        {
            sequence.push_back(requests[i]);
        }
        if (sequence.back() != 0)
            sequence.push_back(0);

        for (int i = index + 1; i < requests.size(); i++) {
            sequence.push_back(requests[i]);
        }
    }
    cout << "\nSeek Sequence: ";
    for (int i = 0; i < sequence.size(); i++) 
    {
        cout << sequence[i] << " ";
        if (i > 0)
            total_movement += abs(sequence[i] - sequence[i - 1]);
    }
    cout << "\nTotal Seek Operation: " << total_movement << endl;
    return 0;
}
