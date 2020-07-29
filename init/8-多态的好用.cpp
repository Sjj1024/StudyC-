#include <iostream>
using namespace std;


// 体验多台带来的好处: 体现了开闭原则，就是拓展开放，修改关闭的原则
class Calculate{
    // 创建的计算器类
public:
    int c_num1 =0 ;
    int c_num2 = 0;

public:
    // 创建一个虚函数用于让子类继承
    virtual int getResult(){
        return 0;
    }
};

// 创建一个加法类
class addCalcute: public Calculate {
    // 重写父类的加法运算
    int getResult(){
        //std::cout << "执行加法运算的结果是：" << this->c_num1 + this->c_num2 << endl;
        return this->c_num1 + this->c_num2;
    }
};


// 创建一个减法类
class delCalcute: public Calculate {
    // 重写父类的加法运算
    int getResult(){
        //std::cout << "执行加法运算的结果是：" << this->c_num1 + this->c_num2 << endl;
        return this->c_num1 - this->c_num2;
    }
};

// 创建一个测试类
void test1(){

    // 创建一个加法对象,使用父类指针指向子类对象的方法实现多态
    Calculate * add1 = new addCalcute;
    add1->c_num1 = 11;
    add1->c_num2 = 22;
    int res = add1->getResult();
    std::cout << "执行加法运算的结果是：" << res << endl;
    delete add1;

    add1 = new delCalcute;
    add1->c_num1 = 50;
    add1->c_num2 = 10;
    res = add1->getResult();
    std::cout << "执行减法运算的结果是：" << res << endl;
    delete add1;

}

int main(){

    test1();

    return 0;
}
