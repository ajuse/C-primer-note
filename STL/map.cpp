/*
STL: map/multimap/unordered_map/unordered_multimap
特性：
1. map和multimap，底层实现都是红黑树，添加，查找，删除，插入的算法都是O(lgn)，
   unordered_map与unordered_multimap中key为无序排列，其底层实现为hash table；散列表实现
   最坏为O(n)，因为需要考虑hash冲突问题，还有就是key值很长
2. map，key不可重复，有序
3. multimap，key可以重复，有序
4. 插入操作不会让迭代器失效，因为插入或删除都是指针的替换，并不涉及到内存的变动；
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

template<typename T>
void traverse(T tmp)
{
    for (auto iter = tmp.begin(); iter != tmp.end(); iter++)
        cout << iter->first << ":" << iter->second << " ";
    cout << endl;
}

int main()
{
    map<string, int> m1;

    m1["li"] = 98;
    m1["yuan"] = 93;
    m1["ken"] = 91;
    m1["jun"] = 92;
    m1["lu"] = 98;
    m1["lu"] = 99;
    m1["a1"] = 77;
    m1["zw"] = 88;
    m1["ce"] = 56;
    traverse(m1);

    m1.insert(make_pair("kang", 23));
    traverse(m1);

    m1.erase("jun");
    auto it = m1.find("li");
    m1.erase(it);
    traverse(m1);

    m1.clear();

    return 0;
}