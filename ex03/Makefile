NAME	:= bureaucrats
SRCS	:=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS	:= $(SRCS:.cpp=.o)
CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98
RM		:= rm -f

.PHONY: all clean fclean re run

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *_shrubbery

re: fclean all

run: all
	./$(NAME)