#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

// 打印容器的内容
void printDeque(deque<int> de) {
	cout << "输出容器中的内容是:" << endl;
	for (deque<int>::iterator i = de.begin(); i != de.end(); i++)
	{
		cout << *i << " ";
	}

}


// deque容器类似于vector容器，但是deque容器支持双端插入和删除元素，
void testdeque() {

	deque<int> denum;

	for (int i = 0; i < 10; i++)
	{
		// 向后端加入元素
		denum.push_back(i);
	}

	for (int i = 0; i < 5; i++)
	{
		// 向容器前端加入元素
		denum.push_front(i);
	}

	printDeque(denum);

	// 返回容器中第一个位置上的元素
	int first = denum.front();
	cout << "deque中第一个元素是：" << first << endl;

	// 获取最后一个元素是back
	int ends = denum.back();
	cout << "最后一个元素是:" << ends << endl;

	// 使用sort算法对元素进行排序操作
	sort(denum.begin(), denum.end());

	// 排序后再进行输出
	printDeque(denum);

}


int main() {

	testdeque();
	return 0;
}
