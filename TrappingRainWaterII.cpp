/* Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.
*/

class Solution {
public:
    class node {
    public:
        int x;
        int y;
        int height;
        node(void) {x = 0; y = 0; height = 0;}
        node(int x_t, int y_t, int height_t) {x = x_t; y = y_t; height = height_t;}
        bool is_out(int m, int n) {
            if (x < 0 || x >= n || y > 0 || y >= m)
                return false;
        }
        bool operator <(const node& other) const{
            return (height < other.height);
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m <= 2)
            return 0;
        int n = heightMap[0].size();
        if (n <= 2)
            return 0;
        int trap = 0;
        static pair<int, int> dir[4] = {{0, -1},{0, 1},{-1, 0}, {1, 0}};
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        priority_queue<node, vector<node>> que;
        // 外围的柱子依次进入优先队列
        for (int i = 0; i < m; i++) {
            node node1(i, 0, heightMap[i][0]);
            node node2(i, n-1, heightMap[i][n-1]);
            que.push(node1);
            que.push(node2);
            visit[i][0] = true;
            visit[i][n-1] = true;
        }

        for (int i = 1; i < n-1; i++) {
            node node1(0, i, heightMap[0][i]);
            node node2(m-1, i, heightMap[m-1][i]);
            que.push(node1);
            que.push(node2);
            visit[0][i] = true;
            visit[m-1][i] = true;
        }
        int Max = INT_MIN;
        while (!que.empty()) {
            int x, y, height_t;
            node t = que.top();
            que.pop();
            x = t.x; y = t.y; height_t = t.height;
            Max = max(Max, height_t);
            for (auto r: dir) {
                int x2 = x+r.first;
                int y2 = y+r.second;
                if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visit[x2][y2]) 
                    continue;
                else {
                    if (heightMap[x2][y2] < Max)
                        trap += Max-heightMap[x2][y2];
                    node node1 = node(x2, y2, heightMap[x2][y2]);
                    que.push(node1);
                    visit[x2][y2] = true;
                }
            }
        }
        return trap;
    }
};