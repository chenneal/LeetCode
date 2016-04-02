/* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
   n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
   which together with x-axis forms a container, such that the container contains the most water.

   Note: You may not slant the container. */

/* A TLE BF version */
int maxArea(int* height, int heightSize) {
    int max = 0;
    int temp_area = 0;
    for (int l = 1; l < heightSize; l++) {
        int begin = 0;
        int end = l;
        while (end < heightSize) {
    		if ((temp_area = (height[begin] > height[end] ? height[end] : height[begin]) * l) > max) {
    			max = temp_area;
    		}
    		begin++;
    		end++;
    	}
    }

    return max;
}

/* A optimized version */
int maxArea(int* height, int heightSize) {
	int max = 0;
	int temp_area = 0;
    int begin = 0;
    int end = heightSize - 1;
    while (end > begin) {
    	temp_area = (end - begin) * (height[begin] > height[end] ? height[end--] : height[begin++]);
        max = temp_area > max ? temp_area : max;
    }

    return max;
}