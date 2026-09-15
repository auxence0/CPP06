/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:18:59 by asauvage          #+#    #+#             */
/*   Updated: 2026/09/15 14:41:47 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
	
int	main() {
	std::srand(std::time(NULL));
	Base*	banane = generate();
	Base*	kiwi = generate();
	Base*	Goyave = generate();
	identify(banane);
	identify(*banane);
	identify(kiwi);
	identify(*kiwi);
	identify(Goyave);
	identify(*Goyave);
}