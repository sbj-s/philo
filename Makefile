SRCS =  init.c \
		monitor.c \
		parsing.c \
		philosophers.c \
		routine.c \
		utils.c \

OBJS = $(SRCS:.c=.o)

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re