/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:26:44 by asauvage          #+#    #+#             */
/*   Updated: 2026/09/15 14:44:04 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {	
};

Base*	generate(void) {
	int	x = rand();
	if (x % 3 == 0)
		return new A;
	else if (x % 3 == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Base p type is A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Base p type is B\n";
	else
		std::cout << "Base p type is C\n";
}

void	identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "Base p type is A\n";
	}
	catch (std::exception& e) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "Base p type is B\n";
	}
	catch (std::exception& e) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "Base p type is C\n";
	}
	catch (std::exception& e) {}
}
