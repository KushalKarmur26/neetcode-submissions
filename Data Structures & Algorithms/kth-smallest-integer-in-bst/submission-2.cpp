/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        int count = 1;
        int ans = -1;

        stack<TreeNode*> mystack;

        TreeNode* temp = root;

        while(!mystack.empty() || temp)
        {
            while(temp)
            {
                mystack.push(temp);
                temp = temp->left;
            }

            if(count==k){
                ans = mystack.top()->val;
                return ans;
            }

            temp = mystack.top()->right;

            mystack.pop();
            count++;
        }

        return ans;
    
    }
};
