/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:20:56 by asauvage          #+#    #+#             */
/*   Updated: 2026/09/09 15:19:18 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctype.h>
# include <math.h>
# include <climits>

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