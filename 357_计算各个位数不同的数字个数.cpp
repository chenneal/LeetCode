class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
      if (n == 0)
        return 1;

      if (n == 1)
        return 10;

      int* dp = new int[n + 1];

      dp[0] = 1;
      dp[1] = 10;

      //递归公式: dp[i] = (11 - i) * (dp[i - 1] - dp[i - 1]) + dp[i - 1]
      for (int i = 2; i <= n; i++) {
          dp[i] = (11 - i) * (dp[i - 1] - dp[i - 2]) + dp[i - 1];
      }

      int result = dp[n];

      delete[] dp;

      return result;
    }
};
