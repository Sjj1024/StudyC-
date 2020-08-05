#include <iostream>
#include <vector>

using namespace std;

class Person {
public:
	string name;
	int age;

public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

};

// 定义存储自定义数据类型的数据
void test1() {
	// 创建一个容器存储自定义的数据
	vector<Person> v;

	// 创建几个不同的对象
	Person p1 = Person("王思聪", 34);
	Person p2 = Person("王健林", 35);
	Person p3 = Person("汪汪汪", 36);
	Person p4 = Person("刘荣", 37);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	// 遍历存储在容器中的内容
	for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
	{
		// 把i当做指针使用，解指针获取到的内容就是Person，使用对象就可以获取到内容
		cout << "姓名:" << (*i).name << "年龄:" << (*i).age << endl;
	}
}

// 创建一个存储对象指针的容器
void test2() {
	// 创建一个容器
	vector<Person *> vp;

	Person p1 = Person("王思聪", 34);
	Person p2 = Person("王健林", 35);
	Person p3 = Person("汪汪汪", 36);
	Person p4 = Person("刘荣", 37);

	vp.push_back(&p1);
	vp.push_back(&p2);
	vp.push_back(&p3);
	vp.push_back(&p4);

	// 遍历存储在容器中的内容
	for (vector<Person *>::iterator i = vp.begin(); i != vp.end(); i++)
	{
		// 把i当做指针使用，解指针获取到的内容就是Person *，然后使用指针箭头获取内容
		cout << "姓名:" << (*i)->name << "年龄:" << (*i)->age << endl;
	}
}


int main() {

	//test1();

	test2();

	return 0;

}
