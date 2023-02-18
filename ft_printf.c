/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akapusti <akapusti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:40:58 by akapusti          #+#    #+#             */
/*   Updated: 2023/02/18 15:26:23 by akapusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char *format, va_list args, int *len)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (*format == 's')
		ft_string(va_arg(args, char *), len);
	else if (*format == 'p')
		ft_pointer(va_arg(args, void *), len);
	else if (*format == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (*format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (*format == 'u')
		ft_unsigned(va_arg(args, unsigned int), len);
	else if (*format == 'x')
		ft_hex(va_arg(args, unsigned int), len, 'x');
	else if (*format == 'X')
		ft_hex(va_arg(args, unsigned int), len, 'X');
	else if (*format == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(format, args, &len);
			format++;
		}
		else
			ft_putchar(*format++, &len);
	}
	va_end(args);
	return (len);
}

/*#include "stdio.h"

int	main(void)
{
	char	*arr;
	int	n, res1, res2;
	char	c;
	unsigned int	p;
	arr = "Hello, I'm Nastya 123";
 	n = -2647678;
	c = 'a';
	p  = 1997;
	res1 = ft_printf("it is %c\n", c);
	res2 = printf("it is %c\n", c);
	res1 = ft_printf("%s", arr);
	res2 = printf("%s", arr);
	res1 = ft_printf("void*: %p %p\n", 0, 0);
	res2 = printf("void*: %p %p\n", 0, 0);
	res1 = ft_printf("show  %d\t \n", n);
	res2 = printf("show  %d\t \n", n);
	res1 = ft_printf("int %i\n", n);
	res2 = printf("int %i\n", n);
	res1 = ft_printf("unsigned %u\n", p);
	res2 = printf("unsigned %u\n", p);
	res1 = ft_printf("hex lower %x\n", p);
	res2 = printf("hex lower %x\n", p);
	res1 = ft_printf("hex upper %X\n", p);
	res2 = printf("hex upper %X\n", p);
	res1 = ft_printf("percent %%\n");
	res2 = printf("percent %%\n");
	
	printf ("%i - %i\n", res1, res2);
}*/
