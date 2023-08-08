# 新的开始。

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

### 11, c++多态

多态的字面意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承管关联的时候就会用到多态。c++多态以为这它会根据成员函数的对象不同，而调用不懂函数。 其实就是子类重写父类，父类对于需要重写的函数设置为虚函数。

```
第一种是 virtual int funtion();
第二种是 virtual int funtion() = 0;
第二种是纯虚函数。第一种子类是可以不用重写父类的，但是第二种子类必须重新父类。
```

### 12，数据抽象。

指的是只向外交提供关键信息，并隐藏其后台细节，只能变现必要的信息，而不呈现细节。