/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:11:23 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/13 13:04:48 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>


int main(void) {
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);

    int val = 6;
    try {
        std::vector<int>::iterator result = easyfind(numbers, val);
        std::cout << "Value " << *result << " exists in container\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    val = 4;
    try {
        std::vector<int>::iterator result = easyfind(numbers, val);
        std::cout << "Value " << *result << " exists in container\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}