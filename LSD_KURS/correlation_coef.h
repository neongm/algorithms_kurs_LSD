#pragma once
#include <vector>
#include <numeric>
#include "benchmark_result.h"



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
		std::vector<size_t> values_x;
		std::vector<size_t> values_y;
		long double mid_x;
		long double mid_y;
		long double mid_xy;
		long double dispersion_x;
		long double dispersion_y;
		long double mid_quad_deviation_x;
		long double mid_quad_deviation_y;
		long double coefficent_of_correlation;

	public:
			
		calculate();
		calculate(const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y);
		void set_arrays(const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y);
		void calc_mid();
		void calc_dispersion();
		void calc_mid_quad_deviation();
		void calc_coefficent_of_correlation();

		long double get_coefficent_of_correlation() { return coefficent_of_correlation; }
		long double get_mid_quad_deviation_x() { return mid_quad_deviation_x; }
		long double get_mid_quad_deviation_y() { return mid_quad_deviation_y; }
		long double get_dispersion_x() { return dispersion_x; }
		long double get_dispersion_y() { return dispersion_y; }
		long double get_mid_x() { return mid_x; }
		long double get_mid_y() { return mid_y; }
		long double get_mid_xy() { return mid_xy; }
		std::vector<size_t> get_values_x() { return values_x; }
		std::vector<size_t> get_values_y() { return values_y; }
	};

	calculate::calculate(const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y) 
	{
		values_x = arr_x;
		values_y = arr_y;
	}

	void calculate::set_arrays(const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y)
	{
		values_x = arr_x;
		values_y = arr_y;
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

	void calculate::calc_coefficent_of_correlation()
	{
		coefficent_of_correlation = (mid_xy - mid_x * mid_y) / (mid_quad_deviation_x * mid_quad_deviation_y);
	}

	calculate call_all_methods (const std::vector<size_t>& arr_x, const std::vector<size_t>& arr_y)
	{
		calculate calculator = calculate(arr_x, arr_y);
		calculator.calc_mid();
		calculator.calc_dispersion();
		calculator.calc_mid_quad_deviation();
		calculator.calc_coefficent_of_correlation();
		return calculator;
	}

	calculate do_calculations(const std::vector<benchmark_result>& arr)
	{
		std::vector<size_t> values_x;
		std::vector<size_t> values_y;
		for (auto el : arr) {
			values_x.push_back(el.get_elements_amount());
			values_y.push_back(el.get_time());
		}
		calculate result = call_all_methods(values_x, values_y);
		return result;
	}
}	

