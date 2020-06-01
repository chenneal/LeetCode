/* There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. 
   The overall run time complexity should be O(log (m+n)).*/

/* A merge sort version that the complexity of time is O(m+n) */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        int length;
        vector<int> merge;
        int p = 0, p1 = 0, p2 = 0;
        while (p1 < nums1.size() && p2 < nums2.size()) {
        	if (nums1[p1] < nums2[p2])    merge.push_back(nums1[p1++]);
        	else                          merge.push_back(nums2[p2++]);
        }
        while (p1 < nums1.size())    merge.push_back(nums1[p1++]);
        while (p2 < nums2.size())    merge.push_back(nums2[p2++]);

        length = merge.size();
        if (length % 2 == 0)    result = (merge[length/2] + merge[length/2 - 1]) / 2.0;
        else                    result = merge[(length+1)/2 - 1];

        return result;
    }
};

/* A recusive version based on Find Kth number in two sorted sequence list */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int length1, length2;
    	length1 = nums1.size();
    	length2 = nums2.size();
    	if ((length1 + length2) % 2 != 0)    
    	    return findKthNumber(nums1, nums2, 0, length1 - 1, 0, length2 - 1, (length1 + length2 - 1) / 2);
    	else {
    		int a = findKthNumber(nums1, nums2, 0, length1 - 1, 0, length2 - 1, (length1 + length2) / 2);
    		int b = findKthNumber(nums1, nums2, 0, length1 - 1, 0, length2 - 1, (length1 + length2 - 2) / 2);
    		return (a + b) / 2.0;
    	}             
    	                                          
    }

    int findKthNumber(vector<int>& a, vector<int>& b, int la, int ra, int lb, int rb, int k) {
    	int ma, mb;
    	ma = (la + ra) / 2;
    	mb = (lb + rb) / 2;
    	if (la > ra)    return b[lb + k];
    	if (lb > rb)    return a[la + k];
    	if (a[ma] > b[mb]) {
    		if (k + 1 < ma - la + 1 + mb - lb + 1)    return findKthNumber(a, b, la, ma - 1, lb, rb, k);
    		else                                      return findKthNumber(a, b, la, ra, mb + 1, rb, k - (mb - lb + 1));
    	}
    	else {
    		if (k + 1 < ma - la + 1 + mb - lb + 1)    return findKthNumber(a, b, la, ra, lb, mb - 1, k);
    		else                                      return findKthNumber(a, b, ma + 1, ra, lb, rb, k - (ma - la + 1));
    	}
    }
};
