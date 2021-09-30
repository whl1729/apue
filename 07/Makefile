ROOT=..
include $(ROOT)/Make.defines

PROGS = hi atexit argv environ double_free free_local_var free_random \
		loop_malloc loop_calloc overflow mallinfo getenv putenv setenv \
		hello longjmp getrlimit

all: clean $(PROGS)

$(PROGS): $(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out foo bar

include $(ROOT)/Make.libapue.inc
