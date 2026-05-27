/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:25:04 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 00:37:46 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include "terminal.h"
#include <termcap.h>

static void	print_color(t_terminal *term, t_color color)
{
	char	ansi_color[7];

	ft_memcpy(ansi_color, "\e[0;3", 5);
	ansi_color[5] = '0' + color;
	ansi_color[6] = 'm';
	write(term->fd, ansi_color, 7);
}

void	set_style(t_terminal *term, uint8_t style, t_color color)
{
	ft_putstr_fd(tgetstr("me", 0), term->fd);
	print_color(term, color);
	if (style & INVERT)
		ft_putstr_fd(tgetstr("mr", 0), term->fd);
	if (style & UNDERLINE)
		ft_putstr_fd(tgetstr("us", 0), term->fd);
}

void	print_str(t_terminal *term, const char *s, uint col, uint row)
{
	ft_putstr_fd(tgoto(tgetstr("cm", 0), col, row), term->fd);
	write(term->fd, s, ft_strlen(s));
}

void	clear_screen(t_terminal *term)
{
	ft_putstr_fd(tgetstr("cl", 0), term->fd);
}
