#include <iostream>
#include <vector>
using namespace std;


class Player {
private:
	string name;
	int health;
	int damage;

public:
	Player(string n,int healt,int dmg):name(n),health(healt),damage(dmg){}

	string GetName() { //getter
		return name;
	}
	int GetHealth() {

		return health; //getter

	}
	int GetDmg() {
		return damage;  //getter
	}
	void TakeDmg(int dmg) {

		if (dmg > health) {
			health = 0;       //health never 0
		}
		else
			health -= dmg;  // health = initial healt -dmg
	}
	void Attack(Player& target) {   //functia ataca , cu referinta la playe
		target.TakeDmg(damage);
	}
	bool Alive() {
		return health > 0;  //check if its Alive 
	}

	void ShowStatus()const {
		cout << name<< "HP:" << health << " " << "DMG:" << damage;  //check status Player
	}
};



int main()
{
	
	Player p1("Ion",  100, 100);
	Player p2("Marin",  100, 6);
	while (p1.Alive() && p2.Alive()) {
		int cmd;
		cout << "Introdu 1 ca ion sa atace";
		cout << endl;
		cout << "Introdu 2 ca Marin sa atace";
		cout << endl;
		cout << "Introdu 0 pentru a incheia programul";
		cout << endl;
		cin >> cmd;
		if (cmd == 1) {
			p1.Attack(p2);
			cout << "Ion il ataca pe Marin!";
			cout << endl;
			p2.ShowStatus();                                 //game loop
			cout << endl;
		}


		if (cmd == 2) {
			p2.Attack(p1);
			cout << "Marin il ataca pe Ion!";
			cout << endl;
			p1.ShowStatus();
			cout << endl;
		}
		if (cmd == 0) {
			cout << "Program inchis cu succes!";
			break;
		}
	
	}

	if (!p1.Alive()) {
		cout << "Ion a murit!Marin a castigat lupta!";
	}
	else  if(!p2.Alive())
		cout << "Marin a murit!Ion a castigat!";



}

