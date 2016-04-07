/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> spath;
        string result;
        int i = 0;
        while (i < path.size()) {
            string temp = "";
            while (path[i] == '/' && i < path.size()) {
                i++;
            }
            while (path[i] != '/' && i < path.size()) {
                temp += path[i++];
            }
            if (temp == ".." && !spath.empty()) {
                spath.pop();
            }
            else {
                if (temp != "." && temp != "" && temp != "..")
                spath.push(temp);
            }
        }
        if (spath.empty())
            return "/";
        while (!spath.empty()) {
            result.insert(0, '/' + spath.top());
            spath.pop();
        }

        return result;
    }
};