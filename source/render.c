/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:33 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 02:39:30 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "libft.h"
#include <termcap.h>
#include <unistd.h>

static void	print_str(const char *s, uint col, uint row)
{
	ft_putstr_fd(tgoto(tgetstr("cm", 0), col, row), 1);
	write(1, s, ft_strlen(s));
}

static void	clear_screen(void)
{
	ft_putstr_fd(tgetstr("cl", 0), 1);
}

void	render(t_ctx *ctx)
{
	const char message[] = "Hello, World!";
	clear_screen();
	uint pos_row = ctx->term.win.row / 2;
	uint pos_col = ctx->term.win.col / 2 - ft_strlen(message) / 2;
	print_str(message, pos_col, pos_row);
}