ROOT=..
include $(ROOT)/Make.defines

PROGS = pthread_self pthread_id pthread_join pthread_join_twice \
		pthread_exit_stack pthread_cleanup_push unprotected_count \
		protect_count unlock_twice philosophy_eat_spaghetti \
		use_two_mutexes simplified_locking timedlock rwlock \
		timedrdlock timedwrlock \

all: clean $(PROGS)

$(PROGS): $(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out foo bar

include $(ROOT)/Make.libapue.inc
