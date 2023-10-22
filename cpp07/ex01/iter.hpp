/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:45:16 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/22 13:06:37 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, typename Function>
void iter(T (&arr), size_t len, Function f)
{
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}
