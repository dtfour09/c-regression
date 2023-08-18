# 新的开始。

说明以下，该记录是参考了不同大佬的讲解，仅作为个人笔记，图是偷的。

### 1，vs studio 使用c的时候发出了警告，导致程序无法运行。

需要在程序的开头加入宏命令

```c++
#define _CRT_SECURE_NO_WARNINGS
```

### 2，ctime 的使用。

第一种 gmtime

```
#include<ctime>
time_t now = time(0)   //基于当前的日期或者时间 1691457948 这里面得到的是自1970来的时间
char * dt = ctime(&now); //把now 转换为字符形式。 Tue Aug  8 09:25:48 2023 映射为字符

tm *gmtm = gmtime(&now); //获取tm类型
dt = asctime(gmtm);   //tm类型转换为字符串

//tm的结构
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
};

关于ctime库里面的函数描述
time_t time(time_t *time);

该函数返回系统的当前日历时间，自 1970 年 1 月 1 日以来经过的秒数。如果系统没有时间，则返回 -1。
struct tm *localtime(const time_t *time);

该函数返回一个指向表示本地时间的 tm 结构的指针。
clock_t clock(void);

该函数返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。如果时间不可用，则返回 -1。
char * asctime ( const struct tm * time );

该函数返回一个指向字符串的指针，字符串包含了 time 所指向结构中存储的信息，返回形式为：day month date hours:minutes:seconds year\n\0。

struct tm *gmtime(const time_t *time);
该函数返回一个指向 time 的指针，time 为 tm 结构，用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示。

double difftime ( time_t time2, time_t time1 );
该函数返回 time1 和 time2 之间相差的秒数。

size_t strftime();
该函数可用于格式化日期和时间为指定的格式。

time_t maktime(tm *);
将tm* 类型变成time_t类型方便difftime使用。
```

### 3，关于 -r的使用。

```
	for (int i = 1; i < 101; ++i)
	{
		cout << '\r';
		cout << i << "%";
	}
//  -r在里面会自动会到行首，会覆盖掉之前输出的内容。
```

### 4，auto和decltype自动推导类型

```
int x = 0; // 整型变量
decltype(x) x1; // 推导为int，x1是int
decltype(x)& x2 = x; // 推导为int，x2是int&，引用必须赋值
decltype(x)* x3; // 推导为int，x3是int*
decltype(&x) x4; // 推导为int*，x4是int*
decltype(&x)* x5; // 推导为int*，x5是int**
decltype(x2) x6 = x2; // 推导为int&，x6是int&，引用必须赋值
auto f = 3.14; //double
auto s("546123asdas"); // const char *
auto z = new auto(9); // int

```

### 5,储存方式

```
//register 
register int miles;
所以定义的变量是储存在寄存器当中而不是内存中的局部变量，但是这并不意味这被register定义的变量是被储存到了寄存器当中。而且不适用&；

//static
static void func();
static int num = 10;
定义静态成员被static所定义的变量只能在该文件内使用。

//extern
erxern 引用其他文件内已经定义的全局变量 或者 函数。

//mutable
用于引用常量，突破const的限制。
```

### 6 cmath的数学运算

```
1	double cos(double);
该函数返回弧度角（double 型）的余弦。
2	double sin(double);
该函数返回弧度角（double 型）的正弦。
3	double tan(double);
该函数返回弧度角（double 型）的正切。
4	double log(double);
该函数返回参数的自然对数。
5	double pow(double, double);
假设第一个参数为 x，第二个参数为 y，则该函数返回 x 的 y 次方。
6	double hypot(double, double);
该函数返回两个参数的平方总和的平方根，也就是说，参数为一个直角三角形的两个直角边，函数会返回斜边的长度。
7	double sqrt(double);
该函数返回参数的平方根。
8	int abs(int);
该函数返回整数的绝对值。
9	double fabs(double);
该函数返回任意一个浮点数的绝对值。
10	double floor(double);
该函数返回一个小于或等于传入参数的最大整数。
```

### 7,一个总是被遗忘的内容

```
输出字符串的首地址 %c 是第一个字符 %s是该字符及以后的字符。

保留n为有效数字。
在c++ 里面是
cout << fixed << setprecision(2) ;
c里面是
%.2
```

### 8，指针的一些问题。

```
可以使用 &来进行取地址，当然&也可以用来引用。
```

### 9，基本输入输出

