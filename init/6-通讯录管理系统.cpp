#include <iostream>
#include <ctime>
#define MAX 1000 // 定义最大存放人数

// 显示菜单
void showMenu(){
    std::cout << "*****  1.添加联系人  *****\n";
    std::cout << "*****  2.显示联系人  *****\n";
    std::cout << "*****  3.删除联系人  *****\n";
    std::cout << "*****  4.查找联系人  *****\n";
    std::cout << "*****  5.修改联系人  *****\n";
    std::cout << "*****  6.清空联系人  *****\n";
    std::cout << "*****  0.推出联系人  *****\n";
}

// 设计通讯录和联系人结构体
struct Person{
    std::string name;
    std::string sex;
    int age;
    std::string phone;
    std::string addr;
};

struct AddressBooks{
    struct Person personList[MAX]; // 通讯录中的联系人列表
    int size = 0; // 通讯录中的人数
};

void addPerson(AddressBooks *addr){
    // 先判断通讯录是否已经满了
    if (addr->size == MAX) {
        std::cout << "通讯录已经满了！";
    } else {
        std::cout << "请输入联系人姓名：\n";
        std::string username;
        std::cin >> username;
        addr->personList[addr->size].name = username;
        // 输入年龄和性别等信息
        std::cout << "请输入性别：1.男  2.女\n";
        int userSex;
        std::cin >> userSex;
        if (userSex == 1) {
            addr->personList[addr->size].sex = "男";
        } else {
            addr->personList[addr->size].sex = "女";
        }
        std::cout << "请输入年龄：\n";
        int userAge;
        std::cin >> userAge;
        addr->personList[addr->size].age = userAge;
        std::cout << "请输入电话号码：\n";
        std::string userPhone;
        std::cin >> userPhone;
        addr->personList[addr->size].phone = userPhone;
        std::cout << "请输入电话家庭住址：\n";
        std::string userHome;
        std::cin >> userHome;
        addr->personList[addr->size].addr = userHome;
        addr->size++;
    }

}

void showPerson(AddressBooks *addr){
    std::cout << "显示的所有联系人：\n";
    if (addr->size == 0) {
        std::cout << "联系人为空\n";
    } else {
        for (int i = 0; i < addr->size; ++i) {
            std::cout << "姓名：" + addr->personList[i].name + "\t";
            std::cout << "性别：" << addr->personList[i].sex << "\t";
            std::cout << "年龄：" << addr->personList[i].age << "\t";
            std::cout << "电话：" << addr->personList[i].phone << "\t";
            std::cout << "住址：" << addr->personList[i].addr << "\n";
        }
    }
}

int isExist(AddressBooks *addr, std::string name){
    //  查找是否有联系人，有的话返回联系人坐标，没有的话返回-1
    for (int i = 0; i < addr->size; ++i) {
        if (addr->personList[i].name == name) {
            return i;
        }
    }
    return -1;
};

void delPerson(AddressBooks *addr){
    std::cout << "删除联系人姓名：\n";
    std::string name;
    std::cin >> name;
    int position = isExist(addr, name);
    if (position == -1) {
        std::cout << "查不到此联系人";
    } else {
        std::cout << "查找到了此联系人，正在执行删除操作\n";
        for (int i = position; i < addr->size; ++i) {
            // 删除操作就是将后面的所有元素往前移动
            addr->personList[i] = addr->personList[i + 1];
        }
        // 删除完之后，还要将所有数据进行健一操作
        addr->size--;
    }
}

void findPerson(){
    std::cout << "查找联系人姓名：\n";

}

void editPerson(){
    std::cout << "编辑联系人姓名：\n";

}

void cleanPerson(){
    std::cout << "清空所有联系人？：\n";

}

int main() {
    std::cout << "欢迎使用手机通讯录系统!" << std::endl;
    // 创建联系人和通讯录结构体
    Person person;
    AddressBooks addressBooks;
    while (true) {
        showMenu();
        std::cout << "请选择你要的操作：" << std::endl;
        int select = 0;
        std::cin >> select;
        if (select == 1) {
            addPerson(&addressBooks);
        } else if (select == 2) {
            showPerson(&addressBooks);
        }else if (select == 3) {
            delPerson(&addressBooks);
        }else if (select == 4) {
            findPerson();
        }else if (select == 5) {
            editPerson();
        }else if (select == 6) {
            cleanPerson();
        }else if (select == 0) {
            std::cout << "已退出，欢迎下次使用";
            break;
        }
    }

    return 0;
}
