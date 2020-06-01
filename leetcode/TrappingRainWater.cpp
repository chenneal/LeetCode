/*  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        if (length < 3)
            return 0;
        int trap = 0;
        int high;
        int sec_high;
        bool is_left;
        int left = 0, right = length-1;
        is_left = height[left] < height[right] ? true : false;
        high = max(height[left], height[right]);
        sec_high = min(height[left], height[right]);
        while (left < right) {
            if (is_left) {
                if (height[left+1] > high) {
                    sec_high = high;
                    high = height[left+1];
                    left++;
                    is_left = false;
                }
                else if (height[left+1] > sec_high) {
                    sec_high = height[left+1];
                    left++;
                }
                else {
                    trap += (sec_high-height[left+1]);
                    left++;
                }
            }
            else {
                if (height[right-1] > high) {
                    sec_high = high;
                    high = height[right-1];
                    right--;
                    is_left = true;
                }
                else if (height[right-1] > sec_high) {
                    sec_high = height[right-1];
                    right--;
                }
                else {
                    trap += (sec_high-height[right-1]);
                    right--;
                }
            }
        }
        return trap;  
    }
};