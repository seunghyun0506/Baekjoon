#include <iostream>

using namespace std;

bool com[101][101];
bool isTrue[101];
int N;
void bfs(int start);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, a, b;
	cin >> N >> T;
	
	for(int i = 0 ; i < T; i++){
		cin >> a >> b;
		com[a][b] = com[b][a] = 1;
	}
	bfs(1);
}

void bfs(int start){
	int deq[10001];
	int s = 0;
	int sum = 0;
	deq[s++] = start;
	while(s != 0){
		int current = deq[--s];
		isTrue[current] = 1;
		for(int i = 1; i <= N; i++){
			if(com[current][i] == 1 && isTrue[i] == 0)
			{
				sum++;
				deq[s++] = i;
				isTrue[i] = 1;
			}
		}
	}
	
	cout << sum << '\n';
}