```
iostream
iostream 提供了cin cout cerr clog的标准输入输出，非缓冲标准错误流和非缓冲标准错误流。

iomanip 提供了参数化的流操纵器 例如setw 和 setprecison

fstream 文件处理声名服务。

cerr
预定义的对象 cerr 是 iostream 类的一个实例。cerr 对象附属到标准输出设备，通常也是显示屏，但是 cerr 对象是非缓冲的，且每个流插入到 cerr 都会立即输出。

clog
预定义的对象 clog 是 iostream 类的一个实例。clog 对象附属到标准输出设备，通常也是显示屏，但是 clog 对象是缓冲的。这意味着每个流插入到 clog 都会先存储在缓冲区，直到缓冲填满或者缓冲区刷新时才会输出。

通过这些小实例，我们无法区分 cout、cerr 和 clog 的差异，但在编写和执行大型程序时，它们之间的差异就变得非常明显。所以良好的编程实践告诉我们，使用 cerr 流来显示错误消息，而其他的日志消息则使用 clog 流来输出。
```

### 10，文件和流

```
//头文件
#include<iostream>
#include<fstream>
void open(const char *filename, ios::openmode mode);
//写文件
ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc );
//读文件
ifstream  afile;
afile.open("file.dat", ios::out | ios::in );
void close(); 关闭文件流。
```

| 模式标志   | **描述**                                                     |
| ---------- | ------------------------------------------------------------ |
| ios::app   | 追加模式。所有写入都追加到文件末尾。                         |
| ios::ate   | 文件打开后定位到文件末尾。                                   |
| ios::in    | 打开文件用于读取。                                           |
| ios::out   | 打开文件用于写入。                                           |
| ios::trunc | 如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0 |

```
#include <fstream>
#include <iostream>
using namespace std;
int main ()
{
   char data[100];
   // 以写模式打开文件
   ofstream outfile;
   outfile.open("afile.dat");
   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);
   // 向文件写入用户输入的数据
   outfile << data << endl;
   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   // 再次向文件写入用户输入的数据
   outfile << data << endl;
   // 关闭打开的文件
   outfile.close();
   // 以读模式打开文件
   ifstream infile; 
   infile.open("afile.dat"); 
   cout << "Reading from the file" << endl; 
   infile >> data; 
   // 在屏幕上写入数据
   cout << data << endl;
   // 再次从文件读取数据，并显示它
   infile >> data; 
   cout << data << endl; 
   // 关闭打开的文件
   infile.close();
   return 0;
}
```

文件指针

```
// 定位到 fileObject 的第 n 个字节（假设是 ios::beg）
fileObject.seekg( n );
// 把文件的读指针从 fileObject 当前位置向后移 n 个字节
fileObject.seekg( n, ios::cur );
// 把文件的读指针从 fileObject 末尾往回移 n 个字节
fileObject.seekg( n, ios::end );
// 定位到 fileObject 的末尾
fileObject.seekg( 0, ios::end );
```

建议用下边的。心态有点炸了。记得if 和 out  if读 out写。

```
#define _CRT_SECURE_NO_WARNING_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char* filename = "data.txt";
void chuli(fstream& m_in)
{
	std::ifstream file(filename, std::ios::binary | std::ios::ate);
	streampos  fillsize = file.tellg();
	long long fillSizeLL = fillsize;
	int num = 0;
    cout << fillSizeLL << endl;
    char c;
    for (int i = fillSizeLL -1; i >= 0; i--)
    {
        file.seekg(i);
        file.get(c);
        cout << c ;
    }
    file.close();
}
int main() {
    fstream fileRead(filename, ios::in);
    fstream fileWrite(filename, ios::out | ios::app); // 追加模式
    if (!fileRead || !fileWrite) {
        cerr << "Failed to open file" << endl;
        return 1;
    }
	chuli(fileRead);
    // 写入新内容到文件末尾
    fileWrite << "New content" << endl;
    fileRead.close();
    fileWrite.close();
    return 0;
}
```

当然有时候一行会过大 就需要指定大小的缓冲区读取了。

```
inLogFile.open(file, ios::in);
unsigned long long blockSize = 16 * 1024 * 1024;//16MB
char *tempStr = new char[blockSize];
inLogFile.read(tempStr, blockSize);
cout <<" after read postion" << (long long)inLogFile.tellg() << endl;
```

文件写入后如果需要排序得要flush 以下。

但是flush之后也不一定可以立即写入。

这时候需要强制写入了mySt.myOutput.sync();

另外文件如果一直不关闭的话，光标的位置不是初始值。

关于光标读写都是如果需要移动到某个位置

```
seekg(0，ios::start)
但是有时候会移动不到需要借助
fstream：：clear（）
```



### 11, c++多态

