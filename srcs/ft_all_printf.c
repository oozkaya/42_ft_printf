/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:22:18 by oozkaya           #+#    #+#             */
/*   Updated: 2018/02/20 15:22:22 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
