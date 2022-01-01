#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
void main()
{
	cout << "Russian roulette is a game of chance,the risk is the player's life, not money.";
	cout << "The game is played with a revolver with a single bullet.";
	cout << "Players spin the cylinder in turns, put the muzzle against their head and pull the trigger.";
	cout << "The player has 16.67% chances of firing a bullet into his head.";
	cout << "Thus each player has an equal chance of being killed by the bullet.";
	char select;
	int chamber; 
	srand(time(NULL)); 

	cout << "\n \n Welcome to the Game :Russian Roulette\n";
	cout << "\n This game shall decide each player's fate \n";
	cout << "------------------------------\n";
	cout << " Choose your decision carefully.";
	cout << "\n (1) Fire  (2) Spin  (5) Peek  (0) Quit\n";

spin:	chamber = 1 + rand() % (6 - 1 + 1); // Spin randomizes

choice: 
	cout << "--> ";
	cin >> select;
//If the user wants to pull the trigger.
	if (select == '1') 
		{
//If the bullet is in the next chamber.
		if (chamber == 1) 
		 {
			cout << "BAM!! You're dead!\n";
			_getch();
			return ; 
		 }
		else {
//But if the player is lucky, spin the chamber and let him live!
			chamber -= 1;
			cout << "Click...\n";
//Then let him pick what he wants to do next.
			goto choice;
		}
//If the player wants to spin the chamber.
	}if (select == '2') {
//First tell him how close he was to death before spinning.
		if (chamber>1) {
			cout << "There were " << chamber << " more shots to death.\n";
		}
		else {
			cout << "Next shot would have been death.\n";
		}
		cout << "You spinned the chamber.\n";
/*But go to the point before the choice, so it rerandomizes
the value before asking for input again.*/
		goto spin;
//And if the player wants to peek.
	}
	if (select == '5') {
		if (chamber>1) {
			cout << chamber << " more shots to death.\n";
		}
		else {
			cout << "Next shot is death.\n"; // HEART ATTACK!!
		}
//Let them choose again.
		goto choice;
	}
//And if the player wants to quit...
	if (select == '0') {
		if (chamber>1) {
			cout << "You're a scared chicken! \n" << chamber << " more shots to death.\n";
		}
		else {
			cout << "You're one lucky son of a gun! Next shot is death.\n";
			cout << " \n Game over. You win.";
		}
		_getch();
		return ;
	}
	else
	{
		goto choice; // When invalid choice is entered.
	}
	_getch();
	return ;
}