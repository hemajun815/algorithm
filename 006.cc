class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) return 0;
        for (int i = 0; i < rotateArray.size() - 2; i++)
            if (rotateArray[i] > rotateArray[i+1])
                return rotateArray[i+1];
        return 0;
    }
};