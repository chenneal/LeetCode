/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
  (you may want to display this pattern in a fixed font for better legibility) */

/*A very simple version*/
class Solution {
public:
    string convert(string s, int numRows) {
        string result[numRows];
        string res;
        int i = 0;
        int row;
        while (i < s.size()) {
            for (row = 0; (row < numRows) && (i < s.size()); i++, row++) {
            	result[row] += s[i];
            }
            for (row = numRows - 1 - 1; (row > 0) && (i < s.size()); row--, i++) {
            	result[row] += s[i];
            }
        }
        
        for (int i = 0; i < numRows; i++) {
            res += result[i];
        }

        return res;
    }
};