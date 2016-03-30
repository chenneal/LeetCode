/* Reverse digits of an integer.
   Example1: x = 123, return 321
   Example2: x = -123, return -321 */

/*A little trick version */
class Solution {
public:
    int reverse(int x) {
        long long int temp;
        int length;
        char help[64];
        temp = x;
        sprintf(help, "%ld", temp);
        length = stringLength(help);
        stringReverse(help, length);
        sscanf(help, "%ld", &temp);
        if (temp > INT_MAX)    return 0;
        else if (temp < INI_MIN)    return 0;
        else return (int)temp;
    }

    void stringReverse(char * s, int length) {
    	char temp;
    	int i = 0;
    	for (; i < length/2; i++) {
    		if (s[i] == '-') {
    		    length++;  
    			continue;
    		}
            temp = s[i];
            s[i] = s[length-i-1];
            s[length-i-1] = temp;
    	}
    }

    int stringLength(char *s) {
    	int i = 0;
    	while (s[i] != '\0')    i++;
    	return i;
    }
};