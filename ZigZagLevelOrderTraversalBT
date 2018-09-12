/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector< vector<int>> result;
    result.resize(1);
    int level = 1;
    stack<TreeNode *> curStack;
    stack<TreeNode *> nexLevel;
    bool rtl = true;
    if (A == nullptr)
        return result;
    curStack.push(A);
    while (!curStack.empty())
    {
        TreeNode *cur;
        cur = curStack.top();
        curStack.pop();

        result[level - 1].push_back(cur->val);
        if (rtl)
        {
            if(cur->left)
                nexLevel.push(cur->left);
            if(cur->right)
                nexLevel.push(cur->right);
        }
        else
        {
            if(cur->right)
                nexLevel.push(cur->right);
            if(cur->left)
                nexLevel.push(cur->left);
        }

        if (curStack.empty())
        {
            
            swap(curStack, nexLevel);
            rtl = !rtl;
            if(!curStack.empty())
            {
                ++level;
                result.resize(level);
            }
        }
    }
    return result;
}
