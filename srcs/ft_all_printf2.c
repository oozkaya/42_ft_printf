/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_printf2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:03:43 by oozkaya           #+#    #+#             */
/*   Updated: 2018/02/20 22:30:07 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Exact analogs of ft_printf and ft_vprintf,
** except that they write to a string "str"
**
** Return : Same as ft_printf
*/

int		ft_sprintf(char *str, const char *format, ...)
{
	t_buffer	buf;
	int			ret;
	va_list		ap;

	buffer_init(&buf);
	va_start(ap, format);
	if ((ret = ft_core_printf(&buf, (char *)format, ap)) < 0)
		return (-1);
	va_end(ap);
	if (!(str = ft_strdup(buf.str)))
		return (-1);
	ft_memdel((void **)&buf.str);
	return (ret);
}

int		ft_vsprintf(char *str, const char *format, va_list ap)
{
	t_buffer	buf;
	int			ret;

	buffer_init(&buf);
	if ((ret = ft_core_printf(&buf, (char *)format, ap)) < 0)
		return (-1);
	if (!(str = ft_strdup(buf.str)))
		return (-1);
	ft_memdel((void **)&buf.str);
	return (ret);
}

/*
** Same as above, except they write at most "size" bytes
** (including the terminating null byte ('\0')) to "str"
*/

int		ft_snprintf(char *str, size_t size, const char *format, ...)
{
	t_buffer	buf;
	int			ret;
	va_list		ap;

	buffer_init(&buf);
	va_start(ap, format);
	if ((ret = ft_core_printf(&buf, (char *)format, ap)) < 0)
		return (-1);
	va_end(ap);
	if (!(str = ft_strndup(buf.str, size)))
		return (-1);
	ft_memdel((void **)&buf.str);
	return (ret);
}

int		ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	t_buffer	buf;
	int			ret;

	buffer_init(&buf);
	if ((ret = ft_core_printf(&buf, (char *)format, ap)) < 0)
		return (-1);
	if (!(str = ft_strndup(buf.str, size)))
		return (-1);
	ft_memdel((void **)&buf.str);
	return (ret);
}
