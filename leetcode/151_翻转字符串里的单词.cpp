class Solution {
public:
    string reverseWords(string s) {
        stack<char> ori;
        stack<char> rst;
        string result;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                ori.push(s[i]);
            } else if (ori.size() > 0) {
                while (ori.size() > 0) {
                    rst.push(ori.top());
                    ori.pop();
                }
                rst.push(' ');
            } else {
                continue;
            }
        }

        while (ori.size() > 0) {
            rst.push(ori.top());
            ori.pop();
        }

        //去掉尾部的空格
        if (rst.size() > 0 && rst.top() == ' ') {
            rst.pop();
        }

        while (rst.size() > 0) {
            result.push_back(rst.top());
            rst.pop();
        }

        return result;
    }
};
