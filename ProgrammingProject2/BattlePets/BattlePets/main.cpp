using namespace std;
#include <iostream>
#include "Moves.h"
#include "Battledex.h"
#include "Owner.h"
#include <windows.h>
#include <string>
#include "PetStack.h"
#include "Moves.h"
#include "PetTree.h"
#include "PetVisitor.h"
#include <algorithm>
#include <cctype>
//including twitcurl libraries for the API
#include "..\..\twitcurl\libtwitcurl\oauthlib.h"
#include "..\..\twitcurl\libtwitcurl\twitcurl.h"

FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
extern "C" void impset_output_format(void) {};

//a simple function to remove whitespace for the 
string removeWhiteSpace(string word)
{
	string temp = word;
	temp.erase(remove(temp.begin(), temp.end(), '\n'), temp.end());
	return temp;
}

void drawBanner()
{//this is the banner for aesthetic purposes
	cout << R"(
 _______  _______  _______  _______  ___      _______  _______  _______  _______  _______    |
|  _    ||   _   ||       ||       ||   |    |       ||       ||       ||       ||       |   |
| |_|   ||  |_|  ||_     _||_     _||   |    |    ___||    _  ||    ___||_     _||  _____|   |
|       ||       |  |   |    |   |  |   |    |   |___ |   |_| ||   |___   |   |  | |_____    |
|  _   | |       |  |   |    |   |  |   |___ |    ___||    ___||    ___|  |   |  |_____  |   |
| |_|   ||   _   |  |   |    |   |  |       ||   |___ |   |    |   |___   |   |   _____| |   |
|_______||__| |__|  |___|    |___|  |_______||_______||___|    |_______|  |___|  |_______|   |
_____________________________________________________________________________________________|)" << endl;
}

