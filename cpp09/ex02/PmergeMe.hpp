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
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>



class PmergeMe {
    private:
        std::queue<int> _queue;
        std::vector<int> _vector;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe const &src);
        PmergeMe &operator=(PmergeMe const &src);
        void fillVector(int argc, char **argv);
        void fillQueue(int argc, char **argv);
};
