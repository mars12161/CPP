/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:00 by mschaub           #+#    #+#             */
/*   Updated: 2023/10/21 07:40:02 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	IMPOSSIBLE
};

class ScalarConverter {
	private:
		static std::string _str;
		static char _c;
		static int _i;
		static float _f;
		static double _d;
		static e_type _type;
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const &src);

		static void setStr(std::string str);
		static std::string getStr();

		static char getChar();
		static void setChar(char c);

		static int getInt();
		static void setInt(int i);

		static float getFloat();
		static void setFloat(float f);

		static double getDouble();
		static void setDouble(double d);

		static bool intMinMax();
		static bool isChar();
		static bool isInt();
		static bool isFloat();
		static bool isDouble();
		static bool isNan();
		static bool isInf();
		static bool isLiteral();

		static void printChar();
		static void printInt();
		static void printFloat();
		static void printDouble();

		static e_type getType();
		static void setType();

		static void convert();
};

std::ostream & operator<<(std::ostream &out, ScalarConverter const &src);