int main()
{
	system("CLS");

	//create the twiCurl object so that i can link it to my twitter account
	twitCurl twitter;

	//keys that are required to access twitter services and API
	twitter.getOAuth().setConsumerKey("fGRwDRVgQoM3CDesgebuMn9sN");
	twitter.getOAuth().setConsumerSecret("LrvyxMsHa7PPnvTWhgzdfxzWbpj9RfI7oKZ1TW9cgaoluBPjsR");
	twitter.getOAuth().setOAuthTokenKey("1088469456429273088-n1TrkK59SzXm6TccU0wEBsQywP3NvN");
	twitter.getOAuth().setOAuthTokenSecret("LTRsPQeDazQ93XRimycdaJQX0kTz0ZYEadS1c8yHhPwCQ");
	drawBanner();

	string welcome = "\nHello and welcome to Battle Pets!!\nHere you will experience a short snippet of text-based fighting with various pets of ur own!!\nThis game has three types of pets, Fire, Water and Grass.\nYou are to fight a computer opponent using a team of pets. \nBut before we start, you get to choose your character!!\nPress Enter to proceed!!";
	int x = 0;
	while (welcome[x] != '\0')
	{
		cout << welcome[x];
		Sleep(30);
		x++;
	};
	cin.get();//makes a small animation-like output for aesthetic purposes
	

	//Tree
	//the nodes are read from the text file
	vector<string> treeString;
	string lines;
	ifstream textfile("TreeStrings.txt");
	if (textfile.is_open())
	{
		while (getline(textfile, lines))
		{
			treeString.push_back(lines);
		}
		textfile.close();
	}
	//some formatting on some strigs
	string newlinestring1 = "\n" + treeString[1];
	string newlinestring2 = "\n" + treeString[2];
	string newlinestring3 = "\n" + treeString[3];
	string newlinestring4 = "\n" + treeString[5];

	//turning the strings into tree nodes
	PetTree<string> CharTree(treeString[0]);
	PetTree<string> TreeNode1(newlinestring1);
	PetTree<string> TreeNode2(newlinestring2);
	PetTree<string> TreeNode3(newlinestring3);
	PetTree<string> TreeNode4(treeString[4]);
	PetTree<string> TreeNode5(newlinestring4);
	PetTree<string> TreeNode6(treeString[6]);

	//nodes on the 1st layer
	CharTree.attachLeft(&TreeNode1);
	CharTree.attachRight(&TreeNode2);

	//nodes on the 2nd layer
	CharTree.left().attachLeft(&TreeNode3);//Leo, Mew, Aqua
	CharTree.left().attachRight(&TreeNode4);//Leon, Mewmew, Aquality

	//nodes on the 2nd layer
	CharTree.right().attachLeft(&TreeNode5);//Leoreon, Mewmian, Aquanox
	CharTree.right().attachRight(&TreeNode6);//Fierry, Leafy, Splashy
	
	Battledex& Battledex = Battledex::Get();//declare a pointer to the singleton to get the Pets data later on
	PetStack<Pets> Pets_Stack(3);//initialize stack
	
	cout << "Here is a preview of characters you can choose along with their pets" << endl;
	CharTree.accept(PreviewVisitor<string>());


	//the text file needs to be removed everytime before running to avoid writing duplicate nodes into it
	//this is caused from the recurssion inside the accept method where each key is parsed into the visit function which made me unable to write it all at once
	remove("BattlePetsData.txt");
	CharTree.accept(DisplayVisitor<string>());

	Pets team[3];//an array that is used to store the player's team before the pets get enqueued into the queue
	Owner owner;

	//display character options from the tree and ask for player input
	cout << "\nChoose your character! Each character have a different set of pokemon so choose wisely\nPlease input number (1/2):" << endl;
	cout << "[1]" << removeWhiteSpace(CharTree.left().key()) << "\n or \n[2]" << removeWhiteSpace(CharTree.right().key()) << endl;
	int character;
	cin >> character;
	while (true)
	{
		if (character == 1)
		{
			owner.setName("Ash");//creating the array class
			int teamChoice;
			//display team options from the tree and ask for player input
			cout << "Choose your pet team" << endl;
			cout << "[1]" << removeWhiteSpace(CharTree.left().left().key()) << " or [2]" << CharTree.left().right().key() << endl;
			cout << "Enter the number (1/2): ";
			cin >> teamChoice;
			while (true)
			{
				if (teamChoice == 1)
				{
					team[0] = Battledex.getFirePet("Leo").getPet();
					team[1] = Battledex.getGrassPet("Mew").getPet();
					team[2] = Battledex.getWaterPet("Aqua").getPet();
					break;
				}
				else if (teamChoice == 2)
				{
					team[0] = Battledex.getFirePet("Leon").getPet();
					team[1] = Battledex.getGrassPet("Mewmew").getPet();
					team[2] = Battledex.getWaterPet("Aquality").getPet();
					break;
				}
				else
				{
					cout << "Wrong input please try again" << endl;
					cout << "Choose your pet team" << endl;
					cout << "[1]" << CharTree.left().left().key() << " or [2]" << CharTree.left().right().key() << endl;
					cout << "Enter the number (1/2): ";
					cin >> teamChoice;
					continue;
				}
			}
			break;

		}
		else if (character == 2)
		{
			owner.setName("Amy");//creating the array class
			int teamChoice;
			//display team options from the tree and ask for player input
			cout << "Choose your pet team" << endl;
			cout << "[1]" << removeWhiteSpace(CharTree.right().left().key()) << " or [2]" << CharTree.right().right().key() << endl;
			cout << "Enter the number (1/2): ";
			cin >> teamChoice;
			while (true)
			{
				if (teamChoice == 1)
				{
					team[0] = Battledex.getFirePet("Leoreon").getPet();
					team[1] = Battledex.getGrassPet("Mewmian").getPet();
					team[2] = Battledex.getWaterPet("Aquanox").getPet();
					break;
				}
				else if (teamChoice == 2)
				{
					team[0] = Battledex.getFirePet("Fierry").getPet();
					team[1] = Battledex.getGrassPet("Leafy").getPet();
					team[2] = Battledex.getWaterPet("Splashy").getPet();
					break;
				}
				else
				{
					cout << "Wrong input please try again" << endl;
					cout << "Choose your pet team" << endl;
					cout << "[1]" << CharTree.right().left().key() << " or [2]" << CharTree.right().right().key() << endl;
					cout << "Enter the number (1/2): ";
					cin >> teamChoice;
					continue;
				}
			}
			break;

		}
		else
		{
			cout << "Wrong input please try again" << endl;
			cout << "Choose your character! Each character have a different set of pokemon so choose wisely\n Please input number (1/2):";
			cin >> character;
			continue;
		}
	}
	
	//destroy the tree as it no longer is in use
	CharTree.left().detachLeft();
	CharTree.left().detachRight();
	CharTree.right().detachLeft();
	CharTree.right().detachRight();
	CharTree.detachLeft();
	CharTree.detachRight();
	
	
	//prints out the Pets in the array
	cout << "Hello "<< owner.getName() <<"!\nHere are your pets: " << endl;
	for (int i = 0; i < 3; i++) 
	{
		cout << i + 1 << ". "<< team[i].getName() << endl;
	}
	string yn;
	//letting the player rearrange the pets if they wish to
	cout << "You will have to fight using this team in the exact order. Do you wish to change the arrangement of your team?[Yes/No]" << endl;
	cin >> yn;
	
	if (yn == "Yes" || yn == "yes")
	{
		int new_position;
		Pets new_team[3];
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << ". " << team[i].getName();
			cout << "\tNew position(input a number): ";
			cin >> new_position;
			new_team[new_position - 1] = team[i];
		}
		cout << "Updated team order: " << endl;
		for (int i = 0; i < 3; i++) {//adding the Pets from the above array into the queue in the object class owner
			cout << i + 1 << ". " << new_team[i].getName() << endl;
			owner.enqueue(new_team[i]);
		}

	}
	else
	{
		for (int i = 0; i < 3; i++) {//adding the Pets from the above array into the queue in the object class owner
			owner.enqueue(team[i]);
			
		}
	}

	//a small menu for the player
	int player_choice;
	cout << "Do you wish to: \n[1] View Battledex \n[2] Start Fight \n[0] Exit Program" << endl;
	cin >> player_choice;
	system("CLS");//this is used to clear the screen to make it look more neat
	while (player_choice != 0)
	{
		if (player_choice == 1)//if the player selects to view the Battledex
		{
			int Pets_type;
			drawBanner();
			cout << "Select what kind of Pets you want to see: " << endl;
			cout << "[1] Water \t[2]Fire \t[3]Grass \t[4]View Pets Moves \t[0]Go Back" << endl;
			cout << "Enter a number (1/2/3/0): ";
			cin >> Pets_type;
			system("CLS");

			if (Pets_type == 1)//water Battledex
			{
				drawBanner();
				//prints a preview of the Pets available in the water category
				Battledex.printWaterPet();
				string poke_name;
				cout << "Enter the Pets name EXACTLY for details (Case Sensitive)" << endl;
				cin >> poke_name;

				WaterPet results = Battledex.getWaterPet(poke_name).getPet();
				cout << "ID: " << results.getID() << "\tName: " << results.getName() << "\tHP: " << results.getMaxHP() << "\tMoves: " << results.getMove(1).getName() << ", " << results.getMove(2).getName() << ", " << results.getMove(3).getName() << ", " << results.getMove(4).getName();
				results.printType();//using the override method to print the types

				bool iterating = true;
				//here shows the use of doubly linked list where the player can iterate forwards and backwards through each Pets 
				while (iterating == true)
				{
					string iterate_input;
					cout << "[,] Previous \t [.] Next \t [/] Exit" << endl;
					cin >> iterate_input;
					if (iterate_input == ",")//get the previous Pets in the Battledex
					{
						WaterPet results = Battledex.PreviousWaterPet(poke_name).getPet();
						cout << "ID: " << results.getID() << "\tName: " << results.getName() << "\tHP: " << results.getMaxHP() << "\tMoves: " << results.getMove(1).getName() << "," << results.getMove(2).getName() << "," << results.getMove(3).getName() << "," << results.getMove(4).getName();
						results.printType();
						poke_name = results.getName();
						iterating = true;
					}
					else if (iterate_input == ".")//gets the next Pets in the Battledex
					{
						WaterPet results = Battledex.NextWaterPet(poke_name).getPet();
						cout << "ID: " << results.getID() << "\tName: " << results.getName() << "\tHP: " << results.getMaxHP() << "\tMoves: " << results.getMove(1).getName() << "," << results.getMove(2).getName() << "," << results.getMove(3).getName() << "," << results.getMove(4).getName();
						results.printType();
						iterating = true;
						poke_name = results.getName();
					}
					else if (iterate_input == "/")
					{
						system("CLS");
						break;
					}
					else
					{
						cout << "Invalid Output. Please try again." << endl;
						continue;
					}
				}

			}
			else if (Pets_type == 2)//fire Battledex
			{
				drawBanner();
				Battledex.printFirePet();
				string poke_name;
				cout << "Enter the Pets name EXACTLY for details (Case Sensitive)" << endl;
				cin >> poke_name;
				FirePet results = Battledex.getFirePet(poke_name).getPet();
				cout << "ID: " << results.getID() << "\tName: " << results.getName() << "\tHP: " << results.getMaxHP() << "\tMoves: " << results.getMove(1).getName() << ", " << results.getMove(2).getName() << ", " << results.getMove(3).getName() << ", " << results.getMove(4).getName();
				results.printType();

				bool iterating = true;
				//use of doubly linked list
				while (iterating == true)
				{
					string iterate_input;
					cout << "[,] Previous \t [.] Next \t [/] Exit" << endl;
					cin >> iterate_input;
					if (iterate_input == ",")
					{
						FirePet results = Battledex.PreviousFirePet(poke_name).getPet();
						cout << "ID: " << results.getID() << "\tName: " << results.getName() << "\tHP: " << results.getMaxHP() << "\tMoves: " << results.getMove(1).getName() << "," << results.getMove(2).getName() << "," << results.getMove(3).getName() << "," << results.getMove(4).getName();
						results.printType();
						poke_name = results.getName();
						iterating = true;
					}
					else if (iterate_input == ".")
					{
						FirePet results = Battledex.NextFirePet(poke_name).getPet();
						cout << "ID: " << results.getID() << "\tName: " << results.getName() << "\tHP: " << results.getMaxHP() << "\tMoves: " << results.getMove(1).getName() << "," << results.getMove(2).getName() << "," << results.getMove(3).getName() << "," << results.getMove(4).getName();
						results.printType();
						iterating = true;
						poke_name = results.getName();
					}
					else if (iterate_input == "/")
					{
						system("CLS");
						break;
					}
					else
					{
						cout << "Invalid Output. Please try again." << endl;
						continue;
					}
				}
			}
			else if (Pets_type == 3)//grass Battledex
			{
				drawBanner();
				Battledex.printGrassPet();
				string poke_name;
				cout << "Enter the Pets name EXACTLY for details (Case Sensitive)" << endl;
				cin >> poke_name;
				GrassPet results = Battledex.getGrassPet(poke_name).getPet();
				cout << "ID: " << results.getID() << "\tName: " << results.getName() << "\tHP: " << results.getMaxHP() << "\tMoves: " << results.getMove(1).getName() << ", " << results.getMove(2).getName() << ", " << results.getMove(3).getName() << ", " << results.getMove(4).getName();
				results.printType();
				bool iterating = true;
				//use of doubly linked list
				while (iterating == true)
				{
					string iterate_input;
					cout << "[,] Previous \t [.] Next \t [/] Exit" << endl;
					cin >> iterate_input;
					if (iterate_input == ",")
					{
						GrassPet results = Battledex.PreviousGrassPet(poke_name).getPet();
						cout << "ID: " << results.getID() << "\tName: " << results.getName() << "\tHP: " << results.getMaxHP() << "\tMoves: " << results.getMove(1).getName() << "," << results.getMove(2).getName() << "," << results.getMove(3).getName() << "," << results.getMove(4).getName();
						results.printType();
						poke_name = results.getName();
						iterating = true;
					}
					else if (iterate_input == ".")
					{
						GrassPet results = Battledex.NextGrassPet(poke_name).getPet();
						cout << "ID: " << results.getID() << "\tName: " << results.getName() << "\tHP: " << results.getMaxHP() << "\tMoves: " << results.getMove(1).getName() << "," << results.getMove(2).getName() << "," << results.getMove(3).getName() << "," << results.getMove(4).getName();
						results.printType();
						iterating = true;
						poke_name = results.getName();
					}
					else if (iterate_input == "/")
					{
						system("CLS");
						break;
					}
					else
					{
						cout << "Invalid Output. Please try again." << endl;
						continue;
					}
				}
			}
			else if (Pets_type == 4)//display all the available moves in the singly linked list
			{
				drawBanner();
				Battledex.getMoves();
				system("PAUSE");
				system("CLS");
				drawBanner();
				cout << "Do you wish to: \n[1] View Battledex \n[2] Start Fight \n[0] Exit Program" << endl;
				cin >> player_choice;
				continue;
			}
			else if (Pets_type == 0)
			{
				system("CLS");
				drawBanner();
				cout << "Do you wish to: \n[1] View Battledex \n[2] Start Fight \n[0] Exit Program" << endl;
				cin >> player_choice;
				continue;
			}
		}

		//if the player chooses to battle
		if (player_choice == 2)
		{
			system("CLS");
			drawBanner();
			string opponent = "Looks like your opponent is approaching.\nYou will be going up against one of the water Pets masters. \nPets master: Water you doing?? Get it? Get it? Haha.\nINSTRUCTIONS:\nYou can fight by inputting the move number when it appears on the screen.\nBe careful of your HP shown next to your Pets's name.\nOk, Ready??\nPress Enter if you are ready\n";
			cin.get();
			system("CLS");
			drawBanner();
			int y = 0;
			while (opponent[y] != '\0')
			{
				cout << opponent[y];
				Sleep(50);
				y++;
			};
			//animation-style output for better appearance

			//creates an array of enemy Pets the player is going to face
			Pets enemy_team[] = { Battledex.getWaterPet("Starking").getPet(), Battledex.getWaterPet("Aqua").getPet(), Battledex.getWaterPet("Aquality").getPet()};

			//pushes the enemy into the stack to be faced in an order
			for (int i = 0; i < 3; i++) {
				Pets_Stack.push(enemy_team[i]);
			}


			//fighting commence
			cout << "Pets Master: I choose you, " << Pets_Stack.top().getName() << "!!!" << endl;
			int x = owner.getTeamSize();//this will be used to see which Pets team is completely depleted and decide the winner

			while (!Pets_Stack.isEmpty() && x > 0)
			{
				//creates some indication of current enemy Pets and your own Pets
				cout << "Enemy Pets - " << Pets_Stack.top().getName() << "\tHP: " << Pets_Stack.top().getCurrentHP() << "/" << Pets_Stack.top().getMaxHP() << endl;

				cout << "----------------------------------------------" << endl;
				cout << "Your Pets - " << owner.peek().getName() << "\tHP: " << owner.peek().getCurrentHP() << "/" << owner.peek().getMaxHP() << endl;
				cout << "Pick a move: " << endl;

				//displays the moves for the Pets
				int move_no;
				for (int j = 1; j <= 4; j++)
				{
					cout << "[" << j << "] " << owner.peek().getMove(j).getName() << endl;
				}
				cout << "Enter your move (1/2/3/4): ";
				cin >> move_no;
				system("CLS");
				drawBanner();
				while (move_no > 4)
				{
					cout << "Wrong input please try again." << endl;
					cout << "Enter your move (1/2/3/4): ";
					cin >> move_no;
				}
				//tells the player what move is used and decrease the hp of the enemy Pets 
				cout << owner.peek().getName() << " used " << owner.peek().getMove(move_no).getName() << endl;
				Pets_Stack.top().setHP(owner.peek().getMove(move_no).getdmg());


				//if the enemy Pets health is lesser or equal to zero
				if (Pets_Stack.top().getCurrentHP() <= 0)
				{
					cout << Pets_Stack.top().getName() << " has fainted!" << endl;
					Pets_Stack.pop();//the Pets will be removed from the stack
					continue;
				}
				else
				{
					//if the Pets has not fainted, then the enemy Pets will randomly choose a move and attack the player
					int random_move = rand() % 4 + 1;
					cout << "Enemy " << Pets_Stack.top().getName() << " used " << Pets_Stack.top().getMove(random_move).getName() << endl;
					owner.peek().setHP(Pets_Stack.top().getMove(random_move).getdmg());//decrease the player Pets's hp

					if (owner.peek().getCurrentHP() <= 0)//if the player's Pets dies
					{
						cout << "Your Pets - " << owner.peek().getName() << " has fainted" << endl;
						owner.dequeue();//removed from the list
						x--;
						unsigned int input;
						cout << "Do you want to: \n[1] Switch to the next Pet \n[2] Exit Program" << endl;
						cout << "Enter your choice:";
						cin >> input;
						system("CLS");
						drawBanner();
						while (input > 2)
						{
							cout << "Invalid choice" << endl;
							cout << "Do you want to: \n[1] Switch to the next Pets \n[2] Exit Program" << endl;
							cout << "Enter your choice:";
							cin >> input;
						}
						if (input == 1) {//if the player chooses to switch Pets, it will move to the next Pets in the array
							continue;
						}
						else if (input == 2)
						{//if not the program will end
							return 0;
						}

					}
				}
			}
			if (Pets_Stack.isEmpty())//if enemy stack is empty
			{
				cout << "CONGRATULATIONS YOU WIN!!" << endl;
				char tweeting;
				//prompting the player to make the tweet
				cout << "Like my game? SHARE IT TO THE WORLD!![Y/N]" << endl;
				cin >> tweeting;
				
				while (true)
				{
					if (tolower(tweeting) == 'y')
					{
						//message that will appear on twitter
						string tweet = "I just finished my game of BattlePets as " + owner.getName() + ", it is a great text-based action game come and join me on the fun";
						cout << "This Tweet will be posted on our page on Twitter: " << endl;
						cout << tweet << endl;
						int tweetConfirm;
						cout << "[1]Confirm \t [2]Cancel" << endl;
						cin >> tweetConfirm;
						//if confirmed, make the tweet
						if (tweetConfirm == 1)
						{
							twitter.statusUpdate(tweet);
							cout << "Tweeted successfully! Thank you for playing my game!!" << endl;
							return 0;
						}
						else if (tweetConfirm == 2)
						{
							return 0;
						}

					}
					else if (tolower(tweeting) == 'n')
					{
						return 0;
					}
					else
					{
						cout << "Invalid input please try again." << endl;
						cout << "Like my game? SHARE IT TO THE WORLD!![Y/N]" << endl;
						cin >> tweeting;
						continue;

					}
				}
				
				
			}

			if (x <= 0)//if Pets array count is empty
			{
				cout << "That was your last Pets, You Lost. Better Luck Next Time.^('o')^" << endl;
				char tweeting;
				//prompting player to tweet
				cout << "Like my game? SHARE IT TO THE WORLD!![Y/N]" << endl;
				cin >> tweeting;
				while (true)
				{
					if (tolower(tweeting) == 'y')
					{
						//message that will appear on twitter
						string tweet = "I just finished my game of BattlePets as " + owner.getName() + ", it is a great text-based action game come and join me on the fun";
						cout << "This Tweet will be posted on our page on Twitter: " << endl;
						cout << tweet << endl;
						int tweetConfirm;
						cout << "[1]Confirm \t [2]Cancel" << endl;
						cin >> tweetConfirm;
						//if confirmed, then tweet
						if (tweetConfirm == 1)
						{
							twitter.statusUpdate(tweet);
							cout << "Tweeted successfully! Thank you for playing my game!!" << endl;
							return 0;
						}
						else if (tweetConfirm == 2)
						{
							return 0;
						}


						
					}
					else if (tolower(tweeting) == 'n')
					{
						return 0;
					}
					else
					{
						cout << "Invalid input please try again." << endl;
						cout << "Like my game? SHARE IT TO THE WORLD!![Y/N]" << endl;
						cin >> tweeting;
						continue;
					}
				}
				
			}

		}
	}

	return 0;
}