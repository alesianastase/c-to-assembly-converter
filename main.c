#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mov(char a[100][256]) {
	printf("MOV ");
	if (strstr(a[0], "a") != 0)
		printf("eax, ");
	else if (strstr(a[0], "b") != 0)
		printf("ebx, ");
	else if (strstr(a[0], "c") != 0)
		printf("ecx, ");
	else
		printf("edx, ");

	if (strcmp(a[2], "a") == 0)
		printf("eax");
	else if (strcmp(a[2], "b") == 0)
		printf("ebx");
	else if (strcmp(a[2], "c") == 0)
		printf("ecx");
	else if (strcmp(a[2], "d") == 0)
		printf("edx");
	else
		printf("%s", a[2]);
	printf("\n");
}

void operations(char a[100][256]) {
	if (strcmp(a[3], "&") == 0)
		printf("AND ");
	else if (strcmp(a[3], "|") == 0)
		printf("OR ");
	else if (strcmp(a[3], "^") == 0)
		printf("XOR ");
	if (strcmp(a[3], "+") == 0)
		printf("ADD ");
	else if (strcmp(a[3], "-") == 0)
		printf("SUB ");
	if (strcmp(a[2], "a") == 0)
		printf("eax, ");
	else if (strcmp(a[2], "b") == 0)
		printf("ebx, ");
	else if (strcmp(a[2], "c") == 0)
		printf("ecx, ");
	else
		printf("edx, ");
	if (strcmp(a[4], "a") == 0)
		printf("eax");
	else if (strcmp(a[4], "b") == 0)
		printf("ebx");
	else if (strcmp(a[4], "c") == 0)
		printf("ecx");
	else if (strcmp(a[4], "d") == 0)
		printf("edx");
	else
		printf("%s", a[4]);
	printf("\n");
}

void muldiv(char a[100][256]) {
	char aux2[256];
	if (strcmp(a[4], "a") == 0) {
		strcpy(aux2, "eax");
	} else if (strcmp(a[4], "b") == 0) {
		strcpy(aux2, "ebx");
	} else if (strcmp(a[4], "c") == 0) {
		strcpy(aux2, "ecx");
	} else if (strcmp(a[4], "d") == 0) {
		strcpy(aux2, "edx");
	} else if (strcmp(a[4], "0") == 0 && strcmp(a[3], "/") == 0) {
		printf("Error\n");
		return;
	} else {
		strcpy(aux2, a[4]);
	}

	if (strcmp(a[2], "a") != 0)
		printf("MOV eax, ");

	if (strcmp(a[2], "a") == 0)
	{
		if (strcmp(a[3], "*") == 0)
			printf("MUL %s\n", aux2);
		else if (strcmp(a[3], "/") == 0)
			printf("DIV %s\n", aux2);
	} else if (strcmp(a[2], "b") == 0) {
		printf("ebx\n");
		if (strcmp(a[3], "*") == 0)
			printf("MUL %s\n", aux2);
		else if (strcmp(a[3], "/") == 0)
			printf("DIV %s\n", aux2);
		printf("MOV ebx, eax\n");
	} else if (strcmp(a[2], "c") == 0) {
		printf("ecx\n");
		if (strcmp(a[3], "*") == 0)
			printf("MUL %s\n", aux2);
		else if (strcmp(a[3], "/") == 0)
			printf("DIV %s\n", aux2);
		printf("MOV ecx, eax\n");
	} else if (strcmp(a[2], "d") == 0) {
		printf("edx\n");
		if (strcmp(a[3], "*") == 0)
			printf("MUL %s\n", aux2);
		else if (strcmp(a[3], "/") == 0)
			printf("DIV %s\n", aux2);
		printf("MOV edx, eax\n");
	}
}

void shift(char s[256], char a[100][256]) {
	if (strstr(s, "<<") != 0)
		printf("SHL ");
	else if (strstr(s, ">>") != 0)
		printf("SHR ");

	if (strstr(a[0], "a") != 0)
		printf("eax, ");
	else if (strstr(a[0], "b") != 0)
		printf("ebx, ");
	else if (strstr(a[0], "c") != 0)
		printf("ecx, ");
	else
		printf("edx, ");

	printf("%s", a[4]);

	printf("\n");
}

