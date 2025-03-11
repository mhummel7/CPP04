/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:14:08 by mhummel           #+#    #+#             */
/*   Updated: 2025/03/04 13:25:11 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors & Destructor
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat &operator=(const WrongCat& other);
		~WrongCat();

		// Member Functions
		void makeSound() const; // Not virtual in base class
};

#endif