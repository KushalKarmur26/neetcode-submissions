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

    int diameter = 0;

    int height(TreeNode* miniroot)
    {
        if(!miniroot) return 0;

        int leftheight = height(miniroot->left);
        int rightheight = height(miniroot->right);

        int currentdiameter = leftheight + rightheight;
        
        if(currentdiameter > diameter) diameter = currentdiameter;


        return 1 + max(leftheight,rightheight);
    }



public:
    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
        
    }
};
