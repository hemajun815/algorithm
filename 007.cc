class Solution {
public:
    int Fibonacci(int n) {
        int f1 = 0, f2 = 1;
        while (n--)
        {
            f2 += f1;
            f1 = f2 - f1;
        }
        return f1;
    }
};