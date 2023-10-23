/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:08:51 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/23 14:42:09 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 250
int main(int, char**)
{
    Array<int> num(5);
    try {
        num[0] = 1;
        num[1] = 2;
        num[2] = 3;
        num[3] = 4;
        num[4] = 5;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "num[3] of non const Array: " << num[3] << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    const Array<int> numCopy = num;

    try {
        std::cout << "num[3] of const Array: " << numCopy[3] << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

//    try {
//        numCopy[3] = 10;
//    }
//    catch (std::exception &e) {
//        std::cerr << e.what() << std::endl;
//    }


	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	for (int i = 0; i < MAX_VAL; i++) {
		std::cout << numbers[i] << std::endl;
	}

	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
    try {
        numbers[18] = 0;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << "numbers[18]: " << numbers[18] << std::endl;
    std::cout << std::endl << "size: " << numbers.size() << std::endl;

	delete [] mirror;
	return 0;
}