/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:29:46 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/08 20:44:18 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "Animal parametric constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & src)
{
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

std::string AAnimal::getType() const
{
    return (this->_type);
}