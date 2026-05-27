/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:29:58 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 03:59:32 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "keyboard.h"
#include "libft.h"
#include "select.h"
#include <stdint.h>

static t_key	parse_escape_sequence(char *buffer, uint *cursor)
{
	if (buffer[0] == 0)
		return ((t_key){.code = KEY_ESCAPE, .ctrl_pressed = 0,
			.shift_pressed = 0});
	if (buffer[0] == '[')
	{
		(*cursor)++;
		if (buffer[1])
			(*cursor)++;
		if (buffer[1] == 51)
			return ((t_key){.code = KEY_DELETE, .ctrl_pressed = 0,
				.shift_pressed = 0});
		if (buffer[1] == 65)
			return ((t_key){.code = KEY_ARROW_UP, .ctrl_pressed = 0,
				.shift_pressed = 0});
		else if (buffer[1] == 66)
			return ((t_key){.code = KEY_ARROW_DOWN, .ctrl_pressed = 0,
				.shift_pressed = 0});
		else if (buffer[1] == 67)
			return ((t_key){.code = KEY_ARROW_RIGHT, .ctrl_pressed = 0,
				.shift_pressed = 0});
		else if (buffer[1] == 68)
			return ((t_key){.code = KEY_ARROW_LEFT, .ctrl_pressed = 0,
				.shift_pressed = 0});
	}
	return ((t_key){.code = KEY_NONE, .ctrl_pressed = 0, .shift_pressed = 0});
}

static t_key	parse_control_char(char *buffer)
{
	if (buffer[0] == 8)
		return ((t_key){.code = KEY_BACKSPACE, .ctrl_pressed = 0,
			.shift_pressed = 0});
	else if (buffer[0] == 9)
		return ((t_key){.code = KEY_TAB, .ctrl_pressed = 0,
			.shift_pressed = 0});
	else if (buffer[0] == 10)
		return ((t_key){.code = KEY_ENTER, .ctrl_pressed = 0,
			.shift_pressed = 0});
	else
	{
		return ((t_key){.code = KEY_A + buffer[0] - 1, .ctrl_pressed = 1,
			.shift_pressed = 0});
	}
}

static t_key	parse_ascii(char *buffer)
{
	if (buffer[0] == 32)
		return ((t_key){.code = KEY_SPACE, .ctrl_pressed = 0,
			.shift_pressed = 0});
	else if (buffer[0] >= 'a' && buffer[0] <= 'z')
		return ((t_key){.code = KEY_A + buffer[0] - 'a', .shift_pressed = 0,
			.ctrl_pressed = 0});
	return ((t_key){.code = KEY_A + buffer[0] - 'A', .shift_pressed = 1,
		.ctrl_pressed = 0});
}

t_key	get_key(char *buffer, uint *cursor)
{
	t_key	key;

	(*cursor)++;
	ft_bzero(&key, sizeof(t_key));
	if (buffer[0] == 0)
		return (key);
	else if (buffer[0] == 27)
		key = parse_escape_sequence(buffer + 1, cursor);
	else if (buffer[0] < 32)
		key = parse_control_char(buffer);
	else if (buffer[0] == 127)
		key.code = KEY_BACKSPACE;
	else
		key = parse_ascii(buffer);
	return (key);
}

uint8_t	read_keyboard(t_ctx *ctx)
{
	char	buffer[1024];
	uint	byte_reads;
	uint	cursor;
	t_key	key;

	byte_reads = read(ctx->term.fd, buffer, sizeof(buffer) - 1);
	buffer[byte_reads] = 0;
	cursor = 0;
	while (byte_reads)
	{
		key = get_key(buffer + cursor, &cursor);
		if (!key.code)
			break ;
		if (key.code == KEY_ESCAPE)
			return (1);
		else if (key.code == KEY_ENTER)
			return (2);
		else
			on_key(ctx, &key);
	}
	return (0);
}
