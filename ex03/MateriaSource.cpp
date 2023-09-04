/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:01:28 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/03 21:55:21 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    for (int i = 0; i < 4; i++)
        if (src._materia[i])
            this->_materia[i] = src._materia[i]->clone();
        else
            this->_materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (this->_materia[i])
            delete this->_materia[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
            if (this->_materia[i])
                delete this->_materia[i];
        
        for (int i = 0; i < 4; i++)
            if (src._materia[i])
                this->_materia[i] = src._materia[i]->clone();
            else
                this->_materia[i] = NULL;
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_materia[i])
        {
            this->_materia[i] = m;
            break;
        }
        if ( i == 3 && this->_materia[i])
            delete m;
    }

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
        if (this->_materia[i] && this->_materia[i]->getType() == type)
            return (this->_materia[i]->clone());
    return (NULL);
}

