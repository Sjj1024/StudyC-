#include <iostream>

#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;


// 有五个选手，9个评委为这五个人随机评分，去掉最高分和最低分，然后求出平均分

class Studen {
public:
	string name;
	deque<int> fenshu;
	int agvfen;

public:
	Studen(string n, int agv) {
		this->name = n;
		this->agvfen = agv;
	}
};


// 定义一个函数，在函数中创建五个选手
void creatP(vector<Studen> &stus) {

	for (int i = 1; i < 6; i++)
	{
		Studen s = Studen(std::to_string(i), 0);
		stus.push_back(s);
	}

}

// 遍历输出用户的姓名和平均分
void showInfo(vector<Studen> &stus) {
	// 遍历容器
	for (vector<Studen>::iterator s = stus.begin(); s != stus.end(); s++)
	{
		cout << "用户" << s->name << " " << "平均分是:" << s->agvfen << endl;
	}
}

// 让9个评委为每个选手评分，然后排序，取出最高分和最低分，最后求出平均值
void addFen(vector<Studen>& stus) {
	for (vector<Studen>::iterator s = stus.begin(); s != stus.end(); s++)
	{
		for (size_t i = 0; i < 9; i++)
		{
			int fen = rand() % 41 + 60;
			s->fenshu.push_back(fen);
		}
		// 将分数容器排序
		sort(s->fenshu.begin(), s->fenshu.end());
		// 取出最高分和最低分
		s->fenshu.pop_back();
		s->fenshu.pop_front();
		// 求出平均分
		int allscore = 0;
		for (deque<int>::iterator i = s->fenshu.begin(); i != s->fenshu.end(); i++)
		{
			allscore += *i;
		}
		int agvfen = allscore / s->fenshu.size();
		s->agvfen = agvfen;
	}
}

void test() {

	// 创建一个容器存储5个选手
	vector<Studen> stus;
	creatP(stus);
	showInfo(stus);
	addFen(stus);

	showInfo(stus);
}


int main() {
	// 添加随机数种子
	srand(time(NULL));

	test();

	return 0;
}
