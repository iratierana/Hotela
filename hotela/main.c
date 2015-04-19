#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include"main.h"
#include "menu.h"

int main(){
	FILE *fitxategia = NULL;
	int aukera = 0;
	srand(time(0));

	if ((fitxategia = fopen("hotela.txt", "r")) != NULL){
		fread(&hotela, sizeof(HOTELA), 1, fitxategia);
		fclose(fitxategia);
	}
	else{
		hasieratu(hotela);
	}
	
	menuprintzipala();
	menupertsona();

	if ((fitxategia = fopen("hotela.txt", "w")) != NULL){
		fwrite(&hotela, sizeof(HOTELA), 1, fitxategia);
		fclose(fitxategia);
	}
	
	fflush(stdin);
	getchar();
	return 0;
}

void hasieratu(){
	int i = 0, j = 0, z = 0, sobra=4;//sobra zetako??? ta z????

	for (i = 0; i < BEZEROMAX; i++){
		strcpy(hotela.bezeroak[i].izena,"Izena");
		strcpy(hotela.bezeroak[i].abizena, "Abizena");
		strcpy(hotela.bezeroak[i].NAN, "NAN");
		strcpy(hotela.bezeroak[i].visa, "visa");
		hotela.bezeroak[i].kodea = -1;
	}
	for (i = 0; i < ERAIKINMAX; i++){
		hotela.eraikinak[i].id = i + 1;

			for (j = 0; j < GELAMAX; j++){
				hotela.eraikinak[i].gela[j].erabilgarria = 1;
				hotela.eraikinak[i].gela[j].garbia = 1;
				if (j < 3){
					hotela.eraikinak[i].gela[j].mota = 1;
					hotela.eraikinak[i].gela[j].prezioa = 50;
				}
				else if (j < 5){
					hotela.eraikinak[i].gela[j].mota = 2;
					hotela.eraikinak[i].gela[j].prezioa = 70;
				}
				else if (j < 7){
					hotela.eraikinak[i].gela[j].mota = 3;
					hotela.eraikinak[i].gela[j].prezioa = 90;

				}
				else if (j < 8){
					hotela.eraikinak[i].gela[j].mota = 4;
					hotela.eraikinak[i].gela[j].prezioa = 120;
				}

				hotela.eraikinak[i].gela[j].id = (i * 1000) + (z * 100) + j;

				if (j < 4){
					hotela.eraikinak[i].gela[j].pixua = 0;
				}
				else{
					hotela.eraikinak[i].gela[j].pixua = 1;
				}
			}
	}

}
