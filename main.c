#include "main.h"
#include <unistd.h>

int main(int ac, char **argv)
{
	(void)ac;
	(void)argv;

	shell_loop();
	return (0);
}
