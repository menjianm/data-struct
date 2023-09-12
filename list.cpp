#pragma once
#include<iostream>
#include"list.h"
template<class T>
list<T>::list() {
	H = new head;
	H->s = 0;
	H->tail = nullptr;
	H->next = nullptr;
}

template<class T>
list<T>::list(int n) {
	H = new head;
	H->tail = nullptr;
	H->next = nullptr;
	H->s = n;
	for (int i = 0; i < n; i++) {
		List* temp = new List;
		temp->next = nullptr;
		temp->val = 0;
		if (H->next == nullptr)
			H->next = temp;
		else 
			H->tail->next = temp;
		H->tail = temp;
	}
}

template<class T>
list<T>::list(T* a, int len) {
	H = new head;
	H->tail = nullptr;
	H->next = nullptr;
	H->s = len;
	for (int i = 0; i < len; i++) {
		List* temp = new List;
		temp->next = nullptr;
		temp->val = a[i];
		if (H->next == nullptr)
			H->next = temp;
		else
			H->tail->next = temp;
		H->tail = temp;
	}
}

template<class T>
list<T>::~list() {
	if (H->next != nullptr) {
		List* temp = H->next;
		while (temp != nullptr) {
			List* ptr = temp;
			temp = temp->next;
			delete ptr;
		}
	}
	delete H;
	H = nullptr;
}

template<class T>
list<T>& list<T>::push_back(T n) {
	List* temp = new List;
	temp->val = n;
	temp->next = nullptr;
	if (H->next == nullptr)
		H->next = temp;
	else
		H->tail->next = temp;
	H->tail = temp;
	H->s++;
	return *this;
}

template<class T>
list<T>& list<T>::del(T n) {
	if (H->next == nullptr)
		return *this;
	List temp;
	temp.next = H->next;
	List* ptr = &temp;
	while (ptr->next != nullptr) {
		if (ptr->next->val == n) 
			break;
		ptr = ptr->next;
	}
	List* ptr1 = ptr->next;
	ptr->next = ptr1->next;
	delete ptr1;
	H->s--;
	return *this;
}

template<class T>
List* list<T>::find(T n) {
	if (H->next == nullptr)
		return nullptr;
	List* temp = H->next;
	while (temp != nullptr) {
		if (temp->val == n)
			break;
		temp = temp->next;
	}
	return temp;
}

template<class T>
int list<T>::size() {
	return H->s;
}

template<class T>
bool list<T>::empty() {
	return H->next == nullptr;
}

template<class T>
void list<T>::print() {
	if (H->next == nullptr)
		std::cout << "Á´±íÎª¿Õ" << std::endl;
	List* temp = H->next;
	while (temp != nullptr) {
		std::cout << temp->val << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;
}