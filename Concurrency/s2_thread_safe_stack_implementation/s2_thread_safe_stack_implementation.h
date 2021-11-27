#pragma once

#include <iostream>
#include <mutex>
#include <thread> 
#include <stack>

template<typename T>

class thread_safe_stack
{
	std::stack<T> stk;
	std::mutex m;

public:
	void push(T element) {
		std::lock_guard<std::mutex> lg(m);
		stk.push(element);
	}
	void pop() {

	}
	T& top() {

	}
	bool empty() {

	}
	size_t size() {

	}

};

void run() {

}