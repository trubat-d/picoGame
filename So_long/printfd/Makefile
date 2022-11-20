ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

RM = rm -rf

SRC =	counters/ft_strlen.c			main/flags_check_fd.c			print_functions/print_len_fd.c	print_functions/print_upx_fd.c	\
		text_mod/text_mod_fd.c			utils/ft_putstr_fd.c			counters/len_atoi.c				main/ft_printfd.c	\
		print_functions/print_o_fd.c	print_functions/print_x_fd.c	utils/ft_putchar_fd.c			utils/ft_strchr.c	\
		counters/nbrlen.c				print_functions/print_c_fd.c	print_functions/print_s_fd.c	text_mod/bright_fd.c	\
		utils/ft_putnbr_fd.c			counters/u_nbrlen_base.c		print_functions/print_d_fd.c	print_functions/print_u_fd.c	\
		text_mod/flags_text_fd.c		utils/ft_putnbrb_fd.c

OBJ = $(SRC:.c=.o)

NAME = libftprintfd.a

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Werror -Wextra

$(NAME) : $(OBJ)
	$(ECHO) "$(YELLOW)Compilation de libftprintfd.a...$(RESETTXT)"
	@$(AR) $@ $^
	$(ECHO)  "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

%.o : %.c
	$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
	@$(CC) $(CFLAGS) -o $@ -c $<

bonus : $(NAME)

all : $(NAME)

clean :
	$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
	@$(RM) $(OBJ)
	$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean : clean
	$(ECHO) "$(RED)Suppression de libftprintfd.a...$(RESETTXT)"
	@$(RM) $(NAME)
	$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

re : fclean all

.PHONY: all re bonus clean fclean