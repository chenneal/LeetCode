/*
   Given an array of non-negative integers, you are initially positioned at the first index of the array.

   Each element in the array represents your maximum jump length at that position.

   Your goal is to reach the last index in the minimum number of jumps.

   For example:
   Given array A = [2,3,1,1,4]

   The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        if (length == 1)
            return 0;
        int max;
        int maxj;
        int count = 0;
        int i=0, j;
        while (i < length)
        {
            max = i;
            j = i;
            maxj = i;
            for (j = i+1; (j <= i+nums[i]) && (j < length); j++)
            {
                if (j+nums[j] > max)
                {
                    max = j+nums[j];
                    maxj = j;
                }
            }
            count++;
            if (j > length -1)
                break;
            else
                i = maxj;
        }
        return count;
    }
};