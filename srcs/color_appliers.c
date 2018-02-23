/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_appliers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:00:06 by oozkaya           #+#    #+#             */
/*   Updated: 2018/02/23 12:09:47 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*color_applier1(t_buffer *buf, char *format)
{
	char	*color;

	if ((color = ft_strchr(format, '{')) != NULL)
	{
		buffer_add_str(buf, format, color - format);
		format = ft_tab_color(buf, color);
		if (buf->clr_check2 > 1)
		{
			format += buf->clr_check2 + 2;
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
			buffer_add_str(buf, format, buf->clr_counter);
			format += buf->clr_counter;
		}
	}
	return (format);
}

char	*color_applier2(t_buffer *buf, char *format)
{
	char	*color;

	while ((color = ft_strchr(format, '{')) != NULL)
	{
		buffer_add_str(buf, format, color - format);
		format = ft_tab_color(buf, color);
		if (buf->clr_check2 > 1)
		{
			format += buf->clr_check2 + 2;
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
	return (format);
}
