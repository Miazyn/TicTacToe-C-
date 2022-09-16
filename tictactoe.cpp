#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> spielfeldKasten = {" ", " ", " "," ", " ", " "," ", " ", " "};

void SpielfeldKreation()
{
    cout << "\n";
    for(int i = 0; i < 9; i++)
    {
        cout << "|" << spielfeldKasten[i];
        if(i%3 == 2){
            cout << "|" << endl;
            //cout << "-------" << endl;
        }
    }
}

string WerHatGewonnen()
{
    if(spielfeldKasten[0] == "x" && spielfeldKasten[1] == "x" && spielfeldKasten[2] == "x" ||
            spielfeldKasten[3] == "x" && spielfeldKasten[4] == "x" && spielfeldKasten[5] == "x"||
            spielfeldKasten[6] == "x" && spielfeldKasten[7] == "x" && spielfeldKasten[8] == "x"||
            spielfeldKasten[0] == "x" && spielfeldKasten[4] == "x" && spielfeldKasten[8] == "x"||
            spielfeldKasten[2] == "x" && spielfeldKasten[4] == "x" && spielfeldKasten[6] == "x"||
            spielfeldKasten[0] == "x" && spielfeldKasten[3] == "x" && spielfeldKasten[6] == "x"||
            spielfeldKasten[1] == "x" && spielfeldKasten[4] == "x" && spielfeldKasten[7] == "x"||
            spielfeldKasten[2] == "x" && spielfeldKasten[5] == "x" && spielfeldKasten[8] == "x")
    {
            return "x";   
    }
    if(spielfeldKasten[0] == "o" && spielfeldKasten[1] == "o" && spielfeldKasten[2] == "o" ||
            spielfeldKasten[3] == "o" && spielfeldKasten[4] == "o" && spielfeldKasten[5] == "o"||
            spielfeldKasten[6] == "o" && spielfeldKasten[7] == "o" && spielfeldKasten[8] == "o" ||
            spielfeldKasten[0] == "o" && spielfeldKasten[4] == "o" && spielfeldKasten[8] == "o"||
            spielfeldKasten[2] == "o" && spielfeldKasten[4] == "o" && spielfeldKasten[6] == "o"||
            spielfeldKasten[0] == "o" && spielfeldKasten[3] == "o" && spielfeldKasten[6] == "o"||
            spielfeldKasten[1] == "o" && spielfeldKasten[4] == "o" && spielfeldKasten[7] == "o"||
            spielfeldKasten[2] == "o" && spielfeldKasten[5] == "o" && spielfeldKasten[8] == "o")
    {
            return "o";   
    }

    return "Kein";
}

bool GibtEsGewinner()
{
    if(spielfeldKasten[0] == "x" && spielfeldKasten[1] == "x" && spielfeldKasten[2] == "x" ||
        spielfeldKasten[3] == "x" && spielfeldKasten[4] == "x" && spielfeldKasten[5] == "x"||
        spielfeldKasten[6] == "x" && spielfeldKasten[7] == "x" && spielfeldKasten[8] == "x"||
        spielfeldKasten[0] == "x" && spielfeldKasten[4] == "x" && spielfeldKasten[8] == "x"||
        spielfeldKasten[2] == "x" && spielfeldKasten[4] == "x" && spielfeldKasten[6] == "x"||
        spielfeldKasten[0] == "x" && spielfeldKasten[3] == "x" && spielfeldKasten[6] == "x"||
        spielfeldKasten[1] == "x" && spielfeldKasten[4] == "x" && spielfeldKasten[7] == "x"||
        spielfeldKasten[2] == "x" && spielfeldKasten[5] == "x" && spielfeldKasten[8] == "x")
    {
         return true;   
    }
    if(spielfeldKasten[0] == "o" && spielfeldKasten[1] == "o" && spielfeldKasten[2] == "o" ||
        spielfeldKasten[3] == "o" && spielfeldKasten[4] == "o" && spielfeldKasten[5] == "o"||
        spielfeldKasten[6] == "o" && spielfeldKasten[7] == "o" && spielfeldKasten[8] == "o"||
        spielfeldKasten[0] == "o" && spielfeldKasten[4] == "o" && spielfeldKasten[8] == "o"||
        spielfeldKasten[2] == "o" && spielfeldKasten[4] == "o" && spielfeldKasten[6] == "o"||
        spielfeldKasten[0] == "o" && spielfeldKasten[3] == "o" && spielfeldKasten[6] == "o"||
        spielfeldKasten[1] == "o" && spielfeldKasten[4] == "o" && spielfeldKasten[7] == "o"||
        spielfeldKasten[2] == "o" && spielfeldKasten[5] == "o" && spielfeldKasten[8] == "o")
    {
         return true;   
    }

    return false;

}

bool IstEsUnentschieden(){

    for(int i = 0; i < spielfeldKasten.size(); i++)
    {
        if(spielfeldKasten[i] == " "){
            return false;
        }
    }
    return true;

}

int main(int argc, const char * argv[])
{
    bool spielerTurn = true;

    SpielfeldKreation();
    while(true){

        int eingabe;
        if(spielerTurn)
        {
            cout << "Es ist x-Spielers Zug." << endl;
        }else{
            cout << "Es ist o-Spielers Zug." << endl;
        }
        
        cout << "\nSelect one from the above." << endl;

        cout << "1 | 2 | 3 \n4 | 5 | 6\n7 | 8 | 9" << endl;

        cin >> eingabe;
        cin.clear();
        cin.ignore();

        if(eingabe == 0)
        {
            SpielfeldKreation();
            continue;
        }
        
        eingabe -=1;
        if(spielfeldKasten[eingabe] == " "){
            if(spielerTurn)
            {
                spielfeldKasten[eingabe] = "x";
            }else{
                spielfeldKasten[eingabe] = "o";
            }
        }
        else
        {
            SpielfeldKreation();
            cout << "\nBitte ein unbelegtes Feld auswaehlen." << endl;
            
            continue;
        }
        
        spielerTurn = !spielerTurn;

        SpielfeldKreation();

        if(GibtEsGewinner() == 1)
        {
            cout << "\n!!!\nEs gibt einen Gewinner." << endl;
            break;
        }
        else if(IstEsUnentschieden() == 1)
        {
            cout << "\nDiesmal hat niemand gewonnen...Schade." << endl;
            break;
        }

        
    }

    cout << WerHatGewonnen() << " Spieler hat gewonnen.";

}