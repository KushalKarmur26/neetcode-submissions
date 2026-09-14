class KthLargest {

    vector<int> heap;
    int heapsize;
    int currentsize;


    void heapifyup(int index)
    {
        if(index==0) return;
        
        int parent = (index-1)/2;

        if(heap[parent]<heap[index]) return;

        swap(heap[index],heap[parent]);
        heapifyup(parent);
    }

    void heapifydown(int index)
    {
        int lson = 2*index+1;
        int rson = 2*index+2;

        int smallest = index;

        if(lson<currentsize && heap[lson]<heap[smallest]) smallest = lson;
        if(rson<currentsize && heap[rson]<heap[smallest]) smallest = rson;

        if(smallest!=index)
        {
            swap(heap[index],heap[smallest]);
            heapifydown(smallest);
        }

        else return;
    }

    int pop()
    {
        int val = heap[0];
        heap[0] = heap[currentsize-1];

        heap.pop_back();
        currentsize--;

        heapifydown(0);

        return val;
    }

    int top()
    {
        return heap[0];
    }

    void push(int val)
    {
        if(currentsize>=heapsize)
        {
            if(val>top()) pop();
            else return;
        }

        heap.push_back(val);
        currentsize++;

        heapifyup(currentsize-1);
    }
    

public:
    KthLargest(int k, vector<int>& nums) {

        heapsize = k;
        currentsize = 0;

        for(int i:nums) push(i);
        
    }
    
    int add(int val) {

        push(val);
        return top();
        
    }
};
