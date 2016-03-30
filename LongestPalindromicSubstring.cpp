class Solution {
public:
    string longestPalindrome(string s) {
    	int length = s.size();
        int dp[length][length];
        string result;
        int begin, end;
        int maxlen = 0;
        for (int i = 0; i < length; i++) {
        	dp[i][i] = 1;
        	maxlen = 1;
        }

        for (int i = 0; i < length - 1; i++) {
        	if (s[i] == s[i+1]) {
      		    dp[i][i+1] = 1;
      		    maxlen = 2;
      		    begin = i;
      		    end = i + 1;
        	}    
        }
        
        for (int l = 3; l <= length; l++) {
        	for (int i = 0; i < length - l + 1; i++) {
                int j = i + l - 1;
                if ((s[i] == s[j]) && dp[i+1][j-1]) {
                    dp[i][j] == 1;
                    if (j - i + 1 > maxlen) {
                    	maxlen = j - i + 1;
                    	begin = i;
                    	end = j;
                    }
                }
                else {
                	dp[i][j] == 0;
                }
        	}
        }
        
        if (maxlen == 1)    result = s.substr(0, 1);
        else    result = s.substr(begin, end - begin + 1);
        return result;
    }
};