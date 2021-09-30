#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    char output[] = "to stdout: hello world!\n";
    char err[] = "to stderr: something terrible has happened!\n";

    write(STDOUT_FILENO, output, strlen(output));
    write(STDERR_FILENO, err, strlen(err));

    return 0;
}
