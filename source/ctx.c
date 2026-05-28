/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:11:31 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 02:43:59 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "libft.h"
#include "terminal.h"
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

static void	delete_illegal_choices(t_ctx *ctx)
{
	uint	i;

	i = 0;
	while (i < ctx->choice_count)
	{
		if (ctx->choices[i][0] == 0 || ft_strchr(ctx->choices[i], '\n'))
		{
			ctx->choice_state[i] |= DELETED;
			ctx->alive_choice_count--;
		}
		i++;
	}
}

void	init_ctx(t_ctx *ctx, int argc, char **argv)
{
	ft_bzero(ctx, sizeof(*ctx));
	ctx->term = init_terminal();
	if (!ctx->term.initialized)
	{
		ft_putstr_fd("Unable to load terminal.\n", 2);
		return ;
	}
	ctx->choice_count = argc - 1;
	ctx->alive_choice_count = ctx->choice_count;
	ctx->choices = argv + 1;
	ctx->choice_state = malloc(sizeof(uint8_t) * ctx->choice_count);
	ctx->hover_choice = 0;
	if (ctx->choice_state)
	{
		bzero(ctx->choice_state, sizeof(uint8_t) * ctx->choice_count);
		delete_illegal_choices(ctx);
	}
	else
	{
		ft_putstr_fd("Allocation error.\n", 2);
		destroy_terminal(&ctx->term);
	}
	return ;
}

void	destroy_ctx(t_ctx *ctx)
{
	free(ctx->choice_state);
	ctx->choice_state = NULL;
}
