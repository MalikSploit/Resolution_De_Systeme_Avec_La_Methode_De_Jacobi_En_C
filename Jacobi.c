#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 20 //On alloue plus de cases mémoires que besoin dans notre cas pour pouvoir experimenté sur d'autres matrices plus grandes.

void Jacobi()
{
  int n=15; //Dimension de la Matrice A sans la Matrice B
  //La matrice B sera la derniere colone dans la Matrice A.
  float Matrice[N][N]= //Contient la Matrice A et la Matrice B.
{
{0,  0,        0,      0,     0,     0,       0,      0,      0,       0,       0,       0,        0,        0,      0,       0,     0},
{0, 1.0,     1.0/2,  1.0/4, 1.0/8, 1.0/16, 1.0/32, 1.0/64, 1.0/128, 1.0/256, 1.0/512, 1.0/1024, 1.0/2048, 1.0/4096, 1/8192, 1/16384, 1},
{0, 1.0/2,    1.0,     0,     0,     0,       0,      0,       0,       0,      0,       0,        0,        0,      0,       0,     1},
{0, 1.0/4,     0,     1.0,    0,     0,       0,      0,       0,       0,      0,       0,        0,        0,      0,       0,     1},
{0, 1.0/8,     0,      0,    1.0,    0,       0,     1.0,    1.0,       0,    1.0,       0,        0,        0,      0,       0,     1},
{0, 1.0/16,    0,      0,     0,    1.0,      0,      0,       0,       0,      0,       0,        0,        0,      0,       0,     1},
{0, 1.0/32,    0,      0,     0,     0,      1.0,     0,       0,       0,      0,       0,        0,        0,      0,       0,     1},
{0, 1.0/64,    0,      0,     0,     0,       0,     1.0,      0,       0,      0,       0,        0,        0,      0,       0,     1},
{0, 1.0/128,   0,      0,     0,     0,       0,      0,      1.0,      0,      0,       0,        0,        0,      0,       0,     1},
{0, 1.0/256,   0,      0,     0,     0,       0,      0,       0,      1.0,     0,       0,        0,      1.0,      0,       0,     1},
{0, 1.0/512,   0,      0,     0,     0,       0,      0,       0,       0,     1.0,      0,        0,        0,      0,       0,     1},
{0, 1.0/1024,  0,      0,   1.0,     0,       0,      0,       0,       0,      0,      1.0,       0,        0,    1.0,       0,     1},
{0, 1.0/2048,  0,      0,     0,     0,       0,      0,       0,       0,      0,       0,       1.0,       0,      0,       0,     1},
{0, 1.0/4096,  0,      0,     0,     0,       0,    1.0,       0,       0,      0,       0,        0,       1.0,     0,     1.0,     1},
{0, 1.0/8192,  0,      0,     0,     0,       0,      0,       0,       0,      0,       0,        0,        0,     1.0,      0,     1},
{0, 1.0/16384, 0,      0,     0,     0,       0,      0,       0,       0,      0,       0,        0,        0,      0,      1.0,    1},
}; 
  float x[15],relerror,big,temp,sum;
  float e = 0.00001; //tolérance pour le critére d'arrêt
  int i,j, itr;      
  int maxitr=n*n; //max itérations
  char ch;

  /* 
  printf("Saisir la dimension de votre matrice : ");
  scanf("%d",&n);

  for(i=1;i<=n;i++)
  {
    printf("Saisir les coef de la ligne %d avec le coef de la matrice b à la fin : \n",i);                               Cette partie est faite si l'on souhaite saisir les coeff de la matrice par  saisie clavier.                                                                                                                                                                        
    for(j=1;j<=n+1;j++)
    {
      scanf("%f",&Matrice[i][j]);
    }
  }

  printf("Saisir votre tolérance pour le critére d'arrêt et ensuite saisir le nombre d'itérations :  \n");
  scanf("%f%d",&e,&maxitr);
  //for(i=1;i<=n;i++)
  //x[i]=0;
  */

  //On effectue au maximum n*n itérations, or il n y a pas besoins d'autant d'itérations mais c'est pour garantir qu'on ait fait assez d'itérations, car dès que l'algo converge il s'arrête sans finir le reste des itérations et affiche la solution pour la matrice x.
  for(itr=1;itr<=maxitr;itr++)
  {
    big=0;
    for(i=1;i<=n;i++)
    {
     sum=0;
     for(j=1;j<=n;j++)
     {
      if(i!=j)
      {
        sum=sum+Matrice[i][j]*x[j];
      }
     }    
     temp=(Matrice[i][n+1]-sum)/Matrice[i][i];
     relerror=fabs((x[i]-temp)/temp);
     if(relerror>big)
     {
      big=relerror;
     }
     x[i]=temp;
    }
    //Si l'algo converge.
    if(big<=e) 
    {
     printf("L'algo converge après %d itération(s).\n",itr);
        
     for(i=1;i<=n;i++)
     {
      printf("x%d = %.4f\n", i, x[i]); //On affichera les coefficients de la matrice x avec 4 chiffres après la virgule.
     }
     exit(0); //On quitte immédiatement la boucle et l'algo affiche la solution pour la matrice x.
    }
  }
  //Sinon l'algo ne converge pas.
  printf("L'algo ne converge pas dans %d itération(s).\n",maxitr);
}

int main()
{
  Jacobi();
  return 0;
}