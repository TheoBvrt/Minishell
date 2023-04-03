NAME = minishell
SRCS = CFiles/main.c CFiles/token.c CFiles/utils.c CFiles/list_manager.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all : ${OBJS} ${NAME}

%.o : %.c
	$(CC) -c $< -o $@

${NAME} :
	${MAKE} bonus -C ./Libft 
	$(CC) $(OBJS) $(CFLAGS) ./Libft/libft.a -o ${NAME} -g3

clean:
	${RM} ${OBJS}
	make fclean -C ./Libft

fclean: clean
	${RM} ${NAME}

re: fclean all