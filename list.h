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
	//构造函数
	list();
	list(int n);
	list(T* a, int len);
	//析构函数
	~list();
	//添加节点
	list& push_back(T n);
	//删除节点
	list& del(T n);
	//查找
	List* find(T n);
	//链表长度
	int size();
	//判空
	bool empty();
	//打印
	void print();
private:
	
	struct List {//链表节点
		T val;
		struct List* next;
	};
	struct head {//表头节点
		int s;
		struct List* tail;//保存尾节点
		struct List* next;
	};
	head* H;
};