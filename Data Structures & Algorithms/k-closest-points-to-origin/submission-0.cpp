class Solution {

    vector<vector<int>> heap;

    float distance(vector<int> &v)
    {
        return sqrt(v[0]*v[0] + v[1]*v[1]);
    }

    void heapifydown(int index)
    {
        int largest = index;

        int lson = 2*index + 1;
        int rson = 2*index + 2;

        if(lson<heap.size() && distance(heap[lson]) > distance(heap[largest])) largest = lson;
        if(rson<heap.size() && distance(heap[rson]) > distance(heap[largest])) largest = rson;

        if(largest!=index)
        {
            swap(heap[largest],heap[index]);
            heapifydown(largest);

        }

        else return;
    }

    void heapifyup(int index)
    {
        if(!index) return;

        int parent = (index-1)/2;

        if( distance(heap[index]) > distance(heap[parent]) )
        {
            swap(heap[index],heap[parent]);
            heapifyup(parent);

        }

        else return;
    }


    void pop()
    {
        heap[0] = heap[heap.size()-1];
        heap.pop_back();

        heapifydown(0);
    }

    void push(vector<int> &v)
    {
        heap.push_back(v);

        heapifyup(heap.size()-1);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        for(vector<int> i:points)
        {
            if(heap.size()<k)
            {
                push(i);
            }

            else if(distance(heap[0]) > distance(i))
            {
                pop();
                push(i);
            }
        }


        return heap;
        
    }
};
