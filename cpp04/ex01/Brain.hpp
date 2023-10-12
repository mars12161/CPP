/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:10:25 by mschaub           #+#    #+#             */
/*   Updated: 2023/07/22 14:57:25 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain {

	public:
		Brain();
		Brain( Brain const &brain );
		Brain &operator=( const Brain &brain );
		virtual ~Brain();

	private:
		std::string _ideas[100];
};
