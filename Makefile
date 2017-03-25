CC = cc
CFLAGS = -g -Wall

PROG = table_test
HDRS = table.h
SRCS = main.c table.c

OBJDIR = object
OBJS = $(OBJDIR)/main.o $(OBJDIR)/table.o

# compiling rules

# WARNING: *must* have a tab before each definition
$(PROG): $(OBJS) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

$(OBJDIR)/table.o: table.c $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c table.c -o $(OBJDIR)/table.o

$(OBJDIR)/main.o: main.c $(HDRS) $(OBJDIR)
	$(CC) $(CFLAGS) -c main.c -o $(OBJDIR)/main.o

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -f $(PROG) $(OBJS)



