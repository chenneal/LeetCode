/* Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
*/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return vector<vector<int>>(0);
        int level = 0;
        vector<vector<int>> result;
        queue<TreeNode*> queue_bfs;
        queue_bfs.push(root);
        while (!queue_bfs.empty()) {
            int size = queue_bfs.size();
            result.push_back(vector<int>(0));
            TreeNode* p;
            for (int i = 0; i < size; i++) {
                p = queue_bfs.front();
                queue_bfs.pop();
                if (p->left)
                    queue_bfs.push(p->left);
                if (p->right)
                    queue_bfs.push(p->right);
                result[level].push_back(p->val);
            }
            level++;
        }
        return vector<vector<int>>(result.rbegin(), result.rend());
    }
};