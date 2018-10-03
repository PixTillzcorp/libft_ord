#ifndef FT_BIN_H
# define FT_BIN_H

#include "libft.h"

/*####################################################################################*/

/*
** Hexa mask for binary manipulation. (OCT define -> Keep one octet)
*/

# define OCT_1		0x000000FF
# define OCT_2		0x0000FF00
# define OCT_3		0x00FF0000
# define OCT_4		0xFF000000

/*
** Flag define, Area is the last octet in binary way of an integer length variable.
** This value can be changed to be 0 - 1 - 2 - 3 any other value trigger errors.
*/

# define F_AREA		3

/*
** Flag define dividing the flag area. (Note that some can be undefined but any flag
** needs to be 0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 any other value trigger errors)
*/

/* Exemple:
**
** # define F_ONE 7
**	[here the flag is set on the last bit of the octet F_AREA]
*/

/*####################################################################################*/

unsigned int		ft_bin_intoct(unsigned int nbr, unsigned short oct);
unsigned int		ft_bin_rplcoct(unsigned int nbr, unsigned int newoct, unsigned short oct);
unsigned int		ft_bin_incoct(unsigned int nbr, unsigned short oct);
unsigned int		ft_bin_decoct(unsigned int nbr, unsigned short oct);
unsigned int		ft_bin_valoct(unsigned int nbr, unsigned short oct, int value);
unsigned int		ft_bin_addflag(unsigned int nbr, unsigned short oct, unsigned short pos);
void				ft_bin_shownbr(unsigned int nbr);
void				ft_bin_showoct(unsigned int nbr, unsigned short oct);

#endif