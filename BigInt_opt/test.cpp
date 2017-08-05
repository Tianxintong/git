#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<deque>
#include<string.h>
using namespace std;
#include"./bigint.h"
int main()
{
	char s5[] = "+9348489345848734774743787843883487433477834787837878378578478578437857847857843785478357847857437547357847357484787854785747857437574357475177847817787878437474743784384783785348483778437857387848737847834787387894378875378748784787834787878734878783478737874374378578347857347854375734857834785387278729087890978171111111111111095594959748574040545458485847574875745747834789301018884387547858478748758487578475784785784785845874838574387587438757831001417884858748787577437878487328748238748238948923898482387487237847832784873248787324873287478327847832784783728478327847832784783247832784783278478327843287847832784873247878324787832784873287487328734874873277893278327878327878233782178321778347348616438884382843784737247832787844444873438473847374737477347324732477933333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333848384783278487327487328478327847832784873278873248583248783274837847832784783278478327487382478327847832784783247832784783278478328748732847187327842784781327847813278417832748732847832784783287478783333333333333333333333333333333333333333333333333333333333333333333333388888888888888888888844444444444444444444444444444444444444449999999999999999999999999999999999933333333333333333333333333333374747732493294329473747444444444444444444444444444444444444444444444444444448888888888888888888888888888888888888888888888385";
	char s6[] = "+1111134787547489497457447887438748738347848787434875784387587347857843858734875438757834875873485348583487578438587435783454785478578347864764788787987948747837873878783478873387782872783877288738727827878111111111111111111111111111111111111111111158888888888888888888888888888888888888888888888886845783478534785783478573847853874783874882384287834824838528438723487574578437847878378787834787878437847843784783478478478748378784378787827878234018934834586685774578347848683485848158348153844854815864851843886864366669487555555555555555555555555555555555555555555599999999999999999999999932444444444444444384994393494334793784378743878783478874783187783783478783873478437874878437857834875784378543757834857843758483757835784378573478578437878787804394874537857845375377778348778443788743783478873987478934784787847878347843783478784347837847843743787847847847843478784784785474878843787840349095345743577567940895779439039099";
	char s1[] = "-123456789";
	char s2[] ="-987";
	char s3[]="123";
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	size_t len3 = strlen(s3);
	BigInt big1((u_char*)s1,len1);
	BigInt big2((u_char*)s2,len2);
	BigInt big3((u_char*)s3,len3);
	cout<<"bt1 = ";
	big1.show();
	cout<<"bt2 = ";
	big2.show();
	cout<<"bt3=";
	big3.show();
//	BigInt::Sub(big3,big1,big2);
//	cout<<(big1<big2)<<endl;
//	cout<<(big1>big2)<<endl;
//	BigInt::Mul(big3,big1,big2);
//	cout<<"bt3 = bt1/bt2=";
	BigInt::Div(big3,big1,big2);
//	BigInt::Mod(big3,big1,big2);
//	cout<<"bt3 = bt1 % bt2 = ";
//	BigInt::Squate(big3,big1);
//	BigInt::Power(big3,big1,4);
//	++big1;
// 	big1.Power(big3,big1,big2);
//	BigInt big4(0);
//	BigInt::PowMod(big4,big1,big2,big3);
//	big4.show();
	big3.show();
}
