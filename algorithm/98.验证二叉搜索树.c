
/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool func(struct TreeNode* root, long  min, long max)
{
    if(root == NULL) return true;

    if(root->val >= max || root->val <= min) return false;

    return func(root->left, min, root->val) && func(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root){
    if(root == NULL) return true;
    long max = LONG_MAX;
    long min = LONG_MIN;

    return func(root, min, max);
}


// @lc code=end

