/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:51:20 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/22 12:49:37 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

struct PrintElement
{
	template <typename T>
	void	operator()(T const &x) const
	{
		std::cout << x << std::endl;
	}
};

unsigned long long factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return static_cast<unsigned long long>(n) * factorial(n - 1);
}

template <typename T>
void printFactorial(const T& value) {
	unsigned long long fact = factorial(value);
	std::cout << "Factorial of " << value << " is " << fact << std::endl;
}

int main(void) {
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	int factorialArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

	// Process and print elements of intArray using the functor
	std::cout << "Processing intArray: " << std::endl;
	iter(intArray, 5,PrintElement());
	std::cout << std::endl;

	// Process and print elements of doubleArray using the functor
	std::cout << "Processing doubleArray: " << std::endl;
	iter(doubleArray, 5, PrintElement());
	std::cout << std::endl;

	// Process and print elements of factorialArray using the function
	std::cout << "Processing factorialArray: " << std::endl;
	iter(factorialArray, 9,printFactorial<int>);
	std::cout << std::endl;

	return 0;
}
