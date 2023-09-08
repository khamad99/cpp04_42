/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LeftOver.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:18:39 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/09 02:11:35 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LeftOver.hpp"

LeftOver::LeftOver()
{
    for (int i = 0; i < MAX_LEFTOVER; i++)
        this->_leftOver[i] = NULL;
}

LeftOver::LeftOver(LeftOver const & src)
{
    if (this != &src)
    {
        int i = -1;
        while (src._leftOver[++i])
            this->_leftOver[i] = src._leftOver[i]->clone();
    }
}

LeftOver::~LeftOver()
{
    for (int i = 0; i < MAX_LEFTOVER; i++)
    {
        if (this->_leftOver[i])
        {
            delete this->_leftOver[i];
            this->_leftOver[i] = NULL;
        }
    }
}

LeftOver & LeftOver::operator=(LeftOver const & src)
{
    if (this != &src)
    {
        int i = -1;
        while (this->_leftOver[++i])
            delete this->_leftOver[i];
        i = -1;
        while (src._leftOver[++i])
            this->_leftOver[i] = src._leftOver[i]->clone();
    }
    return (*this);
}

void LeftOver::setLeftOver(AMateria* m)
{
    if (!m)
        return;
    int i = -1;
    while (this->_leftOver[++i])
    {
        if (this->_leftOver[i] == m)
            return;
    }
    this->_leftOver[i] = m;
}

AMateria **LeftOver::getLeftOver()
{
    return (this->_leftOver);
}
