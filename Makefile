NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -O2

MINILIBX_DIR = ./minilibx_opengl_20191021
MINILIBX = $(MINILIBX_DIR)/libmlx.a

INCLUDES = -I$(MINILIBX_DIR)
LDFLAGS = -L$(MINILIBX_DIR)
LIBS = -lm -lmlx -framework OpenGL -framework AppKit

SRCS = 0_fractol.c
SRCS += 1_handle_args.c
SRCS += 2_init.c
SRCS += 3_hooks.c
SRCS += 4_rendor.c
SRCS += 5_fractol.c
SRCS += func_atof.c
SRCS += func_color.c
SRCS += func_complex.c
SRCS += func_utlis.c
SRCS += func_zoom.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJS) $(MINILIBX)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MINILIBX):
	$(MAKE) -j4 -C $(MINILIBX_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re