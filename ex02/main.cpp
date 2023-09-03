/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:33:58 by kalshaer          #+#    #+#             */
/*   Updated: 2023/08/31 12:19:49 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <string>

int main()
{
    // {
    //     AAnimal animal;
    // }

    {
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    delete j;//should not create a leak
    delete i;

    std::cout << "---------------------" << std::endl;

    Dog basic;
    basic.getBrain()->setIdea(0, "idea basic");
    std::cout << "---------------------" << std::endl;
    {
        Dog tmp = basic;
    }
    std::cout << basic.getBrain()->getIdea(0) << std::endl;
    std::cout << "---------------------" << std::endl;
    }

    std::cout << "---------------------" << std::endl;
    {
        AAnimal *animal[4];
        for (int i = 0; i < 4; i++)
        {
            if (i % 2 == 0)
                animal[i] = new Dog();
            else
                animal[i] = new Cat();
        }
        for (int i = 0; i < 4; i++)
            animal[i]->makeSound();
        for (int i = 0; i < 4; i++)
            delete animal[i];
    }
   std::cout << "---------------------" << std::endl;

    {
        Cat c;
        c.getBrain()->setIdea(0, "idea c");
        Cat cc(c);
        cc.getBrain()->setIdea(0, "idea cc");
        Cat ccc;
        ccc = c;
        ccc.getBrain()->setIdea(0, "idea ccc");
        std::cout << c.getBrain()->getIdea(0) << std::endl;
        std::cout << cc.getBrain()->getIdea(0) << std::endl;
        std::cout << ccc.getBrain()->getIdea(0) << std::endl;
    }
    
    std::cout << "---------------------" << std::endl;

    {
        Dog d;
        d.getBrain()->setIdea(0, "idea d");
        Dog dd(d);
        dd.getBrain()->setIdea(0, "idea dd");
        Dog ddd;
        ddd = d;
        ddd.getBrain()->setIdea(0, "idea ddd");
        std::cout << d.getBrain()->getIdea(0) << std::endl;
        std::cout << dd.getBrain()->getIdea(0) << std::endl;
        std::cout << ddd.getBrain()->getIdea(0) << std::endl;
    }

    return (0);
}
