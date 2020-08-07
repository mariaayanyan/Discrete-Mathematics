#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string mes;
void solve(string::iterator first, string::iterator last, const vector<string>& codes, int& count)
{
    if(first == last)
    {
        ++count;
        cout << mes << endl;
        return;
    }

    for(int i = 0; i < codes.size(); ++i)
    {
        if(last - first >= codes[i].size() && equal(codes[i].begin(), codes[i].end(), first))
        {
            mes.push_back('1' + i);
            solve(first + codes[i].size(), last, codes, count);
            mes.pop_back();
        }
    }
}
int main()
{
    vector<string> codes = { "10", "12", "012", "101", "2100" };
    
    string mes;
    cin >> mes;

    int count = 0;
    solve(mes.begin(), mes.end(), codes, count);

    cout << (count ? "Yes, " : "No");
    if(count)
        cout << count;
    cout << endl;
}