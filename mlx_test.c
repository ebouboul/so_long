// #include "minilibx-linux/mlx.h"
// #include <stdio.h>

// #include "so_long.h"
// #define ESC_KEY 65307
// #define W_KEY 119
// #define A_KEY 97
// #define S_KEY 115
// #define D_KEY 100

// int handle_key(int keycode, void *param)
// {
//     (void)param; // To suppress unused parameter warning
//     if (keycode == ESC_KEY)
//     {
//         printf("ESC key pressed\n");
//         exit(0);
//     }
//     else if (keycode == W_KEY)
//         printf("W key pressed\n");
//     else if (keycode == A_KEY)
//         printf("A key pressed\n");
//     else if (keycode == S_KEY)
//         printf("S key pressed\n");
//     else if (keycode == D_KEY)
//         printf("D key pressed\n");
//     return 0;
// }

// int main()
// {
//     void *mlx;
//     void *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 800, 600, "Key Press Example");

//     mlx_key_hook(win, handle_key, NULL);
//     mlx_loop(mlx);

//     return 0;
// }



// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	mlx_pixel_put(&img, NULL, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

// #include <mlx.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*img;
// 	char	*relative_path = "abc.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	void	*mlx_win;
// 	// t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
// 	mlx_loop(mlx);
// }

// #include <mlx.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*img;
// 	char	*relative_path = "./test.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// }
