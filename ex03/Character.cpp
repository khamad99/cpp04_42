/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:44:18 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/04 13:23:54 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Defult")
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;    
}

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
}

Character::Character(Character const & src)
{
    this->_name = src._name;
    for (int i = 0; i < 4; i++)
        if (src._materias[i])
            this->_materias[i] = src._materias[i]->clone();
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (this->_materias[i])
            delete this->_materias[i];
}

Character & Character::operator=(Character const & src)
{
    if (this != &src)
    {
        this->_name = src._name;
        for (int i = 0; i < 4; i++)
            if (this->_materias[i])
                delete this->_materias[i];
        for (int i = 0; i < 4; i++)
            if (src._materias[i])
                this->_materias[i] = src._materias[i]->clone();
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_materias[i])
        {
            this->_materias[i] = m;
            break;
        }
        if ( i == 3 && this->_materias[i])
            delete m;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        this->_leftOver.setLeftOver(this->_materias[idx]);
        this->_materias[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_materias[idx])
        this->_materias[idx]->use(target);
}

