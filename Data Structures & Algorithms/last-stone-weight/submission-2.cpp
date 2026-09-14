class Solution {

    vector<int> heap;

    void heapifyup(int index)
    {
        if(!index) return;

        int parent = (index-1)/2;

        if(heap[parent]<heap[index])
        {
            swap(heap[parent],heap[index]);
            heapifyup(parent);
        }

        else return;
    }

    void heapifydown(int index)
    {
        int largest = index;
        
        int lson = 2*index + 1;
        int rson = 2*index + 2;

        int size = heap.size();

        if(lson<size && heap[lson]>heap[largest]) largest = lson;
        if(rson<size && heap[rson]>heap[largest]) largest = rson;

        if(largest!=index)
        {
            swap(heap[index],heap[largest]);
            heapifydown(largest);
        }

        else return;
    }

    void push(int val)
    {
        heap.push_back(val);
        int size = heap.size();

        heapifyup(size-1);
    }

    int pop()
    {
        int val = heap[0];

        int size = heap.size();
        heap[0] = heap[size-1];

        heap.pop_back();

        heapifydown(0);

        return val;
    }

    int top()
    {
        return heap[0];
    }



public:

    int lastStoneWeight(vector<int>& stones) {

        for(int i : stones) push(i);

        while(heap.size() > 1)
        {
            int stone1 = pop();
            int stone2 = pop();

            int newstone = stone2>stone1 ? stone2-stone1 : stone1-stone2;

            if(newstone) push(newstone);

        }

        if(heap.size()!=0) return top();

        return 0;
        
    }
};
