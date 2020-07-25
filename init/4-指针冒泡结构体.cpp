#include <iostream>
#include <string>

// 定义一个函数，使用指针传参，然后进行冒泡排序
void mao_pao(int *pInt, int length){
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - 1 - i; ++j) {
            if (pInt[j] > pInt[j + 1]) {
                int kong = pInt[j];
                pInt[j] = pInt[j+1];
                pInt[j+1] = kong;
            }
        }
    }
}


// 自定义结构体
struct Student {
    std::string name;
    int age;
    int score;
};


int main() {
    std::cout << "Hello, World!" << std::endl;

    int list_num[] = {3, 5, 6, 7, 1, 2};
    int length = sizeof(list_num)/sizeof(list_num[0]);
    int * p = list_num;

    mao_pao(p, length);

    // 输出数组
    for (int i = 0; i < length; ++i) {
        std::cout << list_num[i] << ",";
    }

    // 使用结构体创建
    std::cout << "\n";
    // 创建结构体的时候，struct关键字可以省略，但是定义的时候，不可以省略
    struct Student s;
    s.name = "王思聪";
    s.age = 19;
    s.score = 100;
    std::cout << s.name << s.age << s.score;
    return 0;
}
