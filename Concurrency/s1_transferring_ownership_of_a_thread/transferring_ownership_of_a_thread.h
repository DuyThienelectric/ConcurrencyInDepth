#pragma once

#include <iostream>
#include <thread>
#include <chrono>
/*
 		   default (1)	thread() noexcept;
	initialization (2)	template <class Fn, class... Args>
						explicit thread (Fn&& fn, Args&&... args);
	copy [deleted] (3)	thread (const thread&) = delete;
			  move (4)	thread (thread&& x) noexcept;
*/

void foo() {
	// do something
	std::cout << "hello from foo \n";
}

void bar() {
	// do something
	std::cout << "hello from bar \n";
}

void run() {
	std::thread thread_1(foo);

	//std::thread thread_2 = thread_1; 
	// So this type of assignment will generate compile time errors.

	std::thread thread_2 = std::move(thread_1);
	// use sauted move operator explicitly to move one thread to another thread variable.

	thread_1 = std::thread(bar); // this Operator, not name variable as in previous case.
	// => In this type of situation, implicit mov call happens so we do not need to 
	// explicitly use STD move function here. And at the time we perform this operation 
	// thread, one did not own any thread object.
	
	std::thread thread_3(foo);

	//thread_1 = std::move(thread_3); // we have an exception here.
	// we cannot transfer ownership while left side variable of this operation owning a thread.
	// => we were able to assign newly constructed thread object to thread one variable.

	thread_1.join();
	thread_2.join();
	thread_3.join();
}