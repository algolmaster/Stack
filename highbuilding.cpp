#include <iostream>
using namespace std;
int size_;
int solution(int x[], int n) {
	int result = 0;

	if (n != size_ - 1) { //�������� �ƴϸ� ������ ���
		double slope = (x[n + 1] - x[n])/1.0; //���� ���
		
		for (int i = n+1; i < size_; i++) {
			if (i == n+1) //������ �̹� �� �� ����.
				++result;
			else {
				if (slope < (double)(x[i] - x[n]) / (i - n)) { //�ִ� ���� ���
					++result;
					slope = (double)(x[i] - x[n]) / (i - n);
				}
			}
		}
	}
	if (n != 0) { //ó���� �ƴϸ� ���� ���� ���
		double slope = (x[n] - x[n - 1]) / 1.0;
		for (int i = n-1; i >= 0; i--) {
			if (i == n-1) //������ �̹� �� �� ����.
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