多态的字面意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承管关联的时候就会用到多态。c++多态以为这它会根据成员函数的对象不同，而调用不懂函数。 其实就是子类重写父类，父类对于需要重写的函数设置为虚函数。

```
第一种是 virtual int funtion();
第二种是 virtual int funtion() = 0;
第二种是纯虚函数。第一种子类是可以不用重写父类的，但是第二种子类必须重新父类。
```

### 12，数据抽象。

指的是只向外交提供关键信息，并隐藏其后台细节，只能变现必要的信息，而不呈现细节。

### 13，异常处理

##### 什么是异常？

用官方的话来说就是程序在执行过程中产生的问题，换句通俗的话来讲就是程序执行的出现的异常，比如程序崩了、内存泄漏了、数组越界以及其他异常信息的出现

##### 关键字

c++里面是 try，catch，throw三个关键字。

```
try{

}cathch(ExceptionName e1){

}cathch(ExceptionName e2){

}cathch(ExceptionName eN){

}
```

如果try 块在不同的情境下会抛出不同的异常，需要罗列出来多catch语言，用于捕获不同的异常类型。

##### 抛出异常

您可以使用 **throw** 语句在代码块中的任何地方抛出异常。throw 语句的操作数可以是任意的表达式，表达式的结果的类型决定了抛出的异常的类型

```
throw "Division by zero condition";
```

##### 捕获异常

catch快跟在try快后面，用于捕获异常。可以指定想要捕获的异常类型，主要是由catch关键字后的括号内的异常声名决定的。

```
try{
	//保护代码
}catch(ExceptionName e)
{
	//处理 ExceptionName 的异常代码
}
```

上面会捕获一个类型为ExceptionName的异常。如果需要catch处理任意异常需要在在 catch（...）里面加入（...）省略号，三个点。

下方例子

```
double division(int a, int b)
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}
 
int main ()
{
   int x = 50;
   int y = 0;
   double z = 0;
 
   try {
     z = division(x, y);  //首先流程是进入division函数，但是y是0会抛出异常。
     cout << z << endl;
   }catch (const char* msg) {
     cerr << msg << endl;  //msg会接收被抛出的异常。
   }
 
   return 0;
}
```

##### c++的标准异常

c++的标准异常定义在了 “exception” 中，其结构如下所示

![](./图片/exceptions_in_cpp.png)

异常说明

| 异常                  | 描述                                                         |
| --------------------- | ------------------------------------------------------------ |
| std::exception        | 该异常是所有标准 C++ 异常的父类。                            |
| std::bad_alloc        | 该异常可以通过 **new** 抛出。                                |
| std::bad_cast         | 该异常可以通过 **dynamic_cast** 抛出。                       |
| std::bad_typeid       | 该异常可以通过 **typeid** 抛出。                             |
| std::bad_exception    | 这在处理 C++ 程序中无法预期的异常时非常有用。                |
| std::logic_error      | 理论上可以通过读取代码来检测到的异常。                       |
| std::domain_error     | 当使用了一个无效的数学域时，会抛出该异常。                   |
| std::invalid_argument | 当使用了无效的参数时，会抛出该异常。                         |
| std::length_error     | 当创建了太长的 std::string 时，会抛出该异常。                |
| std::out_of_range     | 该异常可以通过方法抛出，例如 std::vector 和 std::bitset<>::operator[]()。 |
| std::runtime_error    | 理论上不可以通过读取代码来检测到的异常。                     |
| std::overflow_error   | 当发生数学上溢时，会抛出该异常。                             |
| std::range_error      | 当尝试存储超出范围的值时，会抛出该异常。                     |
| std::underflow_error  | 当发生数学下溢时，会抛出该异常。                             |

##### 重新定义异常

```
#include <iostream>
#include <exception>
using namespace std;
 
struct MyException : public exception
{
  const char * what () const throw ()
  {
    return "C++ Exception";
  }
};
 
int main()
{
  try
  {
    throw MyException();
  }
  catch(MyException& e)
  {
    std::cout << "MyException caught" << std::endl;
    std::cout << e.what() << std::endl;
  }
  catch(std::exception& e)
  {
    //其他的错误
  }
}
```

### 14,c++类中自带的6种函数。

```
class A
{
public:
    A();//构造函数
    A(const A& a);//拷贝构造函数
    ~A();//析构函数
    A& operator=(const A& a);//赋值运算符重载
    A* operator &();//取地址运算符重载
    const A* operator &() const;//const修饰的取地址运算符重载
};
```

### 15，c++动态内存

栈：函数内部声名的所有变量都占用栈内存，static定义的除外，当然也可能有其他例子。

堆：程序中未使用的内存，在程序运行时用于动态分配的内存。

