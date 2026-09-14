/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:20:56 by asauvage          #+#    #+#             */
/*   Updated: 2026/09/14 16:54:37 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <ctype.h>
# include <math.h>
# include <climits>
# include <limits.h>
# include <float.h>

class	ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter& obj );
		ScalarConverter	operator=( const ScalarConverter& rhs );
		~ScalarConverter();
	public:
		static void	convert( const std::string& str );
};

#endif