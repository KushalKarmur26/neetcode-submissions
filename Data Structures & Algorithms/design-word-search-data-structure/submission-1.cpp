class WordDictionary {

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

    bool helper(node* current, int i, string &word)
    {
        if(!current) return false;

        bool isdot = word[i]=='.';

        if(!isdot) //the next child to be searched is not a dot
        {
            //checking if it has a matching child with word end at word[i]
            if(i==word.size()-1) return (current->links[word[i] - 'a'] && current->links[word[i] - 'a']->wordend);

            //checking if it has a matching child and further recursively checking the child
            return( current->links[word[i] - 'a'] && helper(current->links[word[i] - 'a'],i+1,word) );
        }

        else //next child to be searched is a dot
        {
            bool ans = false;

            if(i==word.size()-1) //if dot is the last child
            {
                for(int j=0;j<26;j++) //check if it has any child and also if that child is wordend
                {
                    ans = current->links[j] && current->links[j]->wordend;
                    if(ans) break;
                }
            }

            else
            {
                for(int j=0;j<26;j++) //checking all the children, true if anyone is valid
                {
                    ans = helper(current->links[j],i+1,word);
                    if(ans) break;
                }
            }

            return ans;
        }
    }

public:
    WordDictionary() {

        head.resize(26);
        
    }
    
    void addWord(string word) {

        int size = word.size();
        node* current = nullptr;

        for(int i=0;i<size;i++)
        {
            if(i==0)
            {
                if(!head[word[i] - 'a'])
                    head[word[i] - 'a'] = new node();

                current = head[word[i] - 'a'];
            }

            else
            {
                if(!current->links[word[i] - 'a'])
                    current->links[word[i] - 'a'] = new node();

                current = current->links[word[i] - 'a'];
            }

            if(i==size-1) current->wordend = true;
        }
        
    }
    
    bool search(string word) {

        if(word[0]!='.') // first letter not a dot
        {
            if(!head[word[0] - 'a']) return false;//no words at all starting from the first word of the given word

            if(word.size()==1) return head[word[0]-'a']->wordend; //single letter word

            //give the control to the helper to check the rest of the word
            return helper(head[word[0] - 'a'], 1, word);
        }

        else //first letter a dot
        {
            int ans = false;
            
            if(word.size()==1) // single letter word
            {
                for(int j=0;j<26;j++)
                {
                    ans = head[j] && head[j]->wordend;
                    if(ans) break;
                }
            }

            else
            {
                for(int j=0;j<26;j++) //if any child is valid
                {
                    ans = helper(head[j],1,word);
                    if(ans) break;
                }
            }

            return ans;
        }

    }
};
