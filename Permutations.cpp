/*
 Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
] 
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        perm(result, nums, 0, nums.size()-1);
        return result;
    }
    void perm(vector<vector<int>>& result, vector<int>&nums, int head, int tail) {
        if (head >= tail) {
            result.push_back(nums);
            return ;
        }
        else {
            for (int i = head, i <= tail; i++) {
                //交换首尾的值再深搜
                swap(nums, head, i);
                perm(result, nums, head+1, tail);
                //复原，以便下次继续使用
                swap(nums, head, i);
            }
        }
    }
    void swap(vector<int>&nums, int m, int n) {
        int t;
        t = nums[m];
        nums[m] = nums[n];
        nums[n] = t;
    }
};
