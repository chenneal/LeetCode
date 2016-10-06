/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int max = 0;
        // 2代表配对成功，一开始为0，1代表出现过和配对还未成功
        int hash[70] = {0};
        for (int i = 0; i < s.length(); i++) {
            int position = s[i]-'A';
            if (hash[position] == 0)
                hash[position] = 1;
            else if (hash[position] == 1) {
                hash[position] = 2;
                max += 2;
            }
            else 
                hash[position] = 1;
        }
        return (max == s.length() ? max : max+1);
    }
};