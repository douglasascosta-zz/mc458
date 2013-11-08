#include <iostream>
#include <string>
#include <map>

int main() {
    std::string x = "algorithm";
    std::string y = "altruistic";
    int m = 9;
    int n = 10;

    std::string cop = "Copy ";
    std::string repl = "Replace ";
    std::string del = "Delete ";
    std::string ins = "Insert ";
    std::string twd = "Twiddle ";
    std::string kill = "Kill ";

    std::map<std::string, int> tab = {{cop, 2}, {repl, 2}, {del, 1}, {ins, 3}, {twd, 1}, {kill, 1}};

    int i = 0;
    int j = 0;

    int c[m+1][n+1];
    std::string op[m+1][n+1];

    for (i = 0; i < m+1; i++) {
        c[i][0] = i*tab[del];
        op[i][0] = del;
    }

    for (j = 0; j < n+1; j++) {
        c[0][j] = j*tab[ins];
        op[0][j] = ins ;
    }


    for (i = 1; i < m+1; i++) {
        for (j = 1; j < n+1; j++) {
            c[i][j] = 10000;

            if (x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] + tab[cop];
                op[i][j] = cop + y[i];
            }

            if (x[i] != y[j] && (c[i-1][j-1] + tab[repl]) < c[i][j]) {
                c[i][j] = c[i-1][j-1] + tab[repl];
                op[i][j] = repl + y[j];
            }

            if (i >= 2 && j >= 2 && x[i] == y[j-1] && x[i-1] == y[j] && (c[i-2][j-2] + tab[twd]) < c[i][j]) {
                c[i][j] = c[i-2][j-2] + tab[twd];
                op[i][j] = twd + y[j-1] + y[j];
            }

            if ((c[i-1][j] + tab[del]) < c[i][j]) {
                c[i][j] = c[i-1][j] + tab[del];
                op[i][j] = del + "_";
            }

            if ((c[i][j-1] + tab[ins]) < c[i][j]) {
                c[i][j] = c[i][j-1] + tab[ins];
                op[i][j] = ins + y[j];
            }
        }
    }

    for (i = 0; i < m; i++) {
        if ((c[i][n] + tab[kill]) < c[m][n]) {
            c[m][n] = c[i][n] + tab[kill];
            op[m][n] = kill + "*";
        }
    }

//    for (i = 0; i < m+1; i++) {
//            for (j = 0; j < n+1; j++) {
//                    std::cout << c[i][j] << " ";
//            }
//            std::cout << std::endl;
//    }

    for (i = 0; i < m+1; i++) {
            for (j = 0; j < n+1; j++) {
                    std::cout << op[i][j] << "\t";
            }
            std::cout << std::endl;
    }

    std::cout << c[m][n] <<std::endl;

    return 0;
}

