/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int>v;
    stack<TreeNode*>s;
    while(A|| !s.empty()){
        if(A){
            s.push(A);
            A=A->left;
        }else{
            A=s.top();
            v.push_back(A->val);
            s.pop();
            A=A->right;
        }
    }
    return v;
}
