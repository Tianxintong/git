#include<getopt.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
struct Message
{
	int cmd;
	char tags[0];
};
int main(int argc, char *argv[])
{
		int opt;
		int cmd;
		string machines;
		while ((opt = getopt(argc, argv, "fpum:")) != -1) 
		{
				switch (opt) 
				{
						case 'f':
							cmd |= 1;
								break;
						case 'p':
							cmd  |= (1<<1);
								break;
						case 'u':
							cmd |=(1<<2);
								break;
						case 'm':
						machines = optarg;	
								break;
						default:
						cout<<"erro!"<<endl;
						break;
				}
		}
//				cout<<"cmd = "<<cmd<<endl;
//	cout<<"machines : "<<machines<<endl;
		int bufferlen = sizeof(Message) + machines.length()+1;

		Message * message = (Message*)malloc(bufferlen);
		message[bufferlen] = '\0';
		message->cmd = cmd;
		memcpy(message->tag,machines.c_str(),machines.length());

		cout<<"message "<<message->tags<<endl;
}




