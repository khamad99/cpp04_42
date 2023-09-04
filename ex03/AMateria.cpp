/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 08:02:24 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/04 07:13:27 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    this->_type = "Default";
}

AMateria::AMateria(std::string const & type)
{
    this->_type = type;
}

AMateria::AMateria(AMateria const & src)
{
    *this = src;
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=(AMateria const & src)
{
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}
