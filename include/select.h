/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:09:06 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 01:27:12 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "ctx.h"

void	show_selected(t_ctx *ctx);
void	ft_select(t_ctx *ctx);

void	init_signal(t_ctx *ctx);

void	render(t_ctx *ctx);

void	on_resize(t_ctx *ctx);

#endif