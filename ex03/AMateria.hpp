/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:19:25 by mhummel           #+#    #+#             */
/*   Updated: 2025/03/26 13:29:52 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type; // The materia type

	public:
		AMateria(std::string const & type); // Constructor
		virtual ~AMateria(); // Virtual destructor

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0; // Returns a new instance of the materia
		virtual void use(ICharacter& target); // Uses the materia on the target
};

#endif
