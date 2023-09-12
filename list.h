#pragma once

template<class T>
class list;
struct List;
struct head;

typedef struct head head;
typedef struct List List;

template<class T>
class list {
public:
	//���캯��
	list();
	list(int n);
	list(T* a, int len);
	//��������
	~list();
	//��ӽڵ�
	list& push_back(T n);
	//ɾ���ڵ�
	list& del(T n);
	//����
	List* find(T n);
	//������
	int size();
	//�п�
	bool empty();
	//��ӡ
	void print();
private:
	
	struct List {//����ڵ�
		T val;
		struct List* next;
	};
	struct head {//��ͷ�ڵ�
		int s;
		struct List* tail;//����β�ڵ�
		struct List* next;
	};
	head* H;
};