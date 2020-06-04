#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool same(deque<int>& a, deque<int>& b) {
    for(int i = 0; i < a.size(); i++)
        if(a[i] != b[i]) return false;
    return true;
}

bool chk(deque<int> a, deque<int>& b) {
    for(int i = 0; i < a.size(); i++) {
        if(same(a, b)) return false;
        deque<int> a2 = a;
        for(int j = 1; j < a2.size()/2; j++)
            swap(a2[j], a2[a2.size()-j]);
        if(same(a2, b)) return false;
        a2 = a;
        for(int j = 0; j < a2.size()/2; j++)
            swap(a2[j], a2[a2.size()-j-1]);
        if(same(a2, b)) return false;
        int tmp = a.front();
        a.pop_front();
        a.push_back(tmp);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<deque<int>> ans;
    deque<int> arr = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2};
    int cnt = 0;
    do {
        if((++cnt)%100 == 0) cout << cnt << endl;
        bool isok = true;
        for(auto &i : ans) {
            if(!chk(arr, i)) {
                isok = false;
                break;
            }
        }
        if(isok) ans.push_back(arr);
    } while(next_permutation(arr.begin(), arr.end()));
    cout << endl << ans.size() << endl;
    return 0;
}
