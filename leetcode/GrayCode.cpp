/* A naive version */
class Solution {
public:
    vector<int> grayCode(int n) {
        bool right = true;
        int position;
        int index = 1;
        int length = 1<<n;
        vector<int> result(length, 0);
        result[0] = 0;
        while (index <= length - 1) {
            if (right) {
                result[index] = 1^result[index-1];
                index++;
            }
            else {
                result[index] = ReverseBit(result[index-1]);
                index++;
            }
            right = !right;
        }
        return result;
    }

    int ReverseBit(int num) {
        int position = 0;
        int temp = num;
        bool minus;
        for (int i = 0; i < 30; i++) {
            if (num % 2 == 1) {
                position = i + 1;
                if ((num>>1) % 2 == 1) 
                    minus = true;
                else
                    minus = false;
                break;
            }
            else {
                num = num>>1;
            }
        }

        return (temp + (minus ? (-(1<<position)) : 1<<position));
    }
};

/* a clever version */
    vector<int> grayCode(int n) {
        vector<int> result;
        result.resize(n);
        int length = 1 << n

        for (int i = 0; i < length; i++) {
            result.[i] ^= i^i>>1;
        }

        return result;
    }