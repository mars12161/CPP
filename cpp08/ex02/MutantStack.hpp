/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 07:47:39 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/27 13:13:38 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(MutantStack const &src);
        virtual ~MutantStack();
        MutantStack &operator=(MutantStack const &src);

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};
