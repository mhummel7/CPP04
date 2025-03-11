/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:13:35 by mhummel           #+#    #+#             */
/*   Updated: 2025/03/11 12:30:21 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors & Destructor
		Dog();
		Dog(const Dog& other);
		Dog &operator=(const Dog& other);
		~Dog();

		// Member Functions
		void makeSound() const;
};

#endif