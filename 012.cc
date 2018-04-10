#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    long a = 0;
    long b = 0;
    cin >> a >> b;
    long count = 0;
    long sum = 0;
    for (long i = 1; i < a; i++) sum += i;
    for (long j = a; j <= b; j++)
    {
        sum += j;
        if (sum % 3 == 0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
