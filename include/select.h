/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:09:06 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 21:28:34 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H
#include "keyboard.h"
# define MARGIN 1

# include "ctx.h"

typedef enum e_text_style
{
	NORMAL = 1 << 0,
	INVERT = 1 << 1,
	UNDERLINE = 1 << 2
}		t_text_style;

void	show_selected(t_ctx *ctx);
uint8_t	ft_select(t_ctx *ctx);

void	init_signal(t_ctx *ctx);

void	render(t_ctx *ctx);

void	on_resize(t_ctx *ctx);
void	on_key(t_ctx *ctx, t_key *key);

#endif