/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:39:59 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/09 02:30:48 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    this->_equiped = 0;
}

Ice::Ice(Ice const & src) : AMateria(src)
{
    *this = src;
}

Ice::~Ice()
{
}

Ice & Ice::operator=(Ice const & src)
{
    if (this != &src)
    {
        this->_type = src._type;
        this->_equiped = src._equiped;
    }
    return (*this);
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

void Ice::setEquiped(int i)
{
    this->_equiped = i;
}

int Ice::getEquiped() const
{
    return (this->_equiped);
}
