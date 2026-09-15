/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:26:48 by asauvage          #+#    #+#             */
/*   Updated: 2026/09/15 14:43:18 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <stdlib.h>
# include <ctime>
# include <iostream>

class	Base {
	public:
		virtual ~Base();
};

class	A: public Base {
	
};

class	B: public Base {
	
};

class	C: public Base {
	
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif