/*
STL: deque  (double ended queue)双端队列
特性：
1. 
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


    return 0;
}