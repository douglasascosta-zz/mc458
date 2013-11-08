#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>

void opSequence(std::string **p, int i, int j);


int m, n;
int copyCost, replCost, delCost, insCost, twdCost, killCost;
int killIndex;
std::vector <std::vector <int> > c;
std::vector<std::vector <std::string> > op;

std::string copy = "Copy ";
std::string repl = "Replace ";
std::string del = "Delete ";
std::string ins = "Insert ";
std::string twd = "Twiddle ";
std::string kill = "Kill ";

void opSequence(int i, int j);


int findED() {

    int i, j;

    char xl[100], yl[100];

    scanf("%d %d", &m, &n);
    c.resize(m+1);
    op.resize(m+1);

    for (i = 0; i < m+1; i++) {
        c[i].resize(n+1);
        op[i].resize(n+1);
    }


    scanf("%s", xl);
    scanf("%s", yl);
    std::string x(xl), y(yl);

    scanf("%d %d %d %d %d %d", &copyCost, &replCost, &delCost, &insCost, &twdCost, &killCost);

    /*
    std::cout << m  << " " << n<< std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << copyCost << replCost << delCost << insCost << twdCost << killCost << std::endl;
    */  

    for (i = 0; i < m+1; i++) {
        c[i][0] = i*delCost;
        op[i][0] = del;
    }

    for (j = 0; j < n+1; j++) {
        c[0][j] = j*insCost;
        op[0][j] = ins ;
    }


    for (i = 1; i < m+1; i++) {
        for (j = 1; j < n+1; j++) {
            c[i][j] = 1000000;

            if (x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] + copyCost;
                op[i][j] = copy + y[i];
                std::cout << y[i] << std::endl;
            }

            if ((c[i-1][j-1] + replCost) < c[i][j]) {
                c[i][j] = c[i-1][j-1] + replCost;
                op[i][j] = repl + y[j];
            }

            if (i >= 2 && j >= 2 && x[i] == y[j-1] && x[i-1] == y[j] && (c[i-2][j-2] + twdCost) < c[i][j]) {
                c[i][j] = c[i-2][j-2] + twdCost;
                op[i][j] = twd + y[j-1] + y[j];
            }

            if ((c[i-1][j] + delCost) < c[i][j]) {
                c[i][j] = c[i-1][j] + delCost;
                op[i][j] = del + "_";
            }

            if ((c[i][j-1] + insCost) < c[i][j]) {
                c[i][j] = c[i][j-1] + insCost;
                op[i][j] = ins + y[j];
            }
        }
    }

    for (i = 0; i < m; i++) {
        if ((c[i][n] + killCost) < c[m][n]) {
            c[m][n] = c[i][n] + killCost;
            op[m][n] = kill + '*';
            killIndex = i+1;
        }
    }

    /*
    for (i = 0; i < m+1; i++) {
            for (j = 0; j < n+1; j++) {
                    std::cout << c[i][j] << " ";
            }
            std::cout << std::endl;
    }


    for (i = 0; i < m+1; i++) {
            for (j = 0; j < n+1; j++) {
                    std::cout << "\t\t" << op[i][j] ;
            }
            std::cout << std::endl;
    }
    */

    return c[m][n];
    }


void opSequence(int i, int j) {

    int il, jl;

    if (i == 0 && j == 0) {
        return;
    }

    if (op[i][j].find(copy) != std::string::npos || op[i][j].find(repl) != std::string::npos) {
        il = i - 1;
        jl = j - 1;    
    } else if (op[i][j].find(twd) != std::string::npos) {
        il = i - 2;
        jl = j - 2; 
    } else if (op[i][j].find(del) != std::string::npos) {
        il = i - 1;
        jl = j;
    } else if (op[i][j].find(ins) != std::string::npos) {
        il = i;
        jl = j - 1;
    } else {
        op[i][j] = kill + "*";
        il = killIndex;
        jl = j;
    }

    opSequence(il, jl);
    std::cout << i << " " << j << " " << op[i][j] << std::endl;
    return;
}

int main() {

    std::cout << findED() << std::endl;
    opSequence(m, n);

    return 0;
}







