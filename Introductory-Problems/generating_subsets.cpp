#include <iostream>
#include <vector>

using namespace std;

vector<int> subset;

int n = 3;
void search(int); // recursive for generating sunsets
void search2(); // bit manupulation method


int main()
{
    search2();

    for (auto &i : subset)
    {
        cout << i << " ";
    }
}

void search(int k)
{
    if (k == ::n)
    {
        //process subset
        for (auto &i : subset)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    else
    {
        // search subset without k in it
        search(k + 1);
        subset.push_back(k);
        // search the subset with k in it
        search(k + 1);
        // remove k so that we can find subsets with another k's
        subset.pop_back();
    }
}

void search2()
{
    for (int b = 0; b < (1 << n); b++)
    {
        vector<int> subset2;
        // loop to check all the on bits on a set element
        for (int i = 0; i < n; i++)
        {
            // if bit is on then add the element it
            // correspond to subset
            if (b & (1 << i)){
                subset2.push_back(i);
            }
        }
        // process subset
        for (auto &i : subset2)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}