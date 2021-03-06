#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Cards
{
public:
	int value;
};

class Deck
{
public:
	int wDeck[52];
	int shuffledDeck[52];
	int shuffleNum[52];
	//Populate the deck with cards
	void fillDeck()
	{
		int i = 0;
		int cardnum = 1;
		while (i<52)
		{
			for (int j = 1; j<5; j++)
			{
				wDeck[i] = cardnum;
				i++;
			}
			cardnum++;
		}
	}
	//Print method for debugging
	void printDeck()
	{
		for (int i = 0; i<52; i++)
		{
			switch (shuffledDeck[i])
			{
			case 11:
				cout << "J" << endl;
				break;
			case 12:
				cout << "Q" << endl;
				break;
			case 13:
				cout << "K" << endl;
				break;
			case 14:
				cout << "A" << endl;
				break;
			default: cout << shuffledDeck[i] << endl;
			}
		}
	}

	void shuffleDeck()
	{
		int x = 0;
		int y = 0;
		int count = 0;
		int counter = 0;
		int index;
		while (x < 52)
		{
			shuffleNum[x] = rand() % 52;
			//cout << "RESULT" << shuffleNum[x] << "\n";
			while (y < 52)
			{
				if (shuffleNum[y] == shuffleNum[x] && x != y) //If another number is equal to this one.
				{
					x--; //Set x back one. 
					y = 0; //Reset y;
					break; //Try again.
				}
				else
				{
					y++; //Otherwise, check the next number.
				}
			}
			x++;
			//  cout << "NUMBER:" << shuffleNum[x] << "\n";
		}
		while (counter<52)
		{
			index = shuffleNum[counter];
			shuffledDeck[counter] = wDeck[index];
			counter++;
		}
	}

};




int main()
{
	Deck nDeck;
	nDeck.fillDeck();
	nDeck.shuffleDeck();
	nDeck.printDeck();
	return 0;
}
