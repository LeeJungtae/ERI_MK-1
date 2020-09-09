/*
 * Project Name: ERI
 * Version: MK-1
 * Author: 202005027 LeeJungtae
 * Create Date: 2020-09-09
 * Modify Date: 2020-09-09
 * Platform: Windows 10
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// Macro Constants
#define MAX_SIZE 1000000

// External Variables
static long long eax = 0LL;
static long long ebx = 0LL;
static long long ecx = 0LL;
static long long edx = 0LL;
static char command[MAX_SIZE] = "";

// Function Prototypes
void mk1_start(void);
void mk1_loop(void);				// Run Interpreter
void mk1_loop2(char* filename);		// Run Source Code
void mk1_interpret(void);
void mk1_comment(void);				// Single Line Comment
void mk1_comments(void);			// Multi Line Comment
void mk1_quit(void);
void mk1_exit(void);
void mk1_now(void);
void mk1_error(void);
void mk1_error2(void);
void mk1_put(void);		// print a
void mk1_get(void);		// input a
void mk1_mov(void);		// a = b
void mk1_add(void);		// a = a + b
void mk1_sub(void);		// a = a - b
void mk1_mul(void);		// a = a * b
void mk1_div(void);		// a = a / b
void mk1_mod(void);		// a = a % b
void mk1_pow(void);		// a = a ** b
void mk1_inc(void);		// a = a + 1
void mk1_dec(void);		// a = a - 1
void mk1_lsh(void);		// a = a << b
void mk1_rsh(void);		// a = a >> b
void mk1_and(void);		// a = a & b
void mk1_or(void);		// a = a | b
void mk1_xor(void);		// a = a ^ b
void mk1_not(void);		// a = ~a

// Main Function
int main(int argc, char* argv[])
{
	// Just Execute Interpreter
	if (argc == 1)
	{
		mk1_start();
		mk1_loop();
	}
	// Execute Interpreter to run Source File
	else if (argc == 2)
	{
		mk1_loop2(argv[1]);
	}
}

// Function Definitions
void mk1_start(void)
{
	printf("#######################################################\n");
	printf("#          Welcome to ERI Interpreter World!          #\n");
	printf("# Use <how> if you want what command in this program. #\n");
	printf("#######################################################\n");
}
void mk1_loop(void)
{
	while (true)
	{
		printf("ERI> ");
		fgets(command, MAX_SIZE + 1, stdin);
		mk1_interpret();
	}
}
void mk1_loop2(char* filename)
{
	FILE* input_file;
	input_file = fopen(filename, "r");
	int len = strlen(filename);
	if ((filename[len - 1] == 'i') && (filename[len - 2] == 'r') && (filename[len - 3] == 'e'))
	{
		while (fgets(command, MAX_SIZE + 1, input_file) != NULL)
		{
			mk1_interpret();
		}
	}
	else if (input_file == NULL)
	{
		mk1_error2();
	}
	else
	{
		mk1_error2();
	}
	fclose(input_file);
}
void mk1_interpret(void)
{
	if (!strcmp(command, "###\n"))
	{
		mk1_comments();
	}
	else if (command[0] == '#')
	{
		mk1_comment();
	}
	else if (!strcmp(command, "\n"))
	{
		printf("");
	}
	else if (!strcmp(command, "quit\n"))
	{
		mk1_quit();
	}
	else if (!strcmp(command, "exit\n"))
	{
		mk1_exit();
	}
	else if (!strcmp(command, "now\n"))
	{
		mk1_now();
	}
	else if (!strncmp(command, "put", 3))
	{
		mk1_put();
	}
	else if (!strncmp(command, "get", 3))
	{
		mk1_get();
	}
	else if (!strncmp(command, "mov", 3))
	{
		mk1_mov();
	}
	else if (!strncmp(command, "add", 3))
	{
		mk1_add();
	}
	else if (!strncmp(command, "sub", 3))
	{
		mk1_sub();
	}
	else if (!strncmp(command, "mul", 3))
	{
		mk1_mul();
	}
	else if (!strncmp(command, "div", 3))
	{
		mk1_div();
	}
	else if (!strncmp(command, "mod", 3))
	{
		mk1_mod();
	}
	else if (!strncmp(command, "pow", 3))
	{
		mk1_pow();
	}
	else if (!strncmp(command, "inc", 3))
	{
		mk1_inc();
	}
	else if (!strncmp(command, "dec", 3))
	{
		mk1_dec();
	}
	else if (!strncmp(command, "lsh", 3))
	{
		mk1_lsh();
	}
	else if (!strncmp(command, "rsh", 3))
	{
		mk1_rsh();
	}
	else if (!strncmp(command, "and", 3))
	{
		mk1_and();
	}
	else if (!strncmp(command, "or",  2))
	{
		mk1_or();
	}
	else if (!strncmp(command, "xor", 3))
	{
		mk1_xor();
	}
	else if (!strncmp(command, "not", 3))
	{
		mk1_not();
	}
	else
	{
		mk1_error();
	}
}
void mk1_comment(void)
{
	printf("");
}
void mk1_comments(void)
{
	while (true)
	{
		printf("ERI# ");
		fgets(command, MAX_SIZE + 1, stdin);
		if (!strcmp(command, "###\n"))
		{
			break;
		}
	}
}
void mk1_quit(void)
{
	exit(0);
}
void mk1_exit(void)
{
	exit(0);
}
void mk1_now(void)
{
	time_t now_time = time(NULL);
	struct tm now = *localtime(&now_time);
	int year = now.tm_year + 1900;
	int month = now.tm_mon + 1;
	int day = now.tm_mday;
	int hour = now.tm_hour;
	int minute = now.tm_min;
	int second = now.tm_sec;
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
}
void mk1_error(void)
{
	printf("Wrong Input Detected\n");
}
void mk1_error2(void)
{
	printf("Can\'t Open File!\n");
}
void mk1_put(void)
{
	char var[MAX_SIZE] = "";
	for (int i = 4; command[i] != '\n'; i++)
	{
		var[i - 4] = command[i];
	}
	if (!strcmp(var, "eax"))
	{
		printf("Print eax : %lld\n", eax);
	}
	else if (!strcmp(var, "ebx"))
	{
		printf("Print ebx : %lld\n", ebx);
	}
	else if (!strcmp(var, "ecx"))
	{
		printf("Print ecx : %lld\n", ecx);
	}
	else if (!strcmp(var, "edx"))
	{
		printf("Print edx : %lld\n", edx);
	}
	else
	{
		mk1_error();
	}
}
void mk1_get(void)
{
	char var[MAX_SIZE] = "";
	for (int i = 4; command[i] != '\n'; i++)
	{
		var[i - 4] = command[i];
	}
	if (!strcmp(var, "eax"))
	{
		printf("Input eax : ");
		scanf("%lld", &eax);
		while (getchar() != '\n');
	}
	else if (!strcmp(var, "ebx"))
	{
		printf("Input ebx : ");
		scanf("%lld", &ebx);
		while (getchar() != '\n');
	}
	else if (!strcmp(var, "ecx"))
	{
		printf("Input ecx : ");
		scanf("%lld", &ecx);
		while (getchar() != '\n');
	}
	else if (!strcmp(var, "edx"))
	{
		printf("Input edx : ");
		scanf("%lld", &edx);
		while (getchar() != '\n');
	}
	else
	{
		mk1_error();
	}
}
void mk1_mov(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax = num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx = num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx = num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx = num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax = eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax = ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax = ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax = edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx = eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx = ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx = ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx = edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx = eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx = ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx = ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx = edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx = eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx = ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx = ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx = edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_add(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax += num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx += num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx += num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx += num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax += eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax += ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax += ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax += edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx += eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx += ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx += ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx += edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx += eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx += ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx += ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx += edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx += eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx += ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx += ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx += edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_sub(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax -= num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx -= num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx -= num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx -= num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax -= eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax -= ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax -= ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax -= edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx -= eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx = ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx -= ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx -= edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx -= eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx -= ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx -= ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx -= edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx -= eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx -= ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx -= ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx -= edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_mul(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax *= num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx *= num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx *= num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx *= num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax *= eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax *= ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax *= ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax *= edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx *= eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx *= ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx *= ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx *= edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx *= eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx *= ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx *= ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx *= edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx *= eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx *= ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx *= ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx *= edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_div(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax /= num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx /= num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx /= num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx /= num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax /= eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax /= ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax /= ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax /= edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx /= eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx /= ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx /= ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx /= edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx /= eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx /= ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx /= ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx /= edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx /= eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx /= ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx /= ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx /= edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_mod(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax %= num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx %= num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx %= num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx %= num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax %= eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax %= ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax %= ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax %= edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx %= eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx %= ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx %= ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx %= edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx %= eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx %= ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx %= ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx %= edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx %= eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx %= ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx %= ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx %= edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_pow(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax = (long long) pow(eax, num);
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx = (long long) pow(ebx, num);
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx = (long long) pow(ecx, num);
		}
		else if (!strcmp(var, "edx"))
		{
			edx = (long long) pow(edx, num);
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax = (long long) pow(eax, eax);
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax = (long long) pow(eax, ebx);
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax = (long long) pow(eax, ecx);
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax = (long long) pow(eax, edx);
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx = (long long) pow(ebx, eax);
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx = (long long) pow(ebx, ebx);
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx = (long long) pow(ebx, ecx);
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx = (long long) pow(ebx, edx);
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx = (long long) pow(ecx, eax);
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx = (long long) pow(ecx, ebx);
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx = (long long) pow(ecx, ecx);
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx = (long long) pow(ecx, edx);
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx = (long long) pow(edx, eax);
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx = (long long) pow(edx, ebx);
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx = (long long) pow(edx, ecx);
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx = (long long) pow(edx, edx);
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_inc(void)
{
	char var[MAX_SIZE] = "";
	for (int i = 4; command[i] != '\n'; i++)
	{
		var[i - 4] = command[i];
	}
	if (!strcmp(var, "eax"))
	{
		eax += 1;
	}
	else if (!strcmp(var, "ebx"))
	{
		ebx += 1;
	}
	else if (!strcmp(var, "ecx"))
	{
		ecx += 1;
	}
	else if (!strcmp(var, "edx"))
	{
		edx += 1;
	}
	else
	{
		mk1_error();
	}
}
void mk1_dec(void)
{
	char var[MAX_SIZE] = "";
	for (int i = 4; command[i] != '\n'; i++)
	{
		var[i - 4] = command[i];
	}
	if (!strcmp(var, "eax"))
	{
		eax -= 1;
	}
	else if (!strcmp(var, "ebx"))
	{
		ebx -= 1;
	}
	else if (!strcmp(var, "ecx"))
	{
		ecx -= 1;
	}
	else if (!strcmp(var, "edx"))
	{
		edx -= 1;
	}
	else
	{
		mk1_error();
	}
}
void mk1_lsh(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax <<= num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx <<= num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx <<= num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx <<= num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax <<= eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax <<= ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax <<= ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax <<= edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx <<= eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx <<= ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx <<= ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx <<= edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx <<= eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx <<= ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx <<= ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx <<= edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx <<= eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx <<= ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx <<= ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx <<= edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_rsh(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax >>= num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx >>= num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx >>= num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx >>= num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax >>= eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax >>= ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax >>= ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax >>= edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx >>= eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx >>= ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx >>= ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx >>= edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx >>= eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx >>= ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx >>= ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx >>= edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx >>= eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx >>= ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx >>= ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx >>= edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_and(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax &= num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx &= num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx &= num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx &= num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax &= eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax &= ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax &= ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax &= edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx &= eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx &= ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx &= ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx &= edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx &= eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx &= ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx &= ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx &= edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx &= eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx &= ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx &= ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx &= edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_or(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 3; i < 6; i++)
		{
			var[i - 3] = command[i];
		}
		long long num = 0LL;
		for (int i = 7; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax |= num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx |= num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx |= num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx |= num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 3; i < 6; i++)
		{
			var1[i - 3] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 7; command[i] != '\n'; i++)
		{
			var2[i - 7] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax |= eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax |= ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax |= ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax |= edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx |= eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx |= ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx |= ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx |= edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx |= eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx |= ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx |= ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx |= edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx |= eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx |= ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx |= ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx |= edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_xor(void)
{
	// var <- val
	if ((command[8] >= '0') && (command[8] <= '9'))
	{
		char var[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var[i - 4] = command[i];
		}
		long long num = 0LL;
		for (int i = 8; command[i] != '\n'; i++)
		{
			num = num * 10LL + command[i] - '0';
		}
		if (!strcmp(var, "eax"))
		{
			eax ^= num;
		}
		else if (!strcmp(var, "ebx"))
		{
			ebx ^= num;
		}
		else if (!strcmp(var, "ecx"))
		{
			ecx ^= num;
		}
		else if (!strcmp(var, "edx"))
		{
			edx ^= num;
		}
		else
		{
			mk1_error();
		}
	}
	// var <- var
	else if ((command[8] >= 'a') && (command[8] <= 'z'))
	{
		char var1[MAX_SIZE] = "";
		for (int i = 4; i < 7; i++)
		{
			var1[i - 4] = command[i];
		}
		char var2[MAX_SIZE] = "";
		for (int i = 8; command[i] != '\n'; i++)
		{
			var2[i - 8] = command[i];
		}
		if (!strcmp(var1, "eax") && !strcmp(var2, "eax"))
		{
			eax ^= eax;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ebx"))
		{
			eax ^= ebx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "ecx"))
		{
			eax ^= ecx;
		}
		else if (!strcmp(var1, "eax") && !strcmp(var2, "edx"))
		{
			eax ^= edx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "eax"))
		{
			ebx ^= eax;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ebx"))
		{
			ebx ^= ebx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "ecx"))
		{
			ebx ^= ecx;
		}
		else if (!strcmp(var1, "ebx") && !strcmp(var2, "edx"))
		{
			ebx ^= edx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "eax"))
		{
			ecx ^= eax;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ebx"))
		{
			ecx ^= ebx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "ecx"))
		{
			ecx ^= ecx;
		}
		else if (!strcmp(var1, "ecx") && !strcmp(var2, "edx"))
		{
			ecx ^= edx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "eax"))
		{
			edx ^= eax;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ebx"))
		{
			edx ^= ebx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "ecx"))
		{
			edx ^= ecx;
		}
		else if (!strcmp(var1, "edx") && !strcmp(var2, "edx"))
		{
			edx ^= edx;
		}
		else
		{
			mk1_error();
		}
	}
}
void mk1_not(void)
{
	char var[MAX_SIZE] = "";
	for (int i = 4; command[i] != '\n'; i++)
	{
		var[i - 4] = command[i];
	}
	if (!strcmp(var, "eax"))
	{
		eax = ~eax;
	}
	else if (!strcmp(var, "ebx"))
	{
		ebx = ~ebx;
	}
	else if (!strcmp(var, "ecx"))
	{
		ecx = ~ecx;
	}
	else if (!strcmp(var, "edx"))
	{
		edx = ~edx;
	}
	else
	{
		mk1_error();
	}
}
