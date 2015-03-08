#ifndef MAIN_H
#define MAIN_H

#define GELAMAX 8
#define BEZEROMAX 48
#define ERAIKINMAX 2
#define PIXUMAX 2
#define ERRESERBAMAX 16

typedef struct{
	int SarreraEguna;
	int SarreraHila;
	int SarreraUrtea;
	int IrteeraEguna;
	int IrteeraHila;
	int IrteeraUrtea;
}ERRESERBA;

typedef struct{
	int kodea;
	ERRESERBA erreserba[ERRESERBAMAX];
	int erabilgarria;//libre 1 bai - 0 ez
	int garbia;
	int mota;
	int pixua;
	int prezioa;
	int id;
}GELAK;

typedef struct{
	GELAK gela[GELAMAX];
	int id;
}ERAIKINAK;

typedef struct{
	char izena[40];
	char abizena[40];
	char NAN[9];
	char visa[20];
	int kodea;
}BEZEROA;

typedef struct{
	ERAIKINAK eraikinak[ERAIKINMAX];
	BEZEROA bezeroak[BEZEROMAX];
}HOTELA;

HOTELA hotela;

void hasieratu();
#endif 