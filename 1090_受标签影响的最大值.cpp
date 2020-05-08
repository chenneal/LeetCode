class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        //hash表计算标签出现的次数
        unordered_map<int, int> hash;
        //使用堆排序
        priority_queue<pair<int, int>> heap;

        for (int i = 0; i < values.size(); i++) {
            //依次加入堆
            heap.push({values[i], labels[i]});
        }

        int result = 0;
        int count = 0;

        while(heap.size()) {
            //如果次数没达到上限，根据贪心策略，优先使用权重大的
            if (++hash[heap.top().second] <= use_limit && count < num_wanted) {
                result += heap.top().first;
                count++;
            }
            heap.pop();
        }

        return result;
    }
};
