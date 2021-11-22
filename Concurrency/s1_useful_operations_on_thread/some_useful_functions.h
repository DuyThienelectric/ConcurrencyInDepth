#pragma once

#include <iostream>
#include <thread>

// get_id(): return unique thread id for each active thread of execution
//			 return 0 for all non active thread

void foo() {
	std::cout << "this thread id - " << std::this_thread::get_id() << std::endl;
}

void get_id_test() {
	std::thread threa_1(foo);
	std::thread threa_2(foo);
	std::thread threa_3(foo);
	std::thread threa_4;

	std::cout << "thread 1 id: " << threa_1.get_id() << std::endl;
	std::cout << "thread 2 id: " << threa_2.get_id() << std::endl;
	std::cout << "thread 3 id: " << threa_3.get_id() << std::endl;
	std::cout << "thread 4 id: " << threa_4.get_id() << std::endl;
	// returned zero for thread four.
	// after joining a thread, that thread does not represent an 
	// active thread of execution.
	threa_1.join();
	threa_2.join();
	threa_3.join();
	
	std::cout << "thread 3 id: " << threa_3.get_id() << std::endl;
	// get ID value has returned zero for thread three
}

void run() {
	// hardware conncurrency :
	// return the number of concurrent threads supported by the 
	// implementation. the value should be considered only hint.
		
	int allowed_threads = std::thread::hardware_concurrency();
	std::cout << "Allowed thread count in my divide : " << 
		allowed_threads << std::endl;

	// use this hardware concurrency function extensively to query 
	// the number of allowed parallel

}