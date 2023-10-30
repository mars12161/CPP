/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:11:23 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/27 10:48:03 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T& container, int n) {
    std::cout << "looking for value " << n << std::endl;
    typename T::iterator result = std::find(container.begin(), container.end(), n);
    if (result != container.end())
        return result;
    else
        throw ValueNotFound();
}

const char *ValueNotFound::what() const throw() {
            return ("Value not found");
}


int main(void) {
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);

    std::list<int> num_list;
    num_list.push_back(10);
    num_list.push_back(500);
    num_list.push_back(12);
    num_list.push_back(460235);

    int val = 6;
    int val2 = 460235;
    try {
        std::vector<int>::iterator result = easyfind(numbers, val);
        std::cout << "Value " << *result << " exists in container" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    val = 4;
    try {
        std::vector<int>::iterator result = easyfind(numbers, val);
        std::cout << "Value " << *result << " exists in container" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator result = easyfind(num_list, val);
        std::cout << "Value " << *result << " esists in container" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator result = easyfind(num_list, val2);
        std::cout << "Value " << *result << " esists in container" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}