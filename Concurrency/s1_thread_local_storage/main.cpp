#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> i = 0;

void foo() {
	++i;
	std::cout << "foo :" << i << std::endl;
}

int main() {
	//std::cout << "main :" << i << std::endl;
	std::thread thread_1(foo);
	
	std::thread thread_2(foo);
	
	std::thread thread_3(foo);
	

	thread_1.join();
	thread_2.join();
	thread_3.join();

	std::cout << std::endl;
}