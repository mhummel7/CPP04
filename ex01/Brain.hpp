/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:03:48 by mhummel           #+#    #+#             */
/*   Updated: 2025/03/12 10:59:52 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain &operator=(const Brain& other);
		~Brain();

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};

#endif
