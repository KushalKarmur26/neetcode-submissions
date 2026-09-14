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

    void Traverse(TreeNode* miniroot,int k)
    {
        if(!miniroot) return;
        if(count==k+1) return;

        Traverse(miniroot->left, k);

        if(count==k) ans = miniroot->val;
        count++;

        Traverse(miniroot->right,k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {

            Traverse(root,k);

            return ans;

    }
};
