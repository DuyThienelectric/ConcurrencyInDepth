#pragma once

#include <iostream>
#include <mutex>

class data_object {

};

class data_wrapper {
	data_object protected_data;
	std::mutex m;
public:
	template <typename function>
	void do_some_thing(function f) {
		std::lock_guard<std::mutex> lg(m);
		f(protected_data );
	}
};

data_object* unprotected_data;

void malisious_function(data_object& data) {
	unprotected_data = &data;
}

void run_2() {
	data_wrapper wrapper;
	wrapper.do_some_thing(malisious_function);
}