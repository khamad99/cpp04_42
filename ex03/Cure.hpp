/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:35:10 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/09 01:23:29 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const & src);
        ~Cure();
        Cure & operator=(Cure const & src);
        AMateria* clone() const;
        void use(ICharacter& target);
        void setEquiped(int i);
        int getEquiped() const;
};

#endif