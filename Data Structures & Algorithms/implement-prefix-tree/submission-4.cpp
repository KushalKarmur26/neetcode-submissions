class PrefixTree {

    class node
    {
        public:

            bool wordend;
            vector<node*> links;

            node()
            {
                wordend = false;
                links.resize(26);
            }
    };

    vector<node*> head;


public:
    PrefixTree() {

        head.resize(26);
        
    }
    
    void insert(string word) {

        int size = word.size();

        node* current = nullptr;

        for(int i=0;i<size;i++)
        {

            if(i==0)
            {
                if(!head[word[i]-'a'])
                    head[word[i]-'a'] = new node();

                current = head[word[i]-'a'];
            }

            else
            {
                if(!current->links[word[i]-'a'])
                    current->links[word[i]-'a'] = new node();

                current = current->links[word[i]-'a'];
            }

            if(i==size-1) current->wordend = true;
        }
        
    }
    
    bool search(string word) {

        int size = word.size();

        node* current = nullptr;

        for(int i=0;i<size;i++)
        {
            if(i==0)
            {
                if(!head[word[i]-'a']) return false;

                current = head[word[i] - 'a'];
            }

            else
            {
                if(!current->links[word[i] - 'a']) return false;

                current = current->links[word[i] - 'a'];
            }

            if(i==size-1) return current->wordend;
        }
    }
    
    bool startsWith(string word) {

        int size = word.size();

        node* current = nullptr;

        for(int i=0;i<size;i++)
        {
            if(i==0)
            {
                if(!head[word[i]-'a']) return false;

                current = head[word[i] - 'a'];
            }

            else
            {
                if(!current->links[word[i] - 'a']) return false;

                current = current->links[word[i] - 'a'];
            }

        }

        return true;
        
    }
};
