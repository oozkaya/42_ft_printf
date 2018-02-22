/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:54:34 by oozkaya           #+#    #+#             */
/*   Updated: 2018/02/22 23:46:37 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*void		is_not_color_checker(char *format)
{
	int		ret;
	char	c;

	c = *format;
	if (format[0] == '{' && format[1] == '{' && format[3] != '{')
	{
		c = *++format;
		while (c != '}')
		{
			ret = 1;
			c = *++format;
		}
	}

}*/
//#include <stdio.h>
static char	*is_not_color(t_buffer *buf, char *tab, char *format)
{
	int		i;
	int		j;
//	char	c;
	char	*begin;

	i = 0;
	begin = format;
	//c = *format;
//	printf("format_top_of_isnotcolor = %s\n", format);
	if (format[0] == '{' && format[1] == '}')
	{
		buf->clr_check2 = 1;
		return (format);
//		ft_putstr("OK\n");
	}
	if (format[0] == '{' && format[1] == '{')
	{
//		printf("format[0] = %c\n", format[0]);
//		ft_putstr("OK3\n");
		j = 1;
		while (format[j] != '}')
		{
			tab[i++] = format[j++];
//			printf("tab[%d] = %c\n", i, tab[i]);
			//c = *++format;
		}
		if (format[j] == '}')
		{
			tab[i++] = format[j++];
			//format++;
		}
		buf->clr_check2 = ft_strlen(tab);
	}
	tab[i] = '\0';
//	printf("tab = |%s|\n", tab);
	buffer_add_str(buf, tab, ft_strlen(tab));
	return (format);
}

static char	*is_color(t_buffer *buf, char *tab, char *format)
{
	int		i;
	char	c;
	char	*begin;

//	printf("format top of iscolor = %s\n", format);
	i = 0;
	c = *format;
	begin = format;
	if (c == '{')
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
//	printf("tab of iscolor = %s\n", tab);
	return (format);
}

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
//			printf("format_after_strequ = %s\n", format);
			return (format);
		}
		i++;
	}
	buf->clr_check = 1;
	return (begin);
}

static char	*ft_tab_color(t_buffer *buf, char *format)
{
	char					tab[20];
	static const t_color	tab_color[] = {{ "eoc", "\033[0m" },
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

char	*color_applier1(t_buffer *buf, char *format)
{
	char	*color;

//	ft_putstr("\033[33mAPPLIER1\n\033[0m");
	/*if ((color = ft_strchr(format, '{')) != NULL)
	{	
		buffer_add_str(buf, format, color - format);
		format = ft_tab_color(buf, color);
	}
	return (format);*/
	if ((color = ft_strchr(format, '{')) != NULL)
	{
		buffer_add_str(buf, format, color - format);
		format = ft_tab_color(buf, color);
//		printf("applier1 format after tab_color = %s", format);
		if (buf->clr_check2 > 1)
		{
			format += buf->clr_check2 + 2;
//			printf("format = %s\n", format);
			return (format);
		}
		else if ((buf->clr_counter > 7 || buf->clr_check == 1)
			&& buf->clr_check2 == 1)
		{
				buffer_add_str(buf, format, 2);
				format += 2;
		}
		else if (buf->clr_counter > 7 || buf->clr_check == 1)
		{
//			printf("AAAAAAAAAbuf->clr_counter = %d\n", buf->clr_counter);
			buffer_add_str(buf, format, buf->clr_counter);
			format += buf->clr_counter;
		}
	}
//	ft_putstr("\033[33mEND_APPLIER1\n\033[0m");
	return (format);
}
char	*color_applier2(t_buffer *buf, char *format)
{
	char	*color;

//	ft_putstr("\033[35mAPPLIER2\n\033[0m");
	while ((color = ft_strchr(format, '{')) != NULL)
	{
//		printf("format_APPLIER2_before_tabcolor = %s\n", format);
		buffer_add_str(buf, format, color - format);
		format = ft_tab_color(buf, color);
//		printf("format_APPLIER2_after_tabcolor = %s\n", format);
		if (buf->clr_check2 > 1)
		{
			format += buf->clr_check2 + 2;
//			printf("format_after_buf_check2 = %s\n", format);
			continue ;
		}
		else if ((buf->clr_counter > 7 || buf->clr_check == 1)
			&& buf->clr_check2 == 1)
		{
				buffer_add_str(buf, format, 2);
				format += 2;
		}
		else if (buf->clr_counter > 7 || buf->clr_check == 1)
		{
			buffer_add_str(buf, format, buf->clr_counter);
			format += buf->clr_counter;
		}
	}
//	ft_putstr("\033[35mEND_APPLIER2\n\033[0m");
	return (format);
}
