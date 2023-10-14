/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:34:18 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/14 09:52:24 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _input;
        std::map<std::string, double> _database ;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &src);
        ~BitcoinExchange();

        BitcoinExchange &operator=(BitcoinExchange const &src);


};
