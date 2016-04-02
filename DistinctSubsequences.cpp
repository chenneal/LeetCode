/* Given a string S and a string T, count the number of distinct subsequences of T in S.
   A subsequence of a string is a new string which is formed from the original string by 
   deleting some (can be none) of the characters without disturbing the relative positions 
   of the remaining characters. */

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())    return 0;
        int dp[s.size()+1][t.size()+1];
        int num = 0;
        /* Iintialize the base state */
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[0]) {
                num++;
            }
            dp[i][0] = num;
        }
        
        for (int j = 1; j < t.size(); j++) {
            dp[0][j] = 0;
        }
        
        for (int i = 1; i < s.size(); i++) {
            for (int j = 1; j < t.size(); j++) {
                dp[i][j] = dp[i-1][j]; 
                if (s[i] == t[j])
                    dp[i][j] += dp[i-1][j-1];
            }
        }

        return dp[s.size()-1][t.size()-1];
    }
};

/* optimized version */

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())    return 0;
        int dp[s.size()+1][t.size()+1];
        int num = 0;
        /* Iintialize the base state */
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[0]) {
                num++;
            }
            dp[i][0] = num;
        }
           
        for (int j = 1; j < t.size(); j++) {
            for (int i = j; i < s.size(); i++) {
                if (i == j) {
                    dp[i][j] = (s[i] == t[j] ? dp[i-1][j-1] : 0);
                }
                else {
                    dp[i][j] = dp[i-1][j]; 
                    if (s[i] == t[j])
                        dp[i][j] += dp[i-1][j-1];
                }
            }
        }

        return dp[s.size()-1][t.size()-1];
    }
};