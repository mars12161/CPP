/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:18:03 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/24 13:38:45 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>


class ValueNotFound : public std::exception
{
public:
    virtual const char *what() const throw() {
        return ("Value not found");
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int n) {
    std::cout << "looking for value " << n << std::endl;
    typename T::iterator result = std::find(container.begin(), container.end(), n);
    if (result != container.end())
        return result;
    else
        throw ValueNotFound();
}