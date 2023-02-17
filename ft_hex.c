/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akapusti <akapusti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:59:09 by akapusti          #+#    #+#             */
/*   Updated: 2023/02/17 18:02:25 by akapusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned long i, int *len, char cases)
{
	char	*lowercase;
	char	*uppercase;

	uppercase = "0123456789ABCDEF";
	lowercase = "0123456789abcdef";
	if (i >= 16)
	{
		ft_hex(i / 16, len, cases);
		ft_hex(i % 16, len, cases);
	}
	else
	{
		if (cases == 'x')
			ft_putchar(lowercase[i], len);
		else if (cases == 'X')
			ft_putchar(uppercase[i], len);
	}
}
