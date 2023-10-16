/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:17:19 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/16 15:54:09 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>



class PmergeMe {
    private:
        std::list<int> _list;
        std::vector<int> _vector;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe const &src);
        PmergeMe &operator=(PmergeMe const &src);
        void fillVector(int argc, char **argv);
        void fillList(int argc, char **argv);
		void printVector();
		void printList();
		void sortVector();
		void sortList();
};
