/**
 *   String类的深拷贝实现：
**/

#include "string.h"
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

String::String(const char* str = "")    // 默认初值的构造函数
    : _str(new char[strlen(str)+1]) 
    , _size(strlen(str))
    , _capacity(strlen(str))
{
    strcpy(_str, str);
}
String::String(const String& s) // 拷贝构造函数
{
    String tmp(s._str);
    this->Swap(tmp);
}
String& String::operator=(String s)    // 拷贝赋值构造函数
{
    this->Swap(s);
    return *this;
}
void String::CheckCapacity(int count)  // 检查并分配内存
{
    size_t len = _size + count;
    if(len > _capacity) {
        char* tmp = (char*)realloc(_str, len+1);    // 多出一位放'\0'
        if(tmp != nullptr)
        {
            _str = tmp;
        }
        else 
        {
            cout << "开辟空间失败！" <<endl;
            exit(1);
        }
        _capacity = len;
    }
}
void String::PushBack(char ch) // 尾插
{
    CheckCapacity(5);
    _str[_size] = ch;
    _str[_size+1] = '\0';
    ++_size;
}
void String::Insert(size_t pos, const String&s, size_t SubPos, size_t Len)    // 在指定位置插入指定长度的字符串对象
{
    assert( pos<=_size && SubPos<s._size );
    while(Len-- > 0)
    {
        Insert(pos++, s._str[SubPos++]);
    }
}
inline void String::Insert(size_t pos, char ch)    // 插入字符
{
    assert( pos <= _size );
    CheckCapacity(5);
    size_t end = _size;
    while(end >= pos) 
    {
        _str[ end+1 ] = _str[ end ];
        --end;
    }
    _str[pos] = ch;
    ++_capacity;
}
String String::SubStr(size_t pos, size_t len)
{
    assert(pos<_size);
    size_t count = len;
    if(pos + len >= _size) 
    {
        count = _size-pos;
    }
    String sub;
    sub.CheckCapacity(count);
    char* dst = sub._str;
    char* src = _str+pos;
    for(int i=0; i<count; i++)
    {
        *dst++ = *src++;
    }
    *dst = '\0';
    sub._size = count;
    return sub;
}
void String::Insert(size_t pos, const char* str)   // 插入指定字符串
{
    assert(pos <= _size);
    int len = strlen(str);
    CheckCapacity( _size+len );
    int end = _size;
    while(end >= (int)pos)
    {
        _str[end + len] = _str[end];
        --end;
    }
    int i = 0;
    while(i < len) 
    {
        _str[pos+i] = str[i];
        ++i;
    }
    _size += len;
}
void String::Erase(size_t pos, size_t len) // 删除指定长度字符串
{
    assert(pos < _size);
    if((pos+len) >= _size)
    {
        _size = pos;
        _str[_size] = '\0';
    }
    else
    {
        for(auto i = pos+len; i <= _size; i++)
        {
            _str[i-len] = _str[i];
        }
        _size -= len;
    }
    
}
int String::Find(char ch)   // 返回第一次出现该字符的下标
{
    int i = 0, end = _size;
    while(i < end) 
    {
        if(_str[i] == ch)
            return i;
    }
    return -1;
}
int String::Find(char* str) // 返回第一次出现该子串的首字母下标
{
    int i=0, end=_size, len=strlen(str);
    while(i < end-len) 
    {
        int j=0;
        for( ; j<len; j++)
        {
            if(_str[i+j] != str[j])
                break;
        }
        if(j == len)
            return i;
        ++i;
    }
    return -1;
}
char& String::operator[](const size_t a)   // 重载[]
{
    if(a<0 || a>_size) 
    {
        cout << "下标有误" <<endl;
        exit(1);
    }
    return _str[a];
}
inline void String::Swap(String& s)   // 交换对象
{
    std::swap(_str, s._str);
    std::swap(_size, s._size);
    std::swap(_capacity, s._capacity);
}
String::~String()
{
    delete[] _str;
    _str = nullptr;
    _size = _capacity = 0;
}

ostream& operator<<(ostream& out, String& s)
{
    out << s._str;
    return out;
}
