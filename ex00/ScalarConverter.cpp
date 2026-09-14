/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:03:25 by asauvage          #+#    #+#             */
/*   Updated: 2026/09/14 17:19:32 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	verifSpace( const std::string& str ) {
	for (size_t i = 0; i < str.size(); ++i) {
		if (std::isspace(str[i]))
			return true;
	}
	return	false;
}

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
	else if (str[0] == '-'){
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
	else {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: inff\n";
		std::cout << "double: inf\n";
	}
}

void	printImpossible() {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
}

void	printChar(char c) {
	if (isprint(c))
		std::cout << "char: '" << c << "'\n";
	else
		std::cout << "char: " << "Non Displayable\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void	printInt(int c) {
	if (c >= 0 && c <= 127) {
		if (isprint(c))
			std::cout << "char: '" << static_cast<char>(c) << "'\n";
		else
			std::cout << "char: Non Displayable\n";
	}
	else
		std::cout << "char: impossible\n";
	std::cout << "int: " << c << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void	printFloat( float nb ) {
	if (nb >= 0 && nb <= 127) {
		if (floor(nb) == nb && isprint(static_cast<int>(nb)))
			std::cout << "char: '" << static_cast<char>(nb) << "'\n";
		else
			std::cout << "char: Non Displayable\n";
	}
	else
		std::cout << "char: impossible\n";
	if (nb >= INT_MIN && nb < 2147483648.0)
		std::cout << "int: " << static_cast<int>(nb) << "\n";
	else
		std::cout << "int: impossible\n";
	if (nb == floor(nb) && nb < 1e6 && nb > -1e6)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << nb << "f\n";
	std::cout << "double: " << static_cast<double>(nb) << "\n";
}

void	printDouble( double nb ) {
	if (nb >= 0 && nb <= 127) {
		if (floor(nb) == nb && isprint(static_cast<int>(nb)))
			std::cout << "char: '" << static_cast<char>(nb) << "'\n";
		else
			std::cout << "char: Non Displayable\n";
	}
	else
		std::cout << "char: impossible\n";
	if (nb >= INT_MIN && nb <= INT_MAX)
		std::cout << "int: " << static_cast<int>(nb) << "\n";
	else
		std::cout << "int: impossible\n";
	if (nb == floor(nb) && nb < 1e6 && nb > -1e6)
		std::cout << std::fixed << std::setprecision(1);
	if (nb > std::numeric_limits<float>::max() || nb < -std::numeric_limits<float>::max())
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << nb << "f\n";
	std::cout << "double: " << static_cast<double>(nb) << "\n";
}

bool	checkInt( const std::string& str ) {
	errno = 0;
	if (verifSpace(str))
		return false;
	char	*endptr(NULL);
	long	val(std::strtol(str.c_str(), &endptr, 10));
	if (*endptr != '\0' || str.c_str() == endptr)
		return false;
	if (errno == ERANGE || INT_MIN > val || val > INT_MAX)
		return false;
	return true;
}

bool	checkFloat( const std::string& str ) {
	errno = 0;
	if (verifSpace(str))
		return false;
	if (str.find('.') == std::string::npos)
		return false;
	char	*endptr(NULL);
	float	val(std::strtof(str.c_str(), &endptr));
	(void)val;
	if (*endptr != 'f' || *(endptr + 1) != '\0' || str.c_str() == endptr)
		return false;
	if (errno == ERANGE)
		return false;
	return true;
}

bool	checkDouble( const std::string& str ) {
	errno = 0;
	if (verifSpace(str))
		return false;
	if (str.find('.') == std::string::npos)
		return false;
	char	*endptr(NULL);
	double	val(std::strtod(str.c_str(), &endptr));
	(void)val;
	if (*endptr != '\0' || str.c_str() == endptr)
		return false;
	if (errno == ERANGE)
		return false;
	return true;
}

void	ScalarConverter::convert( const std::string& str ) {
	if (str == "nan" || str == "nanf")
		printNan();
	else if (str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf" || str == "inf" || str == "inff")
		printInf(str);
	else if (str.size() == 1 && !std::isdigit(str[0]))
		printChar(str[0]);
	else if (checkInt(str))
		printInt(std::atoi(str.c_str()));
	else if (checkFloat(str))
		printFloat(std::strtof(str.c_str(), NULL));
	else if (checkDouble(str))
		printDouble(std::strtod(str.c_str(), NULL));
	else
		printImpossible();
	std::cout.unsetf(std::ios::fixed);
	std::cout << std::setprecision(6);
}
