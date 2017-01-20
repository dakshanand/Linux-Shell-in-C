SOURCES.c=redirection.c pipes.c main.c cd.c pwd.c echo.c Exit.c execute.c loop.c split.c listjobs.c launch.c input.c replace_str.c pinfo.c killall.c insert.c delete.c sendsig.c fg.c
INCLUDES= 
CFLAGS=
SLIBS= 
PROGRAM= main

OBJECTS= $(SOURCES.c:.c=.o)

.KEEP_STATE:

debug := CFLAGS= -g

all debug: $(PROGRAM)

$(PROGRAM): $(INCLUDES) $(OBJECTS)
	$(LINK.c) -o $@ $(OBJECTS) $(SLIBS)

clean:
	rm -f $(PROGRAM) $(OBJECTS)

