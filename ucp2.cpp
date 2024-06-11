#include <iostream>
#include <vector>
using namespace std;

class team; // Forward declaration

class sponsor {
    public:
        string namaSponsor;
        vector<team*> daftar_sponsor;
        sponsor(string pNama) : namaSponsor(pNama) {
            cout << "Sponsor \"" << namaSponsor << "\" ada\n";
        }
        ~sponsor() {
            cout << "Sponsor \"" << namaSponsor << "\" tidak ada\n";
        }
        void tambahTeam(team*);
        void cetakTeam();
};

class team {
    public:
        string namaTeam;
        vector<sponsor*> daftar_sponsor;

        team(string pNama) : namaTeam(pNama) {
            cout << "Team \"" << namaTeam << "\" ada\n";
        }
        ~team() {
            cout << "Team \"" << namaTeam << "\" tidak ada\n";
        }
        void tambahSponsor(sponsor*);
        void cetakSponsor();
};

void sponsor::tambahTeam(team* pSponsor) {
    daftar_sponsor.push_back(pSponsor);
}

void sponsor::cetakTeam() {
    cout << "Nama Team dari Sponsor \"" << this->namaSponsor << "\":\n";
    for (auto& a : daftar_sponsor) {
        cout << a->namaTeam << "\n";
    }
    cout << endl;
}

void team::tambahSponsor(sponsor* pSponsor) {
    daftar_sponsor.push_back(pSponsor);
    pSponsor->tambahTeam(this);
}

void team::cetakSponsor() {
    cout << "Nama Sponsor dari Team \"" << this->namaTeam << "\":\n";
    for (auto& a : daftar_sponsor) {
        cout << a->namaSponsor << "\n";
    }
    cout << endl;
}

int main() {
    team* varTeam1 = new team("Onic Esport");
    team* varTeam2 = new team("Evos Esport");
    sponsor* varSponsor1 = new sponsor("Leica");
    sponsor* varSponsor2 = new sponsor("Nike");
    sponsor* varSponsor3 = new sponsor("Samsung");
    

    varTeam1->tambahSponsor(varSponsor1);
    varTeam1->tambahSponsor(varSponsor2);
    varTeam1->tambahSponsor(varSponsor3);
    
    varTeam2->tambahSponsor(varSponsor3);
    varTeam2->tambahSponsor(varSponsor1);

    varSponsor1->tambahTeam(varTeam1);
    varSponsor1->tambahTeam(varTeam2);

    
    varTeam1->cetakSponsor();
    varTeam2->cetakSponsor();
    varSponsor1->cetakTeam();
 
  

    delete varSponsor1;
    delete varSponsor2;
    delete varTeam1;
    delete varTeam2;

    return 0;
}
