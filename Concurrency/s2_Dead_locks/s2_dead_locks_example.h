#pragma once
#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>

std::mutex m1;
std::mutex m2;

void m1_first_m2_second() {
	std::lock_guard<std::mutex> lg1(m1);
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "thread " << std::this_thread::get_id() << " has acquired lock for m1 mutex, its wait for m2 \n";
	std::lock_guard<std::mutex>lg2(m2);
	std::cout << "thread " << std::this_thread::get_id() << " has acquired lock for m2 mutex \n";
}
void m2_first_m1_second() {
	std::lock_guard<std::mutex> lg1(m2);
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	std::cout << "thread " << std::this_thread::get_id() << " has acquired lock for m2 mutex, its wait for m1 \n";
	std::lock_guard<std::mutex>lg2(m1);
	std::cout << "thread " << std::this_thread::get_id() << " has acquired lock for m1 mutex \n";
}
void run_exam() {
	std::thread thread_1(m1_first_m2_second);
	std::thread thread_2(m2_first_m1_second);

	thread_1.join();
	thread_2.join();
}