#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<string,int>> amountMoney;


void mapPrint(){

    for(auto it=amountMoney.begin();it != amountMoney.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }

}

void modify(string id, int amount, bool incrementar){
    for(auto it=amountMoney.begin(); it!= amountMoney.end();++it){
        if(it->first == id){
            if(incrementar) it->second+=amount;
            else it->second-=amount;
        }
    }
}

int main() {
    int numPerson;

    string Identificador;
    string Person;

    int costGift;
    int cantPerson;
    int extra;
    int costForPerson;

    bool firstGroup=true;

    while (cin >> numPerson) {

        for (int i = 0; i < numPerson; ++i) {
            cin >> Identificador;
            amountMoney.push_back(pair<string, int>(Identificador, 0));
        }

        for (int i = 0; i < numPerson; ++i) {
            cin >> Identificador>>costGift>>cantPerson;

            if(cantPerson!=0){
                modify(Identificador,costGift,false);

                costForPerson = costGift / cantPerson;
                extra = costGift - costForPerson*cantPerson;

                if(extra != 0 ) modify(Identificador,extra,true);

                for (int j = 0; j < cantPerson; ++j) {
                    cin >> Person;
                    modify(Person,costForPerson,true);
                }
            }

        }

        if(!firstGroup) cout<<endl;

        mapPrint();
        firstGroup = false;

        amountMoney.clear();

    }
    return 0;
}
