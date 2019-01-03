#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line {
	char *line;
	struct line *next;
};

static char *trimmed(const char *line, char *trimChars);
void inputLines(int *nLines, char ***lines, const char *filename);

static char *trimmed(const char *line, char *trimChars)
{
	const char *b, *e;
	char *trimmedLine;
	int size;

	if (trimChars == NULL) {
		trimChars = "\r\n";
	}

	for (b = line; *b != '\0'; b++) {
		if (strchr(trimChars, *b) == NULL) {
			break;
		}
	}

	for (e = line + strlen(line) - 1; e > b; e--) {
		if (strchr(trimChars, *e) == NULL) {
			break;
		}
	}

	size = e - b + 1;
	trimmedLine = malloc(sizeof(char) * (size + 1));
	strncpy(trimmedLine, b, size);
	trimmedLine[size] = '\0';

	return (trimmedLine);

}

void inputLines(int *nLines, char ***lines, const char *filename)
{
	FILE *f;
	int i;
	struct line *node;
	struct line *head = NULL;
	struct line **tail = &head;

	f = fopen(filename, "r");
	if (f == NULL) {
		perror("fopen");
		exit(1);
	}

	for ((*nLines) = 0; ; (*nLines)++) {
		char *line = NULL;
		size_t len = 0;
		ssize_t ret;

		ret = getline(&line, &len, f);
		if (ret == -1) {
			if (feof(f)) {
				free(line);
				break;
			} else {
				perror("getline");
				exit(1);
			}
		}

		node = malloc(sizeof(struct line));
		node->line = trimmed(line, NULL);
		free(line);

		node->next = *tail;
		*tail = node;
		tail = &(node->next);
	}

	*lines = malloc(sizeof(char *) * *nLines);

	node = head;
	for (i = 0; i < *nLines; i++) {
		struct line *nextNode;

		(*lines)[i] = node->line;
		nextNode = node->next;
		free(node);
		node = nextNode;
	}
}
