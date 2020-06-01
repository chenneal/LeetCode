/* Given a string that contains only digits 0-9 and a target value, 
return all possibilities to add binary operators (not unary) +, -, 
or * between the digits so they evaluate to the target value.

Examples:

"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

class Solution {
public:
    void dfs(string num, int target, vector<string> &result, string path, int pos, long cur, long lastnum) {
        if (pos == num.size()) {
            if (cur == target) {
                result.push_back(path);
            }
            return ;
        }
        for (int i = pos; i < num.size(); i++) {
            if (num[pos] == '0' && i > pos)
                break;
            string now_str = num.substr(pos, i-pos+1);
            long now = stol(now_str);
            if (pos == 0) {
                dfs(num, target, result, now_str, i + 1, now, now);
            }
            else {
                dfs(num, target, result, path+'+'+now_str, i + 1, cur + now, now);
                dfs(num, target, result, path+'-'+now_str, i + 1, cur - now, -now);
                dfs(num, target, result, path+'*'+now_str, i + 1, cur - lastnum + lastnum * now, lastnum*now);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        dfs(num, target, result, "", 0, 0, 0);
        return result;
    }
};