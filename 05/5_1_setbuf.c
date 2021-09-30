#include "apue.h"


void my_setbuf(FILE *fp, char *buf);
void pr_stdio(const char *, FILE *);
int is_unbuffered(FILE *);
int is_linebuffered(FILE *);
int buffer_size(FILE *);

int main() {
    char buf[BUFSIZ];

    printf("before my_setbuf:\n");
    pr_stdio("stdin", stdin);

    my_setbuf(stdin, NULL);

    printf("after my_setbuf(NULL):\n");
    pr_stdio("stdin", stdin);

    my_setbuf(stdin, buf);

    printf("after my_setbuf(buf):\n");
    pr_stdio("stdin", stdin);

    return 0;
}

void my_setbuf(FILE *fp, char *buf) {
    if (buf == NULL) {
        setvbuf(fp, NULL, _IONBF, 0);
    } else {
        setvbuf(fp, buf, _IOFBF, BUFSIZ);
    }
}

void pr_stdio(const char *name, FILE *fp) {
    printf("stream = %s, ", name);

    if (is_unbuffered(fp)) {
        printf("unbuffered");
    } else if (is_linebuffered(fp)) {
        printf("line buffered");
    } else {
        printf("fully buffered");
    }

    printf(", buffer size = %d\n", buffer_size(fp));
}

/*
 * The following is nonportable.
 */
#if defined(_IO_UNBUFFERED)

int is_unbuffered(FILE *fp) {
    return (fp->_flags & _IO_UNBUFFERED);
}

int is_linebuffered(FILE *fp) {
    return (fp->_flags & _IO_LINE_BUF);
}

int buffer_size(FILE *fp) {
    return (fp->_IO_buf_end - fp->_IO_buf_base);
}

#elif defined(__SNBF)

int is_unbuffered(FILE *fp) {
    return (fp->flags & __SNBF);
}

int is_linebuffered(FILE *fp) {
    return (fp->flags & __SLBF);
}

int buffer_size(FILE *fp) {
    return (fp->_buf._size);
}

#elif defined(_IONBF)

#ifdef _LP64
#define _flag __pad[4]
#define _ptr __pad[1]
#define _base __pad[2]
#endif

int is_unbuffered(FILE *fp) {
    return (fp->_flags & _IONBF);
}

int is_linebuffered(FILE *fp) {
    return (fp->_flags & _IOLBF);
}

int buffer_size(FILE *fp) {
#ifdef _LP64
    return (fp->_base - fp->_ptr);
#else
    return BUFSIZ;  /* just a guess */
#endif
}

#else

#error unknown stdio implementation!

#endif
