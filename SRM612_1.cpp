#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n;
int dist[2009][2009];
#define INF 0x77777777
int bfs(void) {
	queue<int> Q;
	Q.push(1); Q.push(0);
	dist[1][0] = 0;
	while(Q.size() > 0) {
		int s = Q.front(); Q.pop();
		int c = Q.front(); Q.pop();
		if(s == n) {
			return dist[s][c];
		}
		//paste
		if((s+c <= 2*n) && dist[s+c][c] >= INF) {
			Q.push(s+c); Q.push(c);
			dist[s+c][c] = dist[s][c] + 1;
		}
		//copy
		if(dist[s][s] >= INF) {
			Q.push(s); Q.push(s);
			dist[s][s] = dist[s][c] + 1;
		}
		//delete
		if((s > 1) && dist[s-1][c] >= INF) {
			Q.push(s-1); Q.push(c);
			dist[s-1][c] = dist[s][c] + 1;
		}
	}
	/*
	int res = INF;
	for(int i=0; i<n; i++) {
		res = min(dist[n][i], res);
	}
	
	return res;
	*/
}
struct EmoticonsDiv1 {
	int printSmiles(int smiles) {
		n = smiles;
		memset(dist, 0x77, sizeof dist);
		int ans = bfs() ;
		return ans;
	}
};

int main() {
	EmoticonsDiv1 obj;
	cout << obj.printSmiles(2) << endl;
	cout << obj.printSmiles(4) << endl;
	cout << obj.printSmiles(6) << endl;
	cout << obj.printSmiles(18) << endl;
	cout << obj.printSmiles(11) << endl;
	return 0;
}
