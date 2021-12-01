#pragma once
#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>

class bank_account {
	double balance;
	std::string name;
	std::mutex m;
public:
	bank_account() {};

	bank_account(double _balance, std::string _name) :balance(_balance), name(_name) {}

	bank_account(bank_account& const) = delete;
	bank_account& operator=(bank_account& const) = delete;

	// you can withdraw(rut), deposite(gui), transfer(chuyen).
	void withdraw(double amount)
	{
		std::lock_guard<std::mutex> lg(m);
		balance -= amount;
	}

	void deposite(double amount)
	{
		std::lock_guard<std::mutex> lg(m);
		balance += amount;
	}

	void transfer(bank_account& from, bank_account& to, double amount)
	{	
		std::lock_guard<std::mutex> lg_1(from.m);
		std::cout << "lock for " << from.name << " account acquire by " 
			<< std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << "waiting to acquire lock for " << to.name 
			<< " account by  " << std::this_thread::get_id() << std::endl;
		std::lock_guard<std::mutex> lg_2(to.m);

		from.balance -= amount;
		to.balance += amount;
		std::cout << "transfer to - " << to.name << "   from - " 
			<< from.name << "  end \n";
	}
};

void run_bank_account()
{
	bank_account account;

	bank_account account_1(1000, "alo");
	bank_account account_2(2000, "ola");

	std::thread thread_1(&bank_account::transfer, &account, std::ref(account_1), std::ref(account_2), 500);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::thread thread_2(&bank_account::transfer, &account, std::ref(account_2), std::ref(account_1), 200);

	thread_1.join();
	thread_2.join();
}
