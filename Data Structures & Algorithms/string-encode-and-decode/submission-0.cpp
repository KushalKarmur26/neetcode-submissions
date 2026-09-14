class Solution {
public:

    queue<int> spacecount;

    string encode(vector<string>& strs) {

        string res = "";

        for(string s:strs)
        {
            res += s;
            spacecount.push(s.size());
        }

        return res;

    }

    vector<string> decode(string s) {

        vector<string> res;

        while(!spacecount.empty())
        {
            int space = spacecount.front();
            string temp = "";

            for(int i=0;i<space;i++)
            {
                temp += s[0];
                s.erase(0,1);
            }

            res.push_back(temp);
            spacecount.pop();
        }

        return res;

    }
};
