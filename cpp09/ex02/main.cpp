/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:23:32 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/16 15:52:18 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cout << "Usage: ./pmerge <list of numbers>" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j]; j++) {
            if (!isdigit(argv[i][j])) {
                std::cout << "Invalid input" << std::endl;
                return (1);
            }
        }
    }
    PmergeMe pmerge;
    pmerge.fillVector(argc, argv);
}
