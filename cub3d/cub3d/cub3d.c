#include "cub3d.h"

void	ft_initial(t_info *pn, int flag, t_list *head, char **argv)
{
	pn->spr->x = -1;
	pn->plr->dir = 0;
	pn->wid = -1;
	pn->hght = -1;
	pn->spr->x = -1;
	pn->spr->y = -1;
	if (flag != -1)
	{
		ft_readconf(&head, argv[1]);
		pn->head = head;
		pn->conf = ft_config(&head, ft_lstsize(head));
		ft_parser(pn, pn->conf, 0, 0);
	}
	ft_mlx(pn, flag);
}

void	ft_first_init(t_info *pn, int flag, t_list *head, char **argv)
{
	pn->color = 0;
	pn->x = 0;
	pn->y = 0;
	pn->side = 0;
	pn->plr->lk = 0;
	pn->plr->rk = 0;
	ft_initial(pn, flag, head, argv);
}

int	main(int argc, char **argv)
{
	t_info	pn;

	pn.plr = (t_plr *)malloc(sizeof(t_plr));
	pn.img = (t_img *)malloc(sizeof(t_img));
	pn.spr = (t_sprite *)malloc(sizeof(t_sprite));
	pn.stxt = (t_texture *)malloc(sizeof(t_texture));
	pn.sptxt = (t_texture *)malloc(sizeof(t_texture));
	pn.ntxt = (t_texture *)malloc(sizeof(t_texture));
	pn.etxt = (t_texture *)malloc(sizeof(t_texture));
	pn.wtxt = (t_texture *)malloc(sizeof(t_texture));
	ft_first_init(&pn, ft_check_input(argc, argv), (t_list *) NULL, \
	argv);
	mlx_hook(pn.win, 3, 1L << 1, ft_keyrelease, &pn);
	mlx_hook(pn.win, 2, 1L << 0, ft_key, &pn);
	mlx_hook(pn.win, 17, 1L << 17, ft_clear, &pn);
	mlx_loop(pn.mlx);
	exit(0);
	return (0);
}
