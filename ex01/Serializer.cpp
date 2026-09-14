/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:27:37 by asauvage          #+#    #+#             */
/*   Updated: 2026/09/14 18:11:13 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr) {
	return	reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return	reinterpret_cast<Data*>(raw);
}
