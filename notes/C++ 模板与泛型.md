模板是泛型编程的基础，比如vector，实际上是使用了vector模板，使用vector可以定义很多类型的变量

* 定义模板

  1. 函数模板 -- 使用同样的功能但参数不同
     ```c++
     // 以template关键字开始，后面跟模板参数列表，可以用逗号分割带多个参数且模板参数列表不能为空;
     template <typename T>
     int func(T v1, T v2){} 
     ```
     
     **实例化函数模板时，编译器会用函数实参来推断模板实参**
     
     模板类型参数T可以看做内置类型说明符一样使用，比如模板函数中定义'T tmp;'
     
     **模板类型参数前必须使用关键字class或typename**，在模板参数列表中，typename和class没有什么不同
     
     模板非类型参数表示一个值而非一个类型，也就决定了模板实参必须是常量表达式
     
     模板的inline和constexpr指定均放在尖括号之后
     
     ```c++
     template <typename T> inline int func(){}
     ```
     
     
     
  2. 



* 

