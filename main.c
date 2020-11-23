#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>

#define RETURNTIME 15

char categorii[][20]={"Patiserie sarata","Patiserie dulce","Produse de post","Produse de sezon"};
void returnfunc(void);
void mainmenu(void);
void adaugaProdus(void);
void stergeProdus(void);
void cautaProdus(void);
void vizualizareProduse(void);
void modificaProdus(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
void Password();
void loaderanim();

FILE *fp,*ft,*fs;


COORD coord = {0, 0};
int s;
char gasesteprodus;
char password[10]={"codewithc"};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
int mm,dd,yy;
};
struct produs
{
int cod;
char nume[20];
char compozitie[30];
int cantitate;
float pret;
int count;
char *cat;
struct meroDate issued;
struct meroDate duedate;
};
struct produs a;
int main()
{
Password();
getch();
return 0;

}
void mainmenu()
{

system("cls");

int i;
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENIUL PRINCIPAL \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xB2 1. Adauga un produs");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 2. Sterge un produs");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 3. Cautare produs ");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 4. Vizualizare lista produse");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 5. Modifica informatiile despre un produs");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 6. Paraseste aplicatia");
gotoxy(20,17);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,19);
t();
gotoxy(20,22);
printf("Alege o optiune din lista de mai sus:");
switch(getch())
{
case '1':
adaugaProdus();
break;
case '2':
stergeProdus();
break;
case '3':
cautaProdus();
break;
case '4':
vizualizareProduse();
break;
case '5':
modificaProdus();
break;
case '6':
{
system("cls");
gotoxy(16,3);
printf("\t Sistem de management al unei patiserii ");
gotoxy(16,4);
printf("\t Iesire din sistem");
gotoxy(16,5);
printf(" Iesire in 3 secunde...........>");
Sleep(3000);
gotoxy(16,7);
exit(0);
}


default:
{
gotoxy(11,23);
printf("\a Ai introdus o valoare gresita! Reintrodu o alta valoare: ");
if(getch())
mainmenu();
}

}
}
void adaugaProdus(void)
{
system("cls");
int i;
gotoxy(20,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Selecteaza categoria \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 1. Patiserie sarata");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 2. Patiserie dulce");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 3. Produse de post");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 4. Produse de sezon");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 5. Inapoi la meniul principal");
gotoxy(20,17);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,19);
printf("Alege o optiune:");
scanf("%d",&s);
if(s==5)

mainmenu() ;
system("cls");
fp=fopen("Bibek.dat","ab+");
if(getdata()==1)
{
a.cat=categorii[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
gotoxy(21,14);
printf("Inregistrarea produsului a fost facuta cu succes !");
gotoxy(21,15);
printf("Adaugi alt produs?(D / N ):");
if(getch()=='n')
mainmenu();
else
system("cls");
adaugaProdus();
}
}


void stergeProdus()
{
system("cls");
int d;
char another='d';
while(another=='d')
{
system("cls");
gotoxy(10,5);
printf("Insereaza codul produsului pe care doresti sa il stergi:");
scanf("%d",&d);
fp=fopen("Bibek.dat","rb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.cod==d)
{

gotoxy(10,7);
printf("Produsul este disponibil");
gotoxy(10,8);
printf("Denumirea produsului este : %s",a.nume);
gotoxy(10,9);
gasesteprodus='t';
}
}
if(gasesteprodus!='t')
{
gotoxy(10,10);
printf("Nu s-a gasit nici un produs cu acest cod");
if(getch())
mainmenu();
}
if(gasesteprodus=='t' )
{
gotoxy(10,9);
printf("Doresti sa stergi acest produs din lista?(D / N):");
if(getch()=='d')
{
ft=fopen("test.dat","wb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.cod!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft);
}
}
fclose(ft);
fclose(fp);
remove("Bibek.dat");
rename("test.dat","Bibek.dat");
fp=fopen("Bibek.dat","rb+");
if(gasesteprodus=='t')
{
gotoxy(10,11);
printf("Produsul a fost sters cu succes din lista !");
gotoxy(10,13);
printf("Doresti sa stergi si alt produs?(D / N)");
}
}
else
mainmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
mainmenu();
}



void cautaProdus()
{
system("cls");
int d;
printf("***************************** Cauta un produs *********************************");
gotoxy(20,10);
printf("\xDB\xDB\xDB\xB2 1. Cauta dupa codul produsului");
gotoxy(20,14);
printf("\xDB\xDB\xDB\xB2 2. Cauta dupa denumire");
gotoxy( 15,20);
printf("Alege o optiune: ");
fp=fopen("Bibek.dat","rb+");
rewind(fp);
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("**** Cauta dupa codul produsului ****");
gotoxy(20,5);
printf("Introducere cod produs:");
scanf("%d",&d);
gotoxy(20,7);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.cod==d)
{
Sleep(2);
gotoxy(20,7);
printf("Produsul este disponibil !");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 Cod: %d",a.cod);gotoxy(51,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Denumire: %s",a.nume);gotoxy(51,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Compozitie: %s ",a.compozitie);gotoxy(51,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Cantitate: %d ",a.cantitate);gotoxy(51,12);printf("\xB2"); gotoxy(51,11);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Pret: %.2f",a.pret);gotoxy(51,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gasesteprodus='t';
}

}
if(gasesteprodus!='t')
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\a Nu s-a gasit nici o inregistrare");
}
gotoxy(20,17);
printf("Incerci alta cautare?(D / N)");
if(getch()=='d')
cautaProdus();
else
mainmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("**** Cauta produs dupa denumire ****");
gotoxy(20,5);
printf("Introducere denumire produs:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.nume,(s))==0)
{
gotoxy(20,7);
printf("Produsul este disponibil !");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 Cod: %d",a.cod);gotoxy(51,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Denumire: %s",a.nume);gotoxy(51,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Compozitie: %s ",a.compozitie);gotoxy(51,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Cantitate: %d ",a.cantitate);gotoxy(51,12);printf("\xB2"); gotoxy(51,11);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Pret: %.2f",a.pret);gotoxy(51,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
d++;
}

}
if(d==0)
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\a Nu s-a gasit nici o inregistrare");
}
gotoxy(20,17);
printf("Incerci alta cautare?(D /N)");
if(getch()=='d')
cautaProdus();
else
mainmenu();
break;
}
default :
getch();
cautaProdus();
}
fclose(fp);
}


