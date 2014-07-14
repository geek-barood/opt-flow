#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;
int face[501*6], num[501*6];
int dp[501*6];
int sol[501*6];
string mp[6] = {"front", "back", "left", "right", "top", "bottom"};
void print_sol(int a) {
	if(a == -1) return;
	print_sol(sol[a]);
	printf("%d ", num[a]+1);	
	cout << mp[a%6] << endl;
}
int main() {
	int tc = 1;
	while(true) {
		scanf("%d", &N);
		if(N == 0) break;
		if(tc > 1) printf("\n");
		int x, y;
		int k = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<3; j++) {
				scanf("%d %d", &x, &y);
				face[k] = x;
				face[k+1] = y;
				num[k] = num[k+1] = i;
				k += 2;	
			}
		}
		/*
		for(int i=0; i<k; i++) {
			cout << face[i] << " " << bot[i] << ":" << num[i] << endl;
		}
		*/
		memset(sol, -1, sizeof sol);
		memset(dp, 0, sizeof dp);
		int max_val = -1, max_idx = 0;
		for(int i=0; i<k; i++) {
			int cur = num[i];
			dp[i] = 1;
			for(int j=0; j<i; j++) {
				if((num[j]!=cur) && (face[i] == face[j])) {
					int opp_face = j + ((j%2)?-1:1);
					if(dp[i] < (1+dp[opp_face])) {
						dp[i] = 1+dp[opp_face];
						sol[i] = opp_face;
					}
				}
			}
		}
		for(int i=0; i<k; i++) {
			if(dp[i] > max_val) {
				max_val = dp[i];
				max_idx = i;
			}
		}
		cout << "Case #" << tc << "\n" << max_val << endl;
		//cout << "\n" << max_val << " " << max_idx << " is the ans.\n";
		/*for(int i=0; i<k; i++) {
			cout << i << ":" << sol[i] << " ";
		}
		cout << "\n";*/
		print_sol(max_idx);
		tc++;
	}
	return 0;
}
