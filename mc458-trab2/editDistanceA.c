#include <stdio.h>
#include <string.h>

char x[] = "algorithm";
char y[] = "altruistic";
int m = 9;
int n = 10;

char cop[] = "Copy ";
char repl[] = "Replace ";
char del[] = "Delete ";
char ins[] = "Insert ";
char twd[] = "Twiddle ";
char kill[] = "Kill ";

int costCop = 1;
int costRepl = 1;
int costDel = 1;
int costIns = 1;
int costTwd = 1;
int costKill = 1;

int main(int argc, const char* argv[]) {
    

    int i = 0;
    int j = 0;

    int c[m+1][n+1];
    char ***op;

    for (i = 0; i < m+1; i++) {
        c[i][0] = i*costDel;
        op[i][0] = del;
    }

    for (j = 0; j < n+1; j++) {
        c[0][j] = j*costIns;
        op[0][j] = ins ;
    }


    for (i = 1; i < m+1; i++) {
        for (j = 1; j < n+1; j++) {
            c[i][j] = 10000;

            if (x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] + costCop;
                op[i][j] = cop + y[i];
            }

            if (x[i] != y[j] && (c[i-1][j-1] + costRepl) < c[i][j]) {
                c[i][j] = c[i-1][j-1] + costRepl;
                op[i][j] = repl + y[j];
            }

            if (i >= 2 && j >= 2 && x[i] == y[j-1] && x[i-1] == y[j] && (c[i-2][j-2] + costTwd) < c[i][j]) {
                c[i][j] = c[i-2][j-2] + costTwd;
                op[i][j] = twd + y[j-1] + y[j];
            }

            if ((c[i-1][j] + costDel) < c[i][j]) {
                c[i][j] = c[i-1][j] + costDel;
                op[i][j] = del + '_';
            }

            if ((c[i][j-1] + costIns) < c[i][j]) {
                c[i][j] = c[i][j-1] + costIns;
                op[i][j] = ins + y[j];
            }
        }
    }

    for (i = 0; i < m; i++) {
        if ((c[i][n] + costKill) < c[m][n]) {
            c[m][n] = c[i][n] + costKill;
            op[m][n] = kill + '*';
        }
    }

    printf("%d\n",c[m][n]);

    opSequence(op, m, n);

    return 0;
}

void opSequence(char ***op, int i, int j) {

    int il, jl;

//    printf("%d %d\n", i,j);

    if (i == 0 || j == 0) {
        return;
    }

    printf("%s\n", op[i][j]);

    if (strcmp(op[i][j], cop) == 0 || strcmp(op[i][j], repl)) {

        il = i-1;
        jl = j-1;

    } else if (strcmp(op[i][j], twd) == 0) {
    
        il = i-2;
        jl = j-2;    
    } else if (strcmp(op[i][j], del) == 0) {

        il = i-1;
        jl = j;        
    } else if (strcmp(op[i][j], ins) == 0) {
        il = i;
        jl = j-1; 
    } else {
    
        //kill
        il = 0;
        jl = 0;
    }

    

    opSequence(op, il, jl);
    printf("%d %d %s\n", i, j, &op[i][j]);

    return;
}




