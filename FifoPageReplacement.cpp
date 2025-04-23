#include <iostream>
#include <queue>
using namespace std;
bool isInMemory(queue<int> memory, int page)
{
    while (!memory.empty()) 
    {
        if (memory.front() == page)
        {
            return true;
        }
        memory.pop();
    }
    return false;
}
int countPageMisses(int pages[], int totalPages, int frameSize) 
{
    queue<int> memory;
    int misses = 0;
    for (int i = 0; i < totalPages; i++) 
    {
        int currentPage = pages[i];
        if (!isInMemory(memory, currentPage)) 
        {
            misses++;
            if (memory.size() == frameSize) 
            {
                memory.pop();
            }
            memory.push(currentPage);
        }
    }
    return misses;
}
int main() 
{
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int totalPages = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 3;
    cout << countPageMisses(pages, totalPages, frameSize) << endl;
    return 0;
}
