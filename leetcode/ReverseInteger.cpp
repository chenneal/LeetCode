/* Reverse digits of an integer.
   Example1: x = 123, return 321
   Example2: x = -123, return -321 */


/*A simple but effective version */
class Solution {
public:
    int reverse(int x) {
    	long long result = 0;
        int minus = false;
        if (x < 0) {
        	minus = true;
        	x = -x;
        }

        while (x) {
            result *= 10;
            result += x % 10;
            if ((result > INT_MAX) && !minus)    return 0;
            if ((result > INT_MIN) && minus)     return 0;
            x /= 10;
         }

         return (int) (minus * result);
    }
};

/*A little trick version */
class Solution {
public:
    int reverse(int x) {
        long long int temp;
        int length;
        char help[64];
        temp = x;
        sprintf(help, "%lld", temp);
        length = stringLength(help);
        stringReverse(help, length);
        sscanf(help, "%lld", &temp);
        if (temp > INT_MAX)    return 0;
        else if (temp < INT_MIN)    return 0;
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