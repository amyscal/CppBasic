#include <iostream>
#include <string>
#include "MyArray.hpp"
using namespace  std;

class Person{
public:
    Person() {};
    //无参构造：在堆区创建新数组时会没有参数，不能调用有参构造，所以必须写一个默认构造
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person> &arr) {
    for(int i = 0; i < arr.getSize(); i++) {
        cout << "name: " << arr[i].m_Name << " age: " << arr[i].m_Age << endl;
    }
}

void printIntArr(MyArray<int> &arr) {
    for(int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << "  ";
    }
}

void func_1() {
    MyArray<int> arr1(5);

    for(int i = 0; i < 5; i++) {
        arr1.Push_Back(i);
    }

    printIntArr(arr1);
    cout << endl;
    cout << "Capacity = "<< arr1.getCapacity() << endl;
    cout << "Size = "<< arr1.getSize() << endl;

    MyArray<int> arr2(arr1);

    printIntArr(arr2);
    //尾删
    arr2.Pop_Back();

    cout << endl;
    cout << "Capacity = "<< arr2.getCapacity() << endl;
    cout << "Size = "<< arr2.getSize() << endl;
}


void func_2() {
    MyArray<Person> arr(10);

    Person p1("A",18);
    Person p2("B",18);
    Person p3("C",18);
    Person p4("D",18);

    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);

    printPersonArray(arr);

    cout << "Capacity = "<< arr.getCapacity() << endl;
    cout << "Size = "<< arr.getSize() << endl;
}
int main() {
    func_2();

    return 0;
}
