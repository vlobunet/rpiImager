NAME	= rpiImager
SRCS	= src/main.c

OBJS	= $(SRCS:.c=.o)
FLAGS	= -Wall -Wextra -Werror -lwiringPi
HEADER	= includes/rpiImager.h

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	@cc -c $< -o $@ $(FLAGS)
	@echo  "█\c)"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(OBJS)

re: fclean $(NAME)
