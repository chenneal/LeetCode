class Solution {
public:
    int find_value(vector<int>& nums, int target, int start, int end) {
        if (end < start) {
            return -1;
        }

        if (end == start) {
            if (nums[start] == target) {
                return start;
            } else {
                return -1;
            }
        }

        int mid = (start + end) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        //代表左侧是递增的
        if (nums[mid] > nums[start]) {
            if (nums[mid - 1] >= target && nums[start] <= target) {
                return find_value(nums, target, start, mid - 1);
            } else {
                return find_value(nums, target, mid + 1, end);
            }
        } else { //代表右侧是递增的
            if (nums[mid + 1] <= target && nums[end] >= target) {
                return find_value(nums, target, mid + 1, end);
            } else {
                return find_value(nums, target, start, mid - 1);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return find_value(nums, target, 0, nums.size() - 1);
    }
};