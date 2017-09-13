/*
在编号为a,b,c,d,e 的五件物品，他们的重量分别是2,2,6,5,4.价值分别是6,3,5,4,6，给你个承重是10的背包，如何让装入背包的物品具有最大价值．
*//*
 * 基本的0-1背包问题：
 * 已知有N类物品，每类物品都只有一件，对应的重量为w[i],价值为v[i]。
 * 背包最多承重为W，在不超出承重范围的前提下，求能拿的物件的最大价值为多少
 *
 *这是DP的一个经典实例，可以用动态规划求解
 *设dp(i,j)表示对于前i件物品，背包剩余容量为j时，能取得的最大价值
 *状态转移方程：dp(i,j) = Max(dp(i-1,j), dp(i-1,j-w[i])+v[i])
 *注：   dp(i-1,j)          -----》                dp(i,j)，即不拿第i件物品
 *   dp(i-1,j-w[i])     -----》                dp(i,j)，即拿第i件物品

 * 当物品数量很多，背包的容量很大时,这时要用二维数组往往是不现实的
 * 我们可以进行空间压缩，使用一维数组实现
 * 状态转移方程：
 * dp(j)=Max(dp(j),dp(j-w[i])+v[i])
 * 注：对于背包的容量要采用倒序的方式！
 */


#include<stdio.h>
#include<iostream>  
using namespace std;    

#define N 5 // N件宝贝  
#define V 10 // C是背包的总capacity  

int main()    
{    
		int value[N + 1]  = {0, 6, 3, 5, 4, 6}; // 钱啊  
		int weight[N + 1] = {0, 2, 2, 6, 5, 4}; // 重量  
		int f[N + 1][V + 1] = {0}; // f[i][j]表示在背包容量为j的情况下， 前i件宝贝的最大价值  

		int i = 1;  
		int j = 1;  
		for(i = 1; i <= N; i++)  
		{  
				for(j = 1; j <= V; j++)  
				{  
						// 递推关系式出炉  
						if(j < weight[i])  
						{  
								f[i][j] = f[i - 1][j];  
						}  
						else  
						{ 
						//决策：在背包承重是j的情况下，有第i件物品和没有第i件物品哪个总的价值大．
								int x = f[i - 1][j];  
								int y = f[i - 1][j - weight[i]] + value[i];  
								f[i][j] = x < y ? y : x;  
						}  
				}  
		}  

		for(i = N; i >= 1; i--)  
		{  
				for(j = 1; j <= V; j++)  
				{  
						printf("%4d ", f[i][j]);  
				}  

				cout << endl;  
		}  

		return 0;    
}    
