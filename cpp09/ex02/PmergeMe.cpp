/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:17:35 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/16 15:52:51 by mschaub          ###   ########.fr       */
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


