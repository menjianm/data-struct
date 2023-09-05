#pragma once
#include<iostream>
//最小heap类
template<class T>
class heap {
public:
	//构造函数，创建具有capicity容量的一个空的heap
	heap(int max);
	//提供一个T类型的数组构造heap
	heap(T* S, int start, int end);
	//析构函数
	~heap();
	//insert函数，上滤,返回类的引用，便于连续插入
	heap& insert(T temp);
	//top函数，获取最小值
	T top();
	//pop函数，删除最小值，下滤
	heap& pop();
	//isempty函数，判空
	bool isEmpty();
	//isfull函数，判满
	bool isFull();
	//size函数获取heap的大小
	int size();
	//capicity函数获取heap的容量
	int capicity();
	//遍历heap
	void showheap(); 
	//重载[]
	int operator[](int n);
private:
	//容量
	int c;
	//大小
	int s = 0;
	//heap指针
	T* H;

};