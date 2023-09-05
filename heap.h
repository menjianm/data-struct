#pragma once
#include<iostream>
//��Сheap��
template<class T>
class heap {
public:
	//���캯������������capicity������һ���յ�heap
	heap(int max);
	//�ṩһ��T���͵����鹹��heap
	heap(T* S, int start, int end);
	//��������
	~heap();
	//insert����������,����������ã�������������
	heap& insert(T temp);
	//top��������ȡ��Сֵ
	T top();
	//pop������ɾ����Сֵ������
	heap& pop();
	//isempty�������п�
	bool isEmpty();
	//isfull����������
	bool isFull();
	//size������ȡheap�Ĵ�С
	int size();
	//capicity������ȡheap������
	int capicity();
	//����heap
	void showheap(); 
	//����[]
	int operator[](int n);
private:
	//����
	int c;
	//��С
	int s = 0;
	//heapָ��
	T* H;

};