/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:23:43 by oozkaya           #+#    #+#             */
/*   Updated: 2018/02/22 15:25:04 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Parses the "format" to check all the existing flags (' ', '0', '+', '-', '#')
**
** Return : The "format" left after the parsing
*/

char	*flags_parser(char *format, t_format *fmt)
{
	char	c;

	c = *format;
	while (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
	{
		if (c == '#')
			fmt->hashtag = 1;
		else if (c == '0')
			fmt->zero = 1;
		else if (c == '-')
			fmt->minus = 1;
		else if (c == ' ')
			fmt->space = 1;
		else if (c == '+')
			fmt->plus = 1;
		c = *++format;
	}
	return (format);
}

/*
** Parses the "format" to check the width field
**
** Return : The "format" left after the parsing
*/

char	*width_parser(char *format, t_format *fmt, va_list ap)
{
	char	c;

	c = *format;
	if (c == '*')
	{
		fmt->width = va_arg(ap, int);
		if (fmt->width < 0)
		{
			fmt->minus = 1;
			fmt->width = -(fmt->width);
		}
		format++;
		return (format);
	}
	while (ft_isdigit(c))
	{
		fmt->width = fmt->width * 10 + (c - '0');
		c = *++format;
	}
	return (format);
}

/*
** Parses the "format" to check the precision field
**
** Return : The "format" left after the parsing
*/

char	*precision_parser(char *format, t_format *fmt, va_list ap)
{
	char	c;

	if (format[0] == '.' && format[1] == '*')
	{
		fmt->prec = va_arg(ap, int);
		format += 2;
		fmt->prec_activated = 1;
		return (format);
	}
	c = *format;
	if (c == '.')
	{
		c = *++format;
		while (ft_isdigit(c))
		{
			fmt->prec = fmt->prec * 10 + (c - '0');
			c = *++format;
			fmt->prec_activated = 1;
		}
		fmt->prec_dot_activated = 1;
	}
	return (format);
}

/*
** Parses the "format" to check the type size
**
** Return : The "format" left after the parsing
*/

char	*type_size_parser(char *format, t_format *fmt)
{
	char	c;

	c = *format;
	if (c != 'h' && c != 'l' && c != 'j' && c != 'z')
		return (format);
	if (c == 'h' && format[1] == 'h')
	{
		fmt->type_size = 'H';
		format += 2;
	}
	else if (c == 'l' && format[1] == 'l')
	{
		fmt->type_size = 'L';
		format += 2;
	}
	else
	{
		fmt->type_size = c;
		format += 1;
	}
	return (format);
}

/*
** Parses the "format" to check the conversion field
**
** Return : If an error occured, returns 0
*/

int		conv_parser(char c, t_format *fmt)
{
	if (c == 'd' || c == 'i')
		fmt->conv = 'd';
	else if (c == 'c' || c == 's' || c == 'S' || c == 'C' || c == '%')
		fmt->conv = c;
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
		fmt->conv = c;
	else if (c == 'b')
		fmt->conv = c;
	else if (c == 'D' || c == 'O' || c == 'U')
	{
		fmt->type_size = 'L';
		fmt->conv = c + 32;
	}
	else
	{
		fmt->conv = 'c';
		fmt->no_conv = c;
	}
	return (fmt->conv != 0);
}
#include <stdio.h>
char	*color_parser(t_buffer *buf, char *format)
{
	char					c;
	int						i;
	char					tab[8];
	int						color_len;
	static const t_color	tab_color[] = {{ "eoc", "\033[0m" },
		{ "black", "\033[30m" },
		{ "red", "\033[31m" },
		{ "green", "\033[32m" },
		{ "brown", "\033[33m" },
		{ "blue", "\033[34m" },
		{ "magenta", "\033[35m" },
		{ "cyan", "\033[36m" },
		{ "gray", "\033[37m" },
		{ NULL, NULL }
	};
//	if (format[0] == '{' && format[1] == '{')
//		return (format);
	//ft_putstr("OK\n");
	i = 0;
	c = *format;
	if (c == '{')
	{
		c = *++format;
		while (c != '}')
		{
			tab[i++] = ft_tolower(c);
			c = *++format;
		}
		if (c == '}')
			format++;
	}
	tab[i] = '\0';
	//ft_putstr("tab = |");
	//ft_putstr(tab);
	//ft_putstr("|\n");
	//ft_putstr("OK2\n");
	//printf("tab = %s", tab);
	i = 0;
	while (tab_color[i].clr)
	{
		if (ft_strequ(tab_color[i].clr, tab))
		{
			color_len = ft_strlen(tab_color[i].clr_code); 
			buffer_add_str(buf, tab_color[i].clr_code, color_len);
			buf->color_len += color_len;
		}
		i++;
	}
	//ft_putstr(buf->str);
	return (format);
}
