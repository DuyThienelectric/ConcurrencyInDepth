#include <iostream>
#include <thread>
#include <chrono>

void foo_1()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "hello from func_1 " << std::endl;
}


int main()
{
	std::thread thread_1(foo_1);
	thread_1.join();        // first example code. Comment this for second example
	//thread_1.detach();   // second example code. Comment this for first example

	std::cout << "hello from main thread " << std::endl;
}