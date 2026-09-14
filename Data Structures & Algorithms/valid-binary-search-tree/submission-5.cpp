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
    int highest = -1001;

    void traverse(TreeNode* miniroot)
    {
        if(!miniroot) return;

        traverse(miniroot->left);
        if(miniroot->val <= highest) ans = false;
        else highest = miniroot->val;
        traverse(miniroot->right);
    }

public:
    bool isValidBST(TreeNode* root) {

        traverse(root);
        return ans;
    
    }

};
