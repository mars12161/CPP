/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:43:26 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/08 13:45:58 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ScalarConverter.hpp"

std::string ScalarConverter::_str = "";
char ScalarConverter::_c = '0';
int ScalarConverter::_i = 0;
float ScalarConverter::_f = 0.0f;
double ScalarConverter::_d = 0.0;
e_type ScalarConverter::_type = IMPOSSIBLE;

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &src) {
	if (this != &src) {
	}
	return *this;
}

void ScalarConverter::setStr(std::string str) {_str = str;}

std::string ScalarConverter::getStr() {return _str;}

char ScalarConverter::getChar() {return _c;}

void ScalarConverter::setChar(char c) {_c = c;}

int ScalarConverter::getInt() {return _i;}

void ScalarConverter::setInt(int i) {_i = i;}

float ScalarConverter::getFloat() {return _f;}

void ScalarConverter::setFloat(float f) {_f = f;}

double ScalarConverter::getDouble() {return _d;}

void ScalarConverter::setDouble(double d) {_d = d;}

bool ScalarConverter::intMinMax() {
	char *end;
	long num = std::strtol(_str.c_str(), &end, 10);

	if (num > INT_MAX || num < INT_MIN)
		return false;
	return true;
}

bool ScalarConverter::isChar() {
	if (_str.length() == 1 && std::isprint(_str[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt() {
	int j = 0;
	if (_str[j] == '+' || _str[j] == '-')
		j++;
	for (size_t i = j; i < _str.length(); i++) {
		if (!isdigit(_str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat() {
	bool hasPoint = false;
	bool hasF = false;
	int j = 0;
	if (_str[j] == '+' || _str[j] == '-')
		j++;
	if (_str.empty())
		return false;
	for (size_t i = j; i < _str.length(); i++) {
		if (_str[i] == '.') {
			if (hasPoint || hasF)
				return false;
			hasPoint = true;
		}
		else if (_str[i] == 'f') {
			if (i != _str.length() - 1)
				return false;
			hasF = true;
		}
		else if (!isdigit(_str[i]))
			return false;
	}
	return hasF || hasPoint;
}

bool ScalarConverter::isDouble() {
	int j = 0;
	int found = 0;
	if ((_str.find('.') == std::string::npos || _str.find('.') == _str.length() - 1)
		|| (_str.find('.') == 0))
		return false;
	if (_str[j] == '+' || _str[j] == '-')
		j++;
	for (size_t i = j; i < _str.length(); i++) {
		if (_str[i] == '.')
			found++;
		if ((!isdigit(_str[i]) && _str[i] != '.') || found > 1)
			return false;
	}
	return true;
}

bool ScalarConverter::isNan() {
	return (_str == "nan" || _str == "nanf");
}

bool ScalarConverter::isInf() {
	return (_str == "inf" || _str == "inff" || _str == "+inf" || _str == "+inff" ||
		_str == "-inf" || _str == "-inff");
}

bool ScalarConverter::isLiteral() {
	return (isChar() || isInt() || isFloat() || isDouble() || isNan() || isInf());
}



e_type ScalarConverter::getType() {
	if (isInt())
		return INT;
	if (isChar())
		return CHAR;
	if (isFloat())
		return FLOAT;
	if (isDouble())
		return DOUBLE;
	return IMPOSSIBLE;
}

void ScalarConverter::setType() {
	_type = ScalarConverter::getType();
}

void ScalarConverter::printChar() {
	if(isNan() || isInf() || !intMinMax())
		std::cout << "Impossible";
	else if (!std::isprint(_c))
		std::cout << "Not displayable";
	else
		std::cout << "'" << getChar() << "'";
}

void ScalarConverter::printInt() {
	if (isNan() || isInf() || !intMinMax())
		std::cout << "Impossible";
	else
		std::cout << getInt();
}

void ScalarConverter::printFloat() {
	if (isNan())
		std::cout << "nanf";
	else if (isInf()) {
		if (_str[0] == '-')
			std::cout << "-";
		std::cout << "inff";
	}
	else {
		std::cout << getFloat();
		if (_f - static_cast<int>(_f) == 0)
			std::cout << ".0";
		std::cout << "f";
	}
}

void ScalarConverter::printDouble() {
	if (isNan())
		std::cout << "nan";
	else if (isInf()) {
		if (_str[0] == '-')
			std::cout << "-";
		std::cout << "inf";
	}
	else {
		std::cout << getDouble();
		if (_d - static_cast<int>(_d) == 0)
			std::cout << ".0";
	}
}

void ScalarConverter::convert() {
	setType();
	switch (_type) {
		case CHAR:
			_c = _str[0];
			_i = static_cast<int>(_c);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
			break;
		case INT:
			_i = std::strtol(_str.c_str(), NULL, 10);
			_c = static_cast<char>(_i);
			_f = static_cast<float>(_i);
			_d = static_cast<double>(_i);
			break;
		case FLOAT:
			_f = std::strtof(_str.c_str(), NULL);
			_c = static_cast<char>(_f);
			_i = static_cast<int>(_f);
			_d = static_cast<double>(_f);
			break;
		case DOUBLE:
			_d = std::strtod(_str.c_str(), NULL);
			_c = static_cast<char>(_d);
			_i = static_cast<int>(_d);
			_f = static_cast<float>(_d);
			break;
		default:
			break;
	}
}

std::ostream &operator<<(std::ostream &out, ScalarConverter const &src) {
	out << "char: "; src.printChar(); std::cout << std::endl;
	out << "int: "; src.printInt(); std::cout  << std::endl;
	out << "float: "; src.printFloat(); std::cout << std::endl;
	out << "double: "; src.printDouble(); std::cout << std::endl;
	return (out);
}
