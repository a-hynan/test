#include <iostream>
#include <cstdlib>
using namespace std;

int m; 
int disksurface[10][10];

void reset() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			disksurface[i][j] = 0; 
		}
	}
}

bool legal(int i, int j, int x) {
	for (int b = 1; b <= m; b++) {
		if (x == disksurface[i][b])
			return false;
	}
	for (int a = 1; a <= m; a++) {
		if (x == disksurface[a][j])
			return false;
	}
	if (m == 4 || m == 6 || m == 8 || m == 9) {
		int interval_i, interval_j;
		int begin_i, begin_j;
		switch (m)
		{
		case 4:
			interval_i = 2;
			interval_j = 2;
			break;
		case 6:
			interval_i = 2;
			interval_j = 3;
			break;
		case 8:
			interval_i = 4;
			interval_j = 2;
			break;
		case 9:
			interval_i = 3;
			interval_j = 3;
			break;
		}
		begin_i = ((i - 1) / interval_i)*interval_i + 1;
		begin_j = ((j - 1) / interval_j)*interval_j + 1;
		for (int a = begin_i; a < begin_i + interval_i; a++) {
			for (int b = begin_j; b < begin_j + interval_j; b++) {
				if (x == disksurface[a][b])
					return false;
			}
		}
	}
	return true;
}

bool DFS(int a, int b) {
	while (disksurface[a][b] != 0) {
		if (a == m && b == m) {
			return true;
		}
		else if (b == m) {
			a++;
			b = 1;
		}
		else {
			b++;
		}
	}
	for (int x = 1; x <= m; x++) {
		if (legal(a, b, x)) {
			disksurface[a][b] = x;
			if (DFS(a, b)) {
				return true;
			}
			disksurface[a][b] = 0;
		}
	}
	return false;
}

int main(int argc, char * argv[]) {
	int n; 
	FILE *input;
	FILE *output;
	m = atoi(argv[2]);
	n = atoi(argv[4]);
	input = fopen("input.txt", "r");
	if (input == NULL) {
		return -1;
	}
	output = fopen("output.txt", "w");
	if (output == NULL) {
		return -1;
	}
	fclose(output);
	while (n > 0) {
		reset();
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				fscanf_s(input, "%d", &disksurface[i][j]);
			}
		}
		DFS(1, 1);
		output = fopen("output.txt", "a");
		if (output == NULL) {
			return -1;
		}
		for (int i = 1; i <= m; i++) {
			fprintf(output, "%d", disksurface[i][1]);
			for (int j = 2; j <= m; j++) {
				fprintf(output, " ");
				fprintf(output, "%d", disksurface[i][j]);
			}
			fprintf(output, "\n");
		}
		fprintf(output, "\n");
		n--;
		fclose(output);
	}
	fclose(input);
	return 0;
}
