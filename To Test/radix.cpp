#include <cstdio>
#include <string>
using std::string;

size_t getMax(char arr[][100], int n)
{
    int max = strlen(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (strlen(a[i]); > max)
            max = strlen(a[0]);
    }
    return max;
}

void countSort(char a[][100], int size, int k)
{
    char **b = (char **)malloc(sizeof(char) * size);
    for (int i = 0; i < size; i++)
    { //allocating memory for output
        b[i] = (char *)malloc(sizeof(char) * 100);
    }
    int c[257];

    for (int i = 0; i < 257; i++)
    {
        c[i] = 0;
        //cout << c[i] << "\n";
    }
    for (int j = 0; j < size; j++)
    {
        c[k < strlen(a[j]) ? (int)(unsigned char)a[j][k] + 1 : 0]++; //a[j] is a string
        //cout << c[a[j]] << endl;
    }

    for (int f = 1; f < 257; f++)
    {
        c[f] += c[f - 1];
    }

    for (int r = size - 1; r >= 0; r--)
    {
        //b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        strcpy(b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1], a[r]);
        c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
    }

    for (int l = 0; l < size; l++)
    {
        //a[l] = b[l];
        strcpy(a[l],b[l]);
    }

}

void radixSort(string b[], int r)
{
    int max = getMax(b, r);
    for (int digit = max; digit > 0; digit--)
    { // size_t is unsigned, so avoid using digit >= 0, which is always true
        countSort(b, r, digit - 1);
    }
}

int main(void)
{
    string data[] = {
        "aaaba",
        "dfjasdlifjai",
        "jiifjeogiejogp",
        "aabaaaa",
        "gsgj",
        "gerph",
        "aaaaaaa",
        "htjltjlrth",
        "joasdjfisdjfdo",
        "hthe",
        "aaaaaba",
        "jrykpjl",
        "hkoptjltp",
        "aaaaaa",
        "lprrjt"};
    puts("before sorting:");
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        printf("    %s\n", data[i]);
    }
    radixSort(data, (int)(sizeof(data) / sizeof(data[0])));
    puts("after sorting:");
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        printf("    %s\n", data[i]);
    }
    return 0;
}