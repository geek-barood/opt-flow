#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define INF 0x70707070
struct TypoCoderDiv1 {
	int getmax(vector<int> D, int X) {
	   	int dp[D.size()+1][2201];
		for(int i=D.size(); i>=0; i--) {
			for(int j=0; j<=2199; j++) {
				if(i == D.size()) {
					dp[i][j] = 0;
				} else {
					if(j < 2200) {
						if(j + D[i] >= 2200) {
							if(i+1 < D.size()) {
								if(j+D[i]-D[i+1] < 2200) {
									dp[i][j] = 2+ dp[i+2][max(0, j+D[i]-D[i+1])];
								}
							} else {
									dp[i][j] = 1;
							}
						} else {
							dp[i][j] = dp[i+1][j+D[i]];
						}
					}
					dp[i][j] = max(dp[i][j], dp[i+1][max(0, j-D[i])]);
				}
			}
		}		
		return dp[0][X];
	}
};
int main() {
	TypoCoderDiv1 obj;
	int arr[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
	vector<int> d(arr, arr+(sizeof(arr)/sizeof(int)));
	cout << obj.getmax(d, 1328) << endl;
	return 0;
}
