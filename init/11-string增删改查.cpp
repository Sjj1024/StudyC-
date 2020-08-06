#include <iostream>
#include <string>

using namespace std;

// 使用string容器操作字符串的增删改查替换
void stringtest() {
	string xing = "wang";

	string name = "sicong";

	string quan = xing + name;

	cout << quan << endl;

	// 判空操作和相等操作,获取长度
	if (quan.empty())
	{
		cout << "字符串是空的" << endl;
	}

	// 判断字符串是否相等
	if (xing == name)
	{
		cout << "两个字符串相等" << endl;
	}

	// 获取字符串长度
	cout << quan.size() << endl;

	// 截取子字符串
	string subname = quan.substr(5, 4);
	cout << "截取到的子字符串是:" << subname << endl;

	// 查找某个字符串的位置
	int post = quan.find("si");
	cout << "找到字符串位置:" << post << endl;

	// 从查找到的位置开始截取
	subname = quan.substr(post);
	cout << "截取到的结果是" << subname << endl;

}


int main() {

	stringtest();

	return 0;
}
