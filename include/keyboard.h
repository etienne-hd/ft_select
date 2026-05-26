/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:30:07 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 20:56:26 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_PARSER_H
# define KEY_PARSER_H
#include "ctx.h"
#include <stdint.h>
# include <sys/types.h>

typedef enum e_keymaps
{
	KEY_NONE = 0,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
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
	char		ctrl_pressed;
	char		shift_pressed;
}				t_key;

t_key			get_key(char *buffer, uint *cursor);
uint8_t			read_keyboard(t_ctx *ctx);

#endif
