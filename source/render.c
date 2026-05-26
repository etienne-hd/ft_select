/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:33 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 18:36:41 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "libft.h"
#include "select.h"
#include <stdint.h>
#include <sys/types.h>
#include <termcap.h>
#include <unistd.h>

static void	print_str(const char *s, uint col, uint row, t_text_style style)
{
	ft_putstr_fd(tgoto(tgetstr("cm", 0), col, row), 1);
	if (style & NORMAL)
		ft_putstr_fd(tgetstr("me", 0), 1);
	if (style & INVERT)
		ft_putstr_fd(tgetstr("mr", 0), 1);
	if (style & UNDERLINE)
		ft_putstr_fd(tgetstr("us", 0), 1);
	write(1, s, ft_strlen(s));
	if (style > NORMAL)
		ft_putstr_fd(tgetstr("me", 0), 1);
}

static void	clear_screen(void)
{
	ft_putstr_fd(tgetstr("cl", 0), 1);
}

uint8_t	get_column_size(t_ctx *ctx, uint *column_count, uint *row_length)
{
	uint	i;
	uint	length;
	uint	arg_count;
	uint8_t	is_deleted;

	*row_length = 0;
	arg_count = 0;
	i = 0;
	while (i < ctx->arg_count)
	{
		is_deleted = ctx->args_state[i / 4] & (1 << (i % 4 * 2 + DELETED));
		if (!is_deleted)
		{
			length = ft_strlen(ctx->args[i]) + MARGIN * 2;
			if (length > *row_length)
				*row_length = length;
			arg_count++;
		}
		i++;
	}
	*column_count = ctx->term.win.col / *row_length;
	return (arg_count <= *column_count * ctx->term.win.row);
}

void	render_arg(char *arg, uint arg_number, uint column_count,
		uint row_length)
{
	print_str(arg, (arg_number % column_count) * row_length + MARGIN, arg_number
		/ column_count, NORMAL);
}

void	render(t_ctx *ctx)
{
	uint	column_count;
	uint	row_length;
	uint	arg_number;
	uint	i;
	uint8_t	is_deleted;

	clear_screen();
	if (!get_column_size(ctx, &column_count, &row_length))
	{
		ft_putstr_fd("No enough space...", 1);
		return ;
	}
	arg_number = 0;
	i = 0;
	while (i < ctx->arg_count)
	{
		is_deleted = ctx->args_state[i / 4] & (1 << (i % 4 * 2 + DELETED));
		if (!is_deleted)
		{
			render_arg(ctx->args[i], arg_number, column_count, row_length);
			arg_number++;
		}
		i++;
	}
}
