#include "main.h"
#include <unistd.h>

/**
 * main - Entry point
 * @ac: argument count
 * @argv: arguments vector
 *
 * Return: 0
 */

int main(int ac, char **argv)
{
	(void)ac;
	(void)argv;

	shell_loop();
	return (0);
}
