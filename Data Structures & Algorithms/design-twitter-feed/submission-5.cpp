class Twitter {

    class tweet
    {
        public:
        int tweetid;
        int time;

        tweet(int id,int t)
        {
            tweetid = id;
            time = t;
        }

    };

    class user
    {

        public:

        unordered_map<int,bool> followees;
        vector<tweet*> tweets;

    };

    class node
    {
        public:

        vector<tweet*> alltweets;
        int top;

        node(vector<tweet*> &tweets)
        {
            alltweets = tweets;
            top = alltweets.size()-1;
        }
    };

    unordered_map<int,user*> allusers;
    int tweettime;


    void heapifydown(int index,vector<node*> &heap)
    {
        int largest = index;
        
        int lson = 2*index + 1;
        int rson = 2*index + 2;

        if(lson<heap.size() && heap[lson]->alltweets[heap[lson]->top]->time > heap[index]->alltweets[heap[index]->top]->time) largest = lson;
        if(rson<heap.size() && heap[rson]->alltweets[heap[rson]->top]->time > heap[index]->alltweets[heap[index]->top]->time) largest = rson;

        if(largest!=index)
        {
            swap(heap[index],heap[largest]);
            heapifydown(largest,heap);
        }

        else return;
    }

    void heapifyup(int index,vector<node*> &heap)
    {
        if(!index) return;

        int parent = (index-1)/2;

        if(heap[index]->alltweets[heap[index]->top]->time > heap[parent]->alltweets[heap[parent]->top]->time)
        {
            swap(heap[parent],heap[index]);
            heapifyup(parent,heap);
        }

        else return;

    }

    void push(node* newnode,vector<node*> &heap)
    {
        heap.push_back(newnode);
        heapifyup(heap.size()-1,heap);
    }

    void pop(vector<node*> &heap)
    {
        heap[0] = heap[heap.size()-1];
        heap.pop_back();

        heapifydown(0,heap);
    }

    node* top(vector<node*> heap)
    {
        return heap[0];
    }


public:
    Twitter() {

        tweettime = 0;
        
    }
    
    void postTweet(int userID, int tweetID) {

        tweet* newtweet = new tweet(tweetID,tweettime);
        tweettime++;
        
        if(allusers.find(userID)==allusers.end())
        {
            allusers[userID] = new user;
            allusers[userID]->tweets.push_back(newtweet);
            
        }
        
        else allusers[userID]->tweets.push_back(newtweet);
    }
    
    vector<int> getNewsFeed(int userID) {

        vector<int> res;

        vector<node*> myheap;

        user* currentuser = allusers[userID];

        if(!currentuser->tweets.empty())
        {
            node* selfnode = new node(currentuser->tweets);
            push(selfnode,myheap);
        }

        for(auto it:currentuser->followees)
        {
            node* newnode = new node(allusers[it.first]->tweets);

            push(newnode, myheap);
        }

        for(int i=0;i<10;i++)
        {
            if(myheap.empty()) break;
            
            node* currenttop = top(myheap);

            res.push_back(currenttop->alltweets[currenttop->top]->tweetid);
            currenttop->top = currenttop->top - 1;

            pop(myheap);

            if(currenttop->top>=0) push(currenttop,myheap);
        }

        return res;
        
    }
    
    void follow(int followerID, int followeeID) {

        if(allusers.find(followerID)==allusers.end())
        {
            allusers[followerID] = new user;
        }

        if(allusers.find(followeeID)==allusers.end())
        {
            allusers[followeeID] = new user;
        }
        
        if(followerID==followeeID) return;
        
        allusers[followerID]->followees[followeeID] = true;
        
    }
    
    void unfollow(int followerID, int followeeID) {

        
        if(followerID==followeeID) return;
        
        allusers[followerID]->followees.erase(followeeID);
        
    }
};
