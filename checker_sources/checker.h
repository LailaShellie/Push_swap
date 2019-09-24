/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:42:58 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/21 19:43:01 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECKER_H
# define _CHECKER_H

# include "../libft/libft.h"
# include "../stack_sources/stack.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# define WIDTH 2000
# define HEIGHT 1000

typedef struct			s_command
{
	char				*str;
	struct s_command	*next;
}						t_command;

typedef struct			s_img
{
	void				*img;
	void				*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	int					flag;
	int					len;
	int					step;
	t_command			*cur_com;
	t_img				*img;
	t_stack				*a;
	t_stack				*b;
	t_command			*com;
}						t_mlx;

int						error_commands(t_command **lst);
int						check_commands(char *str);
void					make_commands(t_command **lst, char *str);
void					free_commands(t_command **lst);
void					exec(t_stack **a, t_stack **b, char *str);
void					visualization(t_mlx *mlx);
void					draw(t_mlx *mlx);
int						make_step(t_mlx *mlx);
int						set_colors_n_len(t_mlx *mlx);
int						free_mlx(t_mlx *mlx);
int						set_colors(unsigned char o, unsigned char r, \
				unsigned char g, unsigned char b);

#endif
