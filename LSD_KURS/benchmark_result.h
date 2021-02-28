#pragma once


struct benchmark_result
{
private:
	size_t elements_amount;
	size_t time;
	unsigned long long elements_amount_squared;
	size_t elements_amount_x_time;
public:
	benchmark_result()
	{
		elements_amount = 0;
		time = 0;
		elements_amount_squared = 0;
		elements_amount_x_time = 0;
	}
	benchmark_result(size_t _elements_amount, size_t _time)
	{
		elements_amount = _elements_amount;
		time = _time;
		elements_amount_squared = pow(_elements_amount, 2);
		elements_amount_x_time = _elements_amount * _time;
	}
	size_t get_elements_amount() { return elements_amount; }
	size_t get_time() { return time; }
	unsigned long long get_amount_squared() { return elements_amount_squared; }
	size_t get_amount_x_time() { return elements_amount_x_time; }
};