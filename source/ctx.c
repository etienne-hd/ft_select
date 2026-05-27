/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:11:31 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 03:40:40 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "libft.h"
#include "terminal.h"
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

t_ctx	init_ctx(int argc, char **argv)
{
	t_ctx	ctx;

	ft_bzero(&ctx, sizeof(ctx));
	ctx.term = init_terminal();
	if (!ctx.term.initialized)
	{
		ft_putstr_fd("Unable to load terminal.\n", 2);
		return (ctx);
	}
	ctx.choice_count = argc - 1;
	ctx.alive_choice_count = ctx.choice_count;
	ctx.choices = argv + 1;
	ctx.choice_state = malloc(sizeof(uint8_t) * ctx.choice_count);
	ctx.hover_choice = 0;
	if (ctx.choice_state)
		bzero(ctx.choice_state, sizeof(uint8_t) * ctx.choice_count);
	else
	{
		ft_putstr_fd("Allocation error.\n", 2);
		destroy_terminal(&ctx.term);
	}
	return (ctx);
}

void	destroy_ctx(t_ctx *ctx)
{
	free(ctx->choice_state);
	ctx->choice_state = NULL;
}
