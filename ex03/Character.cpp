/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:29:03 by mhummel           #+#    #+#             */
/*   Updated: 2025/04/01 13:39:10 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = (other.inventory[i] ? other.inventory[i]->clone() : NULL);
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];
			inventory[i] = (other.inventory[i] ? other.inventory[i]->clone() : NULL);
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete inventory[i];
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		inventory[idx] = NULL; // dont delete, just empty
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}
