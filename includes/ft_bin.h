#ifndef FT_BIN_H
# define FT_BIN_H

#include "libft.h"

/*####################################################################################*/

/*
** Hexa mask for binary manipulation. (OCT define -> Keep one octet)
*/

# define OCT(x)		(0x000000FF << (x * 8))

/*
** Flag define, Area is the last octet in binary way of an integer length variable.
** This value can be changed to be 0 - 1 - 2 - 3 any other value trigger errors.
*/

# define F_AREA		3

/*
** Flag define dividing the flag area. (Note that some can be undefined but any flag
** needs to be 0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 any other value trigger errors)
*/

# define F_INDEX 7
# define F_BHASH 6
# define F_PHASH 5
# define F_NONCE 4

/* Exemple:
**
** # define F_ONE 7
**	[here the flag is set on the last bit of the octet F_AREA]
*/

/*
** Valid flag checker
*/

# define F_VLDFLAG 0x000000F0

/*####################################################################################*/

unsigned int		ft_bin_intoct(unsigned int nbr, unsigned short oct);
unsigned int		ft_bin_rplcoct(unsigned int nbr, unsigned int newoct, unsigned short oct);
unsigned int		ft_bin_incoct(unsigned int nbr, unsigned short oct);
unsigned int		ft_bin_decoct(unsigned int nbr, unsigned short oct);
unsigned int		ft_bin_valoct(unsigned int nbr, unsigned short oct, int value);
unsigned int		ft_bin_incnbr(unsigned int nbr);
unsigned int		ft_bin_addflag(unsigned int nbr, unsigned short oct, unsigned short pos);
void				ft_bin_shownbr(unsigned int nbr);
void				ft_bin_showoct(unsigned int nbr, unsigned short oct);
int					ft_bin_chkflag(unsigned int nbr, unsigned short oct, unsigned int skull);

#endif