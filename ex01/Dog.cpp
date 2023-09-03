/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:35:09 by kalshaer          #+#    #+#             */
/*   Updated: 2023/08/31 12:13:48 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(Dog const & src) : Animal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        this->_brain = new Brain(*src._brain);
    }
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

Dog & Dog::operator=(Dog const & src)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Dog makes a sound" << std::endl;
}

Brain *Dog::getBrain() const
{
    return (this->_brain);
}