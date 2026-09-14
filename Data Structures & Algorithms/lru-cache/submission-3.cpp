class LRUCache {

    unordered_map<int,vector<int>> linkedlist;
    unordered_map<int,int> data;

    int maxsize;
    int currentsize;

    int leastrecent;
    int mostrecent;

    int deletebeg() //delete least recent
    {
        if(currentsize==1)
        {
            int current = leastrecent;
            linkedlist.erase(leastrecent);

            leastrecent = -1;
            mostrecent = -1;

            currentsize--;
            return current;
        }
        
        int next = linkedlist[leastrecent][1];
        int current = leastrecent;
        linkedlist.erase(leastrecent);

        linkedlist[next][0] = -1;

        leastrecent = next;
        currentsize--;
        return current;
    }

    void deletekey(int key) //delete posn
    {
        if(key==leastrecent) deletebeg();
        else if(key==mostrecent)
        {
            int prev = linkedlist[key][0];
            linkedlist[prev][1] = -1;
            mostrecent = prev;

            linkedlist.erase(key);

            currentsize--;
        }

        else
        {
            int prev = linkedlist[key][0];
            int next = linkedlist[key][1];

            linkedlist[prev][1] = next;
            linkedlist[next][0] = prev;

            linkedlist.erase(key);
            currentsize--;

        }
    }

    void insertend(int key) //update most recent;
    {
        if(currentsize==0)
        {
            linkedlist[key] = {-1,-1};

            leastrecent = key;
            mostrecent = key;

            currentsize++;
        }

        else
        {
            linkedlist[mostrecent][1] = key;
            linkedlist[key] = {mostrecent,-1};

            mostrecent = key;

            currentsize++;
        }
    }

public:
    LRUCache(int capacity) {

        maxsize = capacity;
        currentsize = 0;

        leastrecent = -1;
        mostrecent = -1;
        
    }
    
    int get(int key) {

        if(data.find(key)==data.end()) return -1;

        deletekey(key);
        insertend(key);

        return data[key];
        
    }
    
    void put(int key, int value) {

        if(data.find(key) != data.end())
        {
            deletekey(key);
            insertend(key);

            data[key] = value;
            return;
        }

        else
        {
            if(currentsize<maxsize)
            {
                insertend(key);
                data[key] = value;
            }

            else
            {
                int deleted = deletebeg();
                data.erase(deleted);

                insertend(key);

                data[key] = value;
            }
        }
        
    }
};
