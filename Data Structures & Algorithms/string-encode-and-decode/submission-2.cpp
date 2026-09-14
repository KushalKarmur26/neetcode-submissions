class Solution {
public:

    queue<int> spacecount;

    string encode(vector<string>& strs) {

        string res = "";

        for(const string &s:strs)
        {
            res += s;
            spacecount.push(s.size());
        }

        return res;

    }

    vector<string> decode(string s) {

        vector<string> res;
        int count = 0;

        while(!spacecount.empty())
        {
            int space = spacecount.front();
            string temp = "";


            for(int i=count;i<count + space;i++)
            {
                temp += s[i];
            }

            count += space;
            res.push_back(temp);
            spacecount.pop();
        }

        return res;

    }
};
