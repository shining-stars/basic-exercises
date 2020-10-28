/**
 *  引用辅助类的方法，实现类似shared_ptr的效果
**/


#include <iostream> 
using namespace std;

class Point //基础对象类
{
public:
    Point(int xVal = 0, int yVal = 0):x(xVal),y(yVal) { }
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int xVal) { x = xVal; }
    void setY(int yVal) { y = yVal; }

private:
    int x,y;
};

class RefPtr    //辅助类
{   //该类成员访问权限全部为private，因为不想让用户直接使用该类
    friend class SmartPtr;  //定义智能指针类为友元，因为智能指针类需要直接操纵辅助类
    RefPtr(Point *ptr) : p(ptr), count(1) { cout << "count = 1" <<endl; }
    RefPtr(int x, int y) : p(new Point(x, y)), count(1) { cout << "count = 1" <<endl; }
    ~RefPtr() { delete p; }
    int count;  //引用计数
    Point *p;   //基础对象指针
};

class SmartPtr  //智能指针类
{
public:
    SmartPtr() = default;
    explicit SmartPtr(Point *ptr) : rp(new RefPtr(ptr)) { }    //构造函数（禁止隐式类型转换）
    SmartPtr(int x, int y) : rp(new RefPtr(x, y)) { }    //构造函数
    SmartPtr(const SmartPtr &sp) : rp(sp.rp) { ++rp->count; cout << "rp->count = " << rp->count <<endl; } //复制构造函数
    SmartPtr& operator=(const SmartPtr& rhs) {  //重载赋值操作符
        ++rhs.rp->count;    //首先将右操作数引用计数加1，
        cout << "rhs.rp->count = " << rhs.rp->count <<endl;
        cout << "rp->count = " << rp->count-1 <<endl;
        if(--rp->count == 0) {    //然后将引用计数减1，可以应对自赋值
            delete rp;
        }
        rp = rhs.rp;
        return *this;
    }
    static SmartPtr make_shared(int x, int y) {    // 动态内存分配函数
        SmartPtr ret(x, y);
        return ret;
    }
    ~SmartPtr() {   //析构函数
        cout << "rp->count = " << rp->count-1 <<endl;
        if(--rp->count == 0)    //当引用计数减为0时，删除辅助类对象指针，从而删除基础对象
            delete rp;
    }
private:
    RefPtr *rp; //辅助类对象指针
};

int main()
{
    // SmartPtr sp0 = new Point(10, 8);    // Error! 禁止隐式类型转换（不能把普通指针隐式转换为智能指针）
    // SmartPtr sp0(new Point(10, 8));  // 用 普通指针 初始化 智能指针
    SmartPtr sp1 = SmartPtr::make_shared(10, 8);
    SmartPtr sp2(sp1);
    SmartPtr sp3(new Point(5, 5));
    sp3 = sp1;
    return 0;
}
