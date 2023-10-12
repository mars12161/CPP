/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:08:12 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/10 17:28:12 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array {
	public:
		Array() :_size(0) {
			std::cout << "Default constructor called" << std::endl;
			_arr = new T[_size];
		}

		Array(unsigned int n): _size(n) {
			std::cout << "Constructor with size called" << std::endl;
			_arr = new T[_size];
		}

		Array(Array const &other): _size(other._size) {
			std::cout << "Copy constructor called" << std::endl;
			_arr = NULL;
			*this = other;
		}

		~Array() {
			std::cout << "Destructor called" << std::endl;
			if (_arr)
				delete [] _arr;
		}

		Array &operator=(Array const &other) {
			std::cout << "Assignment operator called" << std::endl;
			if (_arr)
				delete [] _arr;
			_size = other._size;
			_arr = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_arr[i] = other._arr[i];
			return *this;
		}

		T &operator[](unsigned int index) {
			if (index >= _size)
				throw std::exception();
			return _arr[index];
		}

		class OutOfBoundsException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Index out of bounds";
				}
		};

	private:
		T *_arr;
		unsigned int _size;
};