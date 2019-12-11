* 虚函数可以是内联函数吗？

  虚函数可以是内联函数，但是当虚函数表现为多态性的时候不能内联；内联是在编译器建议编译器内联，而虚函数的多态性在运行期，

  因此虚函数表现为多态性时不能内联；

  `inline virtual` 唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如 `Base::who()`），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生；

* 各种空类的占用空间大小？

  1. 含有虚函数的类

* 如何定义一个只能在堆上（栈上）生成对象的类？

  只能在堆上

  方法：将析构函数设置为私有

  原因：C++ 是静态绑定语言，编译器管理栈上对象的生命周期，编译器在为类对象分配栈空间时，会先检查类的析构函数的访问性。若析构函数不可访问，则不能在栈上创建对象。

  只能在栈上

  方法：将 new 和 delete 重载为私有

  原因：在堆上生成对象，使用 new 关键词操作，其过程分为两阶段：第一阶段，使用 new 在堆上寻找可用内存，分配给对象；第二阶段，调用构造函数生成对象。将 new 操作设置为私有，那么第一阶段就无法完成，就不能够在堆上生成对象。

* 