```
new data—type
```

data-type 可以是包括数组在内的任意内置数据类型，也可以是包括类或者结构体在内的用户自定义的任何数据类型。

！！指针不用的时候一定要先delete后，置空。 c++ 11后边是nullptr

注意一点 不要在析构函数里面自己delete自己，不然会导致无穷递归。

delete本质上是调用析构函数 + 其他。

如果是非数组类型 delete是   ->  delete  数组类型 delete []

下面是指向一个三维数组的指针

```
#include <iostream>
using namespace std;
int main()
{   
    int i,j,k;   // p[2][3][4]
    int ***p;
    p = new int **[2]; 
    for(i=0; i<2; i++) 
    { 
        p[i]=new int *[3]; 
        for(j=0; j<3; j++) 
            p[i][j]=new int[4]; 
    }
    //输出 p[i][j][k] 三维数据
    for(i=0; i<2; i++)   
    {
        for(j=0; j<3; j++)   
        { 
            for(k=0;k<4;k++)
            { 
                p[i][j][k]=i+j+k;
                cout<<p[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }   
    // 释放内存
    for(i=0; i<2; i++) 
    {
        for(j=0; j<3; j++) 
        {   
            delete [] p[i][j];   
        }   
    }       
    for(i=0; i<2; i++)   
    {       
        delete [] p[i];   
    }   
    delete [] p;  
    return 0;
}
```

### 16，命名空间

一开始以为是类或者结构体里面套用了static

声名需要使用namespace 关键字。以下是一个声名的样例。

```
namespace namespace_name{
 	//代码声名
}
//调用
name::code //code 可以是变量或者函数
```

##### using指令

如果使用了using 关键字后就不需要name::

```
//例如在没有声名 using namespace std 之前
std::cin  std::cout ...
//在声名了 using namespace std;之后
cin  cout ...

```

##### 其他

命名空间也可以套娃。奇怪的套娃。

### 17，模板

##### 函数模板

泛型编程的基础。stl 库里面的泛型编程不少，定义如下：

```
template <typename type> ret-type func-name(parameter list)
{
   // 函数的主体
}
//样例
template <typename T>
inline T const& Max (T const& a, T const& b) 
{ 
    return a < b ? b:a; 
}
```

##### 类模板

除了定义和函数模板有出入外，其他无太大的差别。

```
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
 
using namespace std;
 
template <class T>
class Stack { 
  private: 
    vector<T> elems;     // 元素 
 
  public: 
    void push(T const&);  // 入栈
    void pop();               // 出栈
    T top() const;            // 返回栈顶元素
    bool empty() const{       // 如果为空则返回真。
        return elems.empty(); 
    } 
}; 
 
template <class T>
void Stack<T>::push (T const& elem) 
{ 
    // 追加传入元素的副本
    elems.push_back(elem);    
} 
 
template <class T>
void Stack<T>::pop () 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
    // 删除最后一个元素
    elems.pop_back();         
} 
 
template <class T>
T Stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
    // 返回最后一个元素的副本 
    return elems.back();      
} 
 
//调用
Stack<int> myStack;
```

##### 坑点

该错误描述为：无法解析的外部符号。我们再回顾下上面说过的，本项目一共有两个编译单元，一个是main，一个是function，而编译过程是每个编译单元单独编译过后再交给连接器进行连接的，也就是说在连接器之前两个编译单元就已经进行了编译，而在主函数main里面调用外部编译单元时，由于另外一个编译单元function在编译时模板类没有被调用而没有得到具现化，从而导致了连接器在函数主函数里调用了模板类函数，但是找不到具体的实现方法的情况，从到就出现了开头的错误：LNK2019 无法解析的外部符号。

知道了错误的根源，我们就可以根治这种情况，总得来说就是模板类没有具现化，那我们就让它具现化就好了，所以总结了以下几个解决方案也得到了很好的解析：

1.在主函数包含头文件时将实现模板类的函数也包含进来。原因：一个编译单元内包含了.cpp文件以及被include 的头文件，如果将实现模板类的函数文件.cpp也包含进来，那么主函数调用就给了模板类函数一个具现化的机会。

2.将模板类的实现方法写在头文件里面。原因：同上，将实现写在头文件里面，那么主函数调用就给了模板类函数一个具现化的机会。

3.在实现模板类的文件中调用一下模板类。原因：调用一下让模板类函数得到具现化。

### 18，预处理

最常见的有以下

```
#define 
#ifdef
#if
#endif
#else
#elif
#undef
```

以下是是c++里面定义了的宏。 大概是用来解决日志用的。出错用的。

