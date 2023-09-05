#include"heap.h"

	//构造函数，创建具有capicity容量的一个空的heap
	template<class T>
	heap<T>::heap(int max) {
	this->c = max;
	this->H = new T[this->c + 1];
	this->H[0] = INT_MIN;
}
	//提供一个T类型的数组构造heap
	template<class T>
	heap<T>::heap(T* S, int start, int end) {
	int len = end - start + 1;
	this->H = new T[len + 1];
	this->H[0] = INT_MIN;
	for (int i = 1; i <= len; i++) {
		this->H[i] = S[i - 1 + start];
	}
	this->c = len;
	this->s = len;
	//heap的构建
	for (int i = this->s / 2; i > 0; i--) {
		int last = this->H[i], j;
		int child;
		for (j = i; j * 2 <= this->s; j = child) {
			child = j * 2;
			if (child != this->s && this->H[child + 1] < this->H[child]) {
				child++;
			}
			if (last > this->H[child]) {
				this->H[j] = this->H[child];
			}
			else {
				break;
			}
		}
		this->H[j] = last;
	}
}
	//重载[]
	template<class T>
	int heap<T>::operator[](int n) {
		return this->H[n];
	}
	//析构函数
	template<class T>
	heap<T>::~heap() {
	if (this->H != nullptr) {
		delete[]this->H;
		this->H = nullptr;
	}
}
	//insert函数，上滤,返回类的引用，便于连续插入
	template<class T>
	heap<T>& heap<T>::insert(T temp){
	if (this->s==this->c) {
		std::cout << "容量不足" << std::endl;
		return *this;
	}
	int i;
	for ( i = ++this->s; this->H[i / 2] > temp; i /= 2) {
		this->H[i] = this->H[i / 2];
	}
	this->H[i] = temp;
	return *this;
	}

	//getmin函数，获取最小值
	template<class T>
	T heap<T>::top() {
		return this->H[1];
	}
	//deletemin函数，删除最小值，下滤
	template<class T>
	heap<T>& heap<T>::pop() {
		int i, child;
		if (isEmpty()) {
			std::cout << "空heap" << std::endl;
			return *this;
		}
		T last = this->H[this->s--];
		for (i = 1; i * 2 <= this->s; i = child) {
			child = i * 2;
			if (child != this->s && this->H[child + 1] < this->H[child]) {
				child++;
			}
			if (last > this->H[child]) {
				this->H[i] = this->H[child];
			}
			else {
				break;
			}
		}
		this->H[i] = last;
		return *this;

	}
	//isempty函数，判空
	template<class T>
	bool heap<T>::isEmpty() {
		if (this->s == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	//isfull函数，判满
	template<class T>
	bool heap<T>::isFull() {
		if (this->s == this->c) {
			return true;
		}
		else {
			return false;
		}
	}
	//size函数获取heap的大小
	template<class T>
	int heap<T>::size() {
		return this->s;
	}
	//capicity函数获取heap的容量
	template<class T>
	int heap<T>::capicity() {
		return this->c;
	}
	//遍历heap
	template<class T>
	void heap<T>::showheap() {
		for (int i = 1; i <= this->s; i++) {
			std::cout << this->H[i]<<' ';
		}
		std::cout << std::endl;
	}

