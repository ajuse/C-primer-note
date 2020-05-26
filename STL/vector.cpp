/*
STL: vector
特性：
1. 支持随机访问，内存连续，底层使用动态数组实现，在堆上分配空间；
2. 删除/插入操作会涉及之后的元素内存整体前移，所以尽量只在末尾删除/插入；
3. 当新增元素大于容器容量时，会重新申请较原来1.5~2倍的内存空间，并将元素都拷贝到新内存；
   原来的内存会被释放，被系统回收；应尽量避免这种情况出现；比如初始化时指定大小或reserve重新分配；
4. 可以保存类，很方便的访问，但是在有内存重新分配时迁移数据则有构造函数和析构函数，降低性能；
   应尽量避免保存整个类；
5. 在插入位置和删除位置之后的所有迭代器和指针引用都会失效，扩容之后同理；
*/

#include <iostream>
#include <vector>

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
    // 列表初始化，分配内存
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 未指定大小，此时还未分配内存，动态添加
    vector<int> v2;
    // 默认值初始化，预先分配大小为5的容器，元素被初始化为默认值，int则为0。
    // 也可以vector<int> v3(5, 1)；表示初始化5个值为1的元素；
    vector<int> v3(50);
    // 复制v1, 等价vector<int> v3 = v1，v1与v3类型必须相同
    vector<int> v4(v1);

    // 末尾添加
    v1.push_back(11);

    // 末尾删除
    v1.pop_back();

    // 返回容器元素个数
    cout << "v1 size: " << v1.size() << endl;
    cout << "v3 size: " << v3.size() << endl;

    // 返回容器中最大能容纳元素的个数
    cout << "v1 max_size: " << v1.max_size() << endl;

    // 返回容器是否为空
    cout << "v1 empty: " << v1.empty() << endl;
    cout << "v2 empty: " << v2.empty() << endl;

    // 返回中可容纳的元素个数
    cout << "v1 cap: " << v1.capacity() << endl;
    cout << "v2 cap: " << v2.capacity() << endl;
    cout << "v3 cap: " << v3.capacity() << endl;

    // 64位处理器，vector中有三个指针，则内存占用24字节，具体看编译器如何实现vector
    cout << "sizeof v3: " << sizeof(v3) << endl;

    // 清空容器
    v4.clear();

    // 擦除固定位置元素，也可以是范围v1.erase(begin, end)
    v1.erase(v1.begin() + 3);

    traverse(v1);

    // 改变容器所分配的空间大小
    v3.reserve(100);
    cout << "v3 cap: " << v3.capacity() << endl;

    return 0;
}