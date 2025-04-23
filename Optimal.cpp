#include <iostream>
using namespace std;
bool isInMemory(int memory[], int size, int page) 
{
    for (int i = 0; i < size; i++)
    {
        if (memory[i] == page)
        {
            return true;
        }
    }
    return false;
}
int findReplaceIndex(int memory[], int frameSize, int pages[], int currentIndex, int totalPages) 
{
    int farthestIndex = -1;
    int indexToReplace = -1;

    for (int i = 0; i < frameSize; i++) 
    {
        int j;
        for (j = currentIndex + 1; j < totalPages; j++) 
        {
            if (memory[i] == pages[j]) 
            {
                if (j > farthestIndex) 
                {
                    farthestIndex = j;
                    indexToReplace = i;
                }
                break;
            }
        }
        if (j == totalPages) 
        {
            return i;
        }
    }

    if (indexToReplace == -1)
        return 0;
    else
        return indexToReplace;
}

int main() 
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int totalPages = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 4;

    int memory[frameSize];
    int memorySize = 0;

    int hit = 0, miss = 0;

    for (int i = 0; i < totalPages; i++) 
    {
        int currentPage = pages[i];

        if (isInMemory(memory, memorySize, currentPage)) 
        {
            hit++;
        } 
        else 
        {
            miss++;
            if (memorySize < frameSize) 
            {
                memory[memorySize] = currentPage;
                memorySize++;
            } 
            else 
            {
                int index = findReplaceIndex(memory, frameSize, pages, i, totalPages);
                memory[index] = currentPage;
            }
        }
    }
    cout<<"Page Reference String: ";
    for(int i=0 ; i<totalPages; i++)
    {
        cout<<pages[i]<<' ';
    }
    cout<<endl;
    cout<<"Frame Size : "<< frameSize<<endl;
    cout << "Total Page Hits: " << hit << endl;
    cout << "Total Page Misses: " << miss << endl;
    return 0;
}