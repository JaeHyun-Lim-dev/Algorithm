# include <cstdio>

struct ST {
	int heap[100001];
	int rear = 0;
	void push(int x) {
		heap[++rear] = x;
		int C = rear, P = C / 2;
		while (heap[P] > heap[C] && P >= 1) {
			int temp = heap[P];
			heap[P] = heap[C];
			heap[C] = temp;
			C = P;
			P /= 2;
		}
	}
	bool empty() {
		return (!rear);
	}
	int pop() {
		int ans = heap[1];
		heap[1] = heap[rear--];
		int P, L, R;
		P = 1;
		L = P * 2; R = L + 1;
		while (L <= rear) {
			if (R <= rear && heap[L] > heap[R] && heap[P] > heap[R]) {
				int temp = heap[R];
				heap[R] = heap[P];
				heap[P] = temp;
				P = R;
				L = P * 2; R = L + 1;
			}
			else if (heap[P] > heap[L]) {
				int temp = heap[L];
				heap[L] = heap[P];
				heap[P] = temp;
				P = L;
				L = P * 2; R = L + 1;
			}
			else break;
		}
		return ans;
	}
};

int main() {
	int n, x;
	ST q;
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &x);
		if (x > 0) q.push(x);
		else if (q.empty()) printf("0\n");
		else {
			printf("%d\n", q.pop());
		}
	}
	return 0;
}