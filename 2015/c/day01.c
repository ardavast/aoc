#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

int main(void)
{
	int nLines; char **lines; char *line;
	int floor;
	int i;

	inputLines(&nLines, &lines, "../inputs/day01input.txt");
	line = lines[0];

	/* part 1 */
	floor = 0;

	for (i = 0; i < strlen(line); i++) {
		if (line[i] == '(') {
			floor++;
		} else if (line[i] == ')') {
			floor--;
		}
	}

	printf("%d\n", floor);

	/* part 2 */
	floor = 1;

	for (i = 0; i < strlen(line); i++) {
		if (line[i] == '(') {
			floor++;
		} else if (line[i]) {
			floor--;
		}

		if (floor == -1) {
			printf("%d\n", i);
			break;
		}
	}

	return (EXIT_SUCCESS);
}
