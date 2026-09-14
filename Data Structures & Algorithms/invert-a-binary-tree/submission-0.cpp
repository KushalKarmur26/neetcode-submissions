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

    void switchnodes(TreeNode* miniroot)
    {
        if(!miniroot) return;

        TreeNode* temp = miniroot->left;
        miniroot->left = miniroot->right;
        miniroot->right = temp;

        switchnodes(miniroot->left);
        switchnodes(miniroot->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {

        switchnodes(root);

        return root;
        
    }
};
