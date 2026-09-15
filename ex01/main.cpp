/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 18:05:34 by asauvage          #+#    #+#             */
/*   Updated: 2026/09/15 14:52:50 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data	dta;
	
	dta.id = 0;
	dta.name = "auxence";
	dta.size = 1.73;
	uintptr_t	ptr = Serializer::serialize(&dta);
	std::cout << std::hex << "unitptr_t: address: " << ptr << "\n" << std::dec;
	std::cout << "dta: address: " << &dta << "\n";
	Data*	dta_deserialize = Serializer::deserialize(ptr);
	std::cout << "After Serializer\n";
	std::cout << "id: " << dta_deserialize->id << "\n";
	std::cout << "name: " << dta_deserialize->name << "\n";
	std::cout << "size: " << dta_deserialize->size << "\n";
}