| 宏       | 描述                                                         |
| -------- | ------------------------------------------------------------ |
| __LINE__ | 这会在程序编译时包含当前行号。                               |
| __FILE__ | 这会在程序编译时包含当前文件名。                             |
| __DATE__ | 这会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。 |
| __TIME__ | 这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。 |

说一下 # 和 ## 的作用

“#” 在起到了引号的作用。

”##“ 在c++ 里面起到粘合的作用。

```
#include <iostream>
using namespace std;

#define MKSTR( x ) #x
#define concat(a, b) a ## b

int main()
{
   int xy = 100;
   cout << MKSTR(HELLO C++) << endl;
   cout << concat(x, y);
   return 0;
}
```

### 19，信号处理

介绍：信号是有操作系统传给进程中断的，会提早终止一个程序。在unix，Linux，Mac OS X 或者windows系统上，可以通过ctral + c产生中断。

有写信号是不能被程序捕获的，但是下表所列的信号可以在程序中捕获，并可以基于信号采取适当的动作。这些信号是定义在c++头文件 <csignal>中。

| 信号    | 描述                                         |
| ------- | -------------------------------------------- |
| SIGABRT | 程序的异常终止，如调用 **abort**。           |
| SIGFPE  | 错误的算术运算，比如除以零或导致溢出的操作。 |
| SIGILL  | 检测非法指令。                               |
| SIGINT  | 程序终止(interrupt)信号。                    |
| SIGSEGV | 非法访问内存。                               |
| SIGTERM | 发送到程序的终止请求。                       |

##### signal() 函数

c++ 信号处理库提供了signal函数，用于捕获突发时间。以下是signal（）函数的语法：

```
void (*signal (int sig, void (*func)(int)))(int); 

signal(registered signal, signal handler)
```

这个函数接受两个参数：

第一个参数是要设置的信号的标识符，

第二个参数是指向信号处理函数的指针。

函数返回值是一个指向先前信号处理函数的指针。如果先前没有设置信号处理函数，则返回为SIG_DFL。如果先前的信号处理函数为SIG_IGN， 则返回值为SIG_LGN。

以下是使用signal()函数捕获SIGINT信号。

```
#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;
void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";
    // 清理并关闭
    // 终止程序  
   exit(signum);  
}
int main ()
{
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);  
 
    while(1){
       cout << "Going to sleep...." << endl;
       sleep(1);
    }
    return 0;
}
```

当然也可以通过raise（）函数发送

int raise(signal sig);

如果有机会的话尽量看下 Qt::object里面的信号的机制是如何实现的。

object(&,SIGNAL,&,SLOT);

如果能够实现一个方便函数回调，确实舒服啊。 /dog。

### 20，C++多线程

##### 介绍

c++11 提供了语言层次上的多线程，包含在头文件<thread>里面了。解决了跨平台的问题，提供了管理线程，保护共享数据，线程间的同步操作，原子操作等。c++ 11 新标准引入了5给头文件来支持多线程，如下所示：

![](.\图片\01.png)

##### 多线程与多进程

###### 多进程并发

多进程并发是将一个应用程序划分为多个独立的进程（每个进程只有一个线程），这些独立的进程间可以互相通信，共同完成任务。由于操作系统对于进程提供了大量的保护机制，以免一个进程修改另一个进程的数据，使用多进程比使用多线程更容易写出相对安全的代码。但是也造成就了多进程并发的两个缺点：

1，在进程间的通信，无论是使用信号，套接字，还是文件，管道等方式，七十一要么比较复杂，要么就是速度较慢或者两者都有。

2，运行多个进程的时候开销很大，操作系统要分配更多的资源来对这些进程进行管理。

当多个进程的并发完成同一个任务时，不可避免的是：操作同一个数据的时候进程间的相互通信，上述的缺点就有了。

###### 多线程并发

指的是在一个进程中执行多个线程。

有点：线程是更轻量级的进程，美国线程可以独立的运行不同的指令序列，共享进程资源。

缺点：缺少操作系统提供的保护机制，在多线程共享数据通信的时候，容易卡死，这需要自己多做。

###### 多线程

在单核cpu中，多线程其实是切换时间轮片。

多核cpu中才能真正的做到。

###### 创建线程

形式1

```
std::thread myThread(thread_fun)
// void thread_fun()
myThread.join();
```

形式2

```
std::thrad myThrad(thrad_fun(100))
myThread.join()
//void thrad_fun(int x)
```

形式3

```
std::thrad(thread_fun,1).detach();
//直接创建线程，没有名字
//函数形象 void thread_fun(int x);
```

在跨平台开发的时候 g++ test.cc -o test -l pthread

