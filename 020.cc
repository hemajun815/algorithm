#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void push(int value) {
        this->m_data.push_back(value);
    }
    void pop() {
        this->m_data.pop_back();
    }
    int top() {
        return this->m_data.back();
    }
    int min() {
        if (this->m_data.empty()) return int(NULL);
        int m = this->top();
        for (int i=0; i<this->m_data.size()-1; i++)
            if (m > this->m_data.at(i))
                m = this->m_data.at(i);
        return m;
    }
private:
    vector<int> m_data;
};

int main(int argc, char const *argv[])
{
    Solution * p = new Solution();
    p->push(3);
    cout << p->min() << endl;
    p->push(4);
    cout << p->min() << endl;
    p->push(2);
    cout << p->min() << endl;
    p->push(3);
    cout << p->min() << endl;
    p->pop();
    cout << p->min() << endl;
    p->pop();
    cout << p->min() << endl;
    p->push(0);
    cout << p->min() << endl;
    return 0;
}
