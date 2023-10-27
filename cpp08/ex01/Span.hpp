/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:57:31 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/27 12:18:28 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <list>
#include <cmath>
#include <limits>
#include <algorithm>

class Span
{
    private:
        long unsigned int _n;
        std::list<int> _arr;
        Span();
    public:
        Span(unsigned int n);
        Span(Span const &copy);
        ~Span();
        Span &operator=(Span const &copy);
        const std::list<int>* getArr() const;
        void addNumber(int num);
        void addNumber(std::list<int> list, unsigned int size);
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
