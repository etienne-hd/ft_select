/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:33 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 00:39:34 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "display.h"
#include "libft.h"
#include "select.h"
#include "terminal.h"
#include <stdint.h>
#include <sys/types.h>
#include <termcap.h>
#include <unistd.h>

void	render_arg(t_ctx *ctx, uint real_choice_index, uint choice_index)
{
	uint8_t	style;

	style = NORMAL;
	if (ctx->choice_state[real_choice_index] & SELECTED)
		style |= INVERT;
	if (choice_index == ctx->hover_choice)
		style |= UNDERLINE;
	set_style(&ctx->term, style, WHITE);
	print_str(&ctx->term, ctx->choices[real_choice_index], (choice_index
			% ctx->grid.col) * ctx->grid.row + MARGIN, choice_index
		/ ctx->grid.col);
	set_style(&ctx->term, NORMAL, WHITE);
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
		* (ctx->term.win.row - 1);
}

static void	render_dynamic_search(t_ctx *ctx)
{
	uint	i;

	i = 0;
	set_style(&ctx->term, INVERT, WHITE);
	while (i < ctx->term.win.col)
		print_str(&ctx->term, " ", i++, ctx->term.win.row);
	print_str(&ctx->term, "Search: ", 0, ctx->term.win.row);
	print_str(&ctx->term, ctx->search, 8, ctx->term.win.row);
	set_style(&ctx->term, NORMAL, WHITE);
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
		set_style(&ctx->term, INVERT, RED);
		print_str(&ctx->term, "No enough space!", ctx->term.win.col / 2
			- ft_strlen("No enough space!") / 2, ctx->term.win.row / 2);
		set_style(&ctx->term, NORMAL, WHITE);
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
	render_dynamic_search(ctx);
}
