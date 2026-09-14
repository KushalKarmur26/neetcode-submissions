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

    stack<int> mystack;
    int count = 0;

    void helper(TreeNode* miniroot)
    {
        if(!miniroot) return;
        
        if(mystack.empty() || miniroot->val>=mystack.top())
        {
            mystack.push(miniroot->val);
            count++;
        }

        helper(miniroot->left);
        helper(miniroot->right);

        if(miniroot->val == mystack.top()) mystack.pop();
    }


public:
    int goodNodes(TreeNode* root) {

        helper(root);

        return count;
    }
};
