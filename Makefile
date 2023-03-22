NAME = snake

SRCS =	main.cpp \
		mouvement.cpp \
		snake.cpp \
		food.cpp \
		other.cpp

		

OBJS =	${SRCS:.c=.o}

G++ = g++ 

LINK =  -o $(NAME) -L"~\SFML-2.5.1\lib"/lib -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME): $(OBJS)
	$(G++) $(OBJS) -o $(NAME) -I"~\SFML-2.5.1\include" $(LINK)

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf $(NAME)

re:	fclean all