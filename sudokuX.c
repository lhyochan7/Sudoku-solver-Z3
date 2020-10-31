#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int min(int a, int b) {
	if (a<b)
	return a;
	return b;
}

int main()
{
	char file_name[50];
	int x = 0;
	int y = 0;
	char input[9][9];
	char temp;
	int i, j, k;
	int r, c, n;

	printf("Please enter the input file name: ");
	scanf("%s", file_name);

	FILE* ip = fopen(file_name, "r");
	FILE* fp = fopen("formula", "w");

	while (!feof(ip)) {
		fscanf(ip, "%c", &temp);
		if (temp == ' ') {
			continue;
		}
		else if (temp == '\n') {
			x++;
			y = 0;
			continue;
		}
		else {
			input[x][y] = temp;
			y++;
		}
	}
	fclose(ip);

	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
			fprintf(fp, "(declare-const p%d%d Int)\n", i, j);


	// Q0 pre-assigned cells
	fprintf(fp, "; Q0(input)\n");
	for (r = 0; r < 9; r++) {
		for (c = 0; c < 9; c++) {
			if (input[r][c] != '?')
			fprintf(fp, "(assert (and (= p%d%d %c)))\n", r + 1, c + 1, input[r][c]);
		}
	}

	// Q1 Cell constratins (from 0<n<10 & contains no more than one number per each cell)
	fprintf(fp, "; Q1(cell)\n");
	for (r = 1; r <= 9; r++)
	for (c = 1; c <= 9; c++)
	fprintf(fp, "(assert (and (>= p%d%d 1) (<= p%d%d 9)))\n", r, c, r, c);


	for (r = 1; r <= 9; r++) {
		for (c = 1; c <= 9; c++) {
			fprintf(fp, "(assert (not (and ");
			for (n = 1; n <= 9; n++) {
				fprintf(fp, "(= p%d%d %d) ", r, c, n);
			}
			fprintf(fp, ")))\n");
		}
	}

	// Q2 Every row has exactly one of each number
	fprintf(fp, "; Q2\n");
	fprintf(fp, "(assert (and ");
	for (r = 1; r <= 9; r++) {
		fprintf(fp, "(and ");
		for (n = 1; n <= 9; n++) {
			fprintf(fp, "(or ");
			for (c = 1; c <= 9; c++) {
				fprintf(fp, "(= p%d%d %d) ", r, c, n);
			}
			fprintf(fp, ")");
		}
		fprintf(fp, ")");
	}
	fprintf(fp, "))\n");

	// Q3 Every col has exactly one of each number
	fprintf(fp, "; Q3\n");
	fprintf(fp, "(assert (and ");
	for (c = 1; c <= 9; c++) {
		fprintf(fp, "(and ");
		for (n = 1; n <= 9; n++) {
			fprintf(fp, "(or ");
			for (r = 1; r <= 9; r++) {
				fprintf(fp, "(= p%d%d %d) ", r, c, n);
			}
			fprintf(fp, ")");
		}
		fprintf(fp, ")");
	}
	fprintf(fp, "))\n");


	// Q5
	fprintf(fp, "; Q3\n");
	fprintf(fp, "(assert (and ");
	for (c = 1; c <= 9; c++) {
		fprintf(fp, "(and ");
		for (n = 1; n <= 9; n++) {
			fprintf(fp, "(or ");
			for (r = 1; r <= 9; r++) {
				fprintf(fp, "(= p%d%d %d) ", r, c, n);
			}
			fprintf(fp, ")");
		}
		fprintf(fp, ")");
	}
	fprintf(fp, "))\n");

	// Q4 3x3 contains every number
	fprintf(fp, "; Q4\n");
	fprintf(fp, "(assert (and");
	for (x = 0; x <= 2; x++) {
		fprintf(fp, "(and ");
		for (y = 0; y <= 2; y++) {
			fprintf(fp, "(and ");
			for (n = 1; n <= 9; n++) {
				fprintf(fp, "(or ");
				for (r = 1; r <= 3; r++) {
					fprintf(fp, "(or ");
					for (c = 1; c <= 3; c++) {
						fprintf(fp, "(= p%d%d %d) ", (3 * x + r), (3 * y + c), n);
					}
					fprintf(fp, ")");
				}
				fprintf(fp, ") ");
			}
			fprintf(fp, ")");
		}
		fprintf(fp, ")");
	}
	fprintf(fp, "))\n");


	// Q5 Diagonal contains one of each number Top Right - Bottom Left
	fprintf(fp, "; Q5\n");
	fprintf(fp, "(assert (and ");
	for (r = 9; r <= 9; r++) {
		fprintf(fp, "(and ");
		for (c = 1; c <= 1; c++) {
			fprintf(fp, "(and ");
			for (n = 1; n <= 9; n++) {
				fprintf(fp, "(and (or (= p%d%d %d) ", r,c,n);
				for (k = 1; k <= min(r - 1, 9 - c); k++) {
					fprintf(fp, "(= p%d%d %d)", r - k, k + c, n);
				}
				fprintf(fp, "))");
			}
			fprintf(fp, ")");
		}
		fprintf(fp, ")");
	}
	fprintf(fp, "))\n");

	// Q6 Diagonal contains one of each number Top Left - Bottom Right
	fprintf(fp, "; Q6\n");
	fprintf(fp, "(assert (and ");
	for (r = 1; r <= 1; r++) {
		fprintf(fp, "(and ");
		for (c = 1; c <= 9; c++) {
			if(r==c)
			fprintf(fp, "(and ");
			for (n = 1; n <= 9; n++) {
				if(r == c)
				fprintf(fp, "(and (or (= p%d%d %d) ", r, c, n);
				for (k = 1; k <= min(9 - r , 9 - c); k++) {
					if(r==c)
					fprintf(fp, "(= p%d%d %d)", r + k, k + c, n);
				}
				if(r==c)
				fprintf(fp, "))");
			}
			if(r==c)
			fprintf(fp, ")");
		}
		fprintf(fp, ")");
	}
	fprintf(fp, "))\n");


	fprintf(fp, "(check-sat)\n(get-model)\n");

	fclose(fp);

	FILE* fout = fopen("output.txt", "w");
	FILE * fin = popen("z3 formula", "r") ; 
	char b[128] ;
	char s[128] ;
	char t[128] ;
	char output[r][c];

	fscanf(fin, "%s %*s", b) ;
	if (strcmp(b, "unsat")==0) {
		fprintf(fout, "no solution\n");
		printf("no solution\n");
		return 0;
	}

	for (k = 1 ; k <= 81 ; k++) {
		fscanf(fin, "%*s %s %*s %*s %s", s, t) ;
		r = s[1] - '0' ;
		c = s[2] - '0' ;
		output[r][c] = atoi(t) ;
	}

	for (r = 1 ; r <= 9 ; r++) {
		for (c = 1 ; c <= 9 ; c++) {
			fprintf(fout, "%d ", output[r][c]) ;
			printf("%d ", output[r][c]);
		}
		printf("\n");
		fprintf(fout, "\n") ;
	}

	printf("Results are also in output.txt ! \n");
	pclose(fin);
	fclose(fout);


	return 0;
}
