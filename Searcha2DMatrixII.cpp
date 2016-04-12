/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.*/

/*A TLE version use DFS*/
class Solution {
public:
    bool dfs(vector<vector<int>>& matrix, int column, int row, int length, int width, int target) {
        if (column == width || row == length)
            return (matrix[length-1][width-1] == target ? true : false);
        else if (column == width) {
            if (matrix[row][column] == target)
                return true;
            else if (matrix[row][column] > target)
                return false;
            else
                return dfs(matrix, column, row+1, length, width, target);
        }
        else if (row == length) {
            if (matrix[row][column] == target)
                return true;
            else if (matrix[row][column] > target)
                return false;
            else
                return dfs(matrix, column+1, row, length, width, target);
        }
        else {
            if (matrix[row][column] == target)
                return true;
            else if (matrix[row][column] > target)
                return false;
            else {
                return (dfs(matrix, column+1, row, length, width, target) || dfs(matrix, column, row+1, length, width, target));
            }
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int length = matrix.size();
        int width = matrix[0].size();
        return dfs(matrix, 0, 0, length, width, target);
    }
};

/* A binary search version */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int cloumn = matrix[0].size();
        int i = 0;
        int j = cloumn - 1;
        while (i < row && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j--;
            else 
                i++;
        }
        return false;
    }
};