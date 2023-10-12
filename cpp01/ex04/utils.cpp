/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:34:38 by mschaub           #+#    #+#             */
/*   Updated: 2023/06/05 11:41:43 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

std::string stringReplace(const std::string &line, const std::string str1, const std::string str2) {
	std::string result;

	size_t pos = 0;
	size_t prev = 0;
	while ((pos = line.find(str1, prev)) != std::string::npos) {
		result += line.substr(prev, pos - prev);
		result += str2;
		prev = pos + str1.length();
	}
	result += line.substr(prev);
	return result;
}
