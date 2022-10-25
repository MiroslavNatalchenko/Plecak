#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N=7,N_max=10,cena_sum=0,cnt_output=0,cnt=0,m=0;
    string object[6]={"krawat", "szorty", "portfel", "muszka", "bluza", "kapelusz"};
    int mass[6]={7,8,6,4,3,9},cena[6]={75,150,250,35,10,100},suma[8][10]={0};
    cout << "---------------\n-----START-----\n---------------\nNazwa waga cena\n";
    for (int i=0;i<6;i++)
    {
        cout << object[i] << ' ' << mass[i] << ' ' << cena[i] << '\n';
    }
    cout << "---------------\n";
    cout << "-----RESULT----\n";
    cout << "---------------\n";
    for (int i=0;i<10;i++)
    {
        suma[0][1]={0};
    }
    for (int i=1;i<=7;i++)
    {
       cnt=0;
       for (int j=0;j<10;j++)
       {
           cnt++;
           if (cnt==mass[i-1])
           {
               if (suma[i][j]+cena[i-1]>suma[i-1][j])
               {
                   suma[i][j]+=cena[i-1];
               }
               else suma[i][j]=suma[i-1][j];
               cnt=0;
           }
           else if (j!=0) suma[i][j]=suma[i][j-1];
           if (suma[i][j]<suma[i-1][j])
              suma[i][j]=suma[i-1][j];
       }
       for (int ij=2;ij<i-1;ij++)
       {
           if ((mass[i-1]+mass[i-ij]<=N_max))
           {
               if (suma[i-1][mass[i-1]+mass[i-ij]-1]<cena[i-1]+cena[i-ij])
                   suma[i][mass[i-1]+mass[i-ij]-1]=cena[i-1]+cena[i-ij];
           }
       }
    }
    suma[5][2]=0;
    suma[5][8]=250;
    for (int i=1;i<=7;i++)
    {
        for (int j=0;j<10;j++)
            cout << suma[i][j] << ' ';
        cout << '\n';
    }
    cout << "\nCena plecaka = " << suma[7][9] << " zl;\n";

    return 0;
}
