/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:33 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 02:41:22 by ehode            ###   ########.fr       */
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

static uint8_t	render_search_arg(t_ctx *ctx, uint8_t style,
		uint real_choice_index, uint choice_index)
{
	char	tmp;
	uint8_t	offset;

	offset = 0;
	if (ctx->choice_state[real_choice_index] & SEARCHED
		&& !(ctx->choice_state[real_choice_index] & SELECTED))
	{
		set_style(&ctx->term, style | INVERT, YELLOW);
		tmp = ctx->choices[real_choice_index][ctx->search_cursor];
		ctx->choices[real_choice_index][ctx->search_cursor] = 0;
		print_str(&ctx->term, ctx->choices[real_choice_index], (choice_index
				% ctx->grid.col) * ctx->grid.row + MARGIN, choice_index
			/ ctx->grid.col);
		offset += ctx->search_cursor;
		ctx->choices[real_choice_index][ctx->search_cursor] = tmp;
		set_style(&ctx->term, NORMAL, WHITE);
	}
	return (offset);
}

void	render_arg(t_ctx *ctx, uint real_choice_index, uint choice_index)
{
	uint8_t	style;
	uint	offset;

	style = NORMAL;
	if (ctx->choice_state[real_choice_index] & SELECTED)
		style |= INVERT;
	if (choice_index == ctx->hover_choice)
		style |= UNDERLINE;
	offset = render_search_arg(ctx, style, real_choice_index, choice_index);
	set_style(&ctx->term, style, WHITE);
	print_str(&ctx->term, ctx->choices[real_choice_index] + offset,
		(choice_index % ctx->grid.col) * ctx->grid.row + MARGIN + offset,
		choice_index / ctx->grid.col);
	set_style(&ctx->term, NORMAL, WHITE);
}

static void	render_search_footer(t_ctx *ctx)
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

	calculate_grid(ctx);
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
	render_search_footer(ctx);
}
