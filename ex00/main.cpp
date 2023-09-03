/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:33:58 by kalshaer          #+#    #+#             */
/*   Updated: 2023/08/31 11:45:26 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;

    std::cout << "--------------------" << std::endl;
    }
    {
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << std::endl;

    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl;

    i->makeSound(); //will output the animal sound!
    meta->makeSound();

    std::cout << std::endl;

    delete meta;
    delete i;
    }

    std::cout << "--------------------" << std::endl;

    {
    Cat cat;
    Cat cat2(cat);
    Cat cat3;
    cat3 = cat2;
    Dog dog;
    Dog dog2(dog);
    Dog dog3;
    dog3 = dog2;


    std::cout << std::endl;

    std::cout << cat.getType() << std::endl;
    std::cout << cat2.getType() << std::endl;
    std::cout << cat3.getType() << std::endl;
    std::cout << dog.getType() << std::endl;
    std::cout << dog2.getType() << std::endl;
    std::cout << dog3.getType() << std::endl;

    std::cout << std::endl;

    cat.makeSound();
    cat2.makeSound();
    cat3.makeSound();
    dog.makeSound();
    dog2.makeSound();
    dog3.makeSound();

    std::cout << std::endl;

    }

    std::cout << "--------------------" << std::endl;

    {
        Animal animal;
        Animal animal2(animal);
        Animal animal3;
        animal3 = animal;
        Animal animal4("any animal");
        
        std::cout << std::endl;

        std::cout << animal.getType() << std::endl;
        std::cout << animal2.getType() << std::endl;
        std::cout << animal3.getType() << std::endl;
        std::cout << animal4.getType() << std::endl;

        std::cout << std::endl;

        animal.makeSound();
        animal2.makeSound();
        animal3.makeSound();
        animal4.makeSound();

        std::cout << std::endl;
    }

    return (0);
}
