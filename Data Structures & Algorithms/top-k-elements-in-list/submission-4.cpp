class Solution {
public:

    vector<int> minheap;
    unordered_map<int,int> mp;

    void heapifyup(int index)
    {
        if(index==0) return;
        int parent = (index - 1) / 2;
        
        if(mp[minheap[index]] < mp[minheap[parent]])
        {
            swap(minheap[index],minheap[parent]);

            heapifyup(parent);
        }
    }

    void heapifydown(int index)
    {
        int lowest = index;
        int lson = 2*index + 1;
        int rson = 2*index + 2;
        int size = minheap.size();

        if(lson<size && mp[minheap[lson]]<mp[minheap[lowest]]) lowest = lson;
        if(rson<size && mp[minheap[rson]]<mp[minheap[lowest]]) lowest = rson;

        if(lowest!=index)
        {
            swap(minheap[lowest],minheap[index]);
            heapifydown(lowest);
        }

        else return;
    }


    vector<int> topKFrequent(vector<int>& nums, int k) {

        for(int i:nums) mp[i]++;

        for(auto &it : mp)
        {
            if(minheap.size()<k)
            {
                minheap.push_back(it.first);
                heapifyup(minheap.size()-1);
            }

            else if(mp[minheap[0]] < it.second)
            {
                minheap[0] = minheap[minheap.size()-1];
                minheap.pop_back();
                heapifydown(0);

                minheap.push_back(it.first);
                heapifyup(minheap.size()-1);
            }
        }

        return minheap;
        
    }
};
