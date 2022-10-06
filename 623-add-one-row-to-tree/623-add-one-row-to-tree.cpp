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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp=new TreeNode(val,root,NULL);
            return temp;
        }
        queue<TreeNode*> q;
        q.push(root);
        int s;
        while(!q.empty()){
            s=q.size();
            depth--;
            while(s--){
                TreeNode* temp=q.front();
                // cout<<temp->val<<endl;
                q.pop();
                if(depth==1){
                    temp->left=new TreeNode(val,temp->left,NULL);
                    temp->right=new TreeNode(val,NULL,temp->right);
                }
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
                if(q.empty()&&depth==2){
                    temp->left=new TreeNode(val);
                    temp->right=new TreeNode(val);
                }
            } 
        }
        return root;
    }
};