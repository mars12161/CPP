/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:57:18 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/14 07:36:15 by mschaub          ###   ########.fr       */
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
    for (int i = 0; i < 20; i++)
        vec[i] = i;
    sp2.addNumber(vec, 20);
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

    std::cout << sp2 << std::endl;
}