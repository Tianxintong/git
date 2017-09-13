
//也不晓得跟我一样，在做这道题目之前完全没有接触过0-1背包问题的人有多少。
//为了理解这一道题，不得不说煞费苦心的百科查了不少的文章，算是明白了0-1背包问题的一点点皮毛了吧。
//接下来是我自己搜集的有关入门的一些小结。ps：当然基本上是别人总结过的，我只是把自己理解过了的搬运了过来而已
/*
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

/*
 * 二维背包问题：
 * 对于每件物品,当选择这件物品必须同时付出两种代价；
 * 对于每种代价都有一个可付出的最大值（背包容量）。
 * 问怎样选择物品可以得到最大的价值。
 * 设第i件物品所需的两种代价分别为a[i]和b[i]。两种代价可付出的最大值（两种背包容量）分别为u和v。物品的价值为w[i]。
 * 状态转移方程：dp[i][u][v] = max(dp[i-1][u][v] , w[i] + dp[i-1][u-a[i]][v-b[i]])
 *
 * 同样的进行空间压缩，我们可以得到二维数组的状态转移方程，如下：
 * dp[u][v] = max(dp[u-a[i]][v-b[i]]+w[i],dp[u][v])
 * 注：u、v在此均采用倒序！
 *
 * 例题说明：
 * 众所周知计算机代码底层计算都是0和1的计算，牛牛知道这点之后就想使用0和1创造一个新世界！
 * 牛牛现在手里有n个0和m个1，给出牛牛可以创造的x种物品，每种物品都由一个01串表示。
 * 牛牛想知道当前手中的0和1可以最多创造出多少种物品。
 * 等价对应：
 * n                ---------           背包容量，u
 * m                ---------           背包容量，v
 * x                ---------           物品个数
 * item[i].0的个数 ---------           物品i对应u部分的容量
 * item[i].1的个数 ---------           物品i对应v部分的容量
 * 最多创造的物品种数    ---------           可得到的最大价值（此时物品的价值w[i]=1）
 */

//另外常见的还有完全背包问题以及多重背包问题，就不啰嗦了，花点时间，至少在理解上，问题应该不是很大
//感觉难的还是怎么把一个题目抽象到对应背包问题的模型上来，以及相关代码实现的优化。
import java.util.*;
public class dim_2_bag {
		public static void main(String[] args) {
				Scanner sc = new Scanner(System.in);
				while(sc.hasNext()) {
						int x = sc.nextInt();
						int n = sc.nextInt();
						int m = sc.nextInt();
						int[] zero = new int[x];
						int[] one = new int[x];
						String item;
						for(int i=0;i<x;i++) {
								item = sc.next();
								int cnt = 0;
								for(int j=0;j<item.length();j++) {
										if(item.charAt(j) == '0') {
												cnt++;
										}
								}
								zero[i] = cnt;
								one[i] = item.length()-cnt;
						}
						int[][] dp = new int[n+1][m+1];
						for(int i=0;i<x;i++) {
								for(int j=n;j>=zero[i];j--) {
										for(int k=m;k>=one[i];k--) {
												if(dp[j][k] < dp[j-zero[i]][k-one[i]]+1) {
														dp[j][k] = dp[j-zero[i]][k-one[i]]+1;
												}
										}
								}
						}
						System.out.println(dp[n][m]);
				}
		}
}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(const string &a,const string &b)
{
		return a.length() < b.length();
}
int main()
{
		int x,n,m;
		cin>>x>>n>>m;
		vector<string> vec;
		for(int i = 0;i<x;++i)
		{
				string tmp;
				cin>>tmp;
				vec.push_back(tmp);
		}

		sort(vec.begin(),vec.end(),comp);
		int size = vec.size();
		int  finished_thing_num = 0;
		for(int i = 0;i<size;++i)
		{
				int len = vec[i].length();
				int j;
				for(j = 0;j<len ;++j)
				{
						if(vec[i][j] == '0')
						{
								if(n)
										--n;
								else
										break;
						}
						else
						{
								if(m)
								{
										--m;
								}
								else
										break;
						}
				}
				if(j == len)
						++finished_thing_num;
				if(n == 0 && m == 0)
						break;
		}
		cout<<finished_thing_num<<endl;
		return 0;
}
/*
   int main()
   {
   int n,m,k;
   cin>>n>>m>>k;
   int count = 0;
   if(n == m)
   count = 26;
   else
   {
   if(n - m >m)
   count = n - m;
   else
   count = m;

   for(int i =0;i<(m+1)/2;++i)
   count = count*26;
   }
   cout<<count<<endl;
   return 0;
   }
 */
