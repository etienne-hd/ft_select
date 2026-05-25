/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:29:58 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 00:02:30 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_parser.h"
#include "libft.h"

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
		if (buffer[1] == 'A')
			return ((t_key){.code = KEY_ARROW_UP, .ctrl_pressed = 0,
				.shift_pressed = 0});
		else if (buffer[1] == 'B')
			return ((t_key){.code = KEY_ARROW_DOWN, .ctrl_pressed = 0,
				.shift_pressed = 0});
		else if (buffer[1] == 'C')
			return ((t_key){.code = KEY_ARROW_RIGHT, .ctrl_pressed = 0,
				.shift_pressed = 0});
		else if (buffer[1] == 'D')
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
	else if (buffer[0] == 13)
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
	if (buffer[0] >= 'a' && buffer[0] <= 'z')
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
		key.code = KEY_DELETE;
	else
		key = parse_ascii(buffer);
	return (key);
}
