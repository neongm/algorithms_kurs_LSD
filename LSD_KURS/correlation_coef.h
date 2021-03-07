#pragma once
#include <vector>
#include <numeric>
#include "benchmark_result.h"
#include "MyForm.h"

template<typename T>
T accumulate_big(const std::vector<T>& array)
{
	T sum = 0;
	for (T el : array) sum += el;
	return sum;
}

long double get_mid(const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y)
{
	unsigned long long count = 0;
	for (size_t i = 0; i < arr_x.size(); i++) count += arr_x.at(i) * arr_y.at(i);
	return count / arr_x.size();
}

long double get_mid_sq(const std::vector<size_t>& arr)
{
	unsigned long long count = 0;
	for (size_t i = 0; i < arr.size(); i++) count += pow(arr.at(i), 2);
	return count / arr.size();
}

namespace analysis
{
	class calculate
	{
	private:
		std::vector<size_t> values_x;						// elements amount
		std::vector<size_t> values_y;						// time 
		size_t results_amount;

		std::vector<unsigned long long> values_x_squared;	// x^2
		std::vector<unsigned long long> values_x_to_y;		// x*y
		
		long long unsigned sum_x;
		long long unsigned sum_y;
		long long unsigned sum_xy;
		long long unsigned sum_x_squared;

		long double mid_x;
		long double mid_y;
		long double mid_xy;
		long double dispersion_x;
		long double dispersion_y;
		long double mid_quad_deviation_x;
		long double mid_quad_deviation_y;
		long double coefficent_of_correlation;
		long double coefficent_of_determination;

		// equasion 
		double a0;
		double a1;

		void calc_values_x_squared();
		void calc_values_x_to_y();
		void calc_mid();
		void calc_dispersion();
		void calc_mid_quad_deviation();
		void calc_coefficent_of_correlation_full();
		void calc_coefficent_of_determination();
		void update_auxilliary();
		void solve_equasion();

	public:

		// CONSTRUCTORS
		calculate();
		calculate(const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y);

		// METHODS
		void set_arrays(const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y);
		void add_result(const size_t& _amount, const size_t& _time);

		void update_all();
		void reset();

		// GETTERS
		double get_a0() { return a0; }
		double get_a1() { return a1; }
		long double get_coefficent_of_determination() { return coefficent_of_determination; }
		long double get_coefficent_of_correlation() { return coefficent_of_correlation; }
		long double get_mid_quad_deviation_x() { return mid_quad_deviation_x; }
		long double get_mid_quad_deviation_y() { return mid_quad_deviation_y; }
		long double get_dispersion_x() { return dispersion_x; }
		long double get_dispersion_y() { return dispersion_y; }
		long double get_mid_x() { return mid_x; }
		long double get_mid_y() { return mid_y; }
		long double get_mid_xy() { return mid_xy; }
		size_t get_value_x_at(size_t index) { return values_x.at(index); }
		size_t get_value_y_at(size_t index) { return values_y.at(index); }
		unsigned long long get_value_x_squared_at(size_t index) { return values_x_squared.at(index); }
		unsigned long long get_value_x_to_y_at(size_t index) { return values_x_to_y.at(index); }
		size_t get_results_amount() { return results_amount; }
		std::vector<size_t> get_values_x() { return values_x; }
		std::vector<size_t> get_values_y() { return values_y; }
	};


	calculate::calculate()																				// CONSTRUCTORS
	{
		results_amount = 0;
	}

	calculate::calculate(const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y) 
	{
		values_x = arr_x;
		values_y = arr_y;
		update_auxilliary();
	}

	void calculate::reset()
	{
		values_x.resize(0);
		values_y.resize(0);
	}

	void calculate::set_arrays(const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y)		// METHODS
	{
		values_x = arr_x;
		values_y = arr_y;
	}

	void calculate::update_auxilliary()
	{
		calc_mid();
		calc_dispersion();
		calc_values_x_squared();
		calc_values_x_to_y();

		results_amount = values_x.size();
		sum_x = std::accumulate(values_x.begin(), values_x.end(), 0);
		sum_y = std::accumulate(values_y.begin(), values_y.end(), 0);
		sum_xy = std::accumulate(values_x_to_y.begin(), values_x_to_y.end(), 0);
		sum_x_squared = std::accumulate(values_x_squared.begin(), values_x_squared.end(), 0);
	}


	void calculate::add_result(const size_t& _amount, const size_t& _time)
	{
		values_x.push_back(_amount);
		values_y.push_back(_time);
		update_auxilliary();
	}

	void calculate::calc_values_x_squared()
	{
		if (values_x_squared.size() != 0) values_x_squared.resize(0);
		for (auto el : values_x) values_x_squared.push_back(pow(el, 2));
	}

	void calculate::calc_values_x_to_y()
	{
		if (values_x_to_y.size() != 0) values_x_to_y.resize(0);
		for (size_t i = 0; i < values_x.size(); i++) values_x_to_y.push_back(values_x.at(i) * values_y.at(i));
	}

	void calculate::calc_mid()
	{
		mid_x = std::accumulate(values_x.begin(), values_x.end(), 0) / values_x.size();
		mid_y = std::accumulate(values_y.begin(), values_y.end(), 0) / values_y.size();
		mid_xy = get_mid(values_x, values_y);
	}

	void calculate::calc_dispersion()
	{
		dispersion_x = get_mid_sq(values_x) - pow(mid_x, 2);
		dispersion_y = get_mid_sq(values_y) - pow(mid_y, 2);
	}

	void calculate::calc_mid_quad_deviation()
	{
		mid_quad_deviation_x = pow(dispersion_x, 0.5);
		mid_quad_deviation_y = pow(dispersion_y, 0.5);
	}

	void calculate::calc_coefficent_of_correlation_full()
	{
		std::vector<long long int> xi_minus_mid_x;
		for (auto el : values_x) xi_minus_mid_x.push_back(el - mid_x);

		std::vector<long long int> xi_minus_mid_y;
		for (auto el : values_y) xi_minus_mid_y.push_back(el - mid_y);

		int long long upper_part = 0;
		for (size_t i = 0; i < xi_minus_mid_x.size(); i++) upper_part += xi_minus_mid_x.at(i) * xi_minus_mid_y.at(i);

		unsigned long long x_sum = 0;
		for (auto el : xi_minus_mid_x) x_sum += pow(el, 2);

		unsigned long long y_sum = 0;
		for (auto el : xi_minus_mid_y) y_sum += pow(el, 2);

		long long int lower_part = pow(x_sum * y_sum, 0.5);

		coefficent_of_correlation = (double)upper_part / lower_part;
	}

	void calculate::calc_coefficent_of_determination()                  
	{
		coefficent_of_determination = pow(coefficent_of_correlation, 2);
	}

	void calculate::solve_equasion()
	{
		// TODO IN EQUASION BRANCH
		a1 = (sum_xy * results_amount - (sum_x * sum_y)) /
			((results_amount * sum_x_squared) - pow(sum_x, 2));
		a0 = (sum_y + a1 * sum_x) / results_amount;
	}

	void calculate::update_all()           // main update function
	{
		update_auxilliary();
		calc_mid_quad_deviation();
		calc_coefficent_of_correlation_full();
		calc_coefficent_of_determination();
		solve_equasion();
	}

	calculate call_all_methods (const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y)
	{
		calculate calculator = calculate(arr_x, arr_y);
		calculator.update_all();
		return calculator;
	}

}	

