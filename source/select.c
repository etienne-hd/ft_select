/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:14:55 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 18:53:53 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "key_parser.h"
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
	uint8_t	offset;
	uint8_t	is_selected;
	uint8_t	is_deleted;

	printed_args = 0;
	i = 0;
	while (ctx->arg_count > i)
	{
		offset = i * 2 % 8;
		is_selected = ctx->args_state[i / 4] & (1 << (offset + SELECTED));
		is_deleted = ctx->args_state[i / 4] & (1 << (offset + DELETED));
		if (is_selected && !is_deleted)
		{
			if (printed_args)
				write(1, " ", 1);
			ft_putstr_fd(ctx->args[i], 1);
			printed_args++;
		}
		i++;
	}
}

static uint8_t	read_keyboard(t_ctx *ctx)
{
	char	buffer[1024];
	uint	byte_reads;
	uint	cursor;
	t_key	key;

	byte_reads = read(0, buffer, sizeof(buffer) - 1);
	buffer[byte_reads] = 0;
	cursor = 0;
	while (byte_reads)
	{
		key = get_key(buffer + cursor, &cursor);
		if (!key.code)
			break ;
		if (key.code == KEY_ESCAPE)
		{
			return (1);
			break ;
		}
		else
			on_key(ctx, &key);
	}
	return (0);
}

void	ft_select(t_ctx *ctx)
{
	init_signal(ctx);
	while (1)
	{
		refresh_terminal(&ctx->term);
		render(ctx);
		if (read_keyboard(ctx))
			break ;
	}
}