###### join和detach

当线程启动后，一定要在和线程相关联的thread销毁前，确定以何种方式得带线程结束。

detach方式，启动的线程自主在后台运行，当前的代码继续往下指向，不等待新线程结束。

join方式，等待启动的线程完成，才会继续往下执行。

可以使用joinable判断是join模式还是detach模式。

```
if(myThread.joinable()) foo.join();
```

###### this_thread

this_thrad是一个类有以下4个功能

| 函数        | 使用                                                  | 说明                       |
| ----------- | ----------------------------------------------------- | -------------------------- |
| get_id      | std::this_thread::get_id()                            | std::this_thread::get_id() |
| yield       | std::this_thread::yield()                             | 放弃线程执行，回到就绪状态 |
| sleep_for   | std::this_thread::sleep_for(std::chrono::seconds(1)); | 暂停1秒                    |
| sleep_until | 如下                                                  | 一分钟后执行吗，如下       |

使用如下

```
using std::chrono::system_clock;
std::time_t tt = system_clock::to_time_t(system_clock::now());
struct std::tm * ptm = std::localtime(&tt);
cout << "Waiting for the next minute to begin...\n";
++ptm->tm_min; //加一分钟
ptm->tm_sec = 0; //秒数设置为0//暂停执行，到下一整分执行
this_thread::sleep_until(system_clock::from_time_t(mktime(ptm)));
```

##### mutex

mutex头文件主要生命了与胡扯了mutex相关的类。mutex提供了4种互斥类型，如下表所示。

| 类型                       | 说明                |
| -------------------------- | ------------------- |
| std::mutex                 | 最基本的 Mutex 类。 |
| std::recursive_mutex       | 递归 Mutex 类。     |
| std::time_mutex            | 定时 Mutex 类。     |
| std::recursive_timed_mutex | 定时递归 Mutex 类。 |

std::mutex 是c++ 11中最基本的互斥量，std：：mutex对象提供了独占所有权的特性------即不支持递归地对 std::mutex 对象上锁，而 std::recursive_lock 则可以递归地对互斥量对象上锁。

###### lock 与 unlock

mutex常用操作：

lock（）：资源上锁。

unlock（）：解锁资源。

trylock（）：查看是否上锁，他有下列3中情况：

（1）未上锁返回false，并锁住；

（2）其他线程已经上锁，返回true；

（3）同一个线程已经对它上锁，将会产生死锁。

死锁：死锁是指两个或两个以上的进程在执行过程中，由于竞争资源或者由于彼此通信而造成的一种阻塞现象，若无外力作用，他们将会无法推进下去。此时称系统处于死锁状态或系统产生了死锁，这些永远互相等待的进程被称为死锁。

下面是mutex变量上锁之后，一段时间内，只允许一个线程访问它。

```
#include <iostream>  // std::cout
#include <thread>  // std::thread
#include <mutex>  // std::mutex

std::mutex mtx;  // mutex for critical section
void print_block (int n, char c) 
{
// critical section (exclusive access to std::cout signaled by locking mtx):
    mtx.lock();
    for (int i=0; i<n; ++i) 
    {
       std::cout << c; 
    }
    std::cout << '\n';
    mtx.unlock();
}
int main ()
{
    std::thread th1 (print_block,50,'');//线程1：打印*
    std::thread th2 (print_block,50,'$');//线程2：打印$

    th1.join();
    th2.join();
    return 0;
}
**************************************************
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
```

当程序不涉及资源竞争的情况下，程序会打印的结果可能会交替出现。例如：

```
***********/////////*/*/*/*/*/////////////*
```

###### lock_guard

创建lock_guard对象时，它将尝试获取提供给他的互斥锁的所有权。当控制流离开lock_guard对象的作用域时，lock_guard析构并释放互斥量。lock_guard的特点：

创建即加锁，作用域结束后自动析构并解锁，无需手工解锁。

不能中途解锁，必须等到作用域结束才能解锁。

不能复制。

```
const std::lock_guard<std::mutex> lock(g_i_mutex);
```

###### unique_lock

简单的讲，unique_lock是unique_guard的升级加强版，它具有lock_guard 的所有功能，同时有具有其他很多方法，使用起来更加的灵活方便，能够硬度更复杂的锁定需要。unique_lock的特点：

1，创建时候可以不锁定，默认是锁定的，需要指定第二个参数为（std::defer_lock）,而在需要时再锁定。

2，可以随时加锁解锁。

3，作用域同lock_grard,析构时自动释放锁。

4，不可复制，看移动。

5，添加变量需要该类型的锁作为参数。

