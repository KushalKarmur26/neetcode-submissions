class PrefixTree {

    class node
    {
        public:

        bool wordend;
        unordered_map<char,node*> links;

        node()
        {
            wordend = false;
        }

    };


    unordered_map<char,node*> head;



public:
    PrefixTree() {

        
    }
    
    void insert(string word) {

        int size = word.size();

        if(head.find(word[0]) == head.end())
        {
            head[word[0]] = new node();
        }

        node* currentnode = head[word[0]];

        for(int i=1;i<size;i++)
        {
            if(currentnode->links.find(word[i]) == currentnode->links.end())
            {
                currentnode->links[word[i]] = new node();
            }

            if(i<size-1) currentnode = currentnode->links[word[i]];

            else currentnode->wordend = true;
        }

    }
    
    bool search(string word) {

        int size = word.size();

        if(head.find(word[0]) == head.end()) return false;

        node* currentnode = head[word[0]];

        for(int i=1;i<size;i++)
        {
            if(currentnode->links.find(word[i])==currentnode->links.end()) return false;

            if(i<size-1) currentnode = currentnode->links[word[i]];

            else if(!currentnode->wordend) return false;
        }

        return true;
        
    }
    
    bool startsWith(string prefix) {

        int size = prefix.size();

        if(head.find(prefix[0]) == head.end()) return false;

        node* currentnode = head[prefix[0]];

        for(int i=1;i<size;i++)
        {
            if(currentnode->links.find(prefix[i])==currentnode->links.end()) return false;

            if(i<size-1) currentnode = currentnode->links[prefix[i]];

        }

        return true;
        
    }
};
