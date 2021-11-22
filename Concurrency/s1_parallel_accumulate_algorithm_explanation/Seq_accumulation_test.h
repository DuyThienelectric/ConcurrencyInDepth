#pragma once

#include <thread> 
#include <numeric>
#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <string>

void sequntial_accumulate_test() {
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	// calculate the summation of element in array.
	int sum = std::accumulate(v.begin(), v.end(), 0);

	// calculate the multiplication properly.
	int product = std::accumulate(v.begin(), v.end(), 1, 
		std::multiplies<int>());

	// lambda expression will concatenate 1 integer value
	// from the vector to a string.
	auto dash_fold = [](std::string a, int b) {
		return std::move(a) + "-" + std::to_string(b);
	};

	std::string s = std::accumulate(std::next(v.begin()), v.end(),
		std::to_string(v[0]), dash_fold);

	std::cout << "sum - " << sum << std::endl;
	std::cout << "product - " << product << std::endl;
	std::cout << "dash fold - " << s << std::endl;
}

void run() {
	sequntial_accumulate_test();
}