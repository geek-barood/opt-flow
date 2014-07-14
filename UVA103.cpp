#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(pair<vector<int>, int> a, pair<vector<int>, int> b) {
	int n = a.first.size();
	int i=0;
	for(i=0; (i < n) && (a.first[i] < b.first[i]); i++) {
		;
	}
	if(i == n) return true;
	return false;
}

bool cmp1(pair<vector<int>, int> a, pair<vector<int>, int> b) {
	int n = a.first.size();
	int i=0;
	for(i=0; (i<n) && (a.first[i] == b.first[i]); i++) {
		;
	}
	if((i==n) || (a.first[i] < b.first[i])) return true;
	return false;
}
int LIS[80];
int sol[80];
int main() {
	int k, x, n;
	while(cin >> k) {
		cin >> n;	
		for(int i=0; i<k; i++) sol[i] = -1;
		pair<vector<int>, int> var[k];
		for(int i=0; i<k; i++) {
			var[i].second = i;
			for(int j=0; j<n; j++) {
				scanf("%d", &x);
				var[i].first.push_back(x);
			}	
			sort(var[i].first.begin(), var[i].first.end());
		} 
		sort(var, var+k, cmp1);
		/*	
		cout << "After sorting\n";
		for(int i=0; i<k; i++) {
			for(int j=0; j<n; j++) {
				cout << var[i].first[j] << " ";
			}
			cout << ": " << var[i].second;
			cout << endl;
		}
		cout << endl;
		*/	
		for(int i=0; i<k; i++) LIS[i] = 0;
		int max_idx = 0, max_val = 1;
		for(int i=0; i<k; i++) {
			LIS[i] = 1;
			for(int j=0; j<i; j++) {
				if(cmp(var[j], var[i]) == true) {
					if(1+LIS[j] >= LIS[i]) {
						sol[var[i].second] = var[j].second;
						LIS[i] = 1+LIS[j];
						if(LIS[i] > max_val) {
							max_val = LIS[i];
							max_idx = var[i].second;
						}
					}
				}
			}
		}
		cout << max_val << "\n";
		int idx = max_idx;	
		/*for(int i=0; i<k; i++) {
			cout << sol[i]+1 << " ";
		}
		cout << endl;
		*/
		int res[max_val];
		int i = 1;
		while(idx != -1) {
			res[max_val - i] = idx+1;
			idx = sol[idx];
			i++;
		}
		for(i = 0; i<max_val; i++) {
			printf("%d ", res[i]);
		}
		cout << endl;

	}
	return 0;
}
