/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:06:36 by mhummel           #+#    #+#             */
/*   Updated: 2025/03/12 11:23:25 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	// Subject's required main
	std::cout << "=== Subject's Required Tests ===" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j; // should not create a leak
	delete i;

	// My own tests

	// Test 1: Array of Animals
	std::cout << "\n=== Test 1: Array of Animals ===" << std::endl;
	const int arraySize = 4;
	Animal *animals[arraySize];
	for (int k = 0; k < arraySize; ++k)
	{
		if (k < arraySize / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	for (int k = 0; k < arraySize; ++k)
	{
		animals[k]->makeSound();
	}
	for (int k = 0; k < arraySize; ++k)
	{
		delete animals[k];
	}

	// Test 2: Deep Copying
	std::cout << "\n=== Test 2: Deep Copying ===" << std::endl;
	Dog originalDog;
	originalDog.setIdea(0, "Chase ball\n");
	Dog copiedDog(originalDog); // Copy constructor
	copiedDog.setIdea(0, "Bark");
	std::cout << "Original Dog: " << originalDog.getIdea(0) << "Copied Dog: " << copiedDog.getIdea(0) << std::endl;

	Cat originalCat;
	originalCat.setIdea(0, "Sleep");
	Cat assignedCat = originalCat; // Assignment operator
	assignedCat.setIdea(0, "Scratch");
	std::cout << "Original Cat: " << originalCat.getIdea(0) << "Assigned Cat: " << assignedCat.getIdea(0) << std::endl;

	return (0);
}
