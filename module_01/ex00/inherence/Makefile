COMPIL = c++
CPPFLAGS = -Wall -Wextra -Werror -I../ -std=c++98
SRCS = main.cpp classes/Tool.abstract.cpp classes/Worker.cpp
OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
NAME = compile.out

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/classes

$(NAME): $(OBJDIR) $(OBJS)
	$(COMPIL) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	$(COMPIL) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all