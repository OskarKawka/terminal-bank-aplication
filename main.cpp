#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

struct Login
    {
        string login="admin";
        string haslo="1234";
        double stankonta=2137;

    };
    Login jedenLogin;

    Login dwaLogin;

    struct Lokata
    {
        const float oprocentowanie=0.06;
        const float kapitalizacja=12;
    };
    struct Kredyt
    {
        const float oprkredyt=0.2;
    };

    void logowanie();
    void stankonta();
    void menu();
    void przelew();
    void kredyt();
    Kredyt jedenKredyt;
    void lokata();
    Lokata jedenLokata;
    void blik();
    void haslo();
    void wyloguj();
    int wybor;
    void czysc();
int main()
{
   cout<<"SYSTEM BANKOWOSCI"<<endl;
   logowanie();
   menu();
    return 0;
}


void logowanie()
{
for(int i=1; i<=5; i++)
{
    cout<<"Wpisz login:";
    cin>>dwaLogin.login;
    cout<<endl;
    cout<<"Wpisz haslo:";
    cin>>dwaLogin.haslo;
   cout<<endl;
   if ((jedenLogin.login==dwaLogin.login&& jedenLogin.haslo==dwaLogin.haslo))
    {
        cout<<"Logowanie powiodlo sie"<<endl;
         cout<<"Wcisnij dowolny klawisz, aby przejsc dalej:";
        getch();
       czysc();
        break;
    }
    else
    {
        cout<<"Logowanie nie powiodlo sie, sprobuj jeszcze raz"<<endl;
        cout<<"Wcisnij dowolny klawisz, aby przejsc dalej:";
         getch();
        czysc();
    }

if (i==5)
{
cout<<"Zalogowano blednie 5 razy, konto zablokowane"<<endl;
 cout<<"Wcisnij dowolny klawisz, aby wyjsc";
         getch();
exit(0);
}
}
}
void menu()
{
    cout<<endl;
    cout<<"WITAMY W BANKU"<<endl;
    cout<<"Wybierz co chcesz zrobic:"<<endl;
    cout<<"1.Pokaz stan konta"<<endl;
    cout<<"2.Wyslij przelew"<<endl;
    cout<<"3.Wez kredyt"<<endl;
    cout<<"4.Zaloz lokate"<<endl;
    cout<<"5.Zaplac blikiem"<<endl;
    cout<<"6.Zmien haslo"<<endl;
    cout<<"7.Wyloguj"<<endl;
    cout<<"Wybor:";
    char menu;
    menu=getch();
   switch(menu)
   {
       case '1': stankonta();
       break;
       case '2': przelew();
       break;
       case '3': kredyt();
       break;
       case '4': lokata();
       break;
       case '5': blik();
       break;
       case '6': haslo();
       break;
       case '7': wyloguj();
       break;
   }


}
void stankonta()
{ czysc();
 cout<<"Twoj stan konta:"<<jedenLogin.stankonta<<endl;
 cout<<"Wcisnij dowolny klawisz, aby przejsc dalej:";
         getch();
         system("cls");
         menu();

}

 void przelew()
 {
     czysc();
     double kwotaprzelewu;
     string nrkonta;
     cout<<endl;
    cout<<"Twoj stan konta:"<<jedenLogin.stankonta<<endl;
    cout<<"Podaj kwote przelewu:";
    cin>>kwotaprzelewu;
    if (kwotaprzelewu <=jedenLogin.stankonta)
    {
        cout<<"Podaj nr konta na ktore maja byc przelane pieniadze:";
        cin>>nrkonta;
        cout<<endl;
        jedenLogin.stankonta=jedenLogin.stankonta-kwotaprzelewu;
        cout<<"Przelew zostal wyslany poprawnie"<<endl;
         cout<<"Wcisnij dowolny klawisz, aby przejsc dalej:";
         getch();
         system("cls");
         menu();
    }
    else
    {
        cout<<"Zbyt malo srodkow na koncie"<<endl;
         cout<<"Wcisnij dowolny klawisz, aby przejsc dalej:";
         getch();
         system("cls");
         menu();
    }

 }
   void kredyt()
   {
       czysc();
       int lat;
       long kwota;
        cout<<"Oprocentowanie wynosi:"<<jedenKredyt.oprkredyt<<" procent"<<endl;
       cout<<"Na ile lat chcesz wziac kredyt?";
       cin>>lat;
       cout<<endl;
       cout<<"Na jaka kwote chcesz wziac kredyt?";
       cin>>kwota;
       cout<<endl;
    int rat=lat*12;
       cout<<"Miesieczna rata kredytu to:"<<kwota*(pow(1+(jedenKredyt.oprkredyt/12),rat))*((jedenKredyt.oprkredyt/12)/((pow(1+(jedenKredyt.oprkredyt/12),rat)-1)));
       cout<<endl;
 cout<<"Wcisnij dowolny klawisz, aby przejsc dalej:";
         getch();
         system("cls");
         menu();
   }

    void lokata()
    {
        czysc();
        int lat;
       long kwota;
        cout<<"Oprocentowanie wynosi:"<<jedenLokata.oprocentowanie<<" procent, a liczba kapitalizacji na rok:"<<jedenLokata.kapitalizacja;
        cout<<endl;
        cout<<"Na ile lat chcesz zalozyc lokate?";
       cin>>lat;
       cout<<endl;
       cout<<"Na jaka kwote chcesz zalozyc lokate?";
       cin>>kwota;
       cout<<endl;
       cout<<"Po "<<lat<<" latach bedziesz mial:"<<kwota*(pow(1+(jedenLokata.oprocentowanie/(jedenLokata.kapitalizacja*100)),jedenLokata.kapitalizacja*lat));
        cout<<endl;
        cout<<"Wcisnij dowolny klawisz, aby przejsc dalej:";
         getch();
         system("cls");
         menu();
    }
    void blik ()
    {   czysc();
        srand(time(NULL));
       int blik=rand()%100000+123456;
        cout<<"Twoj blik to:"<<blik<<endl;
         cout<<"Wcisnij dowolny klawisz, aby przejsc dalej:";
         getch();
         system("cls");
         menu();

    }
    void haslo ()
    {
        czysc();
        string starehaslo, nowehaslo1, nowehaslo2;
        cout<<"Wpisz stare haslo:";
        cin>>starehaslo;
        cout<<endl;
        for (int i=1; i++;)
    {
        if (starehaslo==jedenLogin.haslo)
        {
             cout<<"Wpisz nowe haslo dwukrotnie:"<<endl;
            cin>>nowehaslo1;
            cout<<endl;
            cin>>nowehaslo2;
            cout<<endl;
            if (nowehaslo1==nowehaslo2)
            {
                jedenLogin.haslo=nowehaslo1;
                cout<<"Przypisano nowe haslo do konta"<<endl;
                cout<<"Wcisnij dowolny klawisz, aby przejsc dalej:";
         getch();
         system("cls");
                menu();
            }
            else
                cout<<"Hasla sa niezgodne, sproboj jeszcze raz"<<endl;
                 cout<<"Wcisnij dowolny klawisz, aby sprobowac ponownie:";
         getch();
         system("cls");
                haslo();
        }
        else
        {
                cout<<"Haslo jest niezgodne, sproboj jeszcze raz"<<endl;
                cout<<"Wcisnij dowolny klawisz, aby sprobowac ponownie:";
         getch();
         system("cls");
                haslo();
        }
    }
    }
    void wyloguj()
    {
        czysc();
       cout<<"Wylogowano pomyslnie"<<endl;
        long long czas=clock();
        long czas_w_sek = (czas/1000);
        int minuty=czas_w_sek/60;
        cout<<"Czas sesji: "<<minuty<<" minut, "<< czas_w_sek % 60 <<"sekund"<<endl;

    }

    void czysc()
    {
        system("cls");
        cout<<"SYSTEM BANKOWOSCI"<<endl;
    }
