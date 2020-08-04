// https://www.acmicpc.net/problem/2805
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, temp, front = 0, rear = 0, mid;
	int ans = 0;
	int mh = 0;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> tree;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		tree.push_back(temp);
		if (temp > rear) rear = temp;
	}

	mid = rear / 2;
	while (front <= rear) {
		long long int tsum = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] <= mid) continue;
			tsum += (tree[i] - mid);
		}
		
		if (tsum < M) {
			rear = mid - 1;
			mid = (front + rear) / 2;
		}
		else {
			ans = mid;
			front = mid + 1;
			mid = (front + rear) / 2;
		}
	}
	cout << ans << "\n";
	return 0;
}