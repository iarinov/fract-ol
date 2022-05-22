#include "./minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct square
{
	int x;
	int y;
} square;

void snow (char *str)
{

	void	*mlx;
	void	*mlx_win;
	int		color;
	int i = 0;
	square square2;

	mlx = mlx_init();
	color = 913831;
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");

	if (str[i] == '2')
	{
		square2.x = 100;
		square2.y = 100;
		while (square2.x <= 300)
		{
			mlx_pixel_put(mlx, mlx_win, square2.x, square2.y, color);
			square2.x++;
		}
		while (square2.y <= 300)
		{
			mlx_pixel_put(mlx, mlx_win, square2.x, square2.y, color);
			square2.y++;
		}
		while (square2.x >= 100)
		{
			mlx_pixel_put(mlx, mlx_win, square2.x, square2.y, color);
			square2.x--;
		}
		while (square2.y >= 100)
		{
			mlx_pixel_put(mlx, mlx_win, square2.x, square2.y, color);
			square2.y--;
		}
		square2.x = 150;
		square2.y = 150;
		while (square2.x <= 250)
		{
			mlx_pixel_put(mlx, mlx_win, square2.x, square2.y, color);
			square2.x++;
		}
		while (square2.y <= 250)
		{
			mlx_pixel_put(mlx, mlx_win, square2.x, square2.y, color);
			square2.y++;
		}
		while (square2.x >= 150)
		{
			mlx_pixel_put(mlx, mlx_win, square2.x, square2.y, color);
			square2.x--;
		}
		while (square2.y >= 150)
		{
			mlx_pixel_put(mlx, mlx_win, square2.x, square2.y, color);
			square2.y--;
		}
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		snow (argv[1]);
	}
	return(0);
}
