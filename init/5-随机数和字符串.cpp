#include <iostream>
#include <ctime>

// 创建学生结构体
struct Student{
    std::string name;
    int age;
    int score;
};

// 创建老师结构体
struct Teacher{
    std::string name;
    int age;
    struct Student sArray_list[6];
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    // 结构体实战：
    std::string ceshi = "hhh";
    ceshi += "nihao";
    std::cout << ceshi << "\n";

    // 使用随机数种子，使随机数真的随机
    srand((unsigned int)time(NULL));
    int res = rand() % 60 + 40;
    std::cout << res;

    return 0;
}
