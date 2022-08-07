ROOT=..
include $(ROOT)/Make.defines

PROGS = getpgrp getpgid setpgid setpgid_by_child setpgid_by_parent \
		setpgid_by_both setsid fork_and_setsid tcgetpgrp orphaned_process_group \

all: clean $(PROGS)

$(PROGS): $(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out foo bar

include $(ROOT)/Make.libapue.inc
