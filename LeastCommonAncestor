/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool validate(TreeNode *A, int B)
{
    if(A == nullptr)
        return false;
    if (A->val == B)
        return true;
    bool lval = validate(A->left, B);
    bool rval = validate(A->right, B);
    if (lval || rval)
        return true;
    
    return false;
}

int Solution::lca(TreeNode* A, int B, int C) {
    if (A == nullptr)
        return -1;
    if(!validate(A, B))
        return -1;
    if(!validate(A, C))
        return -1;
    if (A->val == B || A->val == C)
        return A->val;
    int lval = lca(A->left, B, C);
    int rval = lca(A->right, B, C);
    if (lval != -1 && rval != -1)
        return A->val;
    return ((lval != -1) ? lval : rval);

}

