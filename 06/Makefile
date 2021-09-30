ROOT=..
include $(ROOT)/Make.defines

PROGS = getpwnam getspnam getgrnam getgrent getgroups uname gethostname \
		time clock_gettime clock_getres gettimeofday gmtime localtime \
		mktime strftime test_strftime strptime \
		6_4_time

all: clean $(PROGS)

$(PROGS): $(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out foo bar

include $(ROOT)/Make.libapue.inc
