/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:30:07 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 04:42:24 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H
# include "ctx.h"
# include <stdint.h>
# include <sys/types.h>

typedef enum e_keymaps
{
	KEY_NONE = 0,
	KEY_ASCII,
	KEY_ESCAPE,
	KEY_ENTER,
	KEY_TAB,
	KEY_SPACE,
	KEY_BACKSPACE,
	KEY_DELETE,
	KEY_ARROW_UP,
	KEY_ARROW_DOWN,
	KEY_ARROW_LEFT,
	KEY_ARROW_RIGHT
}				t_keymaps;

typedef struct s_key
{
	t_keymaps	code;
	t_keymaps	ascii;
	char		ctrl_pressed;
	char		shift_pressed;
}				t_key;

t_key			get_key(char *buffer, uint *cursor);
uint8_t			read_keyboard(t_ctx *ctx);

#endif
