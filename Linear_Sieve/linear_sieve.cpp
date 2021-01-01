#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000

vector<int> p; 
bool isp[MAX+1];

void era(int n) {
	for(int i = 2; i <= n; ++i) {
		if(isp[i]) {
            p.push_back(i);
			for(int j = 2; i*j <= n; ++j)
				isp[i*j] = false;
        }
    }
}

void linear_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
		if(isp[i]) p.push_back(i);
		for(int j = 0; j < p.size() && i*p[j] <= n; ++j) {
			isp[i*p[j]] = false;
			if(i%p[j] == 0) break;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    clock_t start, end;
    memset(isp, true, sizeof isp);

    start = clock();
    era(MAX);
    end = clock();
    cout << "Eratosthenes : " << (double)(end - start) << "\n";

    memset(isp, true, sizeof isp);
    p.clear();

    start = clock();
    linear_sieve(MAX);
    end = clock();
    cout << "Linear : " << (double)(end - start) << "\n";

    cout << MAX << " " << p.size() << "\n";
    return 0;
}