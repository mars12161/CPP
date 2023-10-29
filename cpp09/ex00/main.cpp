/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:43:21 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/27 14:30:37 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc <input file>" << std::endl;
        return (1);
    }
    BitcoinExchange exchange;
    std::string file = argv[1];
    std::string output = "";
    exchange.fillDatabase();
    output = exchange.createOutput(file);
    std::cout << output << std::endl;
    return (0);
}