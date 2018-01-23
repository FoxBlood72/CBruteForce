#include <stdio.h>
#include <string.h>

using namespace std;


void convert(char &x,char *pointer,int pozitie)
{

    switch(x)
    {
    case 'z'+1:
        x = 'A';
        break;
    case 'Z'+1:
        x = '1';
        break;
    case '9'+1:
        x = 'a';
        (*(pointer+pozitie-1))++;
        convert(*(pointer+pozitie-1),pointer,pozitie-1);
        break;
    }
}

char combination[100];
char r = 'n';
int x = 0;
bool stop = false;
void Algorithm()
{
    while(true)
    {
        combination[x-1]++;
        convert(combination[x-1],combination,x-1);

       
        if(r == 'y')
        printf("%s \n",combination);


        stop = true;
        for(int i=0;i<x;i++)
            if(combination[i] != '9')
            stop = false;

        if(stop)
        break;
    }

}


int main()
{

    printf("************************************************* \n");
    printf("Proiect - RedFox \n");
    printf("Creator - FoxBlood \n");
    printf("Descriere: Simplu algoritm de generare a tuturor posibilitatilor de x litere mari, mici + cifre. \n");
    printf("************************************************* \n");

    printf("Doriti afisarea combinatiilor? (afisarea incetineste algoritmul cu foarte mult timp )\n");
    printf("(y/n) \n");
    scanf("%c",&r);
    printf("De cate caractere sa fie combinatiile? \n");


    scanf("%d",&x);


    for(int i=0;i<x;i++)
        combination[i] = 'a';


    Algorithm();

    printf("\n DONE! Toate combinatiile de %d caractere au fost facute! \n",x);


    return 0;
}
