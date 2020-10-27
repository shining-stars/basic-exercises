/**
 *   String类的深拷贝实现：
**/

#include "string.h"
#include <iostream>
using namespace std;

int main() {
    String s1("aaaaaaaaaa");
	String s2("123456");
	s1[5] = 'b';     // 修改
	s1.PushBack('b');   // 尾插
	s1.Insert(1, "0123456", 1, 3);  // 将子串的下标1后3位，插入原串的下标1位置
	s2.Erase(0, 2);        // 删
	String tmp = s1.SubStr(2, 7);
    cout<< "查找子串 ‘345’ ：";
	int ret = s2.Find("345");
	if (ret == -1)
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "在下标[" <<ret<<"]处"<< endl;
	}
	cout << "s1  = " << s1 << endl;
	cout << "tmp = " << tmp << endl;
	cout << "s2  = " << s2 << endl;


    return 0;
}
