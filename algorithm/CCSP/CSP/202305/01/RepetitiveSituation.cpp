#include <bits/stdc++.h>
using namespace std;
int n;
char pieces[64];
map<string, int> status_map;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 64; j++) 
            cin >> pieces[j];
        if (status_map.count(pieces)) 
            status_map[pieces] ++;
        else 
            status_map[pieces] = 1;
        cout << status_map[pieces] << endl;
    }
    return 0;
}