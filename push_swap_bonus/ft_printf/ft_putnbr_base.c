/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:45:53 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/27 11:45:58 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putnbr_base(long nbr, char *base)
{
	long	len_base;
	int		count;

	len_base = (long)ft_strlen1(base);
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr_base(-nbr, base);
	}
	if (nbr < len_base)
		count += ft_putchar(base[nbr % len_base]);
	else
	{
		count += ft_putnbr_base((nbr / len_base), base);
		count += ft_putnbr_base((nbr % len_base), base);
	}
	return (count);
}
