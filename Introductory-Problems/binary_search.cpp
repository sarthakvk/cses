#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <unordered_set>
#include <set>

using namespace std;
// void splitString(std::string &str);

int main()
{
    set<int> s{3, 4, 5, 7, 8, 2};
    // copy(vec.begin(), ite, vec.rbegin());
    // return 0;
    auto x = 6;
    auto it = s.lower_bound(x);
    if (it == s.begin())
    {
        cout << *it << "\n";
    }
    else if (it == s.end())
    {
        it--;
        cout << *it << "\n";
    }
    else
    {
        int a = *it;
        it--;
        int b = *it;
        if (x - b < a - x)
            cout << b << "\n";
        else
            cout << a << "\n";
    }
}
