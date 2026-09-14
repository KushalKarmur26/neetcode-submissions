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

    bool isequal(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;

        return(isequal(p->left,q->left) && isequal(p->right,q->right));
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!subRoot) return true;
        if(!root) return false;

        if(isequal(root,subRoot)) return true;

        return(isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));

        
    }
};
