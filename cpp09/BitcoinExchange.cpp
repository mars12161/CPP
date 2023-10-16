/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:47:09 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/16 11:54:40 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    *this = src;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
    if (this != &src)
        this->_database = src._database;
    return (*this);
}

void BitcoinExchange::fillDatabase() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cout << "Error: File couldn't be opened." << std::endl;
        return ;
    }
    std::string line;
    while (getline(file, line)) {
        std::string key = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);
        this->_database[key] = std::strtod(value.c_str(), NULL);
    }
    file.close();
}

bool BitcoinExchange::isValidDate(std::string date) {
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);

    std::string year = date.substr(0, 4);
    double year_d = std::strtod(year.c_str(), NULL);
    if (year_d > 2022 || year_d < 0)
        return false;  // Invalid year.

    std::string month = date.substr(5, 2);
    double month_d = std::strtod(month.c_str(), NULL);
    if (month_d < 1 || month_d > 12)
        return false;  // Invalid month.

    std::string day = date.substr(8, 2);
    double day_d = std::strtod(day.c_str(), NULL);
    if (day_d < 1 || day_d > 31)
        return false;  // Invalid day.
    return (true);
}

bool BitcoinExchange::checkInput(std::string input) {
    std::ifstream file(input.c_str());
    int count = 0;
    if (!file.is_open())
        return (false);
    std::string line;
    while (getline(file, line)) {
        count++;
        if (count == 1) {
            if (line != "date | value")
                return (false);
        }
        else {
            if (line.find('|') == std::string::npos)
                return (false);
        }
        std::string key = line.substr(0, line.find('|') - 1);
        std::string value = line.substr(line.find('|') + 2);
        if ((key.empty() || value.empty()) && count != 1) {
            std::cout << 3 << std::endl;
            return (false);
        }
        if (!isValidDate(key) && count != 1)
            return (false);
        if ((std::strtod(value.c_str(), NULL) < 0 || std::strtod(value.c_str(), NULL) > 1000) && count != 1)
            return (false);
    }
    file.close();
    return (true);
}
