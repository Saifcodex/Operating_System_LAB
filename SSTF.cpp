#include <bits/stdc++.h>
using namespace std;
int find_min(int diff[][2], int n)
{
    int index = -1;
    int minimum = 1e9;
    for(int i = 0; i < n; i++)
    {
        if (!diff[i][1] && minimum > diff[i][0])
        {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}
void sstf(int request[], int head, int n)
{
    if (n == 0)
    {
        return;
    }
    int diff[n][2] = { { 0, 0 } };
    int sc = 0;
    int seek_sequence[n + 1];
    seek_sequence[0] = head;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (diff[j][1] == 0)
            {
               diff[j][0] = abs(head - request[j]);
            }
        }

        int index = find_min(diff, n);

        diff[index][1] = 1;

        sc += diff[index][0];
        head = request[index];

        seek_sequence[i] = head;
    }
    cout << "Total number of seek operations: " << sc << endl;
    cout << "Seek sequence is: " << endl;
    for(int i = 0; i <= n; i++)
    {
        cout << seek_sequence[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of requests: ";
    cin >> n;
    cout << "Enter the request sequence: " << endl;
    int req[n];
    for(int i = 0; i < n; i++)
    {
        cin >> req[i];
    }
    cout << "Request sequence: ";
    for(int i = 0; i < n; i++)
    {
        cout << req[i] << " ";
    }
    cout << endl;
    int head;
    cout << "Enter the head position: ";
    cin >> head;
    sstf(req, head, n);
    return 0;
}
