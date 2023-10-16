/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:43:21 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/16 11:36:36 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BitcoinExchange exchange;
    std::string file = argv[1];
    if (argc != 2)
    {
        std::cout << "Usage: ./bitcoin <input file>" << std::endl;
        return (1);
    }
    else if (!exchange.checkInput(file))
    {
        std::cout << "Error: File is in the wrong format." << std::endl;
        return (1);
    }
    exchange.fillDatabase();
    return (0);
}