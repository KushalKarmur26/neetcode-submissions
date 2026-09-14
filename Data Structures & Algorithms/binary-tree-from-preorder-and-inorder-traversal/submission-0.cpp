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

    unordered_map<int,int> indices;

    stack<TreeNode*> currentroot;

    unordered_map<int,pair<int,int>> range;

    bool inrange(int target,int host)
    {
        int targetindex = indices[target];

        pair<int,int> hostrange = range[host];

        return (targetindex >= hostrange.first && targetindex <= hostrange.second);
    }


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int size = inorder.size();
        TreeNode* root = nullptr;

        for(int i=0;i<size;i++) indices[inorder[i]] = i;

        for(int i : preorder)
        {
            TreeNode* newnode = new TreeNode(i);
            
            if(currentroot.empty())
            {
                range[i] = {0,size-1};
                currentroot.push(newnode);
                root = newnode;
            }

            else
            {
                while(true)
                {
                    TreeNode* curr = currentroot.top();

                    if(!inrange(i,curr->val)) currentroot.pop();

                    else
                    {
                        if(indices[i]<indices[curr->val])
                        {
                            curr->left = newnode;

                            range[i] = {range[curr->val].first,indices[curr->val]-1};
                            
                        }

                        else
                        {
                            curr->right = newnode;

                            range[i] = {indices[curr->val]+1,range[curr->val].second};

                        }
                        
                        currentroot.push(newnode);
                        break;
                    }

                }

            }
        }


        return root;
    }
};
