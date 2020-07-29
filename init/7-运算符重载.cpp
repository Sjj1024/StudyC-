#include <iostream>
#include <string>

using namespace std;
//ostream& print = cout;

class Per1 {

public:
	string name;
	int age;
public:
	Per1() {

	}

	Per1(string n, int a) {
		this->name = n;
		this->age = a;
	}

	// 局部运算符重载
	//Per1 operator+(Per1 p1) {
	//	cout << "函数运算符重载执行了";
	//	Per1 temp;
	//	temp.name = this->name + p1.name;
	//	temp.age = this->age + p1.age;
	//	return temp;
	//}

	// 重载比较运算符是否重载
	bool operator==(Per1 p) {
		if (this->name == p.name && this->age == p.age)
		{
			return true;
		}
		return false;
	}

};

// 全局加号运算符重载
Per1 operator+(Per1 p1, Per1 p2) {
	cout << "函数运算符重载执行了" << endl;
	Per1 temp;
	temp.name = p1.name + p2.name;
	temp.age = p1.age + p2.age;
	return temp;
}

// 全局左移运算符重载:用于实现打印输出自定义数据类型,一般都会使用全局的左移运算符重载操作
// ostream&表示输出流引用，当后续还想追加别的输出，就需要使用链式编程，所以需要返回cout的引用
ostream& operator<<(ostream &cout, Per1 p) {
	cout << p.name << p.age << endl;
	return cout;
}

class MyInteger {
public:
	int score;

public:
	
};

// 前置递增和后置递增重载操作

//使用全局重载定义自定义输出类型
ostream& operator<<(ostream& cout, MyInteger &mi) {
	cout << mi.score;
	return cout;
}

void test01() {
	// 测试运算符重载：是否相等

}


int main() {

	Per1 per1("王健林", 45);

	Per1 per2("王健林", 45);

	Per1 per3 = per1 + per2;

	//cout << per3.name << per3.age;

	//cout << per3 << endl;

	if (per1 == per2)
	{
		cout << "per1 和 per2 是相等的";
	}
	else {
		cout << "per1 和 per2 不相等";
	}
}
