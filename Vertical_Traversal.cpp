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
    void vertical_traversal(TreeNode*root,int l,int hd,map<int,vector<pair<int,int>>>&m){
        if(root==NULL){
            return;
        }
        m[hd].push_back({l,root->val});
        vertical_traversal(root->left,l+1,hd-1,m);
        vertical_traversal(root->right,l+1,hd+1,m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL){
            return v;
        }
        map<int,vector<pair<int,int>>>m;
        vertical_traversal(root,0,0,m);
        for(auto it=m.begin();it!=m.end();it++){
            sort((it->second).begin(),(it->second).end());
            vector<int>curr;
            for(int i=0;i<it->second.size();i++){
                curr.push_back(it->second[i].second);
            }
            v.push_back(curr);
            curr.clear();
        }
        return v;
        
        
    }
};
