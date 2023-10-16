/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:17:35 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/16 21:14:52 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe const &src) {
    *this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src) {
    if (this != &src) {
        *this = src;
    }
    return (*this);
}

void PmergeMe::fillVector(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (std::find(_vector.begin(), _vector.end(), std::atoi(argv[i])) == _vector.end()) {
            _vector.push_back(std::atoi(argv[i]));
        }
        else {
            std::cout << "Duplicate number" << std::endl;
            return ;
        }
    }
}

void PmergeMe::fillList(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		if (std::find(_list.begin(), _list.end(), std::atoi(argv[i])) == _list.end()) {
			_list.push_back(std::atoi(argv[i]));
		}
		else {
			std::cout << "Duplicate number" << std::endl;
			return ;
		}
	}
}

void PmergeMe::printVector() {
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList() {
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

static std::vector<int> mergeVector(std::vector<int> &left, std::vector<int> &right) {
	std::vector<int> res;
	while (!left.empty() && !right.empty()) {
		if (left.front() < right.front()) {
			res.push_back(left.front());
			left.erase(left.begin());
		}
		else {
			res.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!left.empty()) {
		res.push_back(left.front());
		left.erase(left.begin());
	}

	while (!right.empty()) {
		res.push_back(right.front());
		right.erase(right.begin());
	}
	return (res);
}

static std::list<int> mergeList(std::list<int> &left, std::list<int> &right) {
	std::list<int> res;
	while (!left.empty() && !right.empty()) {
		if (left.front() <= right.front()) {
			res.push_back(left.front());
			left.erase(left.begin());
		}
		else {
			res.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!left.empty()) {
		res.push_back(right.front());
		left.erase(left.begin());
	}

	while (!right.empty()) {
		res.push_back(right.front());
		right.erase(right.begin());
	}
	return (res);
}

static std::vector<int> mergeInsertVector(std::vector<int> &vector) {
	if (vector.size() <= 1) {
		return (vector);
	}

	int middle = vector.size() / 2;
	std::vector<int> left(vector.begin(), vector.begin() + middle);
	std::vector<int> right(vector.begin() + middle, vector.end());

	left = mergeInsertVector(left);
	right = mergeInsertVector(right);
	return (mergeVector(left, right));
}

static std::list<int> mergeInsertList(std::list<int> &list) {
	if (list.size() <= 1) {
		return (list);
	}

	int middle = list.size() / 2;
	std::list<int> left;
	std::list<int> right;

	for (int i = 0; i < middle; i++) {
		left.push_back(list.front());
		list.pop_front();
	}
	right = list;

	left = mergeInsertList(left);
	right = mergeInsertList(right);
	return (mergeList(left, right));
}

void PmergeMe::sortVector() {
	std::cout << "Vector before sort: ";
	printVector();

	std::clock_t start = std::clock();
	_vector = mergeInsertVector(_vector);
	double time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;

	std::cout << "Vector after sort: ";
	printVector();

	std::cout << "Time for a vector: " << time << " microseconds" << std::endl << std::endl;
}

void PmergeMe::sortList() {
	std::cout << "List before sort: ";
	printList();

	std::clock_t start = std::clock();
	_list = mergeInsertList(_list);
	double time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;

	std::cout << "List after sort: ";
	printList();

	std::cout << "Time for a list: " << time << " microseconds" << std::endl;
}
