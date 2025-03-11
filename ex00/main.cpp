/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:10:41 by mhummel           #+#    #+#             */
/*   Updated: 2025/03/11 12:45:29 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* wrongMeta = new WrongAnimal();
const WrongAnimal* wrongJ = new WrongCat();

std::cout << "\n" << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << wrongJ->getType() << " \n" << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
wrongJ->makeSound(); // wont say wrongMeow! wrongMeow! because doesnt have virtual keyword
meta->makeSound();
wrongMeta->makeSound();
return 0;
}
