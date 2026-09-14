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
    vector<vector<int>> levelOrder(TreeNode* root) {


        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;

        while(level!=0)
        {
            int currentlevel = 0;
            vector<int> temp;

            for(int i=0;i<level;i++)
            {
                TreeNode* current = q.front();
                q.pop();

                temp.push_back(current->val);
                if(current->left)
                {
                    q.push(current->left);
                    currentlevel++;
                }
                if(current->right)
                {
                    q.push(current->right);
                    currentlevel++;
                }
            }

            ans.push_back(temp);
            level = currentlevel;
        }

        return ans;
    }
        
};
