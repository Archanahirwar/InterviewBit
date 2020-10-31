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
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        TreeNode*p1=root;
        TreeNode*p2=root;
        while(1){
        while(p1){
            s1.push(p1);
            p1=p1->left;
        }
        while(p2){
            s2.push(p2);
            p2=p2->right;
        }
        if(s1.empty()||s2.empty()){
            return false;
        }
        if(s1.top()==s2.top()){
            return false;
        }
        if(s1.top()->val+s2.top()->val==k){
            return true;
        }else if(!s1.empty() &&s1.top()->val+s2.top()->val<k){
            p1=s1.top();
            p1=p1->right;
            s1.pop();
        }else{
            p2=s2.top();
            p2=p2->left;
            s2.pop();
        }
        }
        return false;
        
        
    }
};