void conditional(char a[100][256]) {
	a[3][strlen(a[3]) - 1] = '\0';
	printf("CMP ");

	if (strcmp(a[1], "(a") == 0)
		printf("eax, ");
	else if (strcmp(a[1], "(b") == 0)
		printf("ebx, ");
	else if (strcmp(a[1], "(c") == 0)
		printf("ecx, ");
	else
		printf("edx, ");

	printf("%s\n", a[3]);

	if (strcmp(a[2], "==") == 0)
		printf("JNE end_label\n");
	else if (strcmp(a[2], "<=") == 0)
		printf("JG end_label\n");
	else if (strcmp(a[2], ">=") == 0)
		printf("JL end_label\n");
	else if (strcmp(a[2], "<") == 0)
		printf("JGE end_label\n");
	else if (strcmp(a[2], ">") == 0)
		printf("JLE end_label\n");
}

void wh(char a[100][256]) {
	a[3][strlen(a[3]) - 1] = '\0';
	printf("start_loop:\nCMP ");

	if (strcmp(a[1], "(a") == 0)
		printf("eax, ");
	else if (strcmp(a[1], "(b") == 0)
		printf("ebx, ");
	else if (strcmp(a[1], "(c") == 0)
		printf("ecx, ");
	else
		printf("edx, ");

	printf("%s\n", a[3]);

	if (strcmp(a[2], "==") == 0)
		printf("JNE end_label\n");
	else if (strcmp(a[2], "<=") == 0)
		printf("JG end_label\n");
	else if (strcmp(a[2], ">=") == 0)
		printf("JL end_label\n");
	else if (strcmp(a[2], "<") == 0)
		printf("JGE end_label\n");
	else if (strcmp(a[2], ">") == 0)
		printf("JLE end_label\n");
}

void fr(char a[100][256], char *aux) {
	if (strcmp(a[1], "(a") == 0)
		strcpy(aux, "eax");
	else if (strcmp(a[1], "(b") == 0)
		strcpy(aux, "ebx");
	else if (strcmp(a[1], "(c") == 0)
		strcpy(aux, "ecx");
	else
		strcpy(aux, "edx");

	printf("MOV %s, %s\n", aux, a[3]);
	printf("start_loop:\n");

	printf("CMP %s, %s\n", aux, a[6]);

	if (strcmp(a[5], "==") == 0)
		printf("JNE end_label\n");
	else if (strcmp(a[5], "<=") == 0)
		printf("JG end_label\n");
	else if (strcmp(a[5], ">=") == 0)
		printf("JL end_label\n");
	else if (strcmp(a[5], "<") == 0)
		printf("JGE end_label\n");
	else if (strcmp(a[5], ">") == 0)
		printf("JLE end_label\n");
}

int main(void) {
	char s[256][256], aux[256], *t, a[100][256], aux2[256];
	int i = 0, g = 1, j;

	while (fgets(s[i], 256, stdin))
	{
		j = 0;
		s[i][strlen(s[i])] = '\0';
		strcpy(aux, s[i]);
		t = strtok(aux, " ;");

		while (t)
		{
			strcpy(a[j++], t);
			t = strtok(NULL, " ;");
		}

		j--;

		if (strcmp(a[1], "=") == 0 && j == 3)
			mov(a);

		if (strstr(s[i], "for") != 0) {
			g = 2;
			fr(a, aux2);
		} else if (strstr(s[i], "+") != 0 || strstr(s[i], "-") != 0 ||
					strstr(s[i], "^") != 0 ||	strstr(s[i], "|") != 0 ||
					strstr(s[i], "&") != 0) {
			operations(a);
		} else if (strstr(s[i], "*") != 0 || strstr(s[i], "/") != 0) {
			muldiv(a);
		} else if (strstr(s[i], "<<") != 0 || strstr(s[i], ">>") != 0) {
			shift(s[i], a);
		} else if (strstr(s[i], "if") != 0) {
			g = 0;
			conditional(a);
		} else if (strstr(s[i], "while") != 0) {
			g = 1;
			wh(a);
		}

		if (strstr(s[i], "}") != 0)
		{
			if (g == 0)
				printf("end_label:\n");
			else if (g == 1)
				printf("JMP start_loop\nend_label:\n");
			else if (g == 2)
			{
				a[11][strlen(a[11]) - 1] = '\0';
				printf("ADD %s, %s\n", aux2, a[11]);
				printf("JMP start_loop\nend_loop:\n");
			}
		}
		i++;
	}

	return 0;
}