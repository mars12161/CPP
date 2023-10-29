/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:57:18 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/29 14:09:50 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
    Span sp = Span(5);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << sp << std::endl;


    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    Span sp2 = Span(20);
    std::list<int> list;
    for (int i = 0; i < 20; i++) {
        list.push_back(i);
    }
    try {
        sp2.addNumber(list, 20);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << sp2 << std::endl;
    try {
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

     Span sp3 = Span(20);

     srand(time(NULL));
     for (int i = 0; i < 20; i++) {
         int value = 1 + (rand() % 100);
         try {
             sp3.addNumber(value);
         }
            catch (std::exception &e) {
                std::cout << e.what() << std::endl;
            }
     }

     int smallestNumber = *std::min_element(sp3.getArr()->begin(), sp3.getArr()->end());
     int biggestNumber = *std::max_element(sp3.getArr()->begin(), sp3.getArr()->end());
     std::cout << "Smallest element in sp3: " << smallestNumber << std::endl;
     std::cout << "Biggest element in sp3: " << biggestNumber << std::endl;
     std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
     std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
     std::cout << sp3 << std::endl;

}
