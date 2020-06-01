/*  Given a set of distinct integers, nums, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.
*/

class Solution {
public:
    void dfs(vector<vector<int>> &subsets, vector<int>& nums, vector<int>& v, int pos, int cnt, int n) {
        if (cnt == n) {
            subsets.push_back(v);
            return ;
        }
        for (int i = pos; i < nums.size(); i++) {
            v.push_back(nums[i]);
            dfs(subsets, nums, v, i+1, cnt+1, n);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> v;
        for (int i = 0; i <= nums.size(); i++) {
            dfs(result, nums, v, 0, 0, i);
        }
        return result;
    }
};