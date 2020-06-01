/* Given preorder and inorder traversal of a tree, construct the binary tree. */

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
    TreeNode* buildChild(map<int, int>& hash, vector<int>& preorder, int left, int right) {
        /* leaf node */
        if (left < right)
            return NULL;
        TreeNode* node = new TreeNode(preorder[left]);
        node->left = buildChild(hash, preorder, inorder, left, hash[preorder[left]]+1);
        node->right = buildChild(hash, preorder, inorder, hash[preorder[left]]+1, right);

        return root_node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> hash;
        TreeNode* result;
        if (inorder.size() == 0)
            return NULL;
        for (int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }
        result = buildChild(hash, preorder, 0, preorder.size()-1);

        return result;
    }
};