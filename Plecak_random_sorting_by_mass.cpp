#include <bits/stdc++.h>
#include <random>

using namespace std;

int random(int min,int max)
{
    int ch=rand();
    int v=max-min+1;
    ch=ch%v;
    ch+=min;
    return ch;
}

int bubble_sort(string name[],int charackter1[],int charakter2[],int N)
{
    for (int i=1;i<N;++i)
    {
        for (int j=0;j<N-i;++j)
        {
         if (charackter1[j]>charackter1[j+1])
         {
             swap(charackter1[j],charackter1[j+1]);
             swap(charakter2[j],charakter2[j+1]);
             swap(name[j],name[j+1]);
         }
        }
    }
}

int main()
{
    int N=7,N_max=15,cena_sum=0,cnt_output=0;
    string object[7]={"krawat", "szorty", "portfel", "muszka", "bluza", "kapelusz", "szalik"};
    int mass[7]={0},cena[7]={0},cnt[7]={0};
    cout << "Nazwa waga cena\n---------------\n-----START-----\n---------------\n";
    for (int i=0;i<7;i++)
    {
        mass[i]=random(1,15);
        cena[i]=random(10,500);
        cout << object[i] << ' ' << mass[i] << ' ' << cena[i] << '\n';
    }
    bubble_sort(object,mass,cena,N);
    cout << "Nazwa waga cena\n";
    cout << "---------------\n";
    cout << "-----SORTED----\n";
    cout << "---------------\n";
    for (int i=0;i<7;i++)
    {
        cout << object[i] << ' ' << mass[i] << ' ' << cena[i] << '\n';
    }
    cout << "---------------\n";
    cout << "-----RESULT----\n";
    cout << "---------------\n";
    cout << "Plecak = ";
    for (int i=0;i<7;i++)
    {
        while (N_max - mass[i] >= 0)
        {
            cnt[i]++;
            N_max-=mass[i];
            cena_sum=cena_sum+cena[i];
        }
        if (cnt[i]!=0)
        {
            cnt_output++;
            if (cnt_output==1)
                cout << cnt[i] << "*[" << object[i] << "]";
            else
                cout << " + " << cnt[i] << "*[" << object[i] << "]";
        }
    }
    cout << ";\nCena plecaka = " << cena_sum << " zl;\n";

    return 0;
}
