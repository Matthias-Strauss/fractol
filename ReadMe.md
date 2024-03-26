# ToDo

-   DEFINE variable struct

-   ZOOM

    -   scroll wheel hook

-   draw full image

-   image loop

-   colors

    -   color fade

-   Fractal Math

    -   Mandelbrot
    -   Julia
        -   needs support for different sets!!!

-   Update on Window resizing

# REQUIREMENTS

-   Mandelbrot

-   Julia

-   Mouse Wheel Zoom

-   colors for Depth

-   Prompt if no parameter (julia or mandelbrot) is provided DONE

-

# GENERAL NOTES

FIND MLX FUNCTIONS:

dont use documentation,
search in folder using VScode

HEADER FILE > DOCUMENTATION

Mandelbrot video:
The Coding Train mandelbrot / julia

approach infinity -> "discard"
stay in bounds -> "keep"

# ALLOWED FUNCTIONS

open, close, read, write,
malloc, free, perror,
strerror, exit
•All functions of the math
library (-lm compiler option,
man man 3 math)
•All functions of the MiniLibX
•ft_printf and any equivalent
YOU coded

# MLX FUNCTIONS THAT MIGHT BE RELEVANT

mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize);
void mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param);
mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height);
bool mlx_resize_image(mlx_image_t* img, uint32_t nwidth, uint32_t nheight);
void mlx_terminate(mlx_t* mlx);

/**
 * Key function callback data.
 * Data related to the mlx_key_hook function
 * 
 * @param key The key that was pressed.
 * @param action The action that was done with the key.
 * @param os_key The os_key is unique for every key, and will have a 
 * different value/keycode depending on the platform. 
 * They may be consistent on different platforms.
 * @param modifier The modifier key that was pressed, 0 if no key was pressed.
 */
typedef struct mlx_key_data
{
	keys_t			key;
	action_t		action;
	int32_t			os_key;
	modifier_key_t	modifier;
}	mlx_key_data_t;

/**
 * Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame 
 * and the current frame.
 */
typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;


/**
 * An image with an individual buffer that can be rendered.
 * Any value can be modified except the width/height and context.
 * 
 * @param width The width of the image.
 * @param height The height of the image.
 * @param pixels The literal pixel data.
 * @param instances An instance carrying the X, Y and Z location data.
 * @param count The element count of the instances array.
 * @param enabled If true the image is drawn onto the screen, else it's not.
 * @param context Abstracted OpenGL data.
 */
typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	size_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;