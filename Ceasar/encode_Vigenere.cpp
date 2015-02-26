#include	<stdio.h>
#include	<string.h>
#include	"en_ceasar.h"
#include	"en_vigenere.h"
void	enVigenere(char key[])
{
	char letter;
	int	 i=-1;
	int keylen=strlen(key);
	FILE *fi=fopen("PLAIN_TEXT.TXT","rt");
	FILE *fo=fopen("CIPHER_TEXT.TXT","wt");
	letter=fgetc(fi);
	while (!feof(fi))
	{	
		if ((letter>='a') && (letter<='z'))
		{
			i=(i+1)%keylen;
			fputc(convert(letter,key[i]-'a'),fo);
		}
		else 
			fputc(letter,fo);
		letter=fgetc(fi);
	}
	fclose(fi);
	fclose(fo);
}