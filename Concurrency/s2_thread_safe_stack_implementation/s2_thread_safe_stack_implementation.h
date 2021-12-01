#pragma once
#include <iostream>
#include <mutex>
#include <stack>
#include <thread>
#include <memory>
#include <stdexcept>

template<typename T>

class thead_safe_stack{
	std::stack<std::shared_ptr<T>> stk;
	std::mutex m;

public:
	void push(T element)
	{
		std::lock_guard<std::mutex> lg(m);
		stk.push(std::make_shared<T>(element));
	}

	std::shared_ptr<T> pop()
	{
		std::lock_guard<std::mutex> lg(m);
		//avoid the race condition between popand empty functions
		if (stk.empty())
		{
			throw std::runtime_error("stack is empty");
		}
		// a shared pointer object using the top value of the stack
		std::shared_ptr<T> res(stk.top());
		// stack stores the shares pointers instead od elements
		stk.pop();
		return res;
	}

	void pop(T& value)
	{
		// contructing the lock gurd object to provide the synchronization
		std::lock_guard<std::mutex> lg(m);
		if (stk.empty()) throw std::runtime_error("stack is empty");
		// get the value out of the stack in this way and assign in to the reference
		value = *(stk.top().get());
		stk.pop();
	}
	bool empty()
	{
		std::lock_guard<std::mutex> lg(m);
		return stk.empty();
	}
	size_t size()
	{
		std::lock_guard<std::mutex> lg(m);
		return stk.size();
	}
};