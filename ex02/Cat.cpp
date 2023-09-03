/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:32:17 by kalshaer          #+#    #+#             */
/*   Updated: 2023/08/31 12:18:48 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(Cat const & src) : AAnimal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        this->_brain = new Brain(*src._brain);
    }
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

Cat & Cat::operator=(Cat const & src)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Cat makes a sound" << std::endl;
}

Brain *Cat::getBrain() const
{
    return (this->_brain);
}
