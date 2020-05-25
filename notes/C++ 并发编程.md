头文件：include <thread>
启动一个线程example：

```
void func() {cout << "thread example code" << endl;}
int main() {
    std::thread td(func);
    td.join();
}
```

使用join()是为了防止线程在主程序结束之前还未执行，与c类似
使用C++线程库启动线程，可以归结为构造std::thread对象
使用一个能访问局部变量的函数去创建线程是一个糟糕的主意(除非十分确定线程会在函数完成前结束)