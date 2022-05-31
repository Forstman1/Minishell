# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# #                                                                          # #
# #       ███╗   ███╗ █████╗ ██╗  ██╗███████╗███████╗██╗██╗     ███████╗     # #
# #       ████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██║██║     ██╔════╝     # #
# #       ██╔████╔██║███████║█████╔╝ █████╗  █████╗  ██║██║     █████╗       # #
# #       ██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██║██║     ██╔══╝       # #
# #       ██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║     ██║███████╗███████╗     # #
# #       ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝     # #
# #                                                                          # #
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #

# --------------------------- Terminal Color Codes --------------------------- #
NNN  := \033[1;0m
RED := \033[1;31m
GRN := \033[1;32m
YEL := \033[1;33m
BLU := \033[1;34m
MGN := \033[1;35m
CYN := \033[1;36m
GRA := \033[1;37m

# ---------------------------------------------------------------------------- #

define TITLE
${RED}
+ ---------------------------------------------------------------------------- +
|   __   __  __   __    _  ___   _______  __   __  _______  ___      ___       |
|  |  |_|  ||  | |  |  | ||   | |       ||  | |  ||       ||   |    |   |      |
|  |       ||  | |   |_| ||   | |  _____||  |_|  ||    ___||   |    |   |      |
|  |       ||  | |       ||   | | |_____ |       ||   |___ |   |    |   |      |
|  |       ||  | |  _    ||   | |_____  ||       ||    ___||   |___ |   |___   |
|  | ||_|| ||  | | | |   ||   |  _____| ||   _   ||   |___ |       ||       |  |
|  |_|   |_||__| |_|  |__||___| |_______||__| |__||_______||_______||_______|  |
|                                                                              |
+ ---------------------------------------------------------------------------- +
${NNN}${GRA}
                                        - Created By ${BLU}Forstman${NNN}\n
endef
export TITLE

# ---------------------------------------------------------------------------- #

CFILES  = utils1.c srcs/builtins/echo.c srcs/builtins/exit.c srcs/builtins/pwd.c srcs/builtins/cd.c srcs/utils/utils2.c \
			srcs/builtins/cd/cd_back.c srcs/builtins/cd/cd_path.c srcs/builtins/cd/cd_home.c srcs/builtins/cd/cd_root.c \
			srcs/builtins/cd/cd_samdir.c

OFILES	= $(CFILES:.c=.o)

CC	= gcc
INT	= ms_head.h
# FLAGS = -Wall -Wextra -Werror
NAME = minishell
ARCHIVE = libft/libft.a

all : $(NAME)

$(NAME) : title $(OFILES) exec.c 
	@$(CC) $(FLAGS) exec.c $(ARCHIVE) $(OFILES) -o minishell 

%.o:%.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean: title
	@rm -f $(OFILES)

fclean:	clean
	@rm -f $(NAME) 

re: fclean all

title:
	@clear
	@echo "$$TITLE"

# ---------------------------------------------------------------------------- # 