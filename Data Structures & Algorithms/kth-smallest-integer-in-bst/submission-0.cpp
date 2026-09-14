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

    int count = 1;
    int ans;
    
    void traverse(TreeNode* miniroot, int k)
    {
        if(!miniroot) return;
        //if(count==k) return;

        traverse(miniroot->left,k);
        if(count==k) ans = miniroot->val;
        count++;
        traverse(miniroot->right,k);
    }


public:
    int kthSmallest(TreeNode* root, int k) {

        traverse(root, k);
        return ans;                
        
    }
};
