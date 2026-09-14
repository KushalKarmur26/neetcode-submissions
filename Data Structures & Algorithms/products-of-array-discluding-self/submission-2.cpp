class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int size = nums.size();

        vector<int> pre(size);
        vector<int> suf(size);
        vector<int> res(size);

        pre[0] = 1;
        suf[size-1] = 1;

        for(int i=1;i<size;i++)
        {
            pre[i] = nums[i-1] * pre[i-1];
            suf[size-i-1] = nums[size-i] * suf[size-i];
        }

        for(int i=0;i<size;i++) res[i] = pre[i] * suf[i];

        return res;

    }
};
