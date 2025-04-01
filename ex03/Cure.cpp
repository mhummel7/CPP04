/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:27:27 by mhummel           #+#    #+#             */
/*   Updated: 2025/04/01 13:39:14 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &other) : AMateria(other)
{
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
