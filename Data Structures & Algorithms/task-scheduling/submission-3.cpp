class Solution {

    vector<int> heap;
    queue<int> temp;
    int freq[26] = {};
    int time[26] = {};
    int currenttime=1;


    void heapifydown(int index)
    {
        int largest = index;
        
        int lson = 2*index + 1;
        int rson = 2*index + 2;

        if(lson<heap.size() && freq[heap[lson]] > freq[heap[index]]) largest = lson;
        if(rson<heap.size() && freq[heap[rson]] > freq[heap[index]]) largest = rson;

        if(largest!=index)
        {
            swap(heap[index],heap[largest]);
            heapifydown(largest);
        }

        else return;
    }

    void heapifyup(int index)
    {
        if(!index) return;

        int parent = (index-1)/2;

        if(freq[heap[index]] > freq[heap[parent]])
        {
            swap(heap[parent],heap[index]);
            heapifyup(parent);
        }

        else return;
    }

    void push(int val)
    {
        heap.push_back(val);
        heapifyup(heap.size()-1);
    }

    void pop()
    {
        heap[0] = heap[heap.size()-1];
        heap.pop_back();

        heapifydown(0);
    }

    int top()
    {
        return heap[0];
    }


public:
    int leastInterval(vector<char>& tasks, int n) {

        int size = tasks.size();

        int res = 0;

        for(int i:tasks) freq[i-65]++;

        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
                push(i);
        }

        int taskscompleted = 0;
        while(taskscompleted!=size)
        {
            while(!heap.empty())
            {
                int current = top();

                if(time[current]==0 || currenttime-time[current] > n) //task completes
                {
                    time[current] = currenttime;
                    freq[current]--;
                    taskscompleted++;
                    pop();
                    if(freq[current]) push(current);

                    while(!temp.empty())
                    {
                        push(temp.front());

                        temp.pop();
                    }

                    res++;
                    currenttime++;

                    if(taskscompleted==size) return res;

                }

                else  //go for next try
                {
                    temp.push(current);
                    pop();
                }

            }

            if(taskscompleted<size) //no tasks eligible, goes idle
            {
                while(!temp.empty())
                {
                    push(temp.front());

                    temp.pop();
                }

                res++;
                currenttime++;
            }
        } 

        return res;       

    }
};
