/*Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        //G(n)代表有n个节点时，排序二叉树的数量
        int G[n+1];
        //这里要注意一下G(0)要为1，否则左右相乘会得到0的结果
        G[0] = 1;
        G[1] = 1;
        G[2] = 2;
        for (int i = 3; i <= n; i++) {
            G[i] = 0;
            for (int j = 1; j <= i; j++) {
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
};