CC			=	clang++
CXXFLAGS	=	-g -Wall -Wextra -Werror -pedantic-errors -Wc++98-compat -Wno-long-long -Wno-variadic-macros -fexceptions #-DNDEBUG -DUSE_CLANG_COMPLETER -std=c++11 -stdlib=libc++
INCLUDE		=	-Iinclude -Iinclude/**

SDIR 		=	src
ODIR 		=	build
HDIR		=	include
BDIR 		=	bin
OUT			=	installer

SRCS		=	$(wildcard $(SDIR)/*.cpp)
OBJS		=	$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SRCS))

$(ODIR)/%.o : $(SDIR)/%.cpp
	$(CC) $(INCLUDE) $(CXXFLAGS) -c $< -o $@

all : clean $(OUT)

$(OUT) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(BDIR)/$(OUT)

clean :
	rm -f $(OBJS) $(BDIR)/$(OUT)
