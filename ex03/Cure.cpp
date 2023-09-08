/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:36:20 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/09 02:30:37 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    this->_equiped = 0;
}

Cure::Cure(Cure const & src) : AMateria(src)
{
    *this = src;
}

Cure::~Cure()
{
}

Cure & Cure::operator=(Cure const & src)
{
    if (this != &src)
    {
        this->_type = src._type;
        this->_equiped = src._equiped;
    }
    return (*this);
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

void Cure::setEquiped(int i)
{
    this->_equiped = i;
}

int Cure::getEquiped() const
{
    return (this->_equiped);
}