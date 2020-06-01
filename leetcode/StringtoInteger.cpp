/* Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front. 
*/

class Solution {
public:
    int myAtoi(string str) {
    	int i;
    	char buf[64];
    	for (i = 0; i < str.size(); i++) {
    		buf[i] = str[i];
    	}
    	buf[str.size()] = '\0';
        long result;
        sscanf(buf, "%ld", &result);
        if (result > INT_MAX)    return INT_MAX;
        else if (result < INT_MIN)    return INT_MIN;
        else return result;
    }
};