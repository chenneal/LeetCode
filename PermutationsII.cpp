/*
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:

[
  [1,1,2],
  [1,2,1],
  [2,1,1]
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
                if ((i != head) && (nums[i] == nums[head]))
                    return ;
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
