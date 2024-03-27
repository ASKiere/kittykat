#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KITTYKAT_DEFAULT() system("echo '  ／l、\n (ﾟ､ ｡ ７\n  l、ﾞ ~ヽ\n  じしf_, )ノ\n' | lolcat");
#define KITTYKAT_COLORLESS() system("echo '  ／l、\n (ﾟ､ ｡ ７\n  l、ﾞ ~ヽ\n  じしf_, )ノ\n'");
#define KITTYKAT_WARNING_LOLCAT() system("echo '  ／l、\n (ﾟ､ ｡ ７\n  l、ﾞ ~ヽ\n  じしf_, )ノ\nUh-oh! Your kitty can`t have colors without lolcat installed! You may disable this warning in your kittykat.ini file!'");
#define KITTYKAT_WARNING_CONFIG() printf("MISSING OR RENAMED INI CONFIG FILE. PLEASE CHECK THE KITTYKAT PATH FOR 'kittykat.ini', OR REINSTALL KITTYKAT."); 

/*  ／l、\n (ﾟ､ ｡ ７\n  l、ﾞ ~ヽ\n  じしf_, )ノ\n*/

void iniRead()
{
	FILE* ini = fopen("kittykat.ini","r");

	if(ini == NULL)
	{
		KITTYKAT_WARNING_CONFIG();
	}

	char line[100];
	char* config1 = "colorful-kittykat=0";
	
	while(fgets(line, sizeof(line), ini) != NULL)
	{
		if(strstr(line,config1) != NULL)
		{
			KITTYKAT_COLORLESS();
			fclose(ini);
			
			return;
		}
	}
	
	fclose(ini);
	KITTYKAT_DEFAULT();
}

int main()
{
	FILE* lolcat = fopen("/usr/bin/lolcat", "rb");
	if(lolcat == NULL)
	{
		KITTYKAT_WARNING_LOLCAT();
	}
	
	else
	{
		fclose(lolcat);
		iniRead();
	}

	return 0;
}
