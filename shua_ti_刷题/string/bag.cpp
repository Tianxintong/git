/*

众所周知计算机代码底层计算都是0和1的计算，牛牛知道这点之后就想使用0和1创造一个新世界！牛牛现在手里有n个0和m个1，给出牛牛可以创造的x种物品，每种物品都由一个01串表示。牛牛想知道当前手中的0和1可以最多创造出多少种物品。

*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
		char s[51];
		int X, N, M, n[21] = { 0 }, m[21] = { 0 }, dp[501][501] = { 0 };  
		cin >> X >> N >> M;
		for (int i = 1; i <= X; i++){
				cin >> s;
				for (int j = 0; j < strlen(s); j++){
						if (s[j] == '0')
								n[i]++;
						else
								m[i]++;
				}
		}
		for (int i = 1; i <= X; i++)
				for (int j = N; j >= n[i]; j--)
						for (int k = M; k >= m[i]; k--)
								dp[j][k] = max(dp[j][k], dp[j - n[i]][k - m[i]] + 1);
		//二维背包，使用动态规划求dp数组
		cout << dp[N][M];
		return 0;
}
