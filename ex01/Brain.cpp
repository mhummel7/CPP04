/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:04:48 by mhummel           #+#    #+#             */
/*   Updated: 2025/03/12 10:59:49 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = "Empty idea";
	}
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = other.ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return (*this);
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
	{
		ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return (ideas[index]);
	}
	return ("Invalid index");
}
