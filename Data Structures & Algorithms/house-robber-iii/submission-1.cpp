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
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};
        auto left = solve(root->left);
        auto right = solve(root->right);

        // if take then sum of skipped value from the child of curr node
        int take = root->val + left.second + right.second;
        // if curr skipped then sum of max value from left and right child
        int skip = max(left.first, left.second) + max(right.first, right.second);
        return {take,skip};
    }
public:
    int rob(TreeNode* root) {
        auto res = solve(root);
        return max(res.first,res.second);
    }
};