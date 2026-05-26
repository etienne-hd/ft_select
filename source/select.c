/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:14:55 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 21:41:06 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "keyboard.h"
#include "libft.h"
#include "select.h"
#include "terminal.h"
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

/*
[SELECTED DELETED]	<- each bit is a state of the arg
[xx][xx][xx][xx]	<- each args is seperate in 2 bits
[xxxxxxxxxxxxxx]	<- byte
*/
void	show_selected(t_ctx *ctx)
{
	uint	printed_args;
	uint	i;
	uint8_t	is_selected;
	uint8_t	is_deleted;

	printed_args = 0;
	i = 0;
	while (ctx->choice_count > i)
	{
		is_selected = ctx->choice_state[i] & SELECTED;
		is_deleted = ctx->choice_state[i] & DELETED;
		if (is_selected && !is_deleted)
		{
			if (printed_args)
				write(1, " ", 1);
			ft_putstr_fd(ctx->choices[i], 1);
			printed_args++;
		}
		i++;
	}
}

uint8_t	ft_select(t_ctx *ctx)
{
	uint8_t	code;

	init_signal(ctx);
	while (1)
	{
		refresh_terminal(&ctx->term);
		render(ctx);
		code = read_keyboard(ctx);
		if (code)
			return (code);
		else if (ctx->alive_choice_count == 0)
			return (1);
	}
}
