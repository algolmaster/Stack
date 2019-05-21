#include <iostream>
using namespace std;
int size_;
int solution(int x[], int n) {
	int result = 0;

	if (n != size_ - 1) { //마지막이 아니면 오른쪽 계산
		double slope = (x[n + 1] - x[n])/1.0; //기울기 계산
		
		for (int i = n+1; i < size_; i++) {
			if (i == n+1) //다음은 이미 볼 수 있음.
				++result;
			else {
				if (slope < (double)(x[i] - x[n]) / (i - n)) { //최대 기울기 계산
					++result;
					slope = (double)(x[i] - x[n]) / (i - n);
				}
			}
		}
	}
	if (n != 0) { //처음이 아니면 왼쪽 전부 계산
		double slope = (x[n] - x[n - 1]) / 1.0;
		for (int i = n-1; i >= 0; i--) {
			if (i == n-1) //이전은 이미 볼 수 있음.
				++result;
			else {
				if (slope > (double)(x[n] - x[i]) / (n - i)) {
					++result;
					slope = (double)(x[n] - x[i]) / (n - i);
				}
			}
		}
	}
	return result;
}
int main() {
	cin >> size_;

	int *x = new int[size_];
	for (int i = 0; i < size_; i++)
		cin >> x[i];
	int max = -1;

	for (int i = 0; i < size_; i++) {
		int result = solution(x, i);
		if (max < result)
			max = result;
	}
	cout << max;
}