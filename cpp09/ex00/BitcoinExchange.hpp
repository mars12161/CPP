/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:34:18 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/16 12:31:35 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

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
        std::string createOutput(std::string input);
        std::string getValue(std::string row);
        std::string findClosestDate(std::string date, std::string value);
};
