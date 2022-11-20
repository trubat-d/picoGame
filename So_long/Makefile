ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

RM = rm -rf

SRC =	gnl/get_next_line.c			main/enemy_move.c	utils/check_map.c	utils/exit_error.c	utils/itostr_base.c	utils/life.c	utils/player_position.c	utils/put_img.c		utils/read_map.c	\
		gnl/get_next_line_utils.c	main/main.c			utils/close_win.c	utils/exit_on.c		utils/key_event.c	utils/map_gen.c	utils/print_move.c		utils/put_img_str.c	utils/set_all.c

OBJ = $(SRC:.c=.o)

NAME = so_long
CC = gcc

CFLAGS = -Wall -Werror -Wextra

ifeq ($(DEBUG), debug)
	CFLAGS += -fsanitize=address -g3
endif

$(NAME) : $(OBJ)
	@make -C printfd
	@make -C mlx
	$(ECHO) "$(YELLOW)Compilation de so_long...$(RESETTXT)"
	@$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ mlx/libmlx.a printfd/libftprintfd.a
	$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

%.o : %.c
	$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
	@$(CC) $(CFLAGS) -Imlx -o $@ -c $<

bonus : $(NAME)

all : $(NAME)

clean :
	@make clean -C printfd
	$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
	@$(RM) $(OBJ)
	$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean : clean
	@$(RM) printfd/libftprintfd.a
	$(ECHO) "$(RED)Suppression de so_long...$(RESETTXT)"
	@$(RM) $(NAME)
	$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean_all : fclean
	@make clean -C mlx

re : fclean all

re_all : fclean_all all

.PHONY: all re bonus clean fclean