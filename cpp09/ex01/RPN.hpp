/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:10:39 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/16 13:41:23 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN {
    private:
        std::string _expr;
        int _result;
        bool _is_valid;
        std::stack<int> _stack;
    public:
        RPN(std::string expr);
        ~RPN();
        RPN(RPN const &src);
        RPN &operator=(RPN const &src);
        void parse();
        void print();
        int getResult();
        bool isValid();
};