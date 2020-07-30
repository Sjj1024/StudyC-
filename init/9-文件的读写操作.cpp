#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 文件操作使用fstream流，创建一个流对象，然后打开文件，传递读写模式，然后写入内容，最后关闭文件
void testWrite() {
	// 创建一个输出流对象，用于写文件
	ofstream outfile;

	// 打开文件写入内容
	outfile.open("ceshi.txt", ios::out);

	outfile << "姓名:测试文件" << endl;
	outfile << "年龄:56" << endl;
	outfile << "老家:洛阳市" << endl;

	// 关闭文件
	outfile.close();
}

void testRead() {
	// 创建一个输入流对象，
	ifstream ifile;

	// 打开文件写入内容
	ifile.open("ceshi.txt");

	if (!ifile.is_open())
	{
		cout << "打开文件失败" << endl;
	}
	cout << "打开文件成功" << endl;
	// 读文件:
	// 第一种方式
	//char buf[1024] = { 0 };
	//while (ifile >> buf)
	//{
	//	cout << buf << endl;
	//}

	// 第二种方式
	string strContent;
	while (getline(ifile, strContent))
	{
		cout << strContent << endl;
	}

	// 关闭文件
	ifile.close();
}

int main() {
	// 测试文件读写案例
	//testWrite();

	// 测试文件读案例
	testRead();

	return 0;
}
