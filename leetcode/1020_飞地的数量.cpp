class Solution {
public:
//只有陆地能过使用此函数
void isFlyPlace(vector<vector<int>>& A, int row, int column) {
    //已经越界
    if (row >= A.size() || column >= A[0].size() || row < 0 || column < 0) {
        return ;
    }
    
    //证明不是飞地
    if (A[row][column] == 0) {
        return ;
    }

    A[row][column] = 0;

    //分四个方向搜索
    isFlyPlace(A, row + 1, column);
    isFlyPlace(A, row, column + 1);
    isFlyPlace(A, row - 1, column);
    isFlyPlace(A, row, column - 1);
}
    int numEnclaves(vector<vector<int>>& A) {
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                //只需要考察边界
                if (i == 0 || i == A.size() - 1 || j == 0 || j == A[0].size() - 1) {
                    isFlyPlace(A, i, j);
                } else {
                    continue;
                }
            }
        }

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                count += A[i][j];
            }
        }

        return count;
    }
};
