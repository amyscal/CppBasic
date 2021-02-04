#pragma once
#include <iostream>
using namespace  std;

template<class T>
class MyArray {
public:
    //有参构造  参数 容量
    MyArray(int capacity) {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity]; //开辟数组空间
    }

    //拷贝构造
    MyArray(const MyArray &arr) {
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //this->pAddress = arr.pAddress;

        this->pAddress = new T[arr.m_Capacity];

        for(int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator= 防止浅拷贝
    MyArray &operator=(MyArray &arr) {
        if(this->pAddress != NULL) {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Size = 0;
            this->m_Capacity = 0;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for(int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    //尾插法
    void Push_Back(const T &val) {
        //判断容量是否等于大小
        if(this->m_Capacity == this->m_Size) {
            cout << "ERR_ARRAY_ALREADY_FULL" << endl;
            return;
        }

        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    //尾删法
    void Pop_Back() {
        if(this->m_Size == 0) {
            cout << "ERR_NO_MEMBER" << endl;
            return;
        }

        this->m_Size--;
    }

    //通过下标访问
    //重载[]
    T &operator[](int index) {
        return this->pAddress[index];
    }

    //返回容量
    int getCapacity() {
        return this->m_Capacity;
    }

    //返回大小
    int getSize() {
        return this->m_Size;
    }
    //析构函数
    ~MyArray() {
        if(this->pAddress != NULL) {
            //cout << "333" << endl;

            delete[] this->pAddress;
            this->pAddress = NULL;

        }
    }

private:
    T *pAddress; //指针指向堆区开辟的真实数组

    int m_Capacity; //数组容量

    int m_Size;  //数组大小
};