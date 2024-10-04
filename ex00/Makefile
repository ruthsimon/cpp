NAME = megaphone

SRCS = megaphone.cpp

OBJS = ${SRCS:.cpp=.o}

RM = rm -f 

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean 
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re