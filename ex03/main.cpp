/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:34:06 by mhummel           #+#    #+#             */
/*   Updated: 2025/03/26 13:30:10 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	// Subject's required test
	std::cout << "=== Subject's Required Test ===\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	// Additional Test 1: Full Inventory and Unequip
	std::cout << "\n=== Test 1: Full Inventory and Unequip ===\n";
	ICharacter* alice = new Character("alice");
	IMateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	AMateria* ice1 = source->createMateria("ice");
	alice->equip(ice1);
	alice->equip(source->createMateria("cure"));
	alice->equip(source->createMateria("ice"));
	alice->equip(source->createMateria("cure"));
	alice->equip(source->createMateria("ice")); // Should do nothing (full)
	alice->use(0, *alice);
	alice->unequip(0);
	delete ice1; // Lösche manuell
	alice->use(0, *alice); // Should do nothing
	delete alice;
	delete source;

	// Additional Test 2: Deep Copy
	std::cout << "\n=== Test 2: Deep Copy ===\n";
	Character original("original");
	original.equip(new Ice());
	Character copy("copy");
	copy = original;
	copy.equip(new Cure());
	original.use(0, original); // Ice
	copy.use(1, copy);        // Cure

	return 0;
}
