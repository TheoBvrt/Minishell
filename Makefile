# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:47:09 by lcamilo-          #+#    #+#              #
#    Updated: 2023/06/09 10:18:30 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------  COLORS  ------------------------------------------------------ #
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_ORANGE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[0;33m
COLOUR_CYAN=\033[0;36m

# ------------  PROJECT  ----------------------------------------------------- #
NAME		= minishell

# ------------  DIRECTORIES  ------------------------------------------------- #
LIB				= libftprintfgnl
SRC_PATH		= src/
HEADERS			= includes
HEADERS_LIB		= libftprintfgnl/includes

INC			= $(addprefix $HEADERS_LIB)

# ------------  FLAGS  ------------------------------------------------------- #
CFLAGS 		= -I $(HEADERS) -I $(HEADERS_LIB) -fsanitize=address
CC			= @cc
RM			= rm -rf

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC 		= 	main.c							\
				builtin/echo.c					\
				builtin/cd.c					\
				builtin/pwd.c					\
				builtin/export.c				\
				builtin/export_utils.c			\
				builtin/unset.c					\
				builtin/env.c					\
				builtin/exit.c					\
				builtin/cd_utils.c				\
				execution/execution.c			\
				execution/error.c				\
				execution/improved_ft.c			\
				execution/execution_utils.c		\
				execution/redir.c				\
				execution/builtin.c				\
				execution/redir_2.c				\
				execution/exec_setup.c			\
				execution/dup_case.c			\
				utils/utils_lst.c				\
				utils/env_utils.c				\
				utils/utils_lst2.c				\
				utils/exec_utils.c				\
				utils/redir_utils.c				\
				utils/utils.c					\
				utils/get_env.c					\
				utils/sig.c						\
				free/free.c						\
				old_parsing/parsing.c				\
				old_parsing/quotes.c				\
				old_parsing/space.c					\
				old_parsing/dollars.c				\
				old_parsing/here_doc.c				\
				old_parsing/create_cmd.c			\
				old_parsing/create_redir.c			\
				parsing/t_parsing.c	

# ------------  FILEPATHS  --------------------------------------------------- #
OBJS				= ${SRC:.c=.o}
OBJS_DIR			= objs
DIRS				= objs objs/utils objs/old_parsing objs/execution objs/builtin objs/free objs/parsing
_OBJS				= $(addprefix $(OBJS_DIR)/, $(OBJS))

all: lib $(NAME)

lib:
			@echo "$(COLOUR_CYAN)Compilation libft..."
			make -C $(LIB)
			@echo "$(COLOUR_YELLOW)Deplacement du libft.a $(COLOUR_END)"
			@cp ./libftprintfgnl/libft.a libft.a

$(NAME): $(_OBJS)
			@echo "$(COLOUR_CYAN)Compile..."
			$(CC) $(_OBJS) libft.a $(CFLAGS) -o $@ -L libftprintfgnl -lreadline -lft -I $(HOME)/.brew/opt/readline/include -L $(HOME)/.brew/opt/readline/lib
			@echo "$(COLOUR_RED)Minishell ready. $(COLOUR_END)"

$(OBJS_DIR)/%.o: $(SRC_PATH)/%.c
		@mkdir -p $(DIRS)
		${CC} $(CFLAGS) -c $< -o $@ -g3

clean:
			$(RM) ${_OBJS}
			make fclean -C $(LIB)

fclean:		clean
			$(RM) $(NAME) *.a

re:			fclean all

.PHONY: re ignore fclean clean all $(LIBFT) $(NAME) $(PRINTF)
