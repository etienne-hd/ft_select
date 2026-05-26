/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:33 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 00:48:52 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "libft.h"
#include "select.h"
#include "terminal.h"
#include <stdint.h>
#include <sys/types.h>
#include <termcap.h>
#include <unistd.h>

static void	print_str(t_terminal *term, const char *s, uint col, uint row,
		t_text_style style)
{
	ft_putstr_fd(tgoto(tgetstr("cm", 0), col, row), term->fd);
	if (style & NORMAL)
		ft_putstr_fd(tgetstr("me", 0), term->fd);
	if (style & INVERT)
		ft_putstr_fd(tgetstr("mr", 0), term->fd);
	if (style & UNDERLINE)
		ft_putstr_fd(tgetstr("us", 0), term->fd);
	write(term->fd, s, ft_strlen(s));
	if (style > NORMAL)
		ft_putstr_fd(tgetstr("me", 0), term->fd);
}

static void	clear_screen(t_terminal *term)
{
	ft_putstr_fd(tgetstr("cl", 0), term->fd);
}

void	render_arg(t_ctx *ctx, uint real_choice_index, uint choice_index)
{
	t_text_style	style;

	style = NORMAL;
	if (ctx->choice_state[real_choice_index] & SELECTED)
		style |= INVERT;
	if (choice_index == ctx->hover_choice)
		style |= UNDERLINE;
	print_str(&ctx->term, ctx->choices[real_choice_index], (choice_index
			% ctx->grid.col) * ctx->grid.row + MARGIN, choice_index
		/ ctx->grid.col, style);
}

static void	refresh_grid(t_ctx *ctx)
{
	uint	i;
	uint	current_length;
	uint8_t	is_deleted;

	ctx->grid.row = 0;
	i = 0;
	while (i < ctx->choice_count)
	{
		is_deleted = ctx->choice_state[i] & DELETED;
		if (!is_deleted)
		{
			current_length = ft_strlen(ctx->choices[i]) + MARGIN * 2;
			if (current_length > ctx->grid.row)
				ctx->grid.row = current_length;
		}
		i++;
	}
	ctx->grid.col = ctx->term.win.col / ctx->grid.row;
	ctx->grid.is_displayable = ctx->alive_choice_count <= ctx->grid.col
		* ctx->term.win.row;
}

void	render(t_ctx *ctx)
{
	uint	choice_index;
	uint	real_choice_index;
	uint8_t	is_deleted;

	refresh_grid(ctx);
	clear_screen(&ctx->term);
	if (!ctx->grid.is_displayable)
	{
		print_str(&ctx->term, "No enough space!", 0, 0, INVERT);
		return ;
	}
	choice_index = 0;
	real_choice_index = 0;
	while (real_choice_index < ctx->choice_count)
	{
		is_deleted = ctx->choice_state[real_choice_index] & DELETED;
		if (!is_deleted)
		{
			render_arg(ctx, real_choice_index, choice_index);
			choice_index++;
		}
		real_choice_index++;
	}
}