所有 lock_guard 能够做到的事情，都可以使用 unique_lock 做到，反之则不然。那么何时使lock_guard呢？很简单，需要使用锁的时候，首先考虑使用 lock_guard，因为lock_guard是最简单的锁。

样例如下：

```
#include <mutex>
#include <thread>
#include <iostream>
struct Box {
    explicit Box(int num) : num_things{num} {}
    int num_things;
    std::mutex m;
};
void transfer(Box &from, Box &to, int num)
{
    // defer_lock表示暂时unlock，默认自动加锁
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);//两个同时加锁
    std::lock(lock1, lock2);//或者使用lock1.lock()

    from.num_things -= num;
    to.num_things += num;//作用域结束自动解锁,也可以使用lock1.unlock()手动解锁
}
int main()
{
    Box acc1(100);
    Box acc2(50);

    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

    t1.join();
    t2.join();
    std::cout << "acc1 num_things: " << acc1.num_things << std::endl;
    std::cout << "acc2 num_things: " << acc2.num_things << std::endl;
}
```

##### condition_variable

condition_variable头文件头两个variable类，一个是condition_variable另一个是condition_variable_any。condition_variable必须结合unique_lock使用。

condition_variable_any可以任意使用任何的锁。下面以condition_variable为例进行介绍。

condition_variable条件变量可以阻塞(wait,wait_for,wait_until)调用的线程直到使用（notify_one或notify_all）通知恢复为止。condition_variable是一个类，这个类即有构造函数也有析构函数，使用时需要构造对于的condition_variable对象,调用对象相应的函数实现上面的功能。

| 类型               | 说明                                         |
| ------------------ | -------------------------------------------- |
| condition_variable | 构建对象                                     |
| 析构               | 删除                                         |
| wait               | wait until notified                          |
| wait_for           | wait for timeout or until notified           |
| wait_until         | wait until notified or time point            |
| notify_one         | 解锁一个线程，如果有多个，则位置那个线程执行 |
| notify_all         | 解锁所有线程                                 |
| cv_status          | 这是一个类，便是variable的状态,如下所示      |

```
enum class cv_status{no_timeout,timeout};
```

###### wait

当前线程调用wait（）后将被阻塞（此时当前线程应该获得了锁（mutex），不妨设获得锁lck），知道另外某个线程调用notify_* 唤醒当前线程。在线程被阻塞时，该函数会自动调用lck.unlock（）释放锁，使得其他被阻塞在锁竞争上的线程得以继续执行。另外一旦当前线程获取通知（notified,通常是另外某线程调用notify__*  唤醒了当前线程），wait()函数也是自动调用了lck.lock()，使得lckd的状态和wait函数被调用时相同。代码示例：

```
#include <iostream>           // std::cout
#include <thread>             // std::thread, std::this_thread::yield
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex mtx;
std::condition_variable cv;
int cargo = 0;
bool shipment_available() 
{
    return cargo!=0;
}
void consume (int n) 
{
    for (int i=0; i<n; ++i) 
    {
        std::unique_lock<std::mutex> lck(mtx);//自动上锁
        //第二个参数为false才阻塞（wait），阻塞完即unlock，给其它线程资源
        cv.wait(lck,shipment_available);// consume:
        std::cout << cargo << '\n';
        cargo=0;
    }
}
int main ()
{
    std::thread consumer_thread (consume,10);
    for (int i=0; i<10; ++i) 
    {
        //每次cargo每次为0才运行。
        while (shipment_available())  std::this_thread::yield();
        std::unique_lock<std::mutex> lck(mtx);
        cargo = i+1;
        cv.notify_one();
    }

    consumer_thread.join();
    return 0;
}
```

说明：

1. 主线程中的while，每次在cargo=0才运行。
2. 每次cargo被置为0，会通知子线程unblock(非阻塞)，也就是子线程可以继续往下执行。
3. 子线程中cargo被置为0后，wait又一次启动等待。也就是说shipment_available为false，则等待。

###### wait_for

与std::condition_variable::wait()类似，不过wait_for 可以指定一个时间段，在当前线程收到通知或者指定的时间rel_time超时之前，该线程都会处于阻塞zhuangt。而一旦超市或者收到了其他线程的通知，wait_for返回，剩下的处理步骤和wait（）类似。

```
template <class Rep, class Period>
  cv_status wait_for (unique_lock<mutex>& lck,
                      const chrono::duration<Rep,Period>& rel_time);
```

另外，wait_for的重载版本的最后一个参数pred表示 wait_for的预测条件，只有当pred添加为false时调用wait（）才会阻塞当前的线程，并且在收到其他线程的通知后只有当pred为true时才会被解除阻塞。

