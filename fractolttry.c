#include "./minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct circle
{
	int a;
	int x;
	int y;
	int xcenter;
	int ycenter;
	int radius;
} Circle;

void snow (char *str)
{

	void	*mlx;
	void	*mlx_win;
	int		color;
	int i = 0;
	Circle kreis;
	kreis.a = 1;
	mlx = mlx_init();
	color = 913831;
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");

	if (str[i] == '1')
	{
		while (kreis.a != 360)
		{
			kreis.radius = 150;
			kreis.xcenter = 250;
			kreis.ycenter = 350;
			mlx_pixel_put(mlx, mlx_win, kreis.x, kreis.y, color);
			kreis.x = kreis.xcenter + kreis.xcenter * sin(kreis.a);
			kreis.y = kreis.ycenter + kreis.ycenter * cos(kreis.a);
			kreis.a++;
		}
	}
	// if (str[i] == '2')
	// {
	// 	while (a != 360)
	// 	{
	// 		radius = 100;
	// 		xcenter = 250;
	// 		ycenter = 100;
	// 		mlx_pixel_put(mlx, mlx_win, x, y, color);
	// 		x = xcenter + xcenter * sin(a);
	// 		y = ycenter + ycenter * cos(a);
	// 		a++;
	// 	}
	// }
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
