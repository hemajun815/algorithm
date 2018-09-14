#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename Key, typename Value>
class Entry
{
  public:
    Key key;
    Value value;
    Entry *next;
    Entry *pre;
    Entry(Key const &key, Value const &value) : key(key), value(value), next(NULL), pre(NULL)
    {
    }
};

template <typename Key, typename Value>
class LRUCache
{
  private:
    unsigned size;
    unordered_map<Key, Entry<Key, Value>> *map;
    Entry<Key, Value> *first;
    Entry<Key, Value> *last;

  private:
    void make_to_first(Key const &k)
    {
        auto it = this->map->find(k);
        if (!this->first && !this->last) // 第一个节点
            this->first = this->last = &it->second;
        else
        {
            if (!it->second.pre && !it->second.next) // 插入节点
            {
                it->second.next = this->first;
                this->first->pre = &it->second;
                this->first = &it->second;
            }
            else if (this->first != &it->second) // 更新节点
            {
                it->second.pre->next = it->second.next;
                if (this->last != &it->second)
                    it->second.next->pre = it->second.pre;
                else
                    this->last = it->second.pre;
                it->second.pre = NULL;
                it->second.next = this->first;
                this->first->pre = &it->second;
                this->first = &it->second;
            }
        }
    }
    void remove_last()
    {
        auto entry = this->last;
        this->last = entry->pre;
        this->last->next = NULL;
        this->map->erase(entry->key);
    }

  public:
    LRUCache(unsigned const &size) : size(size), map(new unordered_map<Key, Entry<Key, Value>>()), first(NULL), last(NULL)
    {
    }
    void put(Key const &k, Value const &v)
    {
        auto entry = new Entry<Key, Value>(k, v);
        auto it = this->map->find(k);
        if (it != this->map->end())
            it->second = *entry;
        else
        {
            this->map->insert(make_pair<>(k, *entry));
            if (this->map->size() > this->size)
                this->remove_last();
        }
        this->make_to_first(k);
    }
    Value *get(Key const &k)
    {
        auto it = this->map->find(k);
        if (it != this->map->end())
        {
            this->make_to_first(k);
            return &it->second.value;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    LRUCache<int, int> cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    auto v = cache.get(1);
    if (v)
        cout << *v << endl; // 1
    else
        cout << "NULL" << endl;
    v = cache.get(2);
    if (v)
        cout << *v << endl; // 2
    else
        cout << "NULL" << endl;
    cache.put(2, 20);
    v = cache.get(2);
    if (v)
        cout << *v << endl; // 20
    else
        cout << "NULL" << endl;
    cache.put(3, 3);
    v = cache.get(1);
    if (v)
        cout << *v << endl;
    else
        cout << "NULL" << endl; // NULL
    cache.put(4, 4);
    v = cache.get(2);
    if (v)
        cout << *v << endl;
    else
        cout << "NULL" << endl; // NULL
    cin.get();
    return 0;
}
