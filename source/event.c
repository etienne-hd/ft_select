/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:35 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 04:47:08 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "keyboard.h"
#include "select.h"
#include "utils.h"
#include <stdint.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>

static void	on_arrow_key(t_ctx *ctx, t_key *key)
{
	if (key->code == KEY_ARROW_LEFT)
	{
		if (ctx->hover_choice == 0)
			ctx->hover_choice = ctx->alive_choice_count - 1;
		else
			ctx->hover_choice--;
	}
	else if (key->code == KEY_ARROW_RIGHT)
	{
		if (ctx->hover_choice == ctx->alive_choice_count - 1)
			ctx->hover_choice = 0;
		else
			ctx->hover_choice++;
	}
	else if (key->code == KEY_ARROW_UP)
	{
		if (ctx->hover_choice / ctx->grid.col != 0)
			ctx->hover_choice -= ctx->grid.col;
	}
	else if (key->code == KEY_ARROW_DOWN)
	{
		if (ctx->hover_choice + ctx->grid.col < ctx->alive_choice_count)
			ctx->hover_choice += ctx->grid.col;
	}
}

void	on_key(t_ctx *ctx, t_key *key)
{
	if (key->code == KEY_ARROW_LEFT || key->code == KEY_ARROW_RIGHT
		|| key->code == KEY_ARROW_UP || key->code == KEY_ARROW_DOWN)
		on_arrow_key(ctx, key);
	else if (key->code == KEY_SPACE)
	{
		toggle_arg_state(ctx, ctx->hover_choice, SELECTED);
		if (get_arg_state(ctx, ctx->hover_choice) & SEARCHED)
			refresh_search(ctx);
	}
	else if (key->code == KEY_DELETE || key->code == KEY_BACKSPACE)
	{
		toggle_arg_state(ctx, ctx->hover_choice, DELETED);
		ctx->alive_choice_count--;
		if (ctx->alive_choice_count != 0
			&& ctx->hover_choice == ctx->alive_choice_count)
			ctx->hover_choice--;
	}
	else if (key->code == KEY_ASCII)
		add_search(ctx, key);
}
