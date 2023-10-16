/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:10:51 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/16 14:25:54 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string expr) : _expr(expr), _result(0), _is_valid(true) {
}

RPN::~RPN() {
}

RPN::RPN(RPN const &src) {
    *this = src;
}

RPN &RPN::operator=(RPN const &src) {
    if (this != &src) {
        this->_expr = src._expr;
        this->_result = src._result;
        this->_is_valid = src._is_valid;
        this->_stack = src._stack;
    }
    return *this;
}

bool RPN::isValid() {
    std::istringstream iss(_expr);
    std::string token;
    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
            continue;
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
            continue;
        else
            return false;
    }
    return true;
}

void RPN::parse() {
    std::istringstream iss(_expr);
    std::string token;
    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            double num;
            std::istringstream(token) >> num;
            _stack.push(num);
        }
        else {
            double op2 = _stack.top();
            _stack.pop();
            double op1 = _stack.top();
            _stack.pop();

            if (token[0] == '+')
                _stack.push(op1 + op2);
            else if (token[0] == '-')
                _stack.push(op1 - op2);
            else if (token[0] == '*')
                _stack.push(op1 * op2);
            else if (token[0] == '/')
                _stack.push(op1 / op2);
            else {
                _is_valid = false;
                return;
            }
        }
    }
}

void RPN::print() {
    if (_stack.size() != 1)
        _is_valid = false;
    else
        _result = _stack.top();
    std::cout << "Result: " << _result << std::endl;
}