```
template <class Rep, class Period, class Predicate>
    bool wait_for (unique_lock<mutex>& lck,
         const chrono::duration<Rep,Period>& rel_time, Predicate pred);
```

另外，wait_for的重载版本的最后一个参数pred表示wait_for的预测条件，只有当pred条件为false时调用wait()才会阻塞当前线程，并且在收到其他线程的通知后只有当pred为true时才会被解除阻塞。

```
template <class Rep, class Period, class Predicate>
    bool wait_for (unique_lock<mutex>& lck,
         const chrono::duration<Rep,Period>& rel_time, Predicate pred);
```

代码示例：

```
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <chrono>             // std::chrono::seconds
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable, std::cv_status

std::condition_variable cv;
int value;
void read_value() 
{
    std::cin >> value;
    cv.notify_one();
}
int main ()
{
    std::cout << "Please, enter an integer (I'll be printing dots): \n";
    std::thread th (read_value);
  
    std::mutex mtx;
    std::unique_lock<std::mutex> lck(mtx);
    while (cv.wait_for(lck,std::chrono::seconds(1))==std::cv_status::timeout) 
    {
        std::cout << '.' << std::endl;
    }
    std::cout << "You entered: " << value << '\n';

    th.join();
    return 0;
}
```

- 通知或者超时都会解锁，所以主线程会一直打印。

- 示例中只要过去一秒，就会不断的打印。

  ##### 线程池

  将不会在此篇记录里面出现，将会放到c++线程池里面，单独做一篇讲述。

  ##### 概念

  在一个程序中，如果我们需要多次使用线程，这意味着需要多次创建和销毁线程。而创建并销毁线程的过程中势必会消耗内存，线程过多会带来调动的开销，进而影响缓存局部性和整体性能。

  线程的创建并销毁有以下一些缺点：

  创建太多线程，将会浪费一定的资源，有些线程未被充分使用。

  销毁太多线程，将会导致之后浪费时间在次创建它们。

  创建线程太慢，将会导致长时间的等待，性能变差。

  销毁线程太慢，导致其他线程资源饥饿。

  线程池维护着多个线程，这避免了在处理短时间任务时，创建与销毁的代价。

  ###### 线程池的实现

  因为程序便运行边创建线程时比较耗时的，所以我们通过池化的思想：在线程开始运行前创建多个线程，这样，在程序运行时，只需要从线程池拿来用就可以了，大大提高了程序的运行速率，一般线程池都有以下几个部分：

  1，线程池管理器：用于创建并管理线程池，线程池类。

  2，工作现在。

  3，任务队列。

  4，添加到任务队列里面的接口

### 21，c++ STL

前面有说过模板库的概念。c++ STL（标准模板库）是一套功能强大的c++模板类，提供了常用的算法和数据，如向量，队列，链表，栈。

| 组件                | 描述                                                         |
| ------------------- | ------------------------------------------------------------ |
| 容器（Containers）  | 容器是用来管理某一类对象的集合。C++ 提供了各种不同类型的容器，比如 deque、list、vector、map 等。 |
| 算法（Algorithms）  | 算法作用于容器。它们提供了执行各种操作的方式，包括对容器内容执行初始化、排序、搜索和转换等操作。 |
| 迭代器（iterators） | 迭代器用于遍历对象集合的元素。这些集合可能是容器，也可能是容器的子集。 |

```
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
   // 创建一个向量存储 int
   vector<int> vec; 
   int i;
   // 显示 vec 的原始大小
   cout << "vector size = " << vec.size() << endl;
   // 推入 5 个值到向量中
   for(i = 0; i < 5; i++){
      vec.push_back(i);
   }
   // 显示 vec 扩展后的大小
   cout << "extended vector size = " << vec.size() << endl;
   // 访问向量中的 5 个值
   for(i = 0; i < 5; i++){
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }
   // 使用迭代器 iterator 访问值
   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }
   return 0;
}
```

### 22，c++标准库

分为了两种：

##### 标准函数库

输入/输出  i/o

字符串和字符处理

数学

时间,日期和本地化

动态分配

其他

宽字符函数库

##### 面向对象库

标准c++ i/o

String类

数值类

STL容器类

STL算法

STL函数对象

STL迭代器

STL分配器

本地化库

异常处理库

杂项支持库



记录下需要复习的 GDB ，G++ ，makefile，vim，（c++ 11其他特性），模板类，容器类，数据结构类，内存池，i/o重载。c++这边其实并未完工，只是最近在学信号工程的一些基础知识。emmp。

