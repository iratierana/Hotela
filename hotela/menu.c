#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "main.h"
#include "menu.h"
#include "info.h"

int menuprintzipala(){
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	char output[128];

	printf("***** IRATI HOTELA *****\n\n");
	strftime(output, 128, "%Y/%m/%d %H:%M:%S", tlocal);
	printf("%s\n", output);
	printf("Eskoritza\n");
	printf("Aranburuzabala 32\n");
	printf("Logelak 50€ tik aurrera\n");
	printf("    Banakakoak --> 50€\n");
	printf("    Birentzat --> 70€\n");
	printf("    Hiruntzat --> 90€\n");
	printf("    Suite --> 120€\n");
}

void menupertsona(){
	int aukera = -1;

	while (aukera != 0){
		printf("*********************************\n");
		printf("1-. Bezeroa\n");
		printf("2-. Langilea\n");
		printf("0-. Irten\n");
		printf("*********************************\n");

		scanf("%i", &aukera);
		system("cls");
		switch (aukera){
		case 1:
			menubezeroa();
			break;
		case 2:
			menulangilea();
			break;
		case 0:
			break;
		default:
			printf("Aukera ezegokia");
			system("cls");
			break;
		}
	}

}

int menubezeroa(){
	int aukera = 0;

	printf("*********************************\n");
	printf("1-. Gelen erabilgarritasuna\n");
	printf("2-. Gela erreserba\n");
	printf("3-. Hotelak dituen gela desberdinen informazioa\n");
	printf("4-. Erreserba kendu\n");
	printf("0-. Irten\n");
	printf("*********************************\n");

	scanf("%i", &aukera);
	system("cls");

	switch (aukera){
		case 1:
			erabilgarritasuna();
			break;
		case 2:
			menuerreserba();
			break;
		case 3:
			informazioa();
			break;
		case 4:
			desErreserba();
			break;
		case 0:
			break;
		default:
			printf("Aukera ezegokia\n");
			break;
		}

}

void informazioa(){
	
	printf("******IRATI HOTELEKO GELAK*******\n");
	printf("Logelak 50€ tik aurrera\n");
	printf("    Banakakoak --> 50€\n");
	printf("    Birentzat --> 70€\n");
	printf("    Hiruntzat --> 90€\n");
	printf("    Suite --> 120€\n");
	printf("*********************************");
}

void menuerreserba(){
	int eraikina , pisua = 0, mota = 0, gela = -1, erreserba = 10, kont = 0, bai = 0;

	printf("**********************************************************\n");
	printf("Bi eraikin ditugu hotel honetan, aukeratu bat(1) edo bi(2)\n->");
	scanf("%i", &eraikina);
	printf("\nZe motatako gela nahi duzu? 1mota(banakakoa)= 1.pisua / 2mota(binakakoak)= 1-2.pisua / 3mota(hirukoak)= 2.pisua / 4mota(suitak)= 2.pisua\n->");//ondo jarrrrriiiiiiiiiiiiiiiiiii
	scanf("%i", &mota);

	eraikina = eraikina - 1;

	for (int i = 0; i < GELAMAX; i++)
		if (hotela.eraikinak[eraikina].gela[i].mota == mota &&
			hotela.eraikinak[eraikina].gela[i].erabilgarria == 1){
			gela = i;
			break;
		}
		if (gela != -1){
		printf("Sartu lehenengo eguneko data:\nEguna\n->");
		scanf("%i", &hotela.eraikinak[eraikina].gela[gela].erreserba[kont].SarreraEguna);
		printf("Hilabetea\n->");
		scanf("%i", &hotela.eraikinak[eraikina].gela[gela].erreserba[kont].SarreraHila);
		printf("Urtea\n->");
		scanf("%i", &hotela.eraikinak[eraikina].gela[gela].erreserba[kont].SarreraUrtea);

		printf("Sartu azken eguneko data: \nEguna\n->");
		scanf("%i", &hotela.eraikinak[eraikina].gela[gela].erreserba[kont].IrteeraEguna);
		printf("Hilabetea\n->");
		scanf("%i", &hotela.eraikinak[eraikina].gela[gela].erreserba[kont].IrteeraHila);
		printf("Urtea\n->");
		scanf("%i", &hotela.eraikinak[eraikina].gela[gela].erreserba[kont].IrteeraUrtea);

		
		hotela.eraikinak[eraikina].gela[gela].erabilgarria = 0;
		printf("\nAukeratutako gelaren prezioa %i da\n", hotela.eraikinak[eraikina].gela[gela].prezioa);
		printf("Erreserbarekin aurrera egin nahi duzu? BAI(1) EZ(0)\n");
		scanf("%i", &erreserba);

		if (erreserba == 1){
			fflush(stdin);//borra el fitxero donde se guarda lo escrito
			printf("Sartu zure izena:\n->");
			fgets(&hotela.bezeroak[kont].izena,40,stdin);
			printf("Sartu zure abizena:\n->");
			fflush(stdin);
			fgets(&hotela.bezeroak[kont].abizena,40,stdin);
			printf("Sartu zure NAN-a zenbaki eta guzti:\n->");
			fflush(stdin);
			fgets(&hotela.bezeroak[kont].NAN,9,stdin);
			printf("Sartu visa zenbakia:\n->");
			fflush(stdin);
			fgets(&hotela.bezeroak[kont].visa,20,stdin);
			printf("Erreserbarekin aurrera egin nahi duzu? BAI(1) EZ(0)\n");
			fflush(stdin);
			scanf("%i", &bai);

			if (bai == 1){
				printf("***** IRATI HOTELA *****\n\n");
				printf("Aranburuzabala 32\n");
				printf("Izena: %s", hotela.bezeroak[kont].izena);
				printf("Abizena: %s", hotela.bezeroak[kont].abizena);
				printf("NAN-a: %s", hotela.bezeroak[kont].NAN);
				printf("Erreserba kentzeko kodea %5i\n", hotela.bezeroak[kont].kodea = rand() % 99999);

				hotela.eraikinak[eraikina].gela[gela].kodea = hotela.bezeroak[kont].kodea;
			}
		}
	}
		kont++;
}

