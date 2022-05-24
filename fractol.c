#include "./minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void mandelbrot ()
{
	void	*mlx;
	void	*mlx_win;
	int		color;
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*250/250;//imageHeight/ImageWidth
	double Re_factor = (MaxRe-MinRe)/(250-1);//ImageWidth because real is x
	double Im_factor = (MaxIm-MinIm)/(250-1);//ImageHeight because imaginary is y
	unsigned int MaxIterations = 30;

	mlx = mlx_init();
	color = 913831;
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	for(unsigned int  y=0; y<250; ++y)//till we reach the end of the image height
	{
		double c_im = MaxIm - y * Im_factor;//complex value for imaginary, conctant c
		for(unsigned int x = 0; x<250; ++x)//till we reach the end of the image bright
		{
			double c_re = MinRe + x * Re_factor;//compex value for real, constant c
			double Z_re = c_re;
			double Z_im = c_im;
			bool isInside = true;
			for(unsigned int n = 0; n < MaxIterations; ++n)
			{
				double Z_re2 = Z_re*Z_re;
				double Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)//absolut value of Z
				{
					isInside = false;
					break;
				}
				Z_im = 2 * Z_re * Z_im + c_im;//become that from (x + yi)^2 = x^2 + 2xyi + yi^2 -> 2xy
				Z_re = Z_re2 - Z_im2 + c_re;//x^2 - y^2
			}
			if(isInside)
			 {
				mlx_pixel_put(mlx, mlx_win, x, y, color);
			 }
		}
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
}

int main()
{
	mandelbrot();
	return(0);
}


