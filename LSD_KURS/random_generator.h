#pragma once
#include <random>

namespace rnd
{

	// iterators based implementation
	template<typename It>
	void fill_random_integers(It beg, It end, int min, int max)
	{
		// random number generator based on
		// example for uniform_int_distribution:
		// https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
		// fills array with random uniform distributed 
		// numbers based on defined bounds

		std::random_device rd; // obtaining seed;
		std::mt19937 gen(rd());  // standard engine seeded with rd()
		std::uniform_int_distribution<> distribution(min, max); // transforming int into our bounds

		while (beg != end) *beg++ = distribution(gen);   // filling the array
	}

	// vector/min/max only
	void fill_random_integers(std::vector<int>& vec, int min, int max)
	{
		fill_random_integers(vec.begin(), vec.end(), min, max);
	}

	// vector/size/min/max
	void fill_random_integers(std::vector<int>& vec, int size, int min, int max)
	{
		vec.resize(size);
		fill_random_integers(vec.begin(), vec.end(), min, max);
	}

	// random integer
	int random_integer(const int& min, const int& max)
	{
		// same as fill_random_integers(), but for one number
		std::random_device rd; // obtaining seed;
		std::mt19937 gen(rd());  // standard engine seeded with rd()
		std::uniform_int_distribution<> distribution(min, max); // transforming int into our bounds

		return distribution(gen);
	}
}