#include <iostream>
#include <thread>
#include <chrono>

void foo_1() {
	std::this_thread::sleep_for(std::chrono::microseconds(10000));
	std::cout << "hello from method " << std::endl;
}

void other_operations() {
	std::cout << " this is other operation" << std::endl;
	throw std::runtime_error(" this is a runtime error ");
}

void run_example_1() {
	std::thread thread_1(foo_1);

	try
	{	// do other operations
		other_operations();
		thread_1.join();

	}
	catch (...) //const std::exception&
	{
	}
	std::cout << " this is main thread " << std::endl;
}

void run_example_2() {
	std::thread thread_1(foo_1);

	try { // do other operations
		other_operations();
		thread_1.join();
	}
	catch (...) {
		thread_1.join();
	}
}

void run_example_3() {
	std::thread thread_1(foo_1);

	try { // do other operations
		other_operations();
	}
	catch (...) {
	}
}

int main() {
	//run_example_1();
	run_example_2();
	//run_example_3();
}
