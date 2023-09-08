/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 08:00:07 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/09 01:23:13 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
        int _equiped;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria const & src);
        AMateria & operator=(AMateria const & src);
        virtual ~AMateria();
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        virtual void setEquiped(int i) = 0;
        virtual int getEquiped() const = 0;
};

#endif