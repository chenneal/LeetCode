/* 
  Given a string, find the length of the longest substring without repeating characters. 
  For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
  which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

/* BF version, test will be TLE */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        if (s.size() == 0)
        {
            return 0;
        }
        
        if (s.size() == 1)
        {
            return 1;
        }
        
        for (int i = 0; i <= s.size() - 2; i++) 
        {
            for (int j = i + 1; j <= s.size() -1; j++) 
            {
                int flag = 0;
                for (int m = i; m <= j - 1; m++) 
                {
                    for (int n = m + 1; n <= j; n++) 
                    {
                        if (s[m] == s[n]) 
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1) 
                    {
                       break;
                    }
                }
                if (flag == 0 && (j - i + 1) > maxlen)
                {
                    maxlen = j - i +1;
                }
            }
        }
        return maxlen;
    }
};

/* hash table version, use a hash table to check the repetition of a char */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j;
        int maxlen = 0;
        int hash[256];
        if (s.size() == 0)
        {
            return 0;
        }
        if (s.size() == 1)
        {
            return 1;
        }
        for (i = 0; i <= s.size() - 2; i++) 
        {
            memset(hash, 0, sizeof(hash));
            hash[s[i]] = 1;
            for (j = i + 1; j <= s.size() -1; j++) 
            {
                if (hash[s[j]] == 0) 
                {
                    hash[s[j]] = 1;
                }
                else 
                {
                    break;
                }
            }
            if ((j - i) > maxlen)
            {
                maxlen = j - i;
            }
        }
        return maxlen;
    }
};

/* a very trick version*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int curlen = 0;
        vector<int> hash(256, -1);
        for (int i = 0; i < s.size(); ++i)
        {
            if (hash[s[i]] == -1 || (i - hash[s[i]]) > curlen) 
            {
                curlen = curlen + 1;
            }
            else 
            {
                curlen = i - hash[s[i]];
            }
            if (curlen > maxlen)
            {
               maxlen = curlen;
            }
            hash[s[i]] = i;             
        }
        return maxlen;
    }
};
