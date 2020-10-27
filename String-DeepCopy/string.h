/**
 *   String类的深拷贝实现：
**/

#include <iostream>

class String {
    friend std::ostream& operator<<(std::ostream& out, String& s);
public:
    String(const char* );	// 提供默认初值的构造函数
    String(const String& s);	// 拷贝构造函数
    String& operator=(String s);    // 拷贝赋值构造函数
    void CheckCapacity(int count);  // 检查并分配内存
    void PushBack(char ch); // 尾插
    void Insert(size_t pos, const String&s, size_t SubPos, size_t Len);    // 在指定下标处插入指定长度的字符串对象
    inline void Insert(size_t pos, char ch);    // 在指定下标处插入字符
    String SubStr(size_t pos, size_t len);	// 从指定下标处截取指定长度的字符串
    void Insert(size_t pos, const char* str);   // 插入指定字符串
    void Erase(size_t pos, size_t len); // 删除指定长度字符串
    int Find(char ch);	// 找到首次出现 ch 的下标，返回该下标
    int Find(char* str);
    char& operator[](const size_t a);   // 重载[]
    inline void Swap(String& s);   // 交换对象
    ~String();

private:
    char* _str;
    size_t _size;	// _size 的实现上，_size 等值于 strlen(_str)
    size_t _capacity;	// 开辟的内存空间（尚未初始化的内存）
};
