/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:57:41 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/29 10:51:09 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {
}


Span::Span(Span const &copy) {
    *this = copy;
}

Span::~Span() {
}

Span &Span::operator=(Span const &copy) {
    if (this != &copy) {
        _n = copy._n;
        _arr = copy._arr;
    }
    return (*this);
}

void Span::addNumber(int num) {
    if (_arr.size() >= _n)
        throw FullException();
    _arr.push_back(num);
}

void Span::addNumber(std::list<int> list, unsigned int size) {
    if (_arr.size() + size > _n)
        throw FullException();
    _arr.insert(_arr.end(), list.begin(), list.end());
}

int Span::shortestSpan() {
    if (_arr.size() <= 1)
        throw NotEnoughNumbersException();

    int shortest = std::numeric_limits<int>::max();
    for (std::list<int>::iterator it = _arr.begin(); it != _arr.end(); it++) {
        for (std::list<int>::iterator it2 = _arr.begin(); it2 != _arr.end(); it2++) {
            if (it != it2) {
                int diff = std::abs(*it - *it2);
                if (diff < shortest)
                    shortest = diff;
            }
        }
    }

    return shortest;
}


int Span::longestSpan() {
    if (_arr.size() <= 1)
        throw NotEnoughNumbersException();
    int longest = 0;

    std::list<int>::iterator prev = _arr.begin();
    std::list<int>::iterator curr = _arr.begin();
    curr++;
    while (curr != _arr.end()) {
        int diff = std::abs(*curr - *prev);
        if (diff > longest)
            longest = diff;
        prev++;
        curr++;
    }

    return longest;
}

const char *Span::FullException::what() const throw() {
    return ("Span is full");
}

const char *Span::NotEnoughNumbersException::what() const throw() {
    return ("Not enough numbers in Span");
}

const std::list<int>* Span::getArr() const {
    return (&_arr);
}

std::ostream &operator<<(std::ostream &out, Span const &span) {
    std::list<int>::const_iterator it = span.getArr()->begin();
    std::list<int>::const_iterator ite = span.getArr()->end();
    while (it != ite) {
        out << *it << " ";
        it++;
    }
    return (out);
}