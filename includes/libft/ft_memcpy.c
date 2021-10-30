/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:59:04 by htumanya          #+#    #+#             */
/*   Updated: 2021/10/24 19:21:38 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*temp;

	if (!dst && !src)
		return (NULL);
	source = (const unsigned char *)src;
	temp = (unsigned char *)dst;
	while (n)
	{
		*temp = *source;
		++source;
		++temp;
		--n;
	}
	return (dst);
}
