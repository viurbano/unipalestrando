#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define CADEIRAS 12
#define FILEIRAS 12

#pragma comment(lib, "user32")

struct Cadeira
{
	int numero;
	int fileira;
	int ocupada;

}total[CADEIRAS][FILEIRAS];

int main(int argc, char *argv[])
{
	HWND win = GetConsoleWindow();
	SendMessage(win, WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	//SetWindowPos(win, HWND_TOPMOST, 0, 0, 1920, 1080, SWP_SHOWWINDOW);
	int alfabeto[25], counter = 0;
	for(int c = 65; c < (65 + FILEIRAS); ++c)
	{
		alfabeto[counter] = c;
		counter++;
	}
		
	printf("Bem vindo a UNIPALESTRANDO\n");
	printf("TEMA: Direitos Humanos\r\nPalestra com membro da ONU - Tiago Forthlac\r\n");
	printf("Para escolher seu assento aperte ENTER..\r\n\r\n");
	
	getchar();
	
	system("cls");
	
	struct Cadeira cd_xy;
	char c;
	
	for(int y = 0; y < FILEIRAS; y++)
	{
		for(int x = 0; x < CADEIRAS; x++)
		{
			cd_xy.numero = x;
			cd_xy.fileira = alfabeto[y];
			cd_xy.ocupada = 0;
			total[x][y] = cd_xy;
		}
	}
	
	
	while(1)
	{
		printf("\t\t\t\t\t\t\t\t\+-----------------------------------------------------------------+\n\t\t\t\t\t\t\t\t|------------------------------PALCO------------------------------|\n\t\t\t\t\t\t\t\t+-----------------------------------------------------------------+\n\n");
	
		int count = 0;
		for(int y = 0; y < FILEIRAS; y++)
		{
			for(int x = 0; x < CADEIRAS; x++)
			{
				
				cd_xy.numero = x;
				cd_xy.fileira = alfabeto[y];
				cd_xy.ocupada = 0;
				if(total[x][y].ocupada == 0)
				{
					printf("\t%c%d\t", total[x][y].fileira, total[x][y].numero);
				}
				else
				{
					printf("\tX\t");
				}
			}
			printf("\r\n");
			count++;
		}
	    
	    char assento[2];
	    printf("\r\n\n\n\nASSENTOS DO A0 AO B11 SAO EXCLUSIVOS PARA PROFESSORES E CONVIDADOS DOS PALESTRANTES\r\n");
	    
	    printf("\r\nASSENTOS DO C3 AO C8 SAO EXCLUSIVOS PARA PORTADORES DE NECESSIDADES ESPECIAIS\r\n");
	    
		printf("\r\n\n\nEscolha o seu assento: ");
		scanf("%s", &assento);
		
		char fila = assento[0] - 65;
		int numero = assento[1] - 48;
		
		total[numero][fila].ocupada = 1;
		
		printf("%d", total[numero][fila].ocupada);


		system("cls");

		getchar();
	}
	
	return 0;
}


/*

	[1	2	3	4		5	6	7	8]
	9	10	11	12		13	14	15	16
	
	
*/
