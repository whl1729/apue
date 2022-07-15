ROOT=..
include $(ROOT)/Make.defines

PROGS = hi atexit argv environ double_free free_local_var free_random \
		loop_malloc loop_calloc overflow mallinfo getenv putenv setenv \
		hello longjmp getrlimit open_too_many_files fork_too_many_processes \
		create_large_local_variable create_too_many_pipes create_large_message_queue \
		setvbuf_local setvbuf_malloc

all: clean $(PROGS)

$(PROGS): $(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out foo bar

include $(ROOT)/Make.libapue.inc
