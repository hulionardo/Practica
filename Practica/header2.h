using namespace std;
string decupare_nume(const char nume[50])
{
    char nume_2[50] = {}; int i;
    for (i = 0; i < strlen(nume); i++)
    {
        if (nume[i] == ' ')
        {
            break;
        }
    }
    strncpy(nume_2, nume, i+1);
    return nume_2;
}
struct placa_video
{
    char producator[20], model[20], tip_mem[10];
    int memoria, tdp, frecventa;
    float pret;
};
void citire_video(placa_video t[], int& n)
{
    fstream f("placa_video.txt", ios::in);
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> t[i].producator >> t[i].model >> t[i].tip_mem >> t[i].memoria >> t[i].tdp >> t[i].frecventa >> t[i].pret;
    }
    f.close();
}
void afisare_video(placa_video t)
{
    cout <<setw(15) << t.producator << setw(15) << t.model;
    cout <<setw(15) << t.tip_mem << setw(15) << t.memoria << setw(9) << t.tdp << 'W' << setw(10) << t.frecventa << "MHz";
    cout << setw(10) << t.pret << "$" << endl;
}
void antet_video()
{
    cout << "Lista de placi video" << endl;
    cout << setw(15) << "Producator" <<" " << setw(15) << "Model";
    cout << setw(20) << "Tip de memorie"  <<setw(10)<<"Memorie"<< setw(8) << " TDP" << setw(13) << "Frecventa";
    cout << setw(8) << "\tPret" << endl;
}
void afisare_video(placa_video t[], const int n)
{
    antet_video();
    for (int i = 0; i < n; i++)
    {
        afisare_video(t[i]);
    }
}
void sortare_video_mic(placa_video t[], const int n)
{
    placa_video aux;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (t[i].pret > t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_video(t, n);
}
void sortare_video_mare(placa_video t[], const int n)
{
    placa_video aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret < t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_video(t, n);
}
void adaugare_video(placa_video t[], int& n)
{
    cout << "Producator: "; cin >> t[n].producator;
    cout << "Model: "; cin >> t[n].model;
    cout << "Tipul memoriei: "; cin >> t[n].tip_mem;
    cout << "Memoria(GB): "; cin >> t[n].memoria;
    cout << "TDP(W): "; cin >> t[n].tdp;
    cout << "Frecventa(MHz): "; cin >> t[n].frecventa;
    cout << "Pret ($): "; cin >> t[n].pret;
    n++;
    fstream f("placa_video.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].tip_mem << " " << t[i].memoria << " " << t[i].tdp << " " << t[i].frecventa << " " << t[i].pret << endl;
    }
    f.close();
}
void excludere_video(placa_video t[], int& n)
{
    int k;
    afisare_video(t, n);
    cout << "\nSelectati randul placii dorit de exclus: "; cin >> k;
    for (int i = k - 1; i < n; i++)
    {
        t[i] = t[i + 1];
    }
    n--;
    fstream f("placa_video.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].tip_mem << " " << t[i].memoria << " " << t[i].tdp << " " << t[i].frecventa << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost exclus";
}
void actualizare_video(placa_video t[], const int n)
{
    int k;
    afisare_video(t, n);
    cout << "\nSelectati randul dorit de actualizat: "; cin >> k;
    cout << "\nProducator: "; cin >> t[k-1].producator;
    cout << "Model: "; cin >> t[k-1].model;
    cout << "Tipul memoriei: "; cin >> t[k-1].tip_mem;
    cout << "Memoria(GB): "; cin >> t[k-1].memoria;
    cout << "TDP(W): "; cin >> t[k-1].tdp;
    cout << "Frecventa(MHz): "; cin >> t[k-1].frecventa;
    cout << "Pret ($): "; cin >> t[k-1].pret;
    fstream f("placa_video.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].tip_mem << " " << t[i].memoria << " " << t[i].tdp << " " << t[i].frecventa << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost actualizat";
}
void extrem_video_pret(placa_video t[], const int n)
{
    float maxim = -32768; int k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].pret)
        {
            maxim = t[i].pret;
            k = i;
        }
    }
    cout << "Placa video cu cel mai mare pret:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].pret << "$" << endl;
}
void extrem_video_memorie(placa_video t[], const int n)
{
    int maxim = -32768, k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].memoria)
        {
            maxim = t[i].memoria;
            k = i;
        }
    }
    cout << "Placa video cu cel mai mare volum de memorie video:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].memoria << "GB" << endl;
}
void media_video_pret(placa_video t[], const int n)
{
    float med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Pretul mediu a placilor video: " << med/n << "$";
}
void media_video_memorie(placa_video t[], const int n)
{
    int med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].memoria;
    }
    cout << "Memoria video medie a placilor video: " << med / n << "GB";
}
struct procesor
{
    char producator[20], model[20], socket[20], nucleu[20];
    int frecventa, nr_nuc, nr_fir;
    float pret;
};
void citire_procesor(procesor t[], int& n)
{
    fstream f("procesor.txt", ios::in);
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> t[i].producator >> t[i].model >> t[i].socket >> t[i].nucleu >> t[i].frecventa >> t[i].nr_nuc >> t[i].nr_fir >> t[i].pret;
    }
    f.close();
}
void afisare_procesor(procesor t)
{
    cout << setw(9) << t.producator << setw(19) << t.model;
    cout << setw(15) << t.socket << setw(14) << t.nucleu << setw(8) << t.frecventa << "MHz" << setw(10) << t.nr_nuc << setw(15) << t.nr_fir;
    cout << setw(8) << t.pret << "$" << endl;
}
void antet_procesor()
{
    cout << "Lista procesoarelor" << endl;
    cout << "Producator" << setw(15) << "Model";
    cout << setw(18) << "Socket" << setw(10) << "Nucleu" << setw(15) << "Frecventa" << setw(13) << "Nr.nuclee" << setw(13) << "Nr.fire";
    cout << setw(8) << "Pret" << endl;
}
void afisare_procesor(procesor t[], const int n)
{
    antet_procesor();
    for (int i = 0; i < n; i++)
    {
        afisare_procesor(t[i]);
    }
}
void sortare_procesor_mic(procesor t[], const int n)
{
    procesor aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret > t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_procesor(t, n);
}
void sortare_procesor_mare(procesor t[], const int n)
{
    procesor aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret < t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_procesor(t, n);
}
void adaugare_procesor(procesor t[], int& n)
{
    cout << "Producator: "; cin >> t[n].producator;
    cout << "Model: "; cin >> t[n].model;
    cout << "Socket: "; cin >> t[n].socket;
    cout << "Nucleul: "; cin >> t[n].nucleu;
    cout << "Frecventa(MHz): "; cin >> t[n].frecventa;
    cout << "Nr.nuclee: "; cin >> t[n].nr_nuc;
    cout << "Nr.fire: "; cin >> t[n].nr_fir;
    cout << "Pret ($): "; cin >> t[n].pret;
    n++;
    fstream f("procesor.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].socket << " " << t[i].nucleu << " " << t[i].frecventa << " " << t[i].nr_nuc << " " << t[i].nr_fir << " " << t[i].pret << endl;
    }
    f.close();
}
void excludere_procesor(procesor t[], int& n)
{
    int k;
    afisare_procesor(t, n);
    cout << "\nSelectati randul procesorului dorit de exclus: "; cin >> k;
    for (int i = k - 1; i < n; i++)
    {
        t[i] = t[i + 1];
    }
    n--;
    fstream f("procesor.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].socket << " " << t[i].nucleu << " " << t[i].frecventa << " " << t[i].nr_nuc << " " << t[i].nr_fir << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost exclus";
}
void actualizare_procesor(procesor t[], const int n)
{
    int k;
    afisare_procesor(t, n);
    cout << "\nSelectati randul dorit de actualizat: "; cin >> k;
    k--;
    cout << "\nProducator: "; cin >> t[k].producator;
    cout << "Model: "; cin >> t[k].model;
    cout << "Socket: "; cin >> t[k].socket;
    cout << "Nucleul: "; cin >> t[k].nucleu;
    cout << "Frecventa(MHz): "; cin >> t[k].frecventa;
    cout << "Nr.nuclee: "; cin >> t[k].nr_nuc;
    cout << "Nr.fire: "; cin >> t[k].nr_fir;
    cout << "Pret ($): "; cin >> t[k].pret;
    fstream f("procesor.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].socket << " " << t[i].nucleu << " " << t[i].frecventa << " " << t[i].nr_nuc << " " << t[i].nr_fir << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost actualizat";
}
void extrem_procesor_pret(procesor t[], const int n)
{
    float maxim = -32768; int k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].pret)
        {
            maxim = t[i].pret;
            k = i;
        }
    }
    cout << "Procesorul cu cel mai mare pret:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].pret << "$" << endl;
}
void extrem_procesor_frecventa(procesor t[], const int n)
{
    int maxim = -32768, k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].frecventa)
        {
            maxim = t[i].frecventa;
            k = i;
        }
    }
    cout << "Procesorul cu cea mai mare frecventa:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].frecventa << "MHz" << endl;
}
void media_procesor_pret(procesor t[], const int n)
{
    float med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Pretul mediu a procesoarelor: " << med / n << "$";
}
void media_procesor_frecventa(procesor t[], const int n)
{
    int med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].frecventa;
    }
    cout << "Frecnveta medie a procesoarelor: " << med / n << "MHz";
}
struct placa_de_baza
{
    char producator[20], model[20], socket[20] ,chipset[20],tip_ram[20];
    int  max_ram;
    float pret;
};
void citire_placa(placa_de_baza t[], int& n)
{
    fstream f("placa de baza.txt", ios::in);
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> t[i].producator >> t[i].model >> t[i].socket >> t[i].chipset >> t[i].tip_ram >> t[i].max_ram >> t[i].pret;
    }
    f.close();
}
void afisare_placa(placa_de_baza t)
{
    cout <<setw(8) << t.producator <<setw(10) << t.model;
    cout << setw(15) << t.socket << setw(14) << t.chipset << setw(10) << t.tip_ram << setw(10) << t.max_ram << "GB";
    cout << setw(9) << t.pret << "$" << endl;
}
void antet_placa()
{
    cout << "Lista placilor de baza" << endl;
    cout << "Producator" << setw(8) << "Model";
    cout << setw(13) << "Socket" << setw(12) << "Chipset" << setw(17) << "Tip ram" << setw(10) << "Max ram";
    cout << setw(8) << "Pret" << endl;
}
void afisare_placa(placa_de_baza t[], const int n)
{
    antet_placa();
    for (int i = 0; i < n; i++)
    {
        afisare_placa(t[i]);
    }
}
void sortare_placa_mic(placa_de_baza t[], const int n)
{
    placa_de_baza aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret > t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_placa(t, n);
}
void sortare_placa_mare(placa_de_baza t[], const int n)
{
    placa_de_baza aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret < t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_placa(t, n);
}
void adaugare_placa(placa_de_baza t[], int& n)
{
    cout << "Producator: "; cin >> t[n].producator;
    cout << "Model: "; cin >> t[n].model;
    cout << "Socket: "; cin >> t[n].socket;
    cout << "Chipset: "; cin >> t[n].chipset;
    cout << "Tip ram: "; cin >> t[n].tip_ram;
    cout << "Max ram: "; cin >> t[n].max_ram;
    cout << "Pret ($): "; cin >> t[n].pret;
    n++;
    fstream f("placa de baza.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].socket << " " << t[i].chipset << " " << t[i].tip_ram << " " << t[i].max_ram << " " << t[i].pret << endl;
    }
    f.close();
}
void excludere_placa(placa_de_baza t[], int& n)
{
    int k;
    afisare_placa(t, n);
    cout << "\nSelectati randul dorit de exclus: "; cin >> k;
    for (int i = k - 1; i < n; i++)
    {
        t[i] = t[i + 1];
    }
    n--;
    fstream f("ram.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].socket << " " << t[i].chipset << " " << t[i].tip_ram << " " << t[i].max_ram << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost exclus";
}
void actualizare_placa(placa_de_baza t[], const int n)
{
    int k;
    afisare_placa(t, n);
    cout << "\nSelectati randul dorit de actualizat: "; cin >> k;
    k--;
    cout << "\nProducator: "; cin >> t[k].producator;
    cout << "Model: "; cin >> t[k].model;
    cout << "Socket: "; cin >> t[k].socket;
    cout << "Chipset: "; cin >> t[k].chipset;
    cout << "Tip ram: "; cin >> t[k].tip_ram;
    cout << "Max ram: "; cin >> t[k].max_ram;
    cout << "Pret ($): "; cin >> t[k].pret;
    fstream f("ram.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].socket << " " << t[i].chipset << " " << t[i].tip_ram << " " << t[i].max_ram << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost actualizat";
}
void extrem_placa_pret(placa_de_baza t[], const int n)
{
    float maxim = -32768; int k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].pret)
        {
            maxim = t[i].pret;
            k = i;
        }
    }
    cout << "Placa de baza cu cel mai mare pret:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].pret << "$" << endl;
}
void extrem_placa_memorie(placa_de_baza t[], const int n)
{
    int maxim = -32768, k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].max_ram)
        {
            maxim = t[i].max_ram;
            k = i;
        }
    }
    cout << "Placa de baza cu cel mai mare volum maximal de memorie ram:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].max_ram << "GB" << endl;
}
void media_placa_pret(placa_de_baza t[], const int n)
{
    float med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Pretul mediu a placilor de baza: " << med / n << "$";
}
void media_placa_memorie(placa_de_baza t[], const int n)
{
    int med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].max_ram;
    }
    cout << "Volumul maxime de memorie ram mediu a placilor de baza: " << med / n << "GB";
}
struct ram
{
    char producator[20], model[20],tip[20];
    int frecventa, volum;
    float pret;
};
void citire_ram(ram t[], int& n)
{
    fstream f("ram.txt", ios::in);
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> t[i].producator >> t[i].model >> t[i].tip >> t[i].frecventa >> t[i].volum >> t[i].pret;
    }
    f.close();
}
void afisare_ram(ram t)
{
    cout << setw(8) << t.producator << setw(15) << t.model;
    cout << setw(8) << t.tip << setw(8) << t.frecventa <<"MHz" <<setw(8) << t.volum << "GB";
    cout << setw(11) << t.pret << "$" << endl;
}
void antet_ram()
{
    cout << "Lista placutelor de memorie" << endl;
    cout << setw(10) << "Producator" << setw(10) << "Model";
    cout << setw(11) << "Tipul" << setw(11) << "Frecventa" << setw(12) << "Volumul";
    cout << setw(10) << "Pret" << endl;
}
void afisare_ram(ram t[], const int n)
{
    antet_ram();
    for (int i = 0; i < n; i++)
    {
        afisare_ram(t[i]);
    }
}
void sortare_ram_mic(ram t[], const int n)
{
    ram aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret > t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_ram(t, n);
}
void sortare_ram_mare(ram t[], const int n)
{
    ram aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret < t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_ram(t, n);
}
void adaugare_ram(ram t[], int& n)
{
    cout << "Producator: "; cin >> t[n].producator;
    cout << "Model: "; cin >> t[n].model;
    cout << "Tipul: "; cin >> t[n].tip;
    cout << "Frecventa(MHz): "; cin >> t[n].frecventa;
    cout << "Volum: "; cin >> t[n].volum;
    cout << "Pret ($): "; cin >> t[n].pret;
    n++;
    fstream f("ram.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].tip << " " << t[i].frecventa << " " << t[i].volum << " " << t[i].pret << endl;
    }
    f.close();
}
void excludere_ram(ram t[], int& n)
{
    int k;
    afisare_ram(t, n);
    cout << "\nSelectati randul dorit de exclus: "; cin >> k;
    for (int i = k - 1; i < n; i++)
    {
        t[i] = t[i + 1];
    }
    n--;
    fstream f("ram.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].tip << " " << t[i].frecventa << " " << t[i].volum << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost exclus";
}
void actualizare_ram(ram t[], const int n)
{
    int k;
    afisare_ram(t, n);
    cout << "\nSelectati randul dorit de actualizat: "; cin >> k;
    k--;
    cout << "\nProducator: "; cin >> t[k].producator;
    cout << "Model: "; cin >> t[k].model;
    cout << "Tipul: "; cin >> t[k].tip;
    cout << "Frecventa(MHz): "; cin >> t[k].frecventa;
    cout << "Volum: "; cin >> t[k].volum;
    cout << "Pret ($): "; cin >> t[k].pret;
    fstream f("ram.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].tip << " " << t[i].frecventa << " " << t[i].volum << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost actualizat";
}
void extrem_ram_pret(ram t[], const int n)
{
    float maxim = -32768; int k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].pret)
        {
            maxim = t[i].pret;
            k = i;
        }
    }
    cout << "Placuta ram cu cel mai mare pret:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].pret << "$" << endl;
}
void extrem_ram_frecventa(ram t[], const int n)
{
    int maxim = -32768, k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].frecventa)
        {
            maxim = t[i].frecventa;
            k = i;
        }
    }
    cout << "Placuta ram cu cea mai mare frecventa:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].frecventa << "MHz" << endl;
}
void media_ram_pret(ram t[], const int n)
{
    float med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Pretul mediu a placutelor ram: " << med / n << "$";
}
void media_ram_frecventa(ram t[], const int n)
{
    int med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].frecventa;
    }
    cout << "Frecventa medie a placutelor ram: " << med / n << "MHz";
}
struct monitor
{
    char producator[20], model[20], x;
    int frecventa, rezolutia_1,rezolutia_2;
    float pret, diagonala;
};
void citire_monitor(monitor t[], int& n)
{
    fstream f("monitor.txt", ios::in);
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> t[i].producator >> t[i].model >> t[i].frecventa >> t[i].rezolutia_1 >> t[i].x >> t[i].rezolutia_2 >> t[i].diagonala  >> t[i].pret;
    }
    f.close();
}
void afisare_monitor(monitor t)
{
    cout << setw(15) << t.producator << setw(10) << t.model;
    cout << setw(10) << t.frecventa << "Hz" << setw(9) << t.diagonala << '"';
    cout << setw(12) << t.rezolutia_1 << setw(2) << t.x << setw(5) << t.rezolutia_2 << " " << setw(8) << t.pret << "$" << endl;
}
void antet_monitor()
{
    cout << "Lista de monitoare" << endl;
    cout << setw(15) << "Producator" << setw(10) << "Model";
    cout << setw(13) << "Frecventa" << setw(12) << "Diagonala " << setw(15);
    cout << setw(13) << "Rezolutia" << setw(11) << "Pret" << endl;
}
void afisare_monitor(monitor t[], const int n)
{
    antet_monitor();
    for (int i = 0; i < n; i++)
    {
        afisare_monitor(t[i]);
    }
}
void sortare_monitor_mic(monitor t[], const int n)
{
    monitor aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret > t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_monitor(t, n);
}
void sortare_monitor_mare(monitor t[], const int n)
{
    monitor aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret < t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_monitor(t, n);
}
void adaugare_monitor(monitor t[], int& n)
{
    cout << "Producator: "; cin >> t[n].producator;
    cout << "Model: "; cin >> t[n].model;
    cout << "Frecventa(Hz): "; cin >> t[n].frecventa;
    cout << "Rezoltuia(1920 x 1080): "; cin >> t[n].rezolutia_1 >> t[n].x >> t[n].rezolutia_2;
    cout << "Diagonala: "; cin >> t[n].diagonala;
    cout << "Pret ($): "; cin >> t[n].pret;
    n++;
    fstream f("monitor.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].frecventa << " " << t[i].rezolutia_1 << " " << t[i].x << " " << t[i].rezolutia_2 << " " << t[i].diagonala << " " << t[i].pret << endl;
    }
    f.close();
}
void excludere_monitor(monitor t[], int& n)
{
    int k;
    afisare_monitor(t, n);
    cout << "\nSelectati randul dorit de exclus: "; cin >> k;
    for (int i = k - 1; i < n; i++)
    {
        t[i] = t[i + 1];
    }
    n--;
    fstream f("monitor.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].frecventa << " " << t[i].rezolutia_1 << " " << t[i].x << " " << t[i].rezolutia_2 << " " << t[i].diagonala << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost exclus";
}
void actualizare_monitor(monitor t[], const int n)
{
    int k;
    afisare_monitor(t, n);
    cout << "\nSelectati randul dorit de actualizat: "; cin >> k;
    k--;
    cout << "\nProducator: "; cin >> t[k].producator;
    cout << "Model: "; cin >> t[k].model;
    cout << "Frecventa(Hz): "; cin >> t[k].frecventa;
    cout << "Rezoltuia(1920 x 1080): "; cin >> t[k].rezolutia_1 >> t[k].x >> t[k].rezolutia_2;
    cout << "Diagonala: "; cin >> t[k].diagonala;
    cout << "Pret ($): "; cin >> t[k].pret;
    fstream f("monitor.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].frecventa << " " << t[i].rezolutia_1 << " " << t[i].x << " " << t[i].rezolutia_2 << " " << t[i].diagonala << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost actualizat";
}
void extrem_monitor_pret(monitor t[], const int n)
{
    float maxim = -32768; int k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].pret)
        {
            maxim = t[i].pret;
            k = i;
        }
    }
    cout << "Monitorul cu cel mai mare pret:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].pret << "$" << endl;
}
void extrem_monitor_frecventa(monitor t[], const int n)
{
    int maxim = -32768, k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].frecventa)
        {
            maxim = t[i].frecventa;
            k = i;
        }
    }
    cout << "Monitorul cu cea mai mare frecventa:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].frecventa << "Hz" << endl;
}
void media_monitor_pret(monitor t[], const int n)
{
    float med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Pretul mediu a monitoarelor: " << med / n << "$";
}
void media_monitor_frecventa(monitor t[], const int n)
{
    int med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].frecventa;
    }
    cout << "Frecventa medie a monitoarelor: " << med / n << "Hz";
}
struct tastatura
{
    char producator[20], model[20], tip_tast[20], iluminare[10];
    int nr_taste;
    float pret;
};
void citire_tastatura(tastatura t[], int& n)
{
    fstream f("tastatura.txt", ios::in);
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> t[i].producator >> t[i].model >> t[i].tip_tast >> t[i].iluminare >> t[i].nr_taste >> t[i].pret;
    }
    f.close();
}
void afisare_tastatura(tastatura t)
{
    cout << setw(10) << t.producator << setw(13) << t.model;
    cout << setw(15) << t.tip_tast  << setw(9) << t.iluminare;
    cout << setw(12) << t.nr_taste <<setw(12)<< t.pret << "$" << endl;
}
void antet_tastatura()
{
    cout << "Lista de tastature" << endl;
    cout << "Producator" << setw(12) << "Model";
    cout << setw(13) << "Tipul" << setw(16) << "Iluminare " << setw(15);
    cout << setw(13) << "Nr.taste" << setw(8) << "Pret" << endl;
}
void afisare_tastatura(tastatura t[], const int n)
{
    antet_tastatura();
    for (int i = 0; i < n; i++)
    {
        afisare_tastatura(t[i]);
    }
}
void sortare_tastatura_mic(tastatura t[], const int n)
{
    tastatura aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret > t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_tastatura(t, n);
}
void sortare_tastatura_mare(tastatura t[], const int n)
{
    tastatura aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret < t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_tastatura(t, n);
}
void adaugare_tastatura(tastatura t[], int& n)
{
    cout << "Producator: "; cin >> t[n].producator;
    cout << "Model: "; cin >> t[n].model;
    cout << "Tipul: "; cin >> t[n].tip_tast;
    cout << "Iluminarea tastelor: "; cin >> t[n].iluminare;
    cout << "Nr.taste: "; cin >> t[n].nr_taste;
    cout << "Pret ($): "; cin >> t[n].pret;
    n++;
    fstream f("tastatura.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].tip_tast << " " << t[i].iluminare << " " << t[i].nr_taste << " " << t[i].pret << endl;
    }
    f.close();
}
void excludere_tastatura(tastatura t[], int& n)
{
    int k;
    afisare_tastatura(t, n);
    cout << "\nSelectati randul dorit de exclus: "; cin >> k;
    for (int i = k - 1; i < n; i++)
    {
        t[i] = t[i + 1];
    }
    n--;
    fstream f("tastatura.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].tip_tast << " " << t[i].iluminare << " " << t[i].nr_taste << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost exclus";
}
void actualizare_tastatura(tastatura t[], const int n)
{
    int k;
    afisare_tastatura(t, n);
    cout << "\nSelectati randul dorit de actualizat: "; cin >> k;
    k--;
    cout << "\nProducator: "; cin >> t[k].producator;
    cout << "Model: "; cin >> t[k].model;
    cout << "Tipul: "; cin >> t[k].tip_tast;
    cout << "Iluminarea tastelor: "; cin >> t[k].iluminare;
    cout << "Nr.taste: "; cin >> t[k].nr_taste;
    cout << "Pret ($): "; cin >> t[k].pret;
    fstream f("tastatura.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].tip_tast << " " << t[i].iluminare << " " << t[i].nr_taste << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost actualizat";
}
void extrem_tastatura_pret(tastatura t[], const int n)
{
    float maxim = -32768; int k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].pret)
        {
            maxim = t[i].pret;
            k = i;
        }
    }
    cout << "Tastatura cu cel mai mare pret:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].pret << "$" << endl;
}
void extrem_tastatura_taste(tastatura t[], const int n)
{
    int maxim = -32768, k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].nr_taste)
        {
            maxim = t[i].nr_taste;
            k = i;
        }
    }
    cout << "Tastatura cu cel mai mare numar de taste:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].nr_taste;
}
void media_tastatura_pret(tastatura t[], const int n)
{
    float med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Pretul mediu a tastaturelor: " << med / n << "$";
}
void media_tastatura_taste(tastatura t[], const int n)
{
    int med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].nr_taste;
    }
    cout << "Nr mediu de taste a tastaturilor: " << med / n;
}
struct mouse
{
    char producator[20], model[20], model_senzor[20], interf_conect[20];
    int rez_senzor, nr_chei;
    float pret;
};
void citire_mouse(mouse t[], int& n)
{
    fstream f("mouse.txt", ios::in);
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> t[i].producator >> t[i].model >> t[i].model_senzor >> t[i].interf_conect >> t[i].rez_senzor >> t[i].nr_chei >> t[i].pret;
    }
    f.close();
}
void afisare_mouse(mouse t)
{
    cout << setw(10) << t.producator << setw(13) << t.model;
    cout << setw(15) << t.model_senzor << setw(15) << t.interf_conect << setw(10) << t.rez_senzor << " DPI";
    cout << setw(16) << t.nr_chei << setw(12) << t.pret << "$" << endl;
}
void antet_mouse()
{
    cout << "Lista de mouse-uri" << endl;
    cout << "Producator" << setw(12) << "Model";
    cout << setw(13) << "Senzor" << setw(16) << "Interfata" << setw(23) << "Rezolutia sensorului";
    cout << setw(13) << "Nr.butoane" << setw(8) << "Pret" << endl;
}
void afisare_mouse(mouse t[], const int n)
{
    antet_mouse();
    for (int i = 0; i < n; i++)
    {
        afisare_mouse(t[i]);
    }
}
void sortare_mouse_mic(mouse t[], const int n)
{
    mouse aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret > t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_mouse(t, n);
}
void sortare_mouse_mare(mouse t[], const int n)
{
    mouse aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret < t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_mouse(t, n);
}
void adaugare_mouse(mouse t[], int& n)
{
    cout << "Producator: "; cin >> t[n].producator;
    cout << "Model: "; cin >> t[n].model;
    cout << "Senzor: "; cin >> t[n].model_senzor;
    cout << "Interfata de conectare: "; cin >> t[n].interf_conect;
    cout << "Rezolutia senzorului(DPI): "; cin >> t[n].rez_senzor;
    cout << "Nr.butoane: "; cin >> t[n].nr_chei;
    cout << "Pret ($): "; cin >> t[n].pret;
    n++;
    fstream f("mouse.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].model_senzor << " " << t[i].interf_conect << " " << t[i].rez_senzor << " " << t[i].nr_chei << " " << t[i].pret << endl;
    }
    f.close();
}
void excludere_mouse(mouse t[], int& n)
{
    int k;
    afisare_mouse(t, n);
    cout << "\nSelectati randul dorit de exclus: "; cin >> k;
    for (int i = k - 1; i < n; i++)
    {
        t[i] = t[i + 1];
    }
    n--;
    fstream f("mouse.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].model_senzor << " " << t[i].interf_conect << " " << t[i].rez_senzor << " " << t[i].nr_chei << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost exclus";
}
void actualizare_mouse(mouse t[], const int n)
{
    int k;
    afisare_mouse(t, n);
    cout << "\nSelectati randul dorit de actualizat: "; cin >> k;
    k--;
    cout << "\nProducator: "; cin >> t[k].producator;
    cout << "Model: "; cin >> t[k].model;
    cout << "Senzor: "; cin >> t[k].model_senzor;
    cout << "Interfata de conectare: "; cin >> t[k].interf_conect;
    cout << "Rezolutia senzorului(DPI): "; cin >> t[k].rez_senzor;
    cout << "Nr.butoane: "; cin >> t[k].nr_chei;
    cout << "Pret ($): "; cin >> t[k].pret;
    fstream f("mouse.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].model_senzor << " " << t[i].interf_conect << " " << t[i].rez_senzor << " " << t[i].nr_chei << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost actualizat";
}
void extrem_mouse_pret(mouse t[], const int n)
{
    float maxim = -32768; int k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].pret)
        {
            maxim = t[i].pret;
            k = i;
        }
    }
    cout << "Mouse-ul cu cel mai mare pret:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].pret << "$" << endl;
}
void extrem_mouse_butoane(mouse t[], const int n)
{
    int maxim = -32768, k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].nr_chei)
        {
            maxim = t[i].nr_chei;
            k = i;
        }
    }
    cout << "Mouse-ul cu cel mai mare numar de butoane:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].nr_chei;
}
void media_mouse_pret(mouse t[], const int n)
{
    float med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Pretul mediu a unui mouse: " << med / n << "$";
}
void media_mouse_butoane(mouse t[], const int n)
{
    int med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Numarul mediu de butoane a unui mouse: " << med / n;
}
struct casti
{
    char producator[20], model[20], microfon[10];
    int frc_redare, impedanta;
    float pret;
};
void citire_casti(casti t[], int& n)
{
    fstream f("casti.txt", ios::in);
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> t[i].producator >> t[i].model >> t[i].microfon >> t[i].frc_redare >> t[i].impedanta >> t[i].pret;
    }
    f.close();
}
void afisare_casti(casti t)
{
    cout << setw(10) << t.producator << setw(13) << t.model;
    cout << setw(15) << t.microfon << setw(15) << t.frc_redare << "Hz" << setw(10) << t.impedanta << "ohm";
    cout << setw(12) << t.pret << "$" << endl;
}
void antet_casti()
{
    cout << "Lista de casti" << endl;
    cout << "Producator" << setw(12) << "Model";
    cout << setw(14) << "Microfon" << setw(21) << "Frec.redare" << setw(14) << "Impedanta";
    cout << setw(9) << "Pret" << endl;
}
void afisare_casti(casti t[], const int n)
{
    antet_casti();
    for (int i = 0; i < n; i++)
    {
        afisare_casti(t[i]);
    }
}
void sortare_casti_mic(casti t[], const int n)
{
    casti aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret > t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_casti(t, n);
}
void sortare_casti_mare(casti t[], const int n)
{
    casti aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret < t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_casti(t, n);
}
void adaugare_casti(casti t[], int& n)
{
    cout << "Producator: "; cin >> t[n].producator;
    cout << "Model: "; cin >> t[n].model;
    cout << "Microfon: "; cin >> t[n].microfon;
    cout << "Frecventa de redare(Hz): "; cin >> t[n].frc_redare;
    cout << "Impedanta(ohm): "; cin >> t[n].impedanta;
    cout << "Pret ($): "; cin >> t[n].pret;
    n++;
    fstream f("casti.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].microfon << " " << t[i].frc_redare << " " << t[i].impedanta << " " << t[i].pret << endl;
    }
    f.close();
}
void excludere_casti(casti t[], int& n)
{
    int k;
    afisare_casti(t, n);
    cout << "\nSelectati randul dorit de exclus: "; cin >> k;
    for (int i = k - 1; i < n; i++)
    {
        t[i] = t[i + 1];
    }
    n--;
    fstream f("casti.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].microfon << " " << t[i].frc_redare << " " << t[i].impedanta << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost exclus";
}
void actualizare_casti(casti t[], const int n)
{
    int k;
    afisare_casti(t, n);
    cout << "\nSelectati randul dorit de actualizat: "; cin >> k;
    k--;
    cout << "\nProducator: "; cin >> t[k].producator;
    cout << "Model: "; cin >> t[k].model;
    cout << "Microfon: "; cin >> t[k].microfon;
    cout << "Frecventa de redare(Hz): "; cin >> t[k].frc_redare;
    cout << "Impedanta(ohm): "; cin >> t[k].impedanta;
    cout << "Pret ($): "; cin >> t[k].pret;
    fstream f("casti.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].producator << " " << t[i].model << " " << t[i].microfon << " " << t[i].frc_redare << " " << t[i].impedanta << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost actualizat";
}
void extrem_casti_pret(casti t[], const int n)
{
    float maxim = -32768; int k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].pret)
        {
            maxim = t[i].pret;
            k = i;
        }
    }
    cout << "Perechea de casti cu cel mai mare pret:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].pret << "$" << endl;
}
void extrem_casti_impedanta(casti t[], const int n)
{
    int maxim = -32768, k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].impedanta)
        {
            maxim = t[i].impedanta;
            k = i;
        }
    }
    cout << "Perechea de casti cu cea mai mare impedanta:" << endl;
    cout << setw(15) << t[k].producator << setw(15) << t[k].model;
    cout << setw(10) << t[k].impedanta << "ohm" << endl;
}
void media_casti_pret(casti t[], const int n)
{
    float med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Pretul mediu a castilor: " << med / n << "$";
}
void media_casti_impedanta(casti t[], const int n)
{
    int med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Impedanta medie a castilor: " << med / n << "ohm";
}
struct calculator
{
    char denumirea[20], placa_video[40], procesor[40], placa_de_baza[40], PSU[40];
    int ram;
    float pret;
};
void citire_calculator(calculator t[], int& n)
{
    fstream f("calculator.txt", ios::in);
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> t[i].denumirea >> t[i].placa_video >> t[i].procesor >> t[i].ram >> t[i].placa_de_baza >> t[i].PSU >> t[i].pret;
    }
    f.close();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(t[i].placa_video); j++)
        {
            if (t[i].placa_video[j] == '-')
            {
                t[i].placa_video[j] = ' ';
            }
        }
        for (int j = 0; j < strlen(t[i].procesor); j++)
        {
            if (t[i].procesor[j] == '-')
            {
                t[i].procesor[j] = ' ';
            }
            if (t[i].procesor[j] == '_')
            {
                t[i].procesor[j] = '-';
            }
        }
        for (int j = 0; j < strlen(t[i].PSU); j++)
        {
            if (t[i].PSU[j] == '-')
            {
                t[i].PSU[j] = ' ';
            }
            if (t[i].PSU[j] == '_')
            {
                t[i].PSU[j] = '-';
            }
        }
    }
}
void afisare_calculator(calculator t)
{
    cout <<setw(8) << t.denumirea  <<setw(28)<< t.placa_video << setw(23) << t.procesor << setw(8) << t.ram << "GB";
    cout << setw(21) << t.placa_de_baza << setw(24) << t.PSU;
    cout << setw(10) <<fixed<<setprecision(2)<< t.pret << "$" << endl;
}
void antet_calculator()
{
    cout << "Lista de calculatoare" << endl;
    cout << "Denumirea" << setw(18) <<"Placa video" << setw(23) << "Procesor" << setw(22) << "Memoria ram";
    cout << setw(18) << "Placa de baza" << setw(24) << "Sursa de alimentare";
    cout << setw(8) << "Pret" << endl;
}
void afisare_calculator(calculator t[], const int n)
{
    antet_calculator();
    for (int i = 0; i < n; i++)
    {
        afisare_calculator(t[i]);
    }
}
void sortare_calculator_mic(calculator t[], const int n)
{
    calculator aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret > t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_calculator(t, n);
}
void sortare_calculator_mare(calculator t[], const int n)
{
    calculator aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].pret < t[j].pret)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare_calculator(t, n);
}
void adaugare_calculator(calculator t[], int& n)
{
    cout << "Denumirea: "; cin >> t[n].denumirea;
    cout << "Placa video: "; cin >> t[n].placa_video;
    cout << "Procesor: "; cin >> t[n].procesor;
    cout << "Ram: "; cin >> t[n].ram;
    cout << "Placa de baza: "; cin >> t[n].placa_de_baza;
    cout << "Sursa de alimentare: "; cin >> t[n].PSU;
    cout << "Pret ($): "; cin >> t[n].pret;
    n++;
    fstream f("calculator.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].denumirea << " " << t[i].placa_video << " " << t[i].procesor << " " << t[i].ram << " " << t[i].placa_de_baza << " " << t[i].PSU << " " << t[i].pret << endl;
    }
    f.close();
}
void excludere_calculator(calculator t[], int& n)
{
    int k;
    afisare_calculator(t, n);
    cout << "\nSelectati randul dorit de exclus: "; cin >> k;
    for (int i = k - 1; i < n; i++)
    {
        t[i] = t[i + 1];
    }
    n--;
    fstream f("calculator.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].denumirea << " " << t[i].placa_video << " " << t[i].procesor << " " << t[i].ram << " " << t[i].placa_de_baza << " " << t[i].PSU << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost exclus";
}
void actualizare_calculator(calculator t[], const int n)
{
    int k;
    afisare_calculator(t, n);
    cout << "\nSelectati randul dorit de actualizat: "; cin >> k;
    k--;
    cout << "Denumirea: "; cin >> t[k].denumirea;
    cout << "Placa video: "; cin >> t[k].placa_video;
    cout << "Procesor: "; cin >> t[k].procesor;
    cout << "Ram: "; cin >> t[k].ram;
    cout << "Placa de baza: "; cin >> t[k].placa_de_baza;
    cout << "Sursa de alimentare: "; cin >> t[k].PSU;
    cout << "Pret ($): "; cin >> t[k].pret;
    fstream f("calculator.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << t[i].denumirea << " " << t[i].placa_video << " " << t[i].procesor << " " << t[i].ram << " " << t[i].placa_de_baza << " " << t[i].PSU << " " << t[i].pret << endl;
    }
    f.close();
    system("cls");
    cout << "Sirul a fost actualizat";
}
void extrem_calculator_pret(calculator t[], const int n)
{
    float maxim = -32768; int k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].pret)
        {
            maxim = t[i].pret;
            k = i;
        }
    }
    cout << "Calculatorul cu cel mai mare pret:" << endl;
    cout << setw(15) << t[k].denumirea << setw(10) << t[k].pret << "$" << endl;
}
void extrem_calculator_ram(calculator t[], const int n)
{
    int maxim = -32768, k;
    for (int i = 0; i < n; i++)
    {
        if (maxim < t[i].ram)
        {
            maxim = t[i].ram;
            k = i;
        }
    }
    cout << "Calculatorul cu cel mai mare pret:" << endl;
    cout << setw(15) << t[k].denumirea << setw(10) << t[k].ram << "GB" << endl;
}
void media_calculator_pret(calculator t[], const int n)
{
    float med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].pret;
    }
    cout << "Pretul mediu a calculatoarelor: " << med / n << "$";
}
void media_calculator_ram(calculator t[], const int n)
{
    int med = 0;
    for (int i = 0; i < n; i++)
    {
        med += t[i].ram;
    }
    cout << "Mamoria ram medie a calculatoarelor: " << med / n << "GB";
}
void save_video(placa_video t[], const int n, string save)
{
    fstream f(save, ios::out);
    f << "Lista de placi video" << endl;
    f << setw(15) << "Producator" << " " << setw(15) << "Model";
    f << setw(20) << "Tip de memorie" << setw(10) << "Memorie" << setw(8) << " TDP" << setw(13) << "Frecventa";
    f << setw(8) << "\tPret" << endl;
    for (int i = 0; i < n; i++)
    {
        f << setw(15) << t[i].producator << setw(15) << t[i].model;
        f << setw(15) << t[i].tip_mem << setw(15) << t[i].memoria << setw(9) << t[i].tdp << 'W' << setw(10) << t[i].frecventa << "MHz";
        f << setw(10) << t[i].pret << "$" << endl;
    }
    f.close();
    cout << "Fisierul a fost salvat"; _getch();
}
void save_procesor(procesor t[], const int n, string save)
{
    fstream f(save, ios::out);
    f << "Lista procesoarelor" << endl;
    f << "Producator" << setw(15) << "Model";
    f << setw(18) << "Socket" << setw(10) << "Nucleu" << setw(15) << "Frecventa" << setw(13) << "Nr.nuclee" << setw(13) << "Nr.fire";
    f << setw(8) << "Pret" << endl;
    for (int i = 0; i < n; i++)
    {
        f << setw(9) << t[i].producator << setw(19) << t[i].model;
        f << setw(15) << t[i].socket << setw(14) << t[i].nucleu << setw(8) << t[i].frecventa << "MHz" << setw(10) << t[i].nr_nuc << setw(15) << t[i].nr_fir;
        f << setw(8) << t[i].pret << "$" << endl;
    }
    f.close();
    cout << "Fisierul a fost salvat"; _getch();
}
void save_placa(placa_de_baza t[], const int n, string save)
{
    fstream f(save, ios::out);
    f << "Lista placilor de baza" << endl;
    f << "Producator" << setw(8) << "Model";
    f << setw(13) << "Socket" << setw(12) << "Chipset" << setw(17) << "Tip ram" << setw(10) << "Max ram";
    f << setw(8) << "Pret" << endl;
    for (int i = 0; i < n; i++)
    {
        f << setw(8) << t[i].producator << setw(10) << t[i].model;
        f << setw(15) << t[i].socket << setw(14) << t[i].chipset << setw(10) << t[i].tip_ram << setw(10) << t[i].max_ram << "GB";
        f << setw(9) << t[i].pret << "$" << endl;
    }
    f.close();
    cout << "Fisierul a fost salvat"; _getch();
}
void save_ram(ram t[], const int n, string save)
{
    fstream f(save, ios::out);
    f << "Lista placutelor de memorie" << endl;
    f << setw(10) << "Producator" << setw(10) << "Model";
    f << setw(11) << "Tipul" << setw(11) << "Frecventa" << setw(12) << "Volumul";
    f << setw(10) << "Pret" << endl;
    for (int i = 0; i < n; i++)
    {
        f << setw(8) << t[i].producator << setw(15) << t[i].model;
        f << setw(8) << t[i].tip << setw(8) << t[i].frecventa << "MHz" << setw(8) << t[i].volum << "GB";
        f << setw(11) << t[i].pret << "$" << endl;
    }
    f.close();
    cout << "Fisierul a fost salvat"; _getch();
}
void save_monitor(monitor t[], const int n, string save)
{
    fstream f(save, ios::out);
    f << "Lista de monitoare" << endl;
    f << setw(15) << "Producator" << setw(10) << "Model";
    f << setw(13) << "Frecventa" << setw(12) << "Diagonala " << setw(15);
    f << setw(13) << "Rezolutia" << setw(11) << "Pret" << endl;
    for (int i = 0; i < n; i++)
    {
        f << setw(15) << t[i].producator << setw(10) << t[i].model;
        f << setw(10) << t[i].frecventa << "Hz" << setw(9) << t[i].diagonala << '"';
        f << setw(12) << t[i].rezolutia_1 << setw(2) << t[i].x << setw(5) << t[i].rezolutia_2 << " " << setw(8) << t[i].pret << "$" << endl;
    }
    f.close();
    cout << "Fisierul a fost salvat"; _getch();
}
void save_tastatura(tastatura t[], const int n, string save)
{
    fstream f(save, ios::out);
    f << "Lista de tastature" << endl;
    f << "Producator" << setw(12) << "Model";
    f << setw(13) << "Tipul" << setw(16) << "Iluminare " << setw(15);
    f << setw(13) << "Nr.taste" << setw(8) << "Pret" << endl;
    for (int i = 0; i < n; i++)
    {
        f << setw(10) << t[i].producator << setw(13) << t[i].model;
        f << setw(15) << t[i].tip_tast << setw(9) << t[i].iluminare;
        f << setw(12) << t[i].nr_taste << setw(12) << t[i].pret << "$" << endl;
    }
    f.close();
    cout << "Fisierul a fost salvat"; _getch();
}
void save_mouse(mouse t[], const int n, string save)
{
    fstream f(save, ios::out);
    f << "Lista de mouse-uri" << endl;
    f << "Producator" << setw(12) << "Model";
    f << setw(13) << "Senzor" << setw(16) << "Interfata" << setw(23) << "Rezolutia sensorului";
    f << setw(13) << "Nr.butoane" << setw(8) << "Pret" << endl;
    for (int i = 0; i < n; i++)
    {
        f << setw(10) << t[i].producator << setw(13) << t[i].model;
        f << setw(15) << t[i].model_senzor << setw(15) << t[i].interf_conect << setw(10) << t[i].rez_senzor << "DPI";
        f << setw(16) << t[i].nr_chei << setw(12) << t[i].pret << "$" << endl;
    }
    f.close();
    cout << "Fisierul a fost salvat"; _getch();
}
void save_casti(casti t[], const int n, string save)
{
    fstream f(save, ios::out);
    f << "Lista de casti" << endl;
    f << "Producator" << setw(12) << "Model";
    f << setw(14) << "Microfon" << setw(21) << "Frec.redare" << setw(14) << "Impedanta";
    f << setw(9) << "Pret" << endl;
    for (int i = 0; i < n; i++)
    {
        f << setw(10) << t[i].producator << setw(13) << t[i].model;
        f << setw(15) << t[i].microfon << setw(15) << t[i].frc_redare << "Hz" << setw(10) << t[i].impedanta << "ohm";
        f << setw(12) << t[i].pret << "$" << endl;
    }
    f.close();
    cout << "Fisierul a fost salvat"; _getch();
}
void save_calculator(calculator t[], const int n, string save)
{
    fstream f(save, ios::out);
    f << "Lista de calculatoare" << endl;
    f << "Denumirea" << setw(18) << "Placa video" << setw(23) << "Procesor" << setw(22) << "Memoria ram";
    f << setw(18) << "Placa de baza" << setw(24) << "Sursa de alimentare";
    f << setw(8) << "Pret" << endl;
    for (int i = 0; i < n; i++)
    {
        f << setw(8) << t[i].denumirea << setw(28) << t[i].placa_video << setw(23) << t[i].procesor << setw(8) << t[i].ram << "GB";
        f << setw(21) << t[i].placa_de_baza << setw(24) << t[i].PSU;
        f << setw(10) << fixed << setprecision(2) << t[i].pret << "$" << endl;
    }
    f.close();
    cout << "Fisierul a fost salvat"; _getch();
}