/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LeftOver.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:16:01 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/04 13:21:44 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEFTOVER_HPP
# define LEFTOVER_HPP

# include <iostream>
# include "AMateria.hpp"

class LeftOver
{
    private:
        AMateria* _leftOver;
    public:
        LeftOver();
        LeftOver(LeftOver const & src);
        ~LeftOver();
        LeftOver & operator=(LeftOver const & src);
        void setLeftOver(AMateria* m);
};

#endif