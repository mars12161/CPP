/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:57:31 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/24 13:48:52 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

class Span
{
    private:
        unsigned int _N;
        unsigned int _filled;
        std::vector<int> _arr;
        Span();
    public:
        Span(unsigned int N);
        Span(Span const &copy);
        ~Span();
        Span &operator=(Span const &copy);
        int getN() const;
        int getFilled() const;
        std::vector<int> getArr() const;
        void addNumber(int num);
        void addNumber(std::vector<int> vector, unsigned int size);
        int shortestSpan();
        int longestSpan();

        class FullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class NotEnoughNumbersException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Span const &span);
