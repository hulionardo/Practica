using namespace std;
struct monitor
{
    char producator[20], model[20], x;
    int frecventa, rezolutia_1,rezolutia_2, v_raspuns;
    float pret, diagonala;
};
void citire(monitor t[], int& n)
{
    fstream f("date.in.txt", ios::in);
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> t[i].producator >> t[i].model >> t[i].frecventa >> t[i].rezolutia_1 >> t[i].x >> t[i].rezolutia_2 >> t[i].diagonala >> t[i].v_raspuns >> t[i].pret;
    }
    f.close();
}
void afisare(monitor t)
{
    cout << setw(15) << t.producator << setw(10) << t.model;
    cout << setw(10) << t.frecventa << "Hz" << setw(13) << t.v_raspuns << "ms" << setw(13) << t.diagonala << '"';
    cout << setw(12) << t.rezolutia_1 << setw(2) << t.x << setw(5) << t.rezolutia_2 << " " << setw(8) << t.pret << "$" << endl;
}
void antet()
{
    cout << "Lista de monitoare" << endl;
    cout << setw(15) << "Producator" << setw(10) << "Model";
    cout << setw(13) << "Frecventa" << setw(20) << "Viteza de raspuns " << setw(12) << "Diagonala " << setw(15);
    cout << setw(13) << "Rezolutia"<<setw(11) << "Pret" << endl;
}
void afisare(monitor t[], const int n)
{
    antet();
    for (int i = 0; i < n; i++)
    {
        afisare(t[i]);
    }
}
void sortare_frc(monitor t[], const int n)
{
    monitor aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].frecventa > t[j].frecventa)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare(t, n);
}
void sortare_v(monitor t[], const int n)
{
    monitor aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].v_raspuns > t[j].v_raspuns)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare(t, n);
}
void sortare_diag(monitor t[], const int n)
{
    monitor aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].diagonala > t[j].diagonala)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare(t, n);
}
void sortare_rez(monitor t[], const int n)
{
    monitor aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].rezolutia_1 * t[i].rezolutia_2 > t[j].rezolutia_1 * t[j].rezolutia_2)
            {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    afisare(t, n);
}
void sortare_pret(monitor t[], const int n)
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
    afisare(t, n);
}
void search_frec(monitor t[], const int n)
{
    int a;
    cout << "Introduceti frecvnta (Hz): "; cin >> a;
    antet();
    for (int i = 0; i < n; i++)
    {
        if (a == t[i].frecventa)
        {
            afisare(t[i]);
        }
    }
}
void search_vrsp(monitor t[], const int n)
{
    int a;
    cout << "Introduceti viteza de raspuns (ms): "; cin >> a;
    antet();
    for (int i = 0; i < n; i++)
    {
        if (a == t[i].v_raspuns)
        {
            afisare(t[i]);
        }
    }
}
void search_diag(monitor t[], const int n)
{
    float a;
    cout << "Introduceti diagonala (inch): "; cin >> a;
    antet();
    for (int i = 0; i < n; i++)
    {
        if (a == t[i].diagonala)
        {
            afisare(t[i]);
        }
    }
}
void search_prod(monitor t[], const int n)
{
    char a[20];
    cout << "Introduceti producatorul: "; cin >> a;
    antet();
    for (int i = 0; i < n; i++)
    {
        if (_strcmpi(a, t[i].producator) == 0)
        {
            afisare(t[i]);
        }
    }
}
void search_pret(monitor t[], const int n)
{
    float a, b;
    cout << "Pret minim: "; cin >> a;
    cout << "Pret maxim: "; cin >> b;
    antet();
    for (int i = 0; i < n; i++)
    {
        if (t[i].pret <= b && t[i].pret >= a)
        {
            afisare(t[i]);
        }
    }
}
void flt_frc(monitor t[], const int n)
{
    cout << "Lista de monitoare" << endl;
    cout << setw(15) << "Producator" << setw(10) << "Model";
    cout << setw(13) << "Frecventa" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << t[i].producator << setw(10) << t[i].model;
        cout << setw(10) << t[i].frecventa << "Hz" << endl;
    }
}
void flt_vrsp(monitor t[], const int n)
{
    cout << "Lista de monitoare" << endl;
    cout << setw(15) << "Producator" << setw(10) << "Model";
    cout << setw(20) << "Viteza de raspuns" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << t[i].producator << setw(10) << t[i].model;
        cout << setw(10) << t[i].v_raspuns << "ms" << endl;
    }
}
void flt_diag(monitor t[], const int n)
{
    cout << "Lista de monitoare" << endl;
    cout << setw(15) << "Producator" << setw(10) << "Model";
    cout << setw(13) << "Diagonala" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << t[i].producator << setw(10) << t[i].model;
        cout << setw(10) << t[i].diagonala << '"' << endl;
    }
}
void flt_rez(monitor t[], const int n)
{
    cout << "Lista de monitoare" << endl;
    cout << setw(15) << "Producator" << setw(10) << "Model";
    cout << setw(13) << "Rezolutie" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << t[i].producator << setw(10) << t[i].model;
        cout << setw(10) << t[i].rezolutia_1 << t[i].x << t[i].rezolutia_2 << endl;
    }
}
void flt_pret(monitor t[], const int n)
{
    cout << "Lista de monitoare" << endl;
    cout << setw(15) << "Producator" << setw(10) << "Model";
    cout << setw(10) << "Pret" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << t[i].producator << setw(10) << t[i].model;
        cout << setw(10) << t[i].pret << "$" << endl;
    }
}
void adaugare(monitor t[], int &n)
{
    cout << "Producator: "; cin >> t[n].producator;
    cout << "Model: "; cin >> t[n].model;
    cout << "Frecventa (Hz): "; cin >> t[n].frecventa;
    cout << "Viteza de raspuns (ms): "; cin >> t[n].v_raspuns;
    cout << "Diagonala (inch): "; cin >> t[n].diagonala;
    cout << "Rezolutia (Ex: 1920 x 1080): "; cin >> t[n].rezolutia_1 >> t[n].x >> t[n].rezolutia_2;
    cout << "Pret ($): "; cin >> t[n].pret;
    n++;
}
void excludere(monitor t[], int &n)
{
    int k;
    afisare(t, n);
    cout << "\nSelectati randul monitorului dorit de exclus: "; cin >> k;
    for (int i = k-1; i < n; i++)
    {
        t[i] = t[i + 1];
    }
    n--;
}
void salvare(monitor t[], const int n)
{
    fstream g;
    string nume;
    cout << "Introduceti denumirea fisierului: "; cin >> nume;
    g.open (nume, ios::out);
    g << "Lista de monitoare" << endl;
    g << setw(15) << "Producator" << setw(10) << "Model";
    g << setw(13) << "Frecventa" << setw(20) << "Viteza de raspuns " << setw(12) << "Diagonala " << setw(15);
    g << setw(13) << "Rezolutia" << setw(9) << "Pret" << endl;
    for (int i = 0; i < n; i++)
    {
        g << setw(15) << t[i].producator << setw(10) << t[i].model;
        g << setw(10) << t[i].frecventa << "Hz" << setw(13) << t[i].v_raspuns << "ms" << setw(13) << t[i].diagonala << '"';
        g << setw(13) << t[i].rezolutia_1 << setw(2) << t[i].x << setw(5) << t[i].rezolutia_2 << " " << setw(8) << t[i].pret << "$" << endl;
    }
    g.close();

}
