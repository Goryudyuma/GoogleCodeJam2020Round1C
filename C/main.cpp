#include<bits/stdc++.h>
/**/
#include <random>
using namespace std;



int main() {
	long long int testCaseNum = 0;
	cin >> testCaseNum;

	vector<vector<long long int>>input;
	for(long long int testCase = 1; testCase <= testCaseNum; testCase++) {
		long long int N, D;
		cin >> N >> D;
		vector<long long int>input(N);

		long long int ans = D - 1;

		long long int sum = 0;

		map<long long int, long long int>mll;

		for(long long int i = 0; i < N; i++) {
			cin >> input[i];
			sum += input[i];
			mll[input[i]]++;
		}


		if(D == 3) {
			long long int memo = LLONG_MAX;
			for(auto now : mll) {
				if(now.second >= 2) {
					memo = min(memo, now.first);
				}
			}
			if(memo != LLONG_MAX) {
				for(auto now : mll) {
					if(now.first>memo) {
						ans = 1;
						break;
					}
				}
			}
			for(auto x : mll) {
				if(mll.count(x.first * 2) != 0) {
					ans = 1;
					break;
				}
			}
		}

		for(auto x : mll) {
			if(x.second >= D) {
				ans = 0;
				break;
			}
		}

		cout << "Case #" << testCase << ": " << ans << endl;
	}
}
