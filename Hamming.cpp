#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getK(int n)
{
    int ans = 0, cur = 1;
    while (n + ans >= cur)
    {
        cur <<= 1;
        ++ans;
    }
    return ans;
}

bool isPow(int n)
{
    while (n % 2 == 0)
    {
        n >>= 1;
    }
    return n == 1;
}

void hamming(const string& a)
{
    int n = a.size();
    int k = getK(n);
    int m = n + k;
    string ans;
    cout << "n = " << n << ", k = " << k << ", m = " << m << endl;

    vector<vector<int> > v(k);
    vector<int> b(k);
    for (int i = 1, j = 0; i <= m; ++i)
    {
        if (isPow(i))
        {
            ans.push_back('0');
        }
        else
        {
            ans.push_back(a[j++]);
        }

        for (int g = 0, mask = 1; g < k; ++g, mask <<= 1)
        {
            if (i & mask)
            {
                v[g].push_back(i);
            }
        }
    }

    for (int i = 0, ind = 1; i < k; ++i, ind <<= 1)
    {
        for (int j = 1; j < v[i].size(); ++j)
        {
            b[i] ^= (ans[v[i][j] - 1] - '0');
        }
        cout << "b" << i + 1 << " = " << b[i] << endl;
        ans[ind - 1] += b[i];
    }

    cout << "Ans: " << ans << endl;
}

int main()
{
    string a;
    cin >> a;

    hamming(a);
}
