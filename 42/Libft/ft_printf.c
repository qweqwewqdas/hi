/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:01:54 by duhkim            #+#    #+#             */
/*   Updated: 2025/05/20 16:50:46 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s + i);
	}
	return (NULL);
}

static int	type_check(const char *input, va_list ap)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_print_char(va_arg(ap, int));
	else if (*input == 's')
		i += ft_print_string(va_arg(ap, char *));
	else if (*input == 'd')
		i += ft_print_int(va_arg(ap, int));
	else if (*input == 'i')
		i += ft_print_int(va_arg(ap, int));
	else if (*input == 'u')
		i += ft_print_unsigned_int(va_arg(ap, unsigned int));
	else if (*input == 'x')
		i += ft_print_hex(va_arg(ap, unsigned int), 'a');
	else if (*input == 'X')
		i += ft_print_hex(va_arg(ap, unsigned int), 'A');
	else if (*input == 'p')
		i += ft_print_pointer(va_arg(ap, unsigned long));
	else if (*input == '%')
		i += ft_print_char('%');
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			ap;
	unsigned int	i;

	i = 0;
	va_start(ap, input);
	while (*input != '\0')
	{
		if (*(input++) == '%')
		{
			if (strchr("cspdiuxX%", *input) && *input != '\0')
				i += type_check(input, ap);
			else if (*(input--) == '\0')
				i = -1;
			else
				i += ft_print_char('%');
			input++;
		}
		else
			i = i + ft_print_char(*(input - 1));
	}
	va_end(ap);
	return (i);
}
