/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:23:18 by asauvage          #+#    #+#             */
/*   Updated: 2026/09/14 18:18:31 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <stdint.h>

struct	Data {
	int			id;
	std::string	name;
	float		size;
};

class	Serializer {
	public:
		static	uintptr_t	serialize(Data* ptr);
		static	Data*		deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer( const Serializer& obj );
		Serializer	operator=( const Serializer& rhs );
		~Serializer();
};

#endif