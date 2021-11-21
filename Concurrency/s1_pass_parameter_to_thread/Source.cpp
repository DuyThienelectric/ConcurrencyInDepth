#include <iostream>
#include <thread>
#include <chrono>

void foo_1(int x, int y)
{
	std::cout << " X + Y = " << x + y << std::endl;
}

void run_example_1()
{
	int p = 9;
	int q = 8;

	std::thread thread_1(foo_1, p, q);

	thread_1.join();
}

void foo_2(int& x)
{
	while (true)
	{
		std::cout << "Thread_1 x value : " << x << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void run_example_2()
{
	int x = 9;
	std::cout << "Main thread current value of X is : " << x << std::endl;
	std::thread thread_1(foo_2, std::ref(x));
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	x = 15;
	std::cout << "Main thread X value changed to : " << x << std::endl;
	thread_1.join();
}


int main()
{
	//run_example_1();
	run_example_2();
}