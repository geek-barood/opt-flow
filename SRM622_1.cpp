#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 987654321
int G[59][59];
struct BuildingRoutes {
	int build(vector <string> dist, int T) {
		for(int i=0; i<dist.length(); i++) {
			for(int j=0; j<dist[0].length; j++) {
				G[i][j] = (int)(dist[i][j] - '0');
			}
		}
		
		dp[59][59][2];
		int n = dist.length();
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(i!=j) {
					dp[i][j][0] = G[i][j];
				} else {
					dp[i][j][0] = INF;
				}
			}
		}
		for(int k=0; k<n; k++) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(dp[i][j][0] > (dp[i][k][0]+dp[k][j][0])) {
						dp[i][j][0] = dp[i][k][0]+dp[k][j][0];
						dp[i][j][1] = 1;
					}
					else if(dp[i][j][0] == (dp[i][k][0] + dp[k][j][0])) {
						dp[i][j][1]++;
					}
				}
			}
		}
		
		int sum = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(i!=j) {
					if(dp[i][j][1] >= T) {
						sum += dp[i][j][0];
					}
				}
			}
		}
		return sum;
	}
};