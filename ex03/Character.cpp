/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:44:18 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/09 02:30:05 by kalshaer         ###   ########.fr       */
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
    {
        if (this->_materias[i])
        {
            delete this->_materias[i];
            this->_materias[i] = NULL;
        }
    }
}

Character & Character::operator=(Character const & src)
{
    if (this != &src)
    {
        this->_name = src._name;
        for (int i = 0; i < 4; i++)
            if (this->_materias[i])
            {
                delete this->_materias[i];
                this->_materias[i] = NULL;
            }
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
    if (m->getEquiped() == 1)
    {
        std::cout << "You can't equip the same materia twice!" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] == m)
            return ;
        if (this->_materias[i] == NULL && m != NULL)
        {
            for (int j = 0; j < MAX_LEFTOVER; j++)
            {
                if (this->_leftOver.getLeftOver()[j] == m)
                {
                    this->_materias[i] = m;
                    m->setEquiped(1);
                    this->_leftOver.getLeftOver()[j] = NULL;
                    return;
                }
            }
            this->_materias[i] = m;
            m->setEquiped(1);
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->_materias[idx])
        {
            this->_leftOver.setLeftOver(this->_materias[idx]);
            this->_materias[idx]->setEquiped(0);
            this->_materias[idx] = NULL;
        }
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_materias[idx])
    {
        if (&target == this)
        {
            std::cout << "You can't use materia on yourself!" << std::endl;
            return ;
        }
        else
        this->_materias[idx]->use(target);
    }
}

