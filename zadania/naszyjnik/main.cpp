#include <bits/stdc++.h>
using namespace std;
string k = "aAeEiIoOuUyY";
bool sam(char p)
{
    for (int i = 0; i < 13; i++)
        if (p == k[i])
            return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string ciag;
    while (t--)
    {
        int wynik = -1, pom = 1, mwynik = 2147483646, last, por, rop, start = 0;
        cin >> ciag;
        int n = ciag.length();
        string maly, duzy;

        if (ciag[n - 1] > 96 && sam(ciag[n - 1]))
            rop = 1;
        if (ciag[n - 1] > 96 && !sam(ciag[n - 1]))
            rop = 2;
        if (ciag[n - 1] < 96 && sam(ciag[n - 1]))
            rop = 3;
        if (ciag[n - 1] < 96 && !sam(ciag[n - 1]))
            rop = 4;
        if (n == 1)
        {
            if (rop == 1)
            {
                cout << 1 << " "
                     << "jasne"
                     << "\n" << 1 << " "
                     << "jasne"
                     << "\n";
                continue;
            }
            if (rop == 2)
            {
                cout << 1 << " "
                     << "ciemne"
                     << "\n" << 1 << " "
                     << "ciemne"
                     << "\n";
                continue;
            }
            if (rop == 3)
            {
                cout << 1 << " "
                     << "JASNE"
                     << "\n" << 1 << " "
                     << "JASNE"
                     << "\n";
                continue;
            }
            if (rop == 4)
            {
                cout << 1 << " "
                     << "CIEMNE"
                     << "\n" << 1 << " "
                     << "CIEMNE"
                     << "\n";
                continue;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ciag[i] > 96 && sam(ciag[i]))
                por = 1;
            if (ciag[i] > 96 && !sam(ciag[i]))
                por = 2;
            if (ciag[i] < 96 && sam(ciag[i]))
                por = 3;
            if (ciag[i] < 96 && !sam(ciag[i]))
                por = 4;

            if (por != rop)
            {
                start = i;
                break;
            }
            if (i == n - 1)
                start = 0;
        }
        rop = 0;
        if (ciag[start] > 96 && sam(ciag[start]))
            rop = 1;
        if (ciag[start] > 96 && !sam(ciag[start]))
            rop = 2;
        if (ciag[start] < 96 && sam(ciag[start]))
            rop = 3;
        if (ciag[start] < 96 && !sam(ciag[start]))
            rop = 4;
        last = rop;
        for (int i = start + 1; i < n; i++)
        {
            if (ciag[i] > 96 && sam(ciag[i]))
                por = 1;
            if (ciag[i] > 96 && !sam(ciag[i]))
                por = 2;
            if (ciag[i] < 96 && sam(ciag[i]))
                por = 3;
            if (ciag[i] < 96 && !sam(ciag[i]))
                por = 4;


            if (por != last)
            {
                if (ciag[i - 1] > 96 && !sam(ciag[i - 1]) && pom > wynik)
                    duzy = "ciemne";
                if (ciag[i - 1] > 96 && !sam(ciag[i - 1]) && pom == mwynik && maly != "JASNE"
                    && maly != "CIEMNE" && maly != "jasne")
                    maly = "ciemne";
                if (ciag[i - 1] > 96 && !sam(ciag[i - 1]) && pom == wynik && duzy != "JASNE"
                    && duzy != "CIEMNE" && duzy != "jasne")
                    duzy = "ciemne";
                if (ciag[i - 1] > 96 && !sam(ciag[i - 1]) && pom < mwynik)
                    maly = "ciemne";
                if (ciag[i - 1] > 96 && sam(ciag[i - 1]) && pom > wynik)
                    duzy = "jasne";
                if (ciag[i - 1] > 96 && sam(ciag[i - 1]) && pom == wynik && duzy != "JASNE"
                    && duzy != "CIEMNE")
                    duzy = "jasne";
                if (ciag[i - 1] > 96 && sam(ciag[i - 1]) && pom < mwynik)
                    maly = "jasne";
                if (ciag[i - 1] > 96 && sam(ciag[i - 1]) && pom == mwynik && maly != "JASNE"
                    && maly != "CIEMNE")
                    maly = "jasne";
                if (ciag[i - 1] < 96 && !sam(ciag[i - 1]) && pom > wynik)
                    duzy = "CIEMNE";
                if (ciag[i - 1] < 96 && !sam(ciag[i - 1]) && pom == wynik && duzy != "JASNE")
                    duzy = "CIEMNE";
                if (ciag[i - 1] < 96 && !sam(ciag[i - 1]) && pom < mwynik)
                    maly = "CIEMNE";
                if (ciag[i - 1] < 96 && !sam(ciag[i - 1]) && pom == mwynik && maly != "JASNE")
                    maly = "CIEMNE";
                if (ciag[i - 1] < 96 && sam(ciag[i - 1]) && pom >= wynik)
                    duzy = "JASNE";
                if (ciag[i - 1] < 96 && sam(ciag[i - 1]) && pom <= mwynik)
                    maly = "JASNE";


                wynik = max(wynik, pom);
                mwynik = min(mwynik, pom);
                last = por;
                pom = 1;
            }
            else
                pom++;

            if (i == n - 1)
            {
                int wtf = por, kl = 0;
                while (wtf == por && kl <= start)
                {
                    if (ciag[kl] > 96 && sam(ciag[kl]))
                        por = 1;
                    if (ciag[kl] > 96 && !sam(ciag[kl]))
                        por = 2;
                    if (ciag[kl] < 96 && sam(ciag[kl]))
                        por = 3;
                    if (ciag[kl] < 96 && !sam(ciag[kl]))
                        por = 4;
                    kl++;
                    pom++;
                    if (kl == 1)
                        pom--;
                }
                if (ciag[i] > 96 && !sam(ciag[i]) && pom > wynik)
                    duzy = "ciemne";
                if (ciag[i] > 96 && !sam(ciag[i]) && pom == wynik && duzy != "JASNE"
                    && duzy != "CIEMNE" && duzy != "jasne")
                    duzy = "ciemne";
                if (ciag[i] > 96 && !sam(ciag[i]) && pom < mwynik)
                    maly = "ciemne";
                if (ciag[i] > 96 && !sam(ciag[i]) && pom == mwynik && maly != "JASNE"
                    && maly != "CIEMNE" && maly != "jasne")
                    maly = "ciemne";
                if (ciag[i] > 96 && sam(ciag[i]) && pom > wynik)
                    duzy = "jasne";
                if (ciag[i] > 96 && sam(ciag[i]) && pom == wynik && duzy != "JASNE"
                    && duzy != "CIEMNE")
                    duzy = "jasne";
                if (ciag[i] > 96 && sam(ciag[i]) && pom < mwynik)
                    maly = "jasne";
                if (ciag[i] > 96 && sam(ciag[i]) && pom == mwynik && maly != "JASNE"
                    && maly != "CIEMNE")
                    maly = "jasne";
                if (ciag[i] < 96 && !sam(ciag[i]) && pom > wynik)
                    duzy = "CIEMNE";
                if (ciag[i] < 96 && !sam(ciag[i]) && pom == wynik && duzy != "JASNE")
                    duzy = "CIEMNE";
                if (ciag[i] < 96 && !sam(ciag[i]) && pom < mwynik)
                    maly = "CIEMNE";
                if (ciag[i] < 96 && !sam(ciag[i]) && pom == mwynik && maly != "JASNE")
                    maly = "CIEMNE";
                if (ciag[i] < 96 && sam(ciag[i]) && pom >= wynik)
                    duzy = "JASNE";
                if (ciag[i] < 96 && sam(ciag[i]) && pom <= mwynik)
                    maly = "JASNE";


                wynik = max(wynik, pom);
                mwynik = min(mwynik, pom);
            }
        }
        cout << wynik << " " << duzy << "\n";
        cout << mwynik << " " << maly << "\n";
    }
    return 0;
}
