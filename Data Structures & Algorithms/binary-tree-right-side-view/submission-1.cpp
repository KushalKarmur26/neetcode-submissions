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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int level = q.size();

        while(!q.empty())
        {
            for(int i=0;i<level;i++)
            {
                TreeNode* current = q.front();
                if(i==level-1)
                {
                    ans.push_back(current->val);
                }

                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);

            }

            level = q.size();
        }
        
        return ans;
    }
};
