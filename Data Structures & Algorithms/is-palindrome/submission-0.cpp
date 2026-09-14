class Solution {
public:

    char lower(char* ptr)
    {
        if(*ptr>=65 && *ptr<=90) *ptr = *ptr+32;

        return *ptr;
    }

    bool isalphanum(char c)
    {
        if(c>=65 && c<=90) return true;
        if(c>=97 && c<=122) return true;
        if(c>=48 && c<=57) return true;

        return false;
    }

    bool isPalindrome(string s) {

        int size = s.size();

        int rear = size-1;
        int front = 0;

        while(front<rear)
        {
            if( !isalphanum(s[rear]) ) 
            {
                rear--;
                continue;
            }
            if( !isalphanum(s[front]) )
            {
                front++;
                continue;
            }

            if( lower(&s[front]) != lower(&s[rear]) ) return false;

            front++;
            rear--;

        }

        return true;
        
    }
};
