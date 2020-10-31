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
    void inorder(TreeNode*root,TreeNode*&prev,TreeNode*&ans1,TreeNode*&ans2){
        if(root==NULL){
            return;
        }
        inorder(root->left,prev,ans1,ans2);
        if(prev==NULL){
            prev=root;
        }else{
            if(prev->val>root->val){
                if(ans1==NULL){
                    ans1=prev;
                }
            }
            if(prev->val>root->val){
                if(ans1!=NULL){
                    ans2=root;
                }
            }
            prev = root;
        }
        inorder(root->right,prev,ans1,ans2);
        
        
        
    }
    void recoverTree(TreeNode* root) {
        TreeNode*ans1=NULL;
        TreeNode*ans2=NULL;
        TreeNode*prev=NULL;
        inorder(root,prev,ans1,ans2);
        int a=ans1->val;
        ans1->val=ans2->val;
        ans2->val=a;
        
    }
};
