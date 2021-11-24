#pragma once

#include <iostream>
#include <mutex>
#include <list>
#include <thread> 

std::list<int> list;
std::mutex m;

void add_to_list(int const & x) {
	m.lock();
	list.push_front(x);
	m.unlock();
}

void size() {
	m.lock();
	int size = list.size();
	m.unlock();
	std::cout << " size of the list is : " << size << std::endl;
}

void run_mutex() {
	std::thread thread_1(add_to_list, 4);
	std::thread thread_2(add_to_list, 11);

	thread_1.join();
	thread_2.join();
}