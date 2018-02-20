/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:22:18 by oozkaya           #+#    #+#             */
/*   Updated: 2018/02/20 20:01:01 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Writes the output to stdout under the control of a format string
** that specifies how following arguments are converted for output
**
** Return : The number of characters printed
** 			If an output error is encountered, -1 is returned
*/

int		ft_printf(const char *format, ...)
{
	t_buffer	buf;
	int			ret;
	va_list		ap;

	buffer_init(&buf);
	buf.fd = 1;
	va_start(ap, format);
	if ((ret = ft_core_printf(&buf, (char*)format, ap)) < 0)
		return (-1);
	va_end(ap);
	write(buf.fd, buf.str, ret);
	ft_memdel((void**)&buf.str);
	return (ret);
}

/*
** Exact analogs of ft_printf, except that it outputs to a file descriptor "fd"
**
** Return : Same as ft_printf
*/

int		ft_dprintf(int fd, const char *format, ...)
{
	t_buffer	buf;
	int			ret;
	va_list		ap;

	buffer_init(&buf);
	buf.fd = fd;
	va_start(ap, format);
	if ((ret = ft_core_printf(&buf, (char*)format, ap)) < 0)
		return (-1);
	va_end(ap);
	write(buf.fd, buf.str, ret);
	ft_memdel((void**)&buf.str);
	return (ret);
}

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_buffer	buf;
	int			ret;

	buffer_init(&buf);
	buf.fd = fd;
	if ((ret = ft_core_printf(&buf, (char*)format, ap)) < 0)
		return (-1);
	write(buf.fd, buf.str, ret);
	ft_memdel((void**)&buf.str);
	return (ret);
}
