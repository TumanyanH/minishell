/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:03:35 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/11 20:41:19 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(unsigned long long nbr)
{
	int	i;

	if (nbr <= 0)
		i = 1;
	else
		i = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		nbr /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(unsigned long long n)
{
	char				*str;
	unsigned long long	nbr;
	int					len;

	nbr = n;
	len = nbrlen(nbr);
	str = malloc(sizeof(unsigned char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	if (nbr == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nbr)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
		--len;
	}
	return (str);
}
