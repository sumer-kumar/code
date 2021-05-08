#include <bits/stdc++.h>
using namespace std;
#define max 1000
typedef struct Frog {
    int w; //for weight
    int l; //for length of jump
} frog;
void conflict(frog f, int index);
void start(int size);
frog a[max];
int jumps = 0;
int k;
void initialize() {
    for (int i = 0; i < max; i++)
    {
        a[i].w = a[i].l = 0;
    }
}

int main() {
    initialize();
    int test;
    cin >> test;
    int size;
    while (test--) {
        cin >> size;
        for (int i = 0; i < size; i++)
            cin >> a[i].w;

        for (int i = 0; i < size; i++) {
            cin >> a[i].l;
        }

        start(size);

        cout << jumps << endl;
        jumps = 0;
        initialize();
    }

    return 0;
}

void start(int size) {
    k = size;
    int i, j;
    j = 0;
    for (i = 1; i < max - 1; i++) {
        if (a[i].w != 0)
        {
            if (a[i].w < a[j].w)
            {
                frog f = a[j];
                a[j].w = a[j].l = 0; //reseting to vacant place

                if (a[j + f.l].w != 0) {
                    jumps++;//if one jump conflicts with the place
                    conflict(f, j + f.l);
                    while (a[++j].w == 0) {}

                }
                else
                {
                    a[j + f.l] = f;
                    while (a[++j].w == 0) {}
                    jumps++;
                }
            }
            else
            {
                while (a[++j].w == 0) {}
            }

        }
    }
}
void conflict(frog f, int index) {

    frog temp;

    if (f.w > a[index].w) {


        if (a[index + f.l].w != 0) {
            jumps++;
            conflict(f, index + f.l);

        }

        else
        {
            jumps++;
            a[index + f.l] = f;
        }

    }
    else
    {
        temp = f;
        f = a[index];
        a[index] = temp;
        jumps++;
        if (a[index + f.l].w == 0)
            a[index + f.l] = f;
        else
            conflict(f, index + f.l);
    }

}














