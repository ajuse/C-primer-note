##### 顺序容器

1. vector
   可变大小数组，支持快速随机访问，插入或删除可能很慢，存储连续
   定义：vector<type> a;
   
2. deque
   双端队列，支持随机访问
   定义：deque<type> a;
   
3. list
   双向链表，只支持双向顺序访问，插入和删除速度都很快
   定义：list<type> a;
   
4. forward_list
   单向链表，只支持单向顺序访问，插入和删除速度很快
   定义：forward_list<type> a;
   
5. array
   大小固定，支持快速随机访问，不能插入和添加元素
   定义：array<type, num> a;
   
6. string
   与vector相似的容器，专门用于保存字符，随机访问快，存储
   定义：string<type> a;
   ps：其中type也可以是一个容器类型

一些基本操作：   
构造函数：

```
C c;    默认构造函数
C c1(c2);   构造c2的拷贝c1
C c(b, e);  构造c，将b和e指定的范围内的元素拷贝到c，array不支持
C c(a, b, c...);    列表初始化c
```

大小：

```
c.size()
c.max_size()
c.empty()
```

添加、删除元素，不适用于array

```
c.insert(args)
c.emplace(args)
c.push_back(args) //追加到容器尾部，不支持array和forward_list
c.push_front(args)//追加到容器头部
c.erase()
c.clear()
```

迭代器

```
c.begin()
c.end()
c.cbegin()
c.cend()
```

访问：

```
除array之外的容器都有front()成员函数，除forward_list之外都有back()成员函数
访问成员函数返回的是引用，如果容器是一个const对象，则返回const引用，否则为一般引用；
对应的也有pop_front()和pop_back()删除元素
```

##### 关联容器

1. map和multimap（unordered_map和unordered_multimap）
   定义：map<type1, type2> a;
2. set和multiset（unordered_set和unordered_multiset）
   定义：set<type> a;

**pair**是一种标准库类型，定义在头文件utility中。类似于容器
定义：pair<type1, type2> a;

* 关联容器不支持顺序容器的位置操作，比如front和back系列