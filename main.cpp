#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<string,int>> amountMoney;


void vectorPrint(){
    for(auto it=amountMoney.begin();it != amountMoney.end();++it)
        cout<<it->first<<" "<<it->second<<endl;
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

    string Id;
    string Person;

    int costGift;
    int totalPerson;
    int costForPerson;

    bool firstGroup=true;

    while (cin >> numPerson) {

        for (int i = 0; i < numPerson; ++i) {
            cin >> Id;
            amountMoney.emplace_back(Id,0);
        }

        for (int i = 0; i < numPerson; ++i) {
            cin >> Id >> costGift >> totalPerson;

            if(totalPerson!=0){
                costForPerson = costGift / totalPerson;

                modify(Id,costForPerson*totalPerson,false);

                for (int j = 0; j < totalPerson; ++j) {
                    cin >> Person;
                    modify(Person,costForPerson,true);
                }
            
            }

        }

        if(!firstGroup) cout<<endl;

        vectorPrint();
        firstGroup = false;

        amountMoney.clear();

    }
    return 0;
}
