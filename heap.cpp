#include"heap.h"

	//���캯������������capicity������һ���յ�heap
	template<class T>
	heap<T>::heap(int max) {
	this->c = max;
	this->H = new T[this->c + 1];
	this->H[0] = INT_MIN;
}
	//�ṩһ��T���͵����鹹��heap
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
	//heap�Ĺ���
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
	//����[]
	template<class T>
	int heap<T>::operator[](int n) {
		return this->H[n];
	}
	//��������
	template<class T>
	heap<T>::~heap() {
	if (this->H != nullptr) {
		delete[]this->H;
		this->H = nullptr;
	}
}
	//insert����������,����������ã�������������
	template<class T>
	heap<T>& heap<T>::insert(T temp){
	if (this->s==this->c) {
		std::cout << "��������" << std::endl;
		return *this;
	}
	int i;
	for ( i = ++this->s; this->H[i / 2] > temp; i /= 2) {
		this->H[i] = this->H[i / 2];
	}
	this->H[i] = temp;
	return *this;
	}

	//getmin��������ȡ��Сֵ
	template<class T>
	T heap<T>::top() {
		return this->H[1];
	}
	//deletemin������ɾ����Сֵ������
	template<class T>
	heap<T>& heap<T>::pop() {
		int i, child;
		if (isEmpty()) {
			std::cout << "��heap" << std::endl;
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
	//isempty�������п�
	template<class T>
	bool heap<T>::isEmpty() {
		if (this->s == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	//isfull����������
	template<class T>
	bool heap<T>::isFull() {
		if (this->s == this->c) {
			return true;
		}
		else {
			return false;
		}
	}
	//size������ȡheap�Ĵ�С
	template<class T>
	int heap<T>::size() {
		return this->s;
	}
	//capicity������ȡheap������
	template<class T>
	int heap<T>::capicity() {
		return this->c;
	}
	//����heap
	template<class T>
	void heap<T>::showheap() {
		for (int i = 1; i <= this->s; i++) {
			std::cout << this->H[i]<<' ';
		}
		std::cout << std::endl;
	}

