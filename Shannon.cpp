#include <iostream>
#include <vector>
#include <string>
using namespace std;

int logU(double n)
{
    int ans = 0, cur = 1;
    while (cur < n)
    {
        cur <<= 1;
        ++ans;
    }
    return ans;
}

void shannon(int n, const vector<double>& prob)
{
    vector<double> sigma(n);
    vector<int> L(n);

    cout << "L: ";
    for (int i = 0; i < n; ++i)
    {
        L[i] = logU(1 / prob[i]);
        cout << L[i] << " ";
    }
    cout << endl;

    cout << "S: 0 ";
    for (int i = 0; i < n - 1; ++i)
    {
        sigma[i + 1] = sigma[i] + prob[i];
        cout << sigma[i + 1] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < n; ++i)
    {
        double cur = sigma[i];
        cout << "Sh(a" << i + 1 << "): ";
        for (int j = 0; j < L[i]; ++j)
        {
            cur *= 2;
            if (cur >= 1)
            {
                cout << 1;
                --cur;
            }
            else
            {
                cout << 0;
            }
        }
        cout << endl;
    }
}

int main()
{
     int n;
     cin >> n;

     vector<double> prob(n);
     for(int i = 0; i < n; ++i)
         cin >> prob[i];

     shannon(n, prob);
}
/*
0.4 0.3 0.08 0.06 0.04 0.04 0.04 0.04
0.3 0.2 0.1 0.1 0.06 0.06 0.06 0.06 0.06
0.4 0.2 0.1 0.05 0.05 0.05 0.05 0.05 0.05
*/
