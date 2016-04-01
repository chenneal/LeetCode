/* Determine whether an integer is a palindrome. Do this without extra space. */

/* A simple version */ 

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)    return false;
        int origin = x;
        int reverse = 0;
        while (x) {
        	reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return origin == reverse;
    }
};