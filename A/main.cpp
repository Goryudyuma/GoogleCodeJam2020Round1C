#include<bits/stdc++.h>
/**/
#include <random>
using namespace std;



int main() {
	long long int testCaseNum = 0;
	cin >> testCaseNum;

	vector<vector<long long int>>input;
	for(long long int testCase = 1; testCase <= testCaseNum; testCase++) {

		long long int X, Y;
		string S;
		cin >> X >> Y >> S;
		long long int ans = -1;
		if(X == 0 && Y == 0) {
			ans = 0;
		} else {

			for(long long int i = 0; i < S.length(); i++) {
				if(S[i] == 'N') {
					Y++;
				} else if(S[i] == 'S') {
					Y--;
				} else if(S[i] == 'E') {
					X++;
				} else {
					X--;
				}
				if(abs(X) + abs(Y) <= i + 1) {
					ans = i + 1;
					break;
				}
			}
		}


		cout << "Case #" << testCase << ": ";
		if(ans == -1) {
			cout << "IMPOSSIBLE";
		} else {
			cout << ans;
		}
		cout << endl;
	}
}
