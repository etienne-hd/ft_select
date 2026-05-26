/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:09:06 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 02:57:56 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "ctx.h"

typedef enum e_text_style
{
	NORMAL,
	INVERT,
	UNDERLINE
}		t_text_style;

void	show_selected(t_ctx *ctx);
void	ft_select(t_ctx *ctx);

void	init_signal(t_ctx *ctx);

void	render(t_ctx *ctx);

void	on_resize(t_ctx *ctx);

#endif