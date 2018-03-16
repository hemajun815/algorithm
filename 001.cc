class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size() - 1, col = 0;
        while (true)
        {
            if (col == array[0].size() || row == -1)
                return false;
            if (target == array[row][col])
                return true;
            else if (target > array[row][col])
                col++;
            else
                row--;
        }
    }
};