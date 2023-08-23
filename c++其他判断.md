# c/c++ 其他判断

### 宏定义方面

在c/c++ 中可以判断当前操作系统来预处理不必要的代码。

```
    #ifdef _WIN32
    std::cout << "Windows\n";
    #elif __linux__
    std::cout << "Linux\n";
    #elif __APPLE__
    std::cout << "Apple\n";
    #endif
```



------------------

待删除

a文件  copy到b文件夹

读b文件夹内文件夹名称

判断是否合法

合法copy

不合法     （时间 n方）。

### vs studio 2019方面

##### 动态库的引用

动态库的引用需要在项目属性

1，添加调试环境。

2，在链接器常规添加附加目录，在连接器输入添加lib库。