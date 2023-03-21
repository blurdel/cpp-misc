#include <iostream>
#include <algorithm>
using namespace std;


/*
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
Given A = [1, 2, 3], the function should return 4.
Given A = [−1, −3], the function should return 1.
 */
int solution(int A[], int N) {
	int min = 1;

	sort(A, A+N);

	for (int i = 0; i < N; i++) {
		if (min == A[i]) {
			min++;
		}
	}
	return min;
}

int main(int argc, char* argv[])
{
	int arr[] = {1, 3, 6, 4, 1, 2};
//	int arr[] = {1, 3, 2};
//	int arr[] = {-1, -3};

	int arrlen = sizeof(arr)/sizeof(arr[0]);

	int ans = solution(arr, arrlen);
	cout << ans << endl;

	return 0;
}
