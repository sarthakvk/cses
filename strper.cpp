// Given a string, your task is to generate all different strings that can be created using its characters.

#include <bits/stdc++.h>

using namespace std;

string per;
string s;
int n;

vector<bool> chosen;
unordered_set<string> pd;
vector<string> o;

void strper() {
        if (pd.count(per) != 0){
                return;
        }
        else if ((int)per.size() == n){
                pd.insert(per);
                o.push_back(per);
                return;
        }
        for(int i = 0; i < n; i++){
                if (chosen[i] == true){
                        continue;
                }
                else{
                        chosen[i] = true;
                        per.push_back(s[i]);
                        strper();
                        chosen[i] = false;
                        per.pop_back();
                }
        }
}

int main() {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin >> s;
        n = (int)s.size();
        chosen.assign(n,false);
        sort(s.begin(), s.end());
        strper();
        cout << (int)o.size() << "\n";
        for (auto i = o.begin(); i < o.end(); i++){
                cout << *i << "\n";
        }
}