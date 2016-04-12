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