void desErreserba(){
	int kodea = 0, i = 0, bai = 0, j = 0, z = 0;

	printf("*********************************\n");
	printf("Sartu zure erreserba kodea: \n-->");
	fflush(stdin);
	scanf("%i", &kodea);

	for (i = 0; i < 48; i++){
		if (kodea == hotela.bezeroak[i].kodea){
			printf("Zure izena: %s ", hotela.bezeroak[i].izena);
			printf("Abizena: %s", hotela.bezeroak[i].abizena);
			printf("BAI(0) EZ(1)");
			scanf("%i", &bai);

			if (bai == 1){
				for (z = 0; z < ERAIKINMAX; z++){
					for (j = 0; j < GELAMAX; j++){
						if (hotela.eraikinak[i].gela[j].kodea == kodea){
							hotela.eraikinak[i].gela[j].erabilgarria = 1;
						}
					}
				}
			}
		}
	}
}

void menulangilea(){
	int aukera = 0;

	printf("\n*********************************\n");
	printf("1-. Harrera\n");
	printf("2-. Garbiketa\n");
	printf("0-. Irten\n");
	printf("*********************************\n");
	scanf("%i", &aukera);
	system("cls");

	switch (aukera){
		case 1:
			menuHarrera();
			break;
		case 2:
			menuGarbitzaile();
			break;
		case 0:
			break;
		default:
			printf("Aukera ezegokia\n");
			break;
		}
}

void menuHarrera(){
	int aukera = 0;

	printf("*********************************\n");
	printf("1-. Gela erreserba\n");
	printf("2-. Erreserba kendu\n");
	printf("3-. Libratzen diren gelen zerrenda \n");
	printf("4-. Sartzen diren bezero berrien zerrenda\n");
	printf("0-. Irten\n");
	printf("*********************************\n");
	scanf("%i", &aukera);
	system("cls");

	switch (aukera){
		case 1:
			menuerreserba();
			break;
		case 2:
			desErreserba();
			break;
		case 3:
			gelakLibre();
			break;
		case 4:
			bezeroZerrenda();
			break;
		case 0:
			break;
		default:
			printf("Aukera ezegokia\n");
			break;
		}
	}

void menuGarbitzaile(){

}

void gelakLibre(){
	int i = 0, j = 0;

	for (i = 0; i < ERAIKINMAX; i++){
		for (j = 0; j < GELAMAX; j++){
			if (j > 0 || i > 0){
				if (hotela.eraikinak[i].gela[j].erabilgarria == 1 && j < 4){
					printf("%i eraikineko %i pixuko %i gela libre\n", i + 1, hotela.eraikinak[i].gela[j].pixua + 1, j + 1);
				}
				else{
					printf("%i eraikineko %i pixuko %i gela libre\n", i + 1, hotela.eraikinak[i].gela[j].pixua + 1, j - 3);
				}
			}
			else{
			}
		}
	}
}

void bezeroZerrenda(){
	int i = 0, j = 0, kodea = 0, z = 0;

	for (i = 0; i < ERAIKINMAX; i++){
		for (j = 0; j < GELAMAX; j++){
			if (hotela.eraikinak[i].gela[j].erabilgarria == 0){
				kodea = hotela.eraikinak[i].gela[j].kodea;
				for (z = 0; z < BEZEROMAX; z++){
					if (hotela.bezeroak[z].kodea == kodea){//ona ez da sartzen
						printf("Izena: %s\n", hotela.bezeroak[z].izena);
						printf("Abizena: %s\n", hotela.bezeroak[z].abizena);
					}
				}
			}
		}
	}
}