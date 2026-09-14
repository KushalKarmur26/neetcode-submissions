class Solution {
public:

    bool isvalid(int length, vector<int> &count, int k)
    {
        int maxi = count[0];

        for(int x : count)
            if(x > maxi) maxi = x;

        return (length - maxi <= k);
    }

    int characterReplacement(string s, int k) {

        vector<int> count(26, 0);

        int size = s.size();
        int left = 0;
        int right = 0;

        int res = 0;

        while(right < size)
        {
            count[s[right] - 'A']++;

            while(!isvalid(right - left + 1, count, k))
            {
                count[s[left] - 'A']--;
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
};