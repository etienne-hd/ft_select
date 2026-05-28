/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 01:42:04 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 04:55:29 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"

static void	check_choice(t_ctx *ctx, uint real_choice_index, uint choice_index,
		uint8_t *found)
{
	if (ft_strncmp(ctx->choices[choice_index], ctx->search,
			ctx->search_cursor) == 0)
	{
		ctx->choice_state[choice_index] |= SEARCHED;
		if (*found == 0 && !(ctx->choice_state[choice_index] & SELECTED))
		{
			ctx->hover_choice = real_choice_index;
			*found = 1;
		}
	}
	else if (ctx->choice_state[choice_index] & SEARCHED)
		ctx->choice_state[choice_index] ^= SEARCHED;
}

uint8_t	refresh_search(t_ctx *ctx)
{
	uint	choice_index;
	uint	real_choice_index;
	uint8_t	found;

	found = 0;
	choice_index = 0;
	real_choice_index = 0;
	while (choice_index < ctx->choice_count)
	{
		if (!(ctx->choice_state[choice_index] & DELETED))
		{
			check_choice(ctx, real_choice_index, choice_index, &found);
			real_choice_index++;
		}
		choice_index++;
	}
	return (found);
}

void	add_search(t_ctx *ctx, t_key *key)
{
	uint8_t	found;

	ctx->search[ctx->search_cursor++] = key->ascii;
	found = refresh_search(ctx);
	if ((!found && ctx->search_cursor != 1) || ctx->search_cursor > SEARCH_SIZE)
	{
		ctx->search_cursor = 0;
		add_search(ctx, key);
	}
	ctx->search[ctx->search_cursor] = '\0';
}
