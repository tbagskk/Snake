NAME = snake

SRCS =	main.cpp \
		mouvement.cpp \
		snake.cpp \
		food.cpp \
		other.cpp

		

OBJS =	${SRCS:.c=.o}

G++ = g++ 

LINK =  -o $(NAME) -L"C:\Users\33643\Desktop\snakecpp\SFML-2.5.1\lib"/lib -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME): $(OBJS)
	$(G++) $(OBJS) -o $(NAME) -I"C:\Users\33643\Desktop\snakecpp\SFML-2.5.1\include" $(LINK)

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf $(NAME)

re:	fclean all