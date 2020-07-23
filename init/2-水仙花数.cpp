#include <iostream>

using namespace std;

int main() {
	cout << "水仙花数";
	
	for (int i = 100; i < 1000; i++)
	{
		// 取个十百三位
		int ge = i % 10;
		int shi = i / 10 % 10;
		int bai = i / 100;
		// 将三个数的三次方相加
		int shui = ge * ge * ge + shi * shi * shi + bai * bai * bai;
		if (shui == i)
		{
			cout << "找到了水仙花数：" << i << endl;
		}

	}

}
