#include <iostream>
#include <queue>

int main(int argc, char const *argv[])
{
    auto n = 0;
    std::cin >> n;
    auto q = new std::queue<int>();
    for (int i = 1; i <= n; i++)
        q->push(i);
    while (!q->empty())
    {
        std::cout << q->front() << ' ';
        q->pop();
        if (q->empty())
            break;
        q->push(q->front());
        q->pop();
    }
    return 0;
}
