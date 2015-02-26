#include	<stdio.h>
#include	<string.h>
#include	"de_ceasar.h"
void	deVigenere(char key[])
{
	char letter;
	int	 i=-1;
	int keylen=strlen(key);
	FILE *fo=fopen("PLAIN_TEXT.TXT","wt");
	FILE *fi=fopen("CIPHER_TEXT.TXT","rt");
	letter=fgetc(fi);
	while (!feof(fi))
	{	
		if ((letter>='A') && (letter<='Z'))
		{
			i=(i+1)%keylen;
			fputc(deconvert(letter,key[i]-'a'),fo);
		}
		else
			fputc(letter,fo);
		letter=fgetc(fi);
	}
	fprintf(fo,"\n");
	fclose(fi);
	fclose(fo);
}