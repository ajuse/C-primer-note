### 动态内存

#### 动态内存申请与释放

使用new和delete

使用动态内存的难点：忘记释放内存造成内存泄漏；释放掉内存后有指针引用内存造成非法指针；

使用new时，底层先在堆上malloc分配内存空间，分配好之后再调用类的构造函数；

使用delete时，底层先调用类的析构函数，然后再free内存；

#### 智能指针

智能指针也是模板；

默认初始化智能指针中保存着一个空指针；判断是否指向空：p->empty()

智能指针使用方式和普通指针类似；

头文件：memory

**shared_ptr**

shared_ptr允许多个指针指向同一个对象

定义：

`shared_ptr<T> p;` 

操作：

1. `make_shared<T>(args);`

   返回一个shared_ptr,指向一个动态分配的类型为T的对象，使用args初始化此对象；

   不带参数时使用值初始化；

2. `shared_ptr<T>p(q);`

   p是shared_ptr q的拷贝；此操作会递增q中的计数器。q中的指针必须能转换为T*

拷贝和赋值：

1. 每个shared_ptr都会记录有多少个其他shared_ptr指向相同对象；引用计数，当计数为0自动释放空间；
2. 用一个shared_ptr初始化另一个shared_ptr、作为参数传递、作为函数返回值，计数器加1；
3. shared_ptr赋予一个新值、shared_ptr被销毁（局部shared_ptr离开其作用域），计数器减1；

**unique_ptr**

unique_ptr独占所指向的对象，可以避免资源泄露，同一时间资源只能被一个unique_ptr拥有，

一旦被销毁或编程empty或拥有另一个对象，先前的对象就会被销毁，对应的资源都会被释放；