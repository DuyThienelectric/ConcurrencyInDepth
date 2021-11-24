#include <iostream>
#include <thread>
#include <atomic>

//std::atomic<int> i = 0; // result 123 
thread_local std::atomic<int> i = 0; // result 111
// When we change our variable type to trade local, then each thread is going to have its own distinct object.
// and that's the reason we get 1,1,1 output in this case.
void foo() {
	++i;
	std::cout << i << std::endl;
}

int main() {
	
	std::thread thread_1(foo);
	std::thread thread_2(foo);
	std::thread thread_3(foo);
	

	thread_1.join();
	thread_2.join();
	thread_3.join();

	std::cout << std::endl;
}