#include <stdio.h>
#include <string.h>

int main()
{
	char UpperDict[27];
	char LowerDict[27];
	char Message[1000];
	char Decrypt[1000];
	int i;

	gets(LowerDict);
	for(i = 0; i < 26; i++)
	{
		UpperDict[i] = LowerDict[i] - 'a' + 'A';
	}
	UpperDict[26] = 0;

	gets(Message);
	for(i = 0; i < strlen(Message); i++)
	{
		if(Message[i] >= 'a' && Message[i] <= 'z')
		{
			Decrypt[i] = LowerDict[Message[i] - 'a'];
		}
		else if(Message[i] >= 'A' && Message[i] <= 'Z')
		{
			Decrypt[i] = UpperDict[Message[i] - 'A'];
		}
		else
		{
			Decrypt[i] = Message[i];
		}
	}
	Decrypt[i] = 0;
	puts(Decrypt);

	return 0;
}

