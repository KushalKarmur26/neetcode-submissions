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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(p->val == q->val) return p;

        TreeNode* temp = root;
        
        while(true)
        {
            
            if((temp->val >= p->val && temp->val <= q->val) || (temp->val >= q->val && temp->val <= p->val))
                return temp;

            if(temp->val>p->val) temp = temp->left;
            else temp = temp->right;

        }

    }
};
