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

    bool ans = true;

    int height(TreeNode* miniroot)
    {
        if(!miniroot) return 0;

        int rightheight = height(miniroot->right);
        int leftheight = height(miniroot->left);

        int diff = rightheight-leftheight;

        if(diff>1 || diff<-1) ans = false;

        return 1 + max(rightheight,leftheight);

    }

public:
    bool isBalanced(TreeNode* root) {

        height(root);

        return ans;
        
    }
};
