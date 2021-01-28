#pragma once
#include <vector>

void Radix(std::vector<int>& vec)
{
	// variables initiation
	std::vector<int> _vec[10];  // temporary arrays
	_vec[0].reserve(vec.size());
	auto it = vec.begin();      // iterator for writing new data
	size_t temp;                // temporary variable for finding maximum base
	size_t max_base = 0;        // variable for maximum base

	// pass to find the maximum base in the array
	for (auto el : vec){                  // it's 20-30%~ faster than without this pass
		temp = 0;
		while (el /= 10) temp++;
		if (temp > max_base) max_base = temp;
	}
	max_base++; 

	// actual sort cycle
	for (size_t base = 0; base < max_base; base++){
		for (auto& el : vec) _vec[el / (int)pow(10, base) % 10].push_back(el); // read/write pass
		for (auto& arr : _vec) {   // wrice/clear pass
			if (arr.size()) for (auto& el : arr) *it++ = el;
			arr.clear();
		}
		it = vec.begin();
	}
}
