/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:39:23 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/09 01:23:48 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const & src);
        ~Ice();
        Ice & operator=(Ice const & src);
        AMateria* clone() const;
        void use(ICharacter& target);
        void setEquiped(int i);
        int getEquiped() const;
};

#endif