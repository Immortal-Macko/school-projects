#ifndef CUB3D_H
# define CUB3D_H

# include "tools.h"
# include <fcntl.h>
# include "get_next_line.h"
# include "./mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_info
{
	void				*mlx;
	void				*txtmlx;
	void				*win;
	char				**map;
	char				**conf;
	t_list				*head;
	int					x;
	int					y;
	int					sz;
	int					wid;
	int					hght;
	int					color;
	int					celling;
	int					floor;
	int					side;
	struct s_img		*img;
	struct s_plr		*plr;
	struct s_texture	*stxt;
	struct s_texture	*sptxt;
	struct s_texture	*wtxt;
	struct s_texture	*etxt;
	struct s_texture	*ntxt;
	struct s_sprite		*spr;
}						t_info;

typedef struct s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct s_texture
{
	char				*path;
	int					width;
	int					hight;
	void				*img;
	int					bpp;
	int					sl;
	int					en;
	char				*addr;
}						t_texture;

typedef struct s_sprite
{
	double				x;
	double				y;
	int					wid;
	int					hight;
	double				start;
	double				end;
	int					flag;
	int					step;
}						t_sprite;

typedef struct s_img {
	void				*img;
	int					bpp;
	int					sl;
	int					en;
	char				*addr;
}						t_img;

typedef struct s_plr
{
	double				x;
	double				y;
	int					color;
	char				symb;
	double				dir;
	double				view_start;
	double				view_end;
	int					lk;
	int					rk;
}						t_plr;

int						ft_check_input(int argc, char **argv);
void					ft_bmp(t_info *pn);
void					ft_mlx(t_info *pn, int flag);
void					ft_checkmap(char **map, int i, int j);
int						pars_color(t_info *pn, char *str, int flag, int c);
int						pars_texture(t_info *pn, char *str, int flag, int i);
void					ft_pixel_put(t_img *img, int x, int y, int color);
void					ft_print_sprite(int hi, t_info *pn, double x, int y);
void					ft_print_cel(t_info *pn, double x, int y);
void					ft_print_floor(t_info *pn, double x, int y);
void					ft_print_walls(t_info *p, double x, int y, t_plr *plr);
int						ft_get_texture(t_texture *txt, char *path, void *mlx);
void					ft_print_plr(t_info *pn, double x);
double					ft_raylen(double x, double xx, double y, double yy);
int						ft_clear(t_info *pn);
void					ft_error(int flag);
int						ft_getside(t_plr *plr, t_info *pn, int flag);
int						ft_isitmap(char *str);
char					**ft_config(t_list **head, int size);
void					ft_read_map(t_info *pn, char **map);
int						pars_res(t_info *pn, char *str, int flag, int g);
int						ft_keyrelease(int keycode, t_info *pn);
int						ft_key(int keycode, t_info *pn);
void					ft_readconf(t_list **head, char *name);
void					ft_parser(t_info *pn, char **conf, int i, int stop);
void					ft_new_image(t_info *pn);
void					ft_forward(t_info *pn);
void					ft_first_line(t_info *pn);
double					ft_get_value(t_info *pn, t_plr *plr);

#endif
