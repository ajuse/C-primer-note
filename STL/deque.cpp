/*
STL: deque  (double ended queue)双端队列
特性：
1. 低层结构是使用一块map（连续内存）每个元素都是一个节点node，指向一块连续的内存空间，这块内存则是
   deque存储的空间，一般为512字节；这样，每次插入的时候则不会像vector那样拷贝，但是由于复杂的存储结构，
   使得迭代效率会比list和vecor低；
2. 可以从双端插入元素；
3. 头尾操作很快，中间操作较慢；
4. 
*/

#include <iostream>
#include <deque>

using namespace std;

template<typename T>
void traverse(T tmp)
{
    for (auto iter = tmp.begin(); iter != tmp.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

int main()
{
    deque<int> deq;
    deque<int> deq1(5,1);
    traverse(deq1);

    deq.push_back(1);
    deq.push_back(2);

    deq.push_front(3);
    traverse(deq);

    deq.pop_back();
    traverse(deq);

    int ret = deq.at(0);

    cout << ret << endl;
    cout << deq.empty() << " " << deq.size() << endl;

    deq1.insert(deq1.begin(), 8);
    traverse(deq1);

    deq1.insert(deq1.begin(), 3, 7);
    traverse(deq1);

    deq1.insert(deq1.begin(), deq.begin(), deq.end());
    traverse(deq1);

    deq1.erase(deq1.begin());
    traverse(deq1);

    // 删除[begin, begin+2)区间的元素
    deq1.erase(deq1.begin(), deq1.begin() + 2);
    traverse(deq1);

    deq.clear();
    traverse(deq);

    return 0;
}