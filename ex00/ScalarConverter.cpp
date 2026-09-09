/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:03:25 by asauvage          #+#    #+#             */
/*   Updated: 2026/09/09 15:20:03 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printNan(void) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: nanf\n";
	std::cout << "double: nan\n";
}

void	printInf( const std::string&	str ) {
	if (str[0] == '+') {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}

void	printChar(char c) {
	if (isprint(c))
		std::cout << "char: " << c << "\n";
	else
		std::cout << "char: " << "Non Displayable\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "0.f\n";
	std::cout << "double: " << static_cast<double>(c) << "0.\n";
}

void	printInt(int c) {
	if (isprint(c))
		std::cout << "char: " << static_cast<char>(c) << "\n";
	else
		std::cout << "char: " << "Non Displayable\n";
	std::cout << "int: " << c << "\n";
	std::cout << "float: " << static_cast<float>(c) << "0.f\n";
	std::cout << "double: " << static_cast<double>(c) << "0.\n";
}

bool	checkInt( const std::string& str ) {
	int 	i(0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (isdigit(str[i]) && i < 11)
		i++;
	if (str.size() != i || ( INT_MIN > std::strtol(str.c_str(), NULL, 10) && std::strtol(str.c_str(), NULL, 10) > INT_MAX ))
		return false;
	return true;
}

bool	checkFloat( const std::string& str ) {
	int i(0);
	int	p(0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (isdigit(str[i]) || str[i] == '.') {
		if (str[i] == '.')
			p++;
		i++;
	}
	if (str.size() != i + 1 || str[i] != 'f' || p != 1)
		return false;
	return true;
}

void	ScalarConverter::convert( const std::string& str ) {
	if (str == "nan" || str == "nanf")
		printNan();
	else if (str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf")
		printInf(str);
	else if (str.size() == 1 && !std::isdigit(str[0]))
		printChar(str[0]);
	else if (str.size() == 1 && std::isdigit(str[0]))
		printInt(str[0] - '0');
	else if (checkInt(str))
		printInt(std::atoi(str.c_str()));
	else if (checkFloat(str))
		printFloat();
}
