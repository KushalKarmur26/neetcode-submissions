#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {

    unordered_map<char, string> mp;

    void dfs(int currentstring_index, int digitindex, string &path, const string &s, vector<string> &res, int size)
    {
        if (digitindex == size) return;
        if (currentstring_index == mp[s[digitindex]].size()) return;

        path.append(1, mp[s[digitindex]][currentstring_index]);
        
        if (path.size() == size)
        {
            res.push_back(path);
        }
        else
        {
            dfs(0, digitindex + 1, path, s, res, size);
        }

        path.erase(path.size() - 1, 1);
        dfs(currentstring_index + 1, digitindex, path, s, res, size);
    }

public:

    Solution()
    {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {

        vector<string> res;
        if (digits.empty()) return res;

        string path = "";
        int size = digits.size();

        dfs(0, 0, path, digits, res, size);

        return res;
    }
};