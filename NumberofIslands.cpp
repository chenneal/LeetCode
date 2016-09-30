/* Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting 
   adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000

Answer: 1

Example 2:

11000
11000
00100
00011
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        int i = 0, j = 0;
        int island = 0;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((grid[i][j] == '1') && !(visit[i][j]))
                {
                    dfs(grid, visit, i, j, m, n);
                    island++;
                }
            }
        }

        return island;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || (grid[i][j] == '0') || visit[i][j])
            return ;
        visit[i][j] = true;
        //up
        dfs(grid, visit, i-1, j, m, n);
        //down
        dfs(grid, visit, i+1, j, m, n);
        //right
        dfs(grid, visit, i, j+1, m, n);
        //left
        dfs(grid, visit, i, j-1, m, n);
    }
};