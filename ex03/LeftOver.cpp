/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LeftOver.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:18:39 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/07 09:26:47 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LeftOver.hpp"

LeftOver::LeftOver()
{
    this->_leftOver = NULL;
}

LeftOver::LeftOver(LeftOver const & src)
{
    *this = src;
}

LeftOver::~LeftOver()
{
    if (this->_leftOver)
    {
        delete this->_leftOver;
        this->_leftOver = NULL;
    }
}

LeftOver & LeftOver::operator=(LeftOver const & src)
{
    if (this != &src)
        this->_leftOver = src._leftOver;
    return (*this);
}

void LeftOver::setLeftOver(AMateria* m)
{
    if (this->_leftOver)
    {
        delete this->_leftOver;
        this->_leftOver = NULL;
    }
    this->_leftOver = m;
}
