/* Write a function to find the longest common prefix string amongst an array of strings. */

/* naive version */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index;
        int end;
        string result;
        if (strs.size() == 0)
            return result;
        int prefix = strs[0].size() - 1;
        int min = prefix;
        for (int i = 1; (i < strs.size()) && (prefix >= 0); i++) {
            index = 0;
            end = (prefix > strs[i].size() - 1) ? (strs[i].size() - 1) : prefix;
            while (index <= end) {
                if (strs[i][index] != strs[0][index])
                    break;
                index++;
            }
            if (index <= end) {
                index--;
                prefix = index;
            }
            else {
                index--;
                prefix = index;
            }
        }
        result = strs[0].substr(0, prefix+1); 
        return result;
    }
};

/*A better version */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int end = strs[0].size() - 1;
        int i, j;
        bool diff = false;
        string result;
        for (i = 1; i < strs.size() && end >= 0; i++) {
            for (j = 0; j < strs[i].size() && j <= end; j++) {
                if (strs[i][j] != strs[0][j]) {
                    end = j - 1;
                    diff = true;
                    break;
                }
            }
            if (j == strs[i].size() && !diff) {
                end  = j - 1;
            }
        }
        return strs[0].substr(0, end+1);
    }
};