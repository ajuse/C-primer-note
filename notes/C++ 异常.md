#### C++中异常处理包括：

* throw表达式
  异常检测部分使用throw表示引发异常；

  example：

  ```c++
  throw tuntime_error("Wrong msg.");
  ```

* try语句
  处理异常的程序代码，可以使用多个catch子句，一般异常问题会被其中之一处理；

  example：

  ```c++
  try {
  	statements
  } catch (exception-declaration) {
  	handler-statements
  }catch (exception-declaration) {
  	handler-statements
  } ...
      
  try {
      
  } catch (...) {
      
  }
  ```

  catch子句包括：关键字catch、括号内对象的声明（异常声明）、异常处理语句；

  try语句块中的语句为正常逻辑，并且**try中声明的变量在外部和catch子句内都无法使用**；

* 一套异常类
  用于在throw表达式和相关的catch子句之间传递异常的具体信息

#### 寻找处理代码的过程：

​	如果多个try嵌套时：

1. 首先在抛出异常的函数中搜索，如果没有找到匹配的catch，则终止该函数，并在调用该函数的函数中继续寻找；
2. 如果还是没有找到匹配的catch，这个新的函数也被终止，并继续搜索调用它的函数；依次类推直到找到为止；
3. 如果最终还是没找到匹配的catch，程序则会调用terminate标准库函数，一般来说该函数会导致程序正常退出；

 注意： 

1. 如果最终也没找到任何try定义的异常，则会调用terminate函数终止当前程序；

2. 对于那些异常终止的函数，也许上下文并没有执行完全，比如内存分配与释放，对象是否有效，状态等，
   由于异常终止而变得不可控，在编写异常代码的时候则要非常注意，往往这比较难；
3. 尽量不使用try嵌套；



#### 标准异常

1. exception头文件中的exception类，只报告异常的发生，不提供任何额外信息
2. stdexcept头文件定义了几种常用的类，比如runtime_error,range_error,invalid_argument,etc...
3. new头文件定义了bad_alloc异常类型
4. type_info头文件定义了bad_cast异常类型
5. 异常类型只定义了一个名为what的成员函数，没有任何参数，返回值是一个const char*的字符串提供文本信息；