/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:47:09 by mschaub           #+#    #+#             */
/*   Updated: 2023/11/02 19:58:50 by mschaub          ###   ########.fr       */
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

std::string BitcoinExchange::findClosestDate(std::string date, std::string value) {
    std::string closest = "";
    std::map<std::string, double>::reverse_iterator it;
    for (it = _database.rbegin(); it != _database.rend(); it++) {
        if (it->first < date) {
            std::ostringstream s;
            s << it->second * std::strtod(value.c_str(), NULL);
            closest += it->first + " => " + value  + " = " + s.str() + "\n";
            break;
        }
    }
    return (closest);
}

std::string BitcoinExchange::getValue(std::string row) {
    std::string date = row.substr(0, row.find('|') - 1);
    std::string value = row.substr(row.find('|') + 2);
    std::string msg = "";
    if (_database.find(date) == _database.end()) {
        msg += findClosestDate(date, value);
        return (msg);
    }
    for (std::map<std::string, double>::iterator it = _database.begin(); it != _database.end(); it++) {
        if (it->first == date) {
            std::ostringstream s;
            s << it->second * std::strtod(value.c_str(), NULL);
            msg += it->first + " => " + value + " = " + s.str() + "\n";
        }
    }
    return (msg);
}

std::string BitcoinExchange::createOutput(std::string input) {
    std::ifstream file(input.c_str());
    std::string output = "";
    std::string line;
    while (getline(file, line)) {
        std::string key = line.substr(0, line.find('|') - 1);
        std::string value = line.substr(line.find('|') + 2);
        if (line.find("|") == std::string::npos) {
            output += "Error: bad input => " + key + "\n";
            continue;
        }
        if (!isValidDate(key) && line != "date | value") {
            output += "Error: bad input => " + key + "\n";
            continue;
        }
        if ((key.empty() || value.empty()) && line != "date | value") {
            output += "Error: invalid format\n";
            continue;
        }
        double value_d = std::strtod(value.c_str(), NULL);
        if (value_d < 0  && line != "date | value") {
            output += "Error: not a positive number.\n";
            continue;
        }
		else if (value_d > 1000 && line != "date | value") {
			output += "Error: number too big.\n";
			continue;
		}
        if (line != "date | value")
            output += getValue(line);
    }
    file.close();
    return (output);
}
