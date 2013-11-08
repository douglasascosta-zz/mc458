#include <iostream>
#include <cstdlib>

using namespace std;
int main(int argc, char* argv[]){
    int s, x, y, i, j, z;
    char c;

    s = atoi(argv[1]);
    //cout << s;

    for(i=0; i<5; i++){
        y = rand()%s;
        z = s - y;
        cout << y << ' ' << z << endl;

        for(j=0; j<y; j++){
            c = rand()%26 + 97;
            cout << c;
        }
        cout << endl;
        for(j=0; j<z; j++){
            c = rand()%26 + 97;
            cout << c;
        }
        cout << endl;
        cout << 18 << " " << 20  << " " << 10 << " " << 8 << " " << 36 << " " << 17 << endl;
    }
    return 0;
}
