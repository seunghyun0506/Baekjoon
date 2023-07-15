#include <iostream>
#include <cstdlib>

using namespace std;

int arr[128][128];

int* div(int x, int y, int len);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	for(int i = 0 ; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> arr[i][j];
	int* sum = div(0, 0, N);
	cout << sum[0] << '\n' << sum[1];
}

int* div(int x, int y, int len){
	bool isTrue = 0;
	int* sum = (int *) malloc(sizeof (int) * 2);
	sum[0] = 0;
	sum[1] = 0;
		for(int i = y; i < y + len; i++)
			for(int j = x; j < x + len; j++){
				if(arr[i][j] != arr[y][x]){
					isTrue = 1;
					break;
				}
			}
	int* tmp = (int *) malloc(sizeof (int) * 2);
	if(isTrue){
		tmp = div(x + len/2 , y + len/2 , len/2);
		sum[0] += tmp[0];
		sum[1] += tmp[1];
		tmp =  div(x, y, len/2);
		sum[0] += tmp[0];
		sum[1] += tmp[1];
		tmp =  div(x, y+ len/2, len/2);
		sum[0] += tmp[0];
		sum[1] += tmp[1];
		tmp =  div(x+ len/2, y, len/2);
		sum[0] += tmp[0];
		sum[1] += tmp[1];
	}
	else{
		if(arr[y][x] == 1) sum[1]++;
		else sum[0]++;
	}
	return sum;
}
