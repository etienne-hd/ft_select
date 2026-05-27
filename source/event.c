/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:13:35 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 19:06:19 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "keyboard.h"
#include "libft.h"
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

void	dynamic_search(t_ctx *ctx, t_key *key)
{
	char	c;
	uint	choice_index;
	uint	real_choice_index;
	uint8_t	found;

	c = key->code - KEY_A + 'a';
	if (key->shift_pressed)
		c -= 32;
	ctx->search[ctx->search_cursor] = c;
	ctx->search_cursor++;
	found = 0;
	choice_index = 0;
	real_choice_index = 0;
	while (choice_index < ctx->choice_count)
	{
		if (!(ctx->choice_state[choice_index] & DELETED))
		{
			if (!(ctx->choice_state[choice_index] & SELECTED)
				&& ft_strncmp(ctx->choices[choice_index], ctx->search,
					ctx->search_cursor) == 0)
			{
				ctx->hover_choice = real_choice_index;
				found = 1;
				break ;
			}
			real_choice_index++;
		}
		choice_index++;
	}
	if ((!found && ctx->search_cursor != 1) || ctx->search_cursor > SEARCH_SIZE)
	{
		ctx->search_cursor = 0;
		dynamic_search(ctx, key);
	}
	ctx->search[ctx->search_cursor] = '\0';
}

void	on_key(t_ctx *ctx, t_key *key)
{
	if (key->code == KEY_ARROW_LEFT || key->code == KEY_ARROW_RIGHT
		|| key->code == KEY_ARROW_UP || key->code == KEY_ARROW_DOWN)
		on_arrow_key(ctx, key);
	else if (key->code == KEY_SPACE)
		toggle_arg_state(ctx, ctx->hover_choice, SELECTED);
	else if (key->code == KEY_DELETE || key->code == KEY_BACKSPACE)
	{
		toggle_arg_state(ctx, ctx->hover_choice, DELETED);
		ctx->alive_choice_count -= 1;
		if (ctx->alive_choice_count != 0
			&& ctx->hover_choice == ctx->alive_choice_count)
			ctx->hover_choice -= 1;
	}
	else if (key->code >= KEY_A && key->code <= KEY_Z)
		dynamic_search(ctx, key);
}
