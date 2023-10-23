/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:08:12 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/23 09:25:45 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

template <class T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(Array<T> const &other);
    ~Array();
    Array<T> &operator=(Array<T> const &other);
    T &operator[](unsigned int index);
    unsigned int size() const;

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

template <class T>
Array<T>::Array() {
    _arr = new T[0];
    _size = 0;
}

template <class T>
Array<T>::Array(unsigned int l) {
    T*	init = new T();

    _size = l;
    _arr = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _arr[i] = *init;
    }
    delete init;
}

template <class T>
Array<T>::Array(Array<T> const &other) {
    _arr = NULL;
    _size = other._size;
    _arr = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _arr[i] = other._arr[i];
    }
}

template <class T>
Array<T>::~Array() {
    delete [] _arr;
}

template <class T>
Array<T> &Array<T>::operator=(Array<T> const &other) {
    if (this != &other) {
        delete [] _arr;
        _size = other._size;
        _arr = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _arr[i] = other._arr[i];
        }
    }
    return *this;
}

template <class T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _arr[index];
}

template <class T>
unsigned int Array<T>::size() const {
    return _size;
}