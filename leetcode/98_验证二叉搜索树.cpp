/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // 解法1
    // long pre = (numeric_limits<long>::min)();
    // bool isValidBST(TreeNode* root) {
    //     if (!root) {
    //         return true;
    //     }

    //     if (!isValidBST(root->left)) {
    //         return false;
    //     }

    //     if (root->val <= pre) {
    //         return false;
    //     }

    //     pre = root->val;
    //     return isValidBST(root->right);
    // }
    // 解法2
    bool helper(TreeNode* root, long min, long max) {
        if (!root) {
            return true;
        }

        if (root->val >= max || root->val <= min) {
            return false;
        }

        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, (numeric_limits<long>::min)(), (numeric_limits<long>::max)());
    }
};
