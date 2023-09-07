/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:02:58 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/07 14:34:35 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"


int main()
{
    {
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
    }

    std::cout << "---------------------" << std::endl;

    {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->unequip(0);

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->use(5, *bob);
    
    me->equip(src->createMateria("ice"));
    me->use(0, *bob);
    
    delete bob;
    delete me;
    delete src;
    
    }

    std::cout << "---------------------" << std::endl;

    {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
  

    ICharacter* me = new Character("me");

    me->equip(src->createMateria("ice"));

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->use(5, *bob);

    
    delete bob;
    delete me;
    delete src;
    
    }

    std::cout << "---------------------" << std::endl;

    {
    Ice *ice = new Ice();
    Cure *cure = new Cure();
    AMateria *ice2 = ice->clone();
    AMateria *cure2 = cure->clone();
    
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    me->equip(ice);
    me->equip(cure);
    me->equip(ice2);
    me->equip(cure2);


    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->use(5, *bob);

    delete bob;
    delete me;
    }
    std::cout << "---------------------" << std::endl;
    {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	Character p1("kkk");
	Character p2("hhh");
	p2.equip(src->createMateria("ice"));
	p1 = p2;

    p2.use(0, p1);
    p1.use(0, p2);

	delete src;
    }

    std::cout << "---------------------" << std::endl;

    {
	MateriaSource src;
    Character p1("khaled");
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    MateriaSource src2(src);
    MateriaSource src3;
    src3 = src;

    }

    std::cout << "---------------------" << std::endl;

    {
	AMateria *m1 = new Ice();
    AMateria *m2;
    m2 = m1;
    AMateria *m3(m2);

    Character p1("kkk");
	Character p2("hhh");

    p1.equip(m1);
    p1.equip(m2);
    p1.equip(m3);



    p1.use(0, p2);
    p1.use(1, p2);
    p1.use(2, p2);
    
    
    }

    return 0;
}