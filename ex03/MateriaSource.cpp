/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:33:20 by mhummel           #+#    #+#             */
/*   Updated: 2025/04/01 13:39:26 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
		learned[i] = (other.learned[i] ? other.learned[i]->clone() : NULL);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete learned[i];
			learned[i] = (other.learned[i] ? other.learned[i]->clone() : NULL);
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete learned[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!learned[i])
		{
			learned[i] = m;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (learned[i] && learned[i]->getType() == type)
			return (learned[i]->clone());
	}
	return (NULL);
}
