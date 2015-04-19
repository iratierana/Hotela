#include <stdio.h>
#include <time.h>
#include"info.h"
#include "main.h"
#include "menu.h"

int erabilgarritasuna(){
	int i = 0, z = 0, j = 0;
	for (i = 0; i < ERAIKINMAX; i++){
		hotela.eraikinak[i].id = i + 1;
		for (z = 0; z < PIXUMAX; z++){
			for (j = 0; j < GELAMAX; j++){
				hotela.eraikinak[i].gela[j].erabilgarria = 1;
				hotela.eraikinak[i].gela[j].garbia = 1;
				if (j < 3){
					if (hotela.eraikinak[i].gela[j].mota == 1){
						printf("%i. eraikineko %i pixuko %i banakako gela libre dago --> 50€\n", i + 1, z + 1, j + 1);
						hotela.eraikinak[i].gela[j].prezioa = 50;
					}
				}
				else if (j < 5){
					hotela.eraikinak[i].gela[j].mota = 2;
					printf("%i. eraikineko %i pixuko %i binakako gela libre dago\n --> 70€\n", i + 1, z + 1, j + 1);
					hotela.eraikinak[i].gela[j].prezioa = 70;
				}
				else if (j < 7){
					hotela.eraikinak[i].gela[j].mota = 3;
					printf("%i. eraikineko %i pixuko %i hirunakako gela libre dago\n --> 90€\n", i + 1, z + 1, j + 1);
					hotela.eraikinak[i].gela[j].prezioa = 90;

				}
				else if (j < 8){
					hotela.eraikinak[i].gela[j].mota = 4;
					printf("%i. eraikineko %i pixuko %i suite gela libre dago --> 120€\n", i + 1, z + 1, j + 1);
					hotela.eraikinak[i].gela[j].prezioa = 120;
				}
			}
		}
	}
}