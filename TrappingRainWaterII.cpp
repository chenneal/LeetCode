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
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m <= 2)
            return 0
        int n = heightMap[0].size();
        if (n <= 2)
            return 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if ()
            }
        }
    }

    bool is_suit(vector<vector<int>>& heightMap)
    {
        
    }
};