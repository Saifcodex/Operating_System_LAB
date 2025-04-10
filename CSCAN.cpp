#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the request sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    int head, disk_size;
    cout << "Enter initial head position: ";
    cin >> head;
    cout << "Enter total number of cylinders (disk size): ";
    cin >> disk_size;

    requests.push_back(0);
    requests.push_back(disk_size - 1);

    sort(requests.begin(), requests.end());

    int total_movement = 0;
    int idx;

    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] >= head) {
            idx = i;
            break;
        }
    }

    cout << "\nSeek Sequence:\n";

    for (int i = idx; i < requests.size(); i++) {
        cout << requests[i] << " ";
        total_movement += abs(head - requests[i]);
        head = requests[i];
    }

    total_movement += abs(head - 0);
    head = 0;

    for (int i = 0; i < idx; i++) {
        cout << requests[i] << " ";
        total_movement += abs(head - requests[i]);
        head = requests[i];
    }

    cout << "\nTotal head movement: " << total_movement;

    return 0;
}
