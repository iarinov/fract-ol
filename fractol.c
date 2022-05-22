#include "./minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


/********************************* TYPEDEF ********************************\*/
typedef struct square
{
	unsigned int x; // width of sqr
	unsigned int y; // high of sqr
	unsigned int begin_point;
} square_t;
/********************************* F_C PROTOTYE ********************************\*/

static void draw_sqr(square_t my_sqr, void	*mlx, void	*mlx_win, int color);

/****BRIEF*****
 * NAME 		: draw_sqr
 * PARAMETRS 	: square_t, mlx win begin, mlx win field, color code in hex
 * RETURN 		: NONE'
 * DESCRIPTION 	: THIS F_C WILL DRAW SQR
*/
static void draw_sqr(square_t my_sqr, void	*mlx, void	*mlx_win, int color)
{
	unsigned int x = 0 ;
	unsigned int y = 0 ;




	x = my_sqr.x - my_sqr.begin_point;
	y = my_sqr.y - my_sqr.begin_point;

	while(x < my_sqr.x)
	{
			mlx_pixel_put(mlx, mlx_win, x, my_sqr.y, color);
			mlx_pixel_put(mlx, mlx_win, my_sqr.x, x, color);

			mlx_pixel_put(mlx, mlx_win, x, my_sqr.begin_point, color);
			mlx_pixel_put(mlx, mlx_win, my_sqr.begin_point, x, color);
			x++;
	}
}


void snow (char *str)
{

	void	*mlx;
	void	*mlx_win;
	int		color;
//	int i = 0;
	square_t square2;

	str[0] = '0';
	mlx = mlx_init();
	color = 913831;
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");

	square2.x = square2.y = 300;
	square2.begin_point = 100;
	draw_sqr(square2,mlx,mlx_win, color);
/*
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
	*/
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
}

int main (int argc, char **argv)
{
	printf("%d \n", argc);
	if (argc == 2)
	{
		snow (argv[1]);
	}
	return(0);
}
