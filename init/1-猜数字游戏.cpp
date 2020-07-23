#include <iostream>

using namespace std;

int main() {

	cout << "项目2,猜数字游戏";

	int randnum = rand() % 100 + 1;
	cout << randnum << endl;

	randnum = rand() % 100 + 1;
	cout << randnum << endl;

	randnum = rand() % 100 + 1;
	cout << randnum << endl;

	int cai = 0;
	while (true)
	{
		cout << "请输入猜测的数字:" << endl;
		cin >> cai;
		if (cai == randnum)
		{
			cout << "恭喜你猜对了！";
			break;
		}
		else {
			if (cai > randnum)
			{
				cout << "猜的数字有点大！";
			}
			else if (cai < randnum)
			{
				cout << "猜的数字有点小！";
			}
		}
	}

}
