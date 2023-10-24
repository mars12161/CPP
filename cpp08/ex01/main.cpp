/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:57:18 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/24 14:21:43 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
    Span sp = Span(5);
    try {
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(3);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << sp << std::endl;


    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    Span sp2 = Span(20);
    std::vector<int> vec(20);
    for (int i = 0; i < 20; i++) {
        vec[i] = i;
    }
    sp2.addNumber(vec, 20);
    std::cout << sp2 << std::endl;
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;


    Span sp3 = Span(15000);
//    std::vector<int> vec2(15000);
//    for (int i = 0; i < 15000; i++)
//        vec2[i] = i;
//    sp3.addNumber(vec2, 15000);
//    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
//    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        int value = 1 + (rand());
        sp3.addNumber(value);
    }

    int smallestNumber = *std::min_element(sp3.getArr().begin(), sp3.getArr().end());
    int biggestNumber = *std::max_element(sp3.getArr().begin(), sp3.getArr().end());
    std::cout << "Smallest element in sp3: " << smallestNumber << std::endl;
    std::cout << "Biggest element in sp3: " << biggestNumber << std::endl;
    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

}