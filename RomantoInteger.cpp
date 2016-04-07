class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int bar;
        int i = 0;
        while (i < s.size()) {
            switch(s[i]) {
                case 'M':
                    bar = i-1;
                    while (bar > 0 && s[bar] == 'C') {
                        result -= 100;
                        bar--;
                    }
                    result += 1000;
                    i++;
                    break;
                case 'D':
                    bar = i-1;
                    while (bar > 0 && s[bar] == 'C') {
                        result -= 100;
                        bar--;
                    }
                    result += 500;
                    i++;
                    break;
                case 'C':
                    bar = i-1;
                    while (bar > 0 && s[bar] == 'X') {
                        result -= 10;
                        bar--;
                    }
                    result += 100;
                    i++;
                    break;
                case 'L':
                    bar = i-1;
                    while (bar > 0 && s[bar] == 'X') {
                        result -= 10;
                        bar--;
                    }
                    result += 50;
                    i++;
                    break;
                case 'X':
                    bar = i-1;
                    while (bar > 0 && s[bar] == 'I') {
                        result -= 1;
                        bar--;
                    }
                    result += 10;
                    i++;
                    break;                   
                case 'V':
                    bar = i-1;
                    while (bar > 0 && s[bar] == 'I') {
                        result -= 1;
                        bar--;
                    }
                    result += 5;
                    i++;
                    break;
                case 'I':
                    result += 1;
                    i++;
                    break;
                default:
                    break;
            }
        }

        return result;
    }
};