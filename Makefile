NAME = test

SRC = main.cpp \
			ressources.t.cpp \
			factory.cpp \
			factory.t.cpp \
			space.cpp \
			space.t.cpp \
			location.hpp

HEADER =-I/home/me/googletest/include

OBJDIR =

all : $(NAME)

$(NAME) :
	g++ -std=c++11 -ggdb3 -Wall -Wextra $(HEADER) -c $(SRC)
	g++ -o $(NAME)   *.o -L/home/me/googletest/lib -lgtest -lgmock -lpthread


clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
