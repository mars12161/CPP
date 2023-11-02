/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:32:18 by mschaub           #+#    #+#             */
/*   Updated: 2023/11/02 20:08:52 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./rpn <expression>" << std::endl;
        return (1);
    }
    RPN rpn(argv[1]);
    if (!rpn.isValid()) {
        std::cout << "Error" << std::endl;
        return (1);
    }
    rpn.parse();
    rpn.print();
}