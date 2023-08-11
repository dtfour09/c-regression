# c/c++ 其他判断

### 1，宏定义方面

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

