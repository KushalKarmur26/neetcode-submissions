class Solution {

    vector<int> heap;

    unordered_map<int,float> distances;

    float distance(vector<int> &v)
    {
        return sqrt(v[0]*v[0] + v[1]*v[1]);
    }

    void heapifydown(int index)
    {
        int largest = index;

        int lson = 2*index + 1;
        int rson = 2*index + 2;

        if(lson<heap.size() && distances[heap[lson]] > distances[heap[largest]]) largest = lson;
        if(rson<heap.size() && distances[heap[rson]] > distances[heap[largest]]) largest = rson;

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

        if( distances[heap[index]] > distances[heap[parent]] )
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

    void push(int i)
    {
        heap.push_back(i);

        heapifyup(heap.size()-1);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int size = points.size();

        vector<vector<int>> res;

        for(int i=0;i<size;i++)
        {
            distances[i] = distance(points[i]);

            if(heap.size()<k)
            {
                push(i);
            }

            else if(distances[heap[0]] > distances[i])
            {
                pop();
                push(i);
            }
        }

        
        for(int index:heap)
        {
            res.push_back(points[index]);
        }



        return res;
        
    }
};
