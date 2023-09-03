/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:28:51 by kalshaer          #+#    #+#             */
/*   Updated: 2023/08/24 21:01:20 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const & src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const & src)
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = src.getIdea(i);
    }
    return (*this);
}

std::string const & Brain::getIdea(int index) const
{
    return (this->_ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
    this->_ideas[index] = idea;
}

