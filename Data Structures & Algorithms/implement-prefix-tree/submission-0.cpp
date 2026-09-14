class PrefixTree {

    class node
    {
        public:
        
        bool present;
        bool completeword;
        node** arr;

        node()
        {
            present = false;
            completeword = false;
        }

        void markpresent()
        {
            present = true;
            arr = new node*[26]();

            for(int i=0;i<26;i++)
            {
                arr[i] = new node();
            }
        }
    };

    node** head;

public:
    PrefixTree() {

        head = new node*[26]();

        for(int i=0;i<26;i++) head[i] = new node();
        
    }
    
    void insert(string word) {

        int size = word.size();

        node* currentnode = head[word[0]-97];

        for(int i=0;i<size;i++)
        {
            if(!currentnode->present) currentnode->markpresent();

            if(i<size-1)
            {
                currentnode = currentnode->arr[word[i+1]-97];
            }

            else if(i==size-1) currentnode->completeword = true;
        }
        
    }
    
    bool search(string word) {

        int size = word.size();

        node* currentnode = head[word[0]-97];

        for(int i=0;i<size;i++)
        {
            if(!currentnode->present) return false;

            if(i<size-1) currentnode = currentnode->arr[word[i+1]-97];
            else if(i==size-1 && !currentnode->completeword) return false;
        }

        return true;
        
    }
    
    bool startsWith(string prefix) {

        int size = prefix.size();

        node* currentnode = head[prefix[0]-97];

        for(int i=0;i<size;i++)
        {
            if(!currentnode->present) return false;

            if(i<size-1) currentnode = currentnode->arr[prefix[i+1]-97];

        }

        return true;
        
    }
};
