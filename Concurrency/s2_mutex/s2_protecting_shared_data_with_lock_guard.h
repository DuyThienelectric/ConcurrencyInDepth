#pragma once

#include <iostream>
#include <mutex>
#include <list>
#include <thread> 

std::list<int> list;
std::mutex m;

void add_to_list(int const& x) {
	std::lock_guard<std::mutex> lg(m);
	list.push_back(x);
}

void size() {
	m.lock();
	int size = list.size();
	m.unlock();
	std::cout << " size of the list is : " << size << std::endl;
}

void run_lock_guard() {
	std::thread thread_1(add_to_list, 4);
	std::thread thread_2(add_to_list, 11);

	thread_1.join();
	thread_2.join();
}
