/* Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i;
        int pro_max = 0;
        int length = prices.size();
        if (length == 0)
            return 0;
        // dp_pre代表在i之前的最大交易值
        vector<int> dp_pre(length, 0);
        // dp_suf代表在i之后的最大交易值
        vector<int> dp_suf(length, 0); 
        int max_t = prices[length-1];
        int min_t = prices[0];
        dp_suf[length-1] = 0;  
        dp_pre[0] = 0;       
        for (i = 1; i < length; i++) {
            if (prices[i] < min_t)
                min_t = prices[i];
            dp_pre[i] = max(prices[i]-min_t, dp_pre[i-1]);
        }

        for (i = length-2; i > 0 ; i--) {
            if (prices[i] > max_t)
                max_t = prices[i];
            dp_suf[i] = max(max_t-prices[i], dp_suf[i+1]);
        }

        for (i = 2; i < length-1; i++) {
                pro_max = max(pro_max, dp_pre[i]+dp_suf[i]);
        }
        return max(dp_pre[length-1], pro_max);
    }
};