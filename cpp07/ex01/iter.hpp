/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:45:16 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/10 16:50:16 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, size_t N, typename Function>
void	iter(T (&arr)[N], Function func)
{
	for (size_t i = 0; i < N; i++)
		func(arr[i]);
}
