/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:34:18 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/16 11:17:44 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database ;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(BitcoinExchange const &src);
        void fillDatabase();
        bool checkInput(std::string input);
        bool isValidDate(std::string date);
};
