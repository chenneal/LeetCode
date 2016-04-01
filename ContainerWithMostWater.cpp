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

/* A optical version */
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