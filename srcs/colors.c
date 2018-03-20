/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:54:34 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/20 10:24:52 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks for all the non_color cases (like "{}")
** Adds the "tab" of the non_color to the buffer, filled or not
**
** Return : The "format" after the parsing
*/

static char	*is_not_color(t_buffer *buf, char *tab, char *format)
{
	int		i;
	int		j;

	i = 0;
	if (format[0] == '{' && format[1] == '}')
	{
		buf->clr_check2 = 1;
		return (format);
	}
	if (format[0] == '{' && format[1] == '{' && format[3] != '}')
	{
		j = 1;
		while (format[j] != '}')
			tab[i++] = format[j++];
		if (format[j] == '}')
			tab[i++] = format[j++];
		buf->clr_check2 = ft_strlen(tab);
	}
	tab[i] = '\0';
	buffer_add_str(buf, tab, ft_strlen(tab));
	return (format);
}

/*
** If the color is existing, stores it into "tab"
** If the color name is longer than the maximun allowed, then nothing is done
** and we return the beginning format to be treated like a normal string
**
** Return : The "format" after the parsing
*/

static char	*is_color(t_buffer *buf, char *tab, char *format)
{
	int		i;
	char	c;
	char	*begin;

	i = 0;
	c = *format;
	begin = format;
	if (format[0] == '{' && (format[1] != '{' || format[1] != '}'))
	{
		c = *++format;
		while (c != '}')
		{
			if (buf->clr_counter <= 7)
				tab[i++] = ft_tolower(c);
			c = *++format;
			buf->clr_counter++;
		}
		if (c == '}')
			format++;
	}
	if (buf->clr_counter > 7)
		return (begin);
	tab[i] = '\0';
	return (format);
}

/*
** Main color parsing function
** Checks if the word between the brackets ('{' and '}') is a color or not,
** and then finds out which color code we need if it's a real color
**
** Return : The "format" after the parsing
*/

static char	*color_parser(t_buffer *buf, const t_color *tab_color, char *tab,
							char *format)
{
	int		i;
	int		color_len;
	char	*begin;
	int		check;

	check = 0;
	begin = format;
	format = is_not_color(buf, tab, format);
	if (buf->clr_check2 == 0)
		format = is_color(buf, tab, format);
	i = 0;
	while (tab_color[i].clr)
	{
		if (ft_strequ(tab_color[i].clr, tab))
		{
			color_len = ft_strlen(tab_color[i].clr_code);
			buffer_add_str(buf, tab_color[i].clr_code, color_len);
			buf->clr_len += color_len;
			return (format);
		}
		i++;
	}
	buf->clr_check = 1;
	return (begin);
}

/*
** Initializes "tab_color" and "buf->clr" variables for the parsing
**
** Return : The "format" after the parsing
*/

char		*ft_tab_color(t_buffer *buf, char *format)
{
	char					tab[20];
	static const t_color	tab_color[] = {{ "eoc", "\033[00m" },
		{ "black", "\033[30m" },
		{ "red", "\033[31m" },
		{ "green", "\033[32m" },
		{ "yellow", "\033[33m" },
		{ "blue", "\033[34m" },
		{ "magenta", "\033[35m" },
		{ "cyan", "\033[36m" },
		{ "gray", "\033[37m" },
		{ NULL, NULL }
	};

	ft_bzero(tab, 20);
	buf->clr_counter = 0;
	buf->clr_check = 0;
	buf->clr_check2 = 0;
	return (color_parser(buf, tab_color, tab, format));
}
