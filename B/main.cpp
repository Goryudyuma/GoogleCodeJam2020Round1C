
#include<bits/stdc++.h>
/**/
#include <random>
using namespace std;



int main() {
	long long int testCaseNum = 0;
	cin >> testCaseNum;

	vector<vector<long long int>>input;
	for(long long int testCase = 1; testCase <= testCaseNum; testCase++) {
		long long int U;
		cin >> U;

		vector<pair<long long int, string>> input(10000);
		map<char, long long int>mcl;
		set<char>count0, member;
		for(size_t i = 0; i < 10000; i++) {
			cin >> input[i].first >> input[i].second;
			for(auto c : input[i].second) {
				member.insert(c);
			}
			if(input[i].second.length() == U) {
				mcl[input[i].second[0]]++;
			}
			count0.insert(input[i].second[0]);
		}

		string ans;

		vector<pair<long long int, char>>vplc;
		for(auto x : member) {
			if(count0.count(x) == 0) {
				ans += x;
				break;
			}
		}
		for(auto x : mcl) {
			vplc.push_back(make_pair(x.second, x.first));
		}

		sort(vplc.rbegin(), vplc.rend());

		for(auto x : vplc) {
			if(x.second != ans[0]) {
				ans += x.second;
			}
		}



		cout << "Case #" << testCase << ": " << ans << endl;
	}
}
