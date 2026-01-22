COMPIL = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Vector2-class/Vector2.cpp Graph-class/Graph.cpp
OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
NAME = graph

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/Vector2-class
	mkdir -p $(OBJDIR)/Graph-class

$(NAME): $(OBJDIR) $(OBJS)
	$(COMPIL) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	$(COMPIL) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all