#include <iostream>
#include <queue>
using namespace std;
   
   
   int main()
{
    // maxHeap through PRIORITY QUEUE
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"element at Top " << pq.top() << endl;
    pq.pop();
    cout<<"element at Top " << pq.top() << endl;
    cout<<"Size is "<< pq.size() << endl;
    if(pq.empty())
    {
        cout<<"pq is empty "<< endl;
    }
    else
    {
        cout<<"pq is not empty "<< endl;
    }
    
    cout << endl;
    

    // minHeap through PRIORITY QUEUE
    priority_queue <int , vector<int> , greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout<<"element at Top " << minHeap.top() << endl;
    minHeap.pop();
    cout<<"element at Top " << minHeap.top() << endl;
    cout<<"Size is "<< minHeap.size() << endl;
    if(minHeap.empty())
    {
        cout<<"minHeap is empty "<< endl;
    }
    else
    {
        cout<<"minHeap is not empty "<< endl;
    }

    return 0;
}