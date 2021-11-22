#include <iostream>
#include <thread>

void foo_1() {
	std::cout << "hello from method " << std::endl;
}

void main() {
	std::thread threa_1(foo_1);

	if (threa_1.joinable())
	{
		std::cout << "this is joinable thread " << std::endl;
	}

	threa_1.join();

	if (threa_1.joinable())
	{
		std::cout<< "this is joinable thread " << std::endl;
	}
	else
	{
		std::cout << "after calling join, threa_1 is not a joinable thread " << std::endl;
	}

	std::cout << "hello from main thread " << std::endl;
}