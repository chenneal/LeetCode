/* Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3]. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /* A recusive version */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        help(root, result);
        return result;
    }
    void help(TreeNode* root, vector<int>& result) {
        if (root != NULL)
            result.push_back(root->val);
        else return;
        help(root->left, result);
        help(root->right, result);
    }
};

/* A non-recursive version */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                result.push_back(root->val);
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
        return result;
    }
};