/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:57:41 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/24 13:56:56 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _filled(0), _arr(_N) {
}

Span::Span(unsigned int N) : _N(N), _filled(0), _arr(_N) {
}

Span::Span(Span const &copy) {
    *this = copy;
}

Span::~Span() {
}

Span &Span::operator=(Span const &copy) {
    if (this != &copy)
    {
        _N = copy._N;
        _filled = copy._filled;
        _arr = std::vector<int>(_N);
        for (unsigned int i = 0; i < _filled; i++)
            _arr[i] = copy._arr[i];
    }
    return (*this);
}

void Span::addNumber(int num) {
    if (_filled >= _N)
        throw FullException();
    _arr[_filled] = num;
    _filled++;
}

void Span::addNumber(std::vector<int> vector, unsigned int size) {
    if (_filled + size > _N)
        throw FullException();
    for (unsigned int i = 0; i < size; i++) {
        _arr[_filled] = vector[i];
        _filled++;
    }
}

int Span::shortestSpan() {
    if (_filled <= 1)
        throw NotEnoughNumbersException();

    std::sort(_arr.begin(), _arr.begin() + _filled);

    int shortest = std::numeric_limits<int>::max();
    for (unsigned int i = 1; i < _filled; i++) {
        int diff = _arr[i] - _arr[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}


int Span::longestSpan() {
    if (_filled <= 1)
        throw NotEnoughNumbersException();
    return (*std::max_element(_arr.begin(), _arr.end()) - *std::min_element(_arr.begin(), _arr.end()));
}

const char *Span::FullException::what() const throw() {
    return ("Span is full");
}

const char *Span::NotEnoughNumbersException::what() const throw() {
    return ("Not enough numbers in Span");
}

int Span::getN() const {
    return (_N);
}

int Span::getFilled() const {
    return (_filled);
}

std::vector<int> Span::getArr() const {
    return (_arr);
}

std::ostream &operator<<(std::ostream &out, Span const &span) {
    out << "Span with " << span.getFilled() << " of " << span.getN() << " numbers: ";
    for (int i = 0; i < span.getFilled(); i++)
        out << span.getArr()[i] << " ";
    return (out);
}