void vizualizareProduse()
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("********************************* Lista produselor *****************************");
gotoxy(2,3);
printf(" CATEGORIE          COD       DENUMIRE           COMPOZITIE             CANTITATE       PRET(lei/buc)     ");
j=5;
fp=fopen("Bibek.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(3,j);
printf("%s",a.cat);
gotoxy(22,j);
printf("%d",a.cod);
gotoxy(33,j);
printf("%s",a.nume);
gotoxy(52,j);
printf("%s",a.compozitie);
gotoxy(77,j);
printf("%d",a.cantitate);
gotoxy(93,j);
printf("%.2f",a.pret);
gotoxy(85,j);
printf("\n\n");
j++;
i=i+a.cantitate;
}
gotoxy(3,25);
printf("Numarul total al produselor = %d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
}



void modificaProdus(void)
{

system("cls");
int c=0;
int d,e;
gotoxy(20,4);
printf("**** Modificarea informatiilor despre produse ****");
char another='d';
while(another=='d')
{
system("cls");
gotoxy(15,6);
printf("Introducere cod produs pentru editare:");
scanf("%d",&d);
fp=fopen("Bibek.dat","rb+");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(checkid(d)==0)
{
gotoxy(15,7);
printf("Produsul este disponibil !");
gotoxy(15,8);
printf("Codul produsului:%d",a.cod);
gotoxy(15,9);
printf("Introducere denumire noua:");scanf("%s",a.nume);
gotoxy(15,10);
printf("Introducere compozitie:");scanf("%s",a.compozitie);
gotoxy(15,11);
printf("Introducere cantitate:");scanf("%d",&a.cantitate);
gotoxy(15,12);
printf("Introducere pret nou:");scanf("%f",&a.pret);
gotoxy(15,14);
printf("Modificarea a fost realizata cu succes");
fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,9);
printf("Nu s-a gasit nici un produs cu acest cod");
}
}
gotoxy(15,16);
printf("Modifici alte informatii despre un produs?(D / N)");
fflush(stdin);
another=getch() ;
}
returnfunc();
}


void returnfunc(void)
{
{
gotoxy(15,18);
printf(" Apasa ENTER pentru a intra in meniul principal   ");
}
a:
if(getch()==13)
mainmenu();
else
goto a;
}

int getdata()
{
int t;
gotoxy(22,3);printf("Introducere informatii: ");
gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5);
printf("\xB2");gotoxy(50,5);printf("\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(50,6);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(50,7);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(50,8);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(50,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(50,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2");gotoxy(50,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,5);
printf(" Categorie:");
gotoxy(33,5);
printf("%s",categorii[s-1]);
gotoxy(21,7);
printf("Cod produs:\t");
gotoxy(32,7);
scanf("%d",&t);
if(checkid(t) == 0)
{
gotoxy(21,13);
printf("\aProdusul exista deja !\a");
getch();
mainmenu();
return 0;
}
a.cod=t;
gotoxy(21,8);
printf("Denumire produs:");gotoxy(37,8);
scanf("%s",a.nume);
gotoxy(21,9);
printf("Compozitie:");gotoxy(32,9);
scanf("%s",a.compozitie);
gotoxy(21,10);
printf("Cantitate:");gotoxy(31,10);
scanf("%d",&a.cantitate);
gotoxy(21,11);
printf("Pret:");gotoxy(26,11);
scanf("%f",&a.pret);
return 1;
}

int checkid(int t)
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.cod==t)
return 0;
return 1;
}

int t(void)
{
time_t t;
time(&t);
printf("Data:%s\n",ctime(&t));

return 0 ;
}



void Password(void) //for password option
{

system("cls");
char d[25]=" Protectie cu parola ";
char ch,pass[10],password[10]="patiserie";
int i=0,j;
gotoxy(10,4);
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
gotoxy(10,10);
gotoxy(15,7);
printf("Introducere parola:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

gotoxy(15,9);

printf(" Parola este valida ");
gotoxy(17,10);
printf(" Apasa orice tasta pentru a continua..... ");
getch();
mainmenu();
}
else
{
gotoxy(15,16);
printf("\a Parola incorecta !");
getch();
Password();
}
}
