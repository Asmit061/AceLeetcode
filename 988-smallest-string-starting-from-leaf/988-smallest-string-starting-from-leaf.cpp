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
    priority_queue<string,vector<string>,greater<string>> pq;
    void dfs(TreeNode* root,string temp){
        if(root==NULL)
            return;
        if(!root->left&&!root->right)
        {
            temp+=char(root->val+'a');
            reverse(temp.begin(),temp.end());
            pq.push(temp);
            reverse(temp.begin(),temp.end());
        }
        dfs(root->left,temp+char(root->val+'a'));
        dfs(root->right,temp+char(root->val+'a'));
    }
    string smallestFromLeaf(TreeNode* root) {
        string temp="";
        dfs(root,temp);
        return pq.top();
    }
};