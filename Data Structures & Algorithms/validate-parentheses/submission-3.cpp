class Solution {
public:
    bool isValid(string s) {

        stack<char> mystack;

        for(char c : s)
        {
            if(c=='(' || c=='[' || c=='{')
            {
                mystack.push(c);
                continue;
            }

            if(mystack.empty()) return false;

            if(c== ')' && mystack.top()!='(') return false;

            if(c== ']' && mystack.top()!='[') return false;

            if(c== '}' && mystack.top()!='{') return false;
            
            mystack.pop();
            continue;
        
        }   

        return mystack.empty();

    }
};
