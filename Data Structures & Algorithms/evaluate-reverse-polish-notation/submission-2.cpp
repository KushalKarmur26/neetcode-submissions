class Solution {
public:

    int convert(string s)
    {
        int n=0;
        int size = s.size();

        int count = size-1;

        bool negative = false;

        for(char c:s)
        {
            if(c=='-')
            {
                negative = true;
                count--;
                continue;
            }

            n += (int(c) - int('0')) * pow(10,count);
            count --;
        }

        return negative ? -1 * n : n;
    }

    int evalRPN(vector<string>& tokens) {

        stack<int> operands;
        
        for(string s:tokens)
        {
            if(s=="+")
            {
                int val2 = operands.top();
                operands.pop();
                
                int val1 = operands.top();
                operands.pop();

                int res = val1 + val2;
                operands.push(res);
            }

            else if(s=="-")
            {
                int val2 = operands.top();
                operands.pop();
                
                int val1 = operands.top();
                operands.pop();

                int res = val1 - val2;
                operands.push(res);
            }

            else if(s=="*")
            {
                int val2 = operands.top();
                operands.pop();
                
                int val1 = operands.top();
                operands.pop();

                int res = val1 * val2;
                operands.push(res);
            }

            else if(s=="/")
            {
                int val2 = operands.top();
                operands.pop();
                
                int val1 = operands.top();
                operands.pop();

                int res = val1 / val2;
                operands.push(res);
            }

            else operands.push(convert(s));

        }

        return operands.top();
        
    }
};
