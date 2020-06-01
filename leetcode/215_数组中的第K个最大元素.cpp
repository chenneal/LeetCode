class Solution {
public:
    void exchange(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void adjust_down(vector<int>& nums, int k, int i) {

        if (i > k / 2 - 1) {
            return ;
        } 

        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int min = left;

        if (left > nums.size() - 1) {
            return ;
        }

        //获取最小值的索引
        if (right < nums.size() && right < k && nums[right] < nums[left]) {
            min = right;
        }

        if (nums[i] > nums[min]) {
            exchange(nums, i, min);
            adjust_down(nums, k, min);
        }
    }

    void create_heap(vector<int>& nums, int k) {
        for (int i = k / 2 - 1; i >= 0; i--) {
            adjust_down(nums, k, i);
        }
    }

    void heap_sort(vector<int>& nums, int k) {
        create_heap(nums, k);
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > nums[0]) {
                nums[0] = nums[i];
                adjust_down(nums, k, 0);
            }
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        heap_sort(nums, k);
        return nums[0];
    }
};