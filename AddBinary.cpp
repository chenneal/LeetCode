class Solution {
public:
    string addBinary(string a, string b) {
        int borrow = 0;
        int bit;
        string result;
        int i, j;
        for (i = a.size()-1, j = b.size()-1; i >= 0 && j >= 0; i--, j--) {
            bit = (a[i]-'0'+b[j]-'0'+borrow) % 2;
            result += bit ? '1' : '0';
            borrow = (a[i]-'0'+b[j]-'0'+borrow) / 2;
        }
        while (i >= 0) {
            bit = (a[i]-'0'+borrow) % 2;
            result += bit ? '1' : '0';
            borrow = (a[i]-'0'+borrow) / 2;
            i--;
        }
        while (j >= 0) {
            bit = (b[j]-'0'+borrow) % 2;
            result += bit ? '1' : '0';
            borrow = (b[j]-'0'+borrow) / 2;
            j--;
        } 
        if (borrow != 0) 
            result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};