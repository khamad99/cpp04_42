/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:42:24 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/04 13:21:46 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "LeftOver.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_materias[4];
        LeftOver _leftOver;
    public:
        Character();
        Character(std::string const & name);
        Character(Character const & src);
        Character & operator=(Character const & src);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif