// Amazing adventure game
// UNFINISHED:
//  The entiery of the second path
//  Some alt paths in the First
/*

NOT FINSHED:
yes > c



You need to figure out a way to keep score. Maybe rewrite the battle function,
but instead of just calling the function everytime, use a while or for loop

*/
// 1/7/19: AFIAK I can't configure points during battle algorithm

// FINISHED:
//  Most of the firstpath
//  The pennywise and kitchen boss battles
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;
int battleScore = 0;

int health(int hp) {
	int r;
	r = hp * 2;
	return r;
}
int h2(int hp2) {
	int x;
	x = hp2 - 20;
	return x;
}
int endit(int end) {
	return 0;
}

/* FAILED CONCEPT
int batmag(int mgn, int mgt) {
  if
}
*/

// WORKSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
int batheal(int hpn, int mgn, int sco) { // Battle algorithm for ghost
	if (hpn < 0) {
		return 33;
	}
	cout << "\n\n\nYou now have " << mgn << " magic points.\nThe ghost has "
		 << hpn << " health points.";
	cout << "\nWhat will you do?\n\n a) Power Punch \n b) Love \n c) Fire "
			"Coconut Gun \n d) Eat Hotdog\n e) Epiccc dabbb\n f) Chance "
			"Time\n\n";
	int sre;

	string fightInput;
	cin >> fightInput;

	if (fightInput == "a") // If the user enters a for a letter then...
	{
		hpn = hpn - 10; // The ghost loses 20 health points.
		mgn = mgn - 10; // You lose 10 magic points.
		sco = sco + 10; // This currently doesn't work properly.

		if (hpn > 0 && mgn >= 0) {
			cout << "You punch the ghost. He cries like a baby.\n\n";

			batheal(hpn, mgn, sco);
		}
		if (mgn < 0) {
			// If, after the inital use of magic, the magic goes under zero,
			// then the health will be turned back to the ghost and the magic
			// will be turned back.
			mgn = mgn + 10;
			hpn = hpn + 10;
			cout << "You don't have enough magic to perform this attack!";

		} else {
			return 33;
		}
	}

	if (fightInput == "b") {
		hpn = hpn + 20;
		cout << "\nYou fool! The ghost now has more health!";

		batheal(hpn, mgn, sco);
	}
	if (fightInput == "c") {
		hpn = hpn - 5;
		mgn = mgn - 5;
		sco = sco + 10;

		if (hpn > 0 && mgn >= 0) {
			cout
				<< "You fire your coconut gun in spurts. You shoot him-it "
				   "hurts. Because your bigger, faster, and stronger, too.\n\n";

			batheal(hpn, mgn, sco);
		}
		if (mgn < 0) {
			mgn = mgn + 5;
			hpn = hpn + 5;
			cout << "You don't have enough magic to perform this attack!\n\n";
			batheal(hpn, mgn, sco);
		} else {
			return 33;
		}
	}
	if (fightInput == "d") {
		hpn = hpn + 5;
		mgn = mgn + 10;
		sco = sco + 10;

		if (hpn > 0 && mgn >= 0) {
			cout << "You eat a pretty good hotdog. The ghost is pretty dumb, "
					"so he doesn't attack you, but he recovers a bit. You do "
					"feel refreshed though.\n\n";

			batheal(hpn, mgn, sco);
		}
	}
	if (fightInput == "e") {
		hpn = hpn - 50;
		mgn = mgn - 40;
		sco = sco + 10;

		if (hpn > 0 && mgn >= 0) {
			cout << "You do a fricking EPIC DAB BRO!!! THE GHOST IS TOO BURNT "
					"FROM YOUR DAB HE TAKES ALOT OF HEALTH OH MY!!!!\n\n";

			batheal(hpn, mgn, sco);
		}
		if (mgn < 0) {
			mgn = mgn + 40;
			hpn = hpn + 50;
			cout << "You don't have enough magic to perform this attack!\n\n";
			batheal(hpn, mgn, sco);
		}
		if (hpn <= 0) {
			return 33;
		}
	}
	if (fightInput == "f") {
		srand(time(NULL));
		int chance1;
		int chance2;

		cout << "CHANCE TIME!!! Test out your luck and see what values you "
				"get!\n";
		cout << "It's simple: You type in a maximum value. The program "
				"generates two random values betwen the maximum and the "
				"minimum (1). You will gain magic points off one value, but "
				"the ghost will also gain health based off the other value. "
				"Feeling lucky? Type in a number.\n\n";

		int max;

		cout << "\nMaximum Value: ";
		cin >> max;
		chance1 = rand() % max + 1;
		chance2 = rand() % max + 1;

		cout << "\n\nAlright. You have gained " << chance1 << " magic points.";
		cout << "\n\nThe ghost has gained " << chance2 << " health points.\n\n";
		mgn = mgn + chance1;
		hpn = hpn + chance2;
		batheal(hpn, mgn, sco);
	}
	/*
	I origanally planned making 2 versions of chance time; one where you gain
   magic but ghost gains health, and this one where you lose magic but the ghost
   loses health. I cut it because it's pretty easy to win; type in a big maximum
   and you have a higher chance of winning from the start.

	if (choice == 2) {
	 int max;

	 cout << "\nAlright! Now, you can choose the maximum value for your
   results.(The minimum is 1!)"; cout << "\nMaximum Value: "; cin >> max;
	 chance1 = rand() % max + 1;
	 chance2 = rand() % max + 1;

	 cout << "\n\nAlright. The ghost loss " << chance1 << " health points.";
	 cout << "\n\nYou have lost " << chance2 << " magic points.\n\n";
	 mgn = mgn - chance2;
	 hpn = hpn - chance1;
						if (hpn > 0 && mgn >= 0) {

					  batheal(hpn, mgn, sco);
					}
					if (mgn < 0) {

					  batheal(hpn, 0, sco);
					}
					else {

					  return 33;
					}

   }*/

	if (fightInput != "a" || "b" || "c" || "d" || "e" || "f") {
		return 2;
	} else {
		return 2;
	}
	/*



	The game will proceed only if a number bigger than 5 is returned as a value.
	Down in the int main fucntion, the rest of the game is held inside the "if
	batheal(100,50) = 33" function. If anything else is entered, including an
	invalid value or the user loses the game, then the game will redirect to
	"lose".*/
}

int batheal2(int hpn, int mgn, int sco) { // Battle algorithm for Pennywise
	if (hpn < 0) {
		return 33;
	}
	cout << "\n\n\nYou now have " << mgn << " magic points.\nPennywise has "
		 << hpn << " health points.";
	cout << "\nWhat will you do?\n\n a) Hit with sledgehammer \n b) Float wit "
			"balloon \n c) Watch Advertisment \n d) Dab on the haters\n e) "
			"Falcon Punch\n f) Chance Time\n\n";
	int sre;

	string fightInput;
	cin >> fightInput;

	if (fightInput == "a") // If the user enters a for a letter then...
	{
		hpn = hpn - 10; // The ghost loses 20 health points.
		mgn = mgn - 10; // You lose 10 magic points.
		sco = sco + 10; // This currently doesn't work properly.

		if (hpn > 0 && mgn >= 0) {
			cout << "\"Why, you are a feisty one, aren't you? Unfortunately, "
					"you'll need to do a bit more than that HAHAH!\"\n\n";

			batheal2(hpn, mgn, sco);
		}
		if (mgn < 0) {
			// If, after the inital use of magic, the magic goes under zero,
			// then the health will be turned back to the ghost and the magic
			// will be turned back.
			mgn = mgn + 10;
			hpn = hpn + 10;
			cout << "You don't have enough magic to perform this attack!";
			batheal2(hpn, mgn, sco);
		} else {
			return 33;
		}
	}

	if (fightInput == "b") {
		srand(time(NULL));
		int floater;

		floater = rand() % 100 + 1;
		hpn = hpn + floater;
		mgn = mgn + floater;
		cout << "\nYou float with a ballon. \"Ohh, my child. It seems things "
				"are a bit... INCREASED!!!! WAHAHAH\" \n\nThere is barely any "
				"effect.";

		batheal2(hpn, mgn, sco);
	}
	if (fightInput == "c") {
		hpn = hpn - 15;
		mgn = mgn - 14;
		sco = sco + 10;

		if (hpn > 0 && mgn >= 0) {
			cout << "You let pennywise advertise more about the movie. \"Well, "
					"you see, Seven young outcasts in Derry, Maine, are about "
					"to face their worst nightmare -- an ancient, "
					"shape-shifting evil that emerges from the sewer every 27 "
					"years to prey on the town's children. Banding together "
					"over the course of one horrifying summer, the friends "
					"must overcome their own personal fears to battle the "
					"murderous, bloodthirsty clown known as Pennywise.\"\n\nIt "
					"wastes both of your time..\n\n";

			batheal2(hpn, mgn, sco);
		}
		if (mgn < 0) {
			mgn = mgn + 5;
			hpn = hpn + 5;
			cout << "You don't have enough magic to perform this attack!\n\n";
			batheal2(hpn, mgn, sco);
		} else {
			return 33;
		}
	}
	if (fightInput == "d") {
		hpn = hpn + 5;
		mgn = mgn + 10;
		sco = sco + 10;

		if (hpn > 0 && mgn >= 0) {
			cout << "Pennywise is a hater, so you dab back on him. Pennywise "
					"isn't hurt by you epic dab, but you feel so good for "
					"reking that n00b you gain some magic.\n\n";

			batheal2(hpn, mgn, sco);
		}
	}
	if (fightInput == "e") {
		hpn = hpn - 70;
		mgn = mgn - 50;
		sco = sco + 10;

		if (hpn > 0 && mgn >= 0) {
			cout << "You charge up for a falcon punch.\n\"Captain Falcon? Gee, "
					"that character sure is for noobs.\" Despite his hurtful "
					"words, you falcon punch him and he loses alot of health. "
					"\"I UNDERESTIMATED YOU!!!\"\n\n";

			batheal2(hpn, mgn, sco);
		}
		if (mgn < 0) {
			mgn = mgn + 40;
			hpn = hpn + 50;
			cout << "You don't have enough magic to perform this attack!\n\n";
			batheal2(hpn, mgn, sco);
		}
		if (hpn <= 0) {
			return 33;
		}
	}
	if (fightInput == "f") {
		srand(time(NULL));
		int chance1;
		int chance2;

		cout << "CHANCE TIME!!! Test out your luck and see what values you "
				"get!\n";
		cout << "It's simple: You type in a maximum value. The program "
				"generates two random values betwen the maximum and the "
				"minimum (1). You will gain magic points off one value, but "
				"the ghost will also gain health based off the other value. "
				"Feeling lucky? Type in a number.\n\n";

		int max;

		cout << "\nMaximum Value: ";
		cin >> max;
		chance1 = rand() % max + 1;
		chance2 = rand() % max + 1;

		cout << "\n\nAlright. You have gained " << chance1 << " magic points.";
		cout << "\n\nThe ghost has gained " << chance2 << " health points.\n\n";
		if (chance1 < chance2) {
			"\"\nWhoops! Looks like your not so lucky today! HAHAHAHA!!\"";
		}
		mgn = mgn + chance1;
		hpn = hpn + chance2;
		batheal2(hpn, mgn, sco);
	}
	/*
	I origanally planned making 2 versions of chance time; one where you gain
   magic but ghost gains health, and this one where you lose magic but the ghost
   loses health. I cut it because it's pretty easy to win; type in a big maximum
   and you have a higher chance of winning from the start.

	if (choice == 2) {
	 int max;

	 cout << "\nAlright! Now, you can choose the maximum value for your
   results.(The minimum is 1!)"; cout << "\nMaximum Value: "; cin >> max;
	 chance1 = rand() % max + 1;
	 chance2 = rand() % max + 1;

	 cout << "\n\nAlright. The ghost loss " << chance1 << " health points.";
	 cout << "\n\nYou have lost " << chance2 << " magic points.\n\n";
	 mgn = mgn - chance2;
	 hpn = hpn - chance1;
						if (hpn > 0 && mgn >= 0) {

					  batheal(hpn, mgn, sco);
					}
					if (mgn < 0) {

					  batheal(hpn, 0, sco);
					}
					else {

					  return 33;
					}

   }*/

	if (fightInput != "a" || "b" || "c" || "d" || "e" || "f") {
		return 2;
	} else {
		return 2;
	}
	/*



	The game will proceed only if a number bigger than 5 is returned as a value.
	Down in the int main fucntion, the rest of the game is held inside the "if
	batheal(100,50) = 33" function. If anything else is entered, including an
	invalid value or the user loses the game, then the game will redirect to
	"lose".*/
}
/*   legacy code:::::::::::
void battle() {

		cout << " What will you do?\n\n";

		cout << "a) Punch \n b) Use flamethrower \n c) Shoot \n";
		string choice;
		cin >> choice;

		if (choice == "a") {

		  cout << "The ghost now has " << h2(hpn) << " health points.";
		  battle();


		}
  }*/

int main() {
	int score;
	score = 0;

	/*int xxx;
	xxx = batheal(100,50,0);
	cout << xxx;*/
	string dan; // string for player's name
	cout << "Hello. Welcome to the game. You will be presented with multiple "
			"choices. Please make sure you enter the correct string. For "
			"example, if you are presented with \"yes\" or \"no\" write yes or "
			"no. No caps or alternate spellings like \"yeah\". Also, this game "
			"is incomplete; there are bugs. for example, during certain "
			"sequences, entering an invalid character will make you win the "
			"game. So please don't do that :p. But let's get "
			"started.\n\n\n\nWhat is your name?\n  ";
	cin >> dan;
	cout << "\n\nYou Wake Up in a strange room. You see a door. Go in it?"
		 << endl;
	string x;
	cin >> x;

	// First{
	if (x == "yes") {
		score = score + 10;
		cout << "You see nothing but a dark alley. You hear some faint cries "
				"and roars. As you slowly walk down, some lights turn on. You "
				"appear to be in an abandoned Hotel... except not!!! Now, Do "
				"you..."
			 << endl
			 << " a) Go out the window b) Go down the stairs c) Keep walking"
			 << endl;
		string walkInput; // entry for walk decision
		// C NOT FINISHED
		cin >> walkInput;
		if (walkInput == "a") {
			score = score - 5;
			cout << "You open up a window and attempt to escape. However, you "
					"clumsily fall due to nothing really holding your fall.";
		}
		if (walkInput == "b") {
			score = score + 20;
			cout << "You go down the stairs. You walk all the way to the "
					"bottom floor, where there appears to be some light. As "
					"you peer through the entrance to the area, you think you "
					"might see someone walking. Should you a) Walk through or "
					"b) Wait a minute?"
				 << endl;
			string walkInput2;
			cin >> walkInput2;
			if (walkInput2 == "a") {
				score = score + 10;
				cout << "You slowly walk through the area. You see a figure "
						"approaching You! You run and run and run, but you "
						"come to a turn. Should you go left or right?"
					 << endl;
				string dirInput;
				cin >> dirInput;
				// LEFT
				if (dirInput == "left") {
					score = score + 10;
					cout << endl
						 << "You turn left and find a rather large cafeteria. "
							"You see many different tables, counters, and many "
							"other large objects to hide, so you hide. "
							"However, the man slowly roams the area waiting. "
							"How many minutes do you hide?"
						 << endl;
					int hide;
					cin >> hide;
					if (hide < 15 || hide == 15 || hide > 45) {
						score = score - 10;
						cout
							<< endl
							<< "After about " << hide
							<< " minutes, you get out of your hiding place and "
							   "roam the cafeteria. The place seems unusually "
							   "clean. Unfortuneatly, before you can examine "
							   "much more, the figure comes bolting at you, "
							   "and before you know it, he gets you.";
					}

					if (hide > 15 && hide < 45) {
						score = score + 10;
						cout << endl
							 << "After about " << hide
							 << " minutes, you get out of your hiding place "
								"and roam the cafeteria. The place seems "
								"unusually clean. The mysterious figure seems "
								"to have left.\nNow, while going around the "
								"cafeteria, you find a dog. It seems to be "
								"injured. Being a really good vegan person man "
								"guy hillary voter that you are, you care for "
								"it. What do you name it?\n";
						string dog;
						cin >> dog;
						cout
							<< "You and " << dog
							<< " walk around the hotel. What is your next "
							   "destination?\n a)The Kitchen b)The Wash Room\n";
						string boss;
						cin >> boss;

						// BOSS BATTLE 1

						if (boss == "a") {
							score = score;
							cout << "\n\n\n\n\nYou go into the kitchen and "
									"theres a ghost!!!! Oh noo!!!!!! You "
									"better kill him before he spooks "
									"you!!\n\n\n\n\n\n\n\n\n\n\n\n";
							int subscore;
							subscore = batheal(100, 50, 0);
							// cout << subscore;

							if (subscore > 20) {
								cout << subscore;
								score = score + 100;
								cout << "Congratulations! You beat the "
										"ghost!\n\nUpon killing him, you and "
									 << dog
									 << " walk around. After defeating the "
										"ghost, you find that the window is "
										"open, and you are on the first floor. "
										"So, you jump out and escape the "
										"building. You runaway as fast as you "
										"can. You then notice that the "
										"mysterious figure is chasing you. You "
										"run and run, but you trip. As the "
										"figure approaches you, "
									 << dog
									 << " comes in. He sacrifices himself for "
										"you. While the figure is taking his "
										"sweet time with the dog, you run "
										"along the road until you find you are "
										"back in the city.\n\nYou never "
										"figured out why you were in that "
										"building and what the figure was, but "
										"you will always remember how "
									 << dog
									 << " saved your life.\n\n\n\nEND OF "
										"GAME\n\nBoss battle chosen: Kitchen "
										"Ghost\n\nPoints: ";

							}

							else {
								"sss.";
							}

							/*hpn = h2(hpn);
							cout << hpn << "\n\n"; */
						}
						if (boss == "b") {
							cout << "\n\n\n\n\nYou go into the Washroom. "
									"Suddenly, you hear a voice. \"Why, hello "
								 << dan
								 << "! Would you like to come with me and "
									"FLOAT! WE ALL FLOAT DOWN HERE!!\" Oh no! "
									"It's pennywise from the hit movie IT that "
									"you can currently see in theaters! You "
									"have no choice but to fight him! "
									"\n\n\n\n\n\n\n\n\n\n\n\n";
							int subscore;
							subscore = batheal2(100, 50, 0);
							// cout << subscore;

							if (subscore > 20) {
								cout << subscore;
								score = score + 100;
								cout
									<< "Congratulations! You beat pennny wise! "
									   "Unfortunately, while you run away, he "
									   "doesn't exactly seem dead. No, he "
									   "chases after you and "
									<< dog << ". \"COME BACK HERE " << dan
									<< " YOU NO GOOD HOOLIGAN!!! COME AND "
									   "FLOAT WITH ME YOU MEATBAG!! Suddenly, "
									   "you trip over a Draco. You find the "
									   "one and only savior of music Lil Pump! "
									   "\"Ayy, iss lil pump. now whatdafuk is "
									   "dat clown b***?\" \"Why, hello child! "
									   "Would you like to come and float with "
									   "me?\" Suddenly, lil pump spills lean "
									   "on pennywise. Then pennywise starts to "
									   "disintegrate and you and "
									<< dog
									<< "are safe. You thank Lil Pump as he "
									   "dies of xan overdose. You never "
									   "figured out why you were in that "
									   "building and what the figure was, but "
									   "you will always remember how Lil Pump "
									   "saved your life.\n\n\n\nEND OF "
									   "GAME\n\nBoss battle chosen: Washroom "
									   "Ghost\n\nPoints: ";
							}
						}
						// FINISH
					}
					if (hide > 45) {
						cout << "You waited too long. The figure comes and "
								"kills you.";
					}
				}
				if (dirInput == "right") {
					score = score + 10;
					cout << "\n\nYou run to the right. You look around. It's a "
							"bit hard to see. But you appear to be in some "
							"sort of lounge area- or the main area. There are "
							"couches and, strangely, a running fountain. But "
							"you are startled as a mysterious being is sitting "
							"in one of the chairs! What is his name?\n";
					string tom;
					cin >> tom;
					cout << "\"Why, hello " << dan << ".\" " << tom
						 << " says. \"Didn't expect to see you here! Trying to "
							"escape??\"";
					string quick;
					cin >> quick;
					if (quick == "yes") {
						score = score + 5;
						cout << "\"Thought so!!";
					}
					if (quick == "no") {
						score = score - 5;
						cout << "\"You liar!";
					}
					cout << " But whatever. Perhaps I shall let you go. But, "
							"you have to win my game. Do you comply, "
						 << dan << "?\"";
					string yessorno;
					cin >> yessorno;
					if (yessorno == "yes") {
						cout << "\n\nOh how splendid!! Well let's get started. "
								"Tell me a number between 10 and 100. ";

						float gameno;
						cin >> gameno;

						cout << "\nAlright. Let me test out to see if you a "
								"functional meatbag, "
							 << dan
							 << "! Now, I am going to give you some math. What "
								"is your number..";
						cout << "\n\nDivided by 2?";
						float gameno2;
						float gameno3;
						float gameno4;
						cin >> gameno2;
						if (gameno2 == gameno / 2) {
							score = score + 5;
							srand(time(NULL));
							int iSecret;
							iSecret = rand() % 100 + 1;
							float gmm;
							gmm = gameno + iSecret;
							cout << "Perfect! No, what is your number plus "
								 << iSecret << "?\n";
							cin >> gameno3;

							if (gameno3 == gmm) {
								score = score + 5;
								float iSecret2;
								float gnn;
								iSecret2 = rand() % 100 + 1;
								gnn = (gmm + (gameno / 2)) - iSecret2;
								cout << "OOOH YESSS!!!! NOW, WHAT IS THE "
										"PREVIOUS 2 NUMBERS ADDED UP THEN "
										"SUBTRACTED BY  "
									 << iSecret2;
								cin >> gameno4;
								if (gameno4 == gnn) {
									score = score + 10;
									cout << "\n\n\nOOOOOOOOOOOOH "
											"YEAHHHHH!!!!!!\n\n"
										 << tom
										 << " is a bit... excited. "
											"\"CONGRATULATIONS, "
										 << dan
										 << ", YOU MEATBAG!!! PROCEED INTO THE "
											"NEXT AREA!!!!!\n\nWhere do you go "
											"next? \n\na) The Kitchen\n\n b) "
											"The Washroom";

									string boss;
									cin >> boss;

									// BOSS BATTLE 1 (copy from above)

									if (boss == "a") {
										score = score;
										cout << "\n\n\n\n\nYou go into the "
												"kitchen. Suddenly, there's a "
												"ghost!!! OOOHHHHH SPOOKY!!! "
												"The ghost  says that he's "
												"gonna 'eat your meat' or "
												"something it dosens't matter "
												"There's a god damn GHOST IN "
												"THE "
												"KITCHEN!!!!"
												"\n\n\n\n\n\n\n\n\n\n\n\n";
										int subscore;
										subscore = batheal(100, 50, 0);
										// cout << subscore;

										if (subscore > 20) {
											cout << subscore;
											score = score + 100;
											cout
												<< "Congratulations! You beat "
												   "the ghost!\n\nUpon killing "
												   "him, you walk around. "
												   "After defeating the ghost, "
												   "you find that the window "
												   "is open, and you are on "
												   "the first floor. So, you "
												   "jump out and escape the "
												   "building. You runaway as "
												   "fast as you can. You then "
												   "notice that the mysterious "
												   "figure is chasing you. You "
												   "run and run, but you trip. "
												   "As the figure approaches "
												   "you, "
												<< tom
												<< " comes in. \"I SAID ID "
												   "HELP YA, YA MEATBAG!!\"He "
												   "sacrifices himself for "
												   "you. While the figure is "
												   "taking his sweet time with "
												<< tom
												<< ", you run along the road "
												   "until you find you are "
												   "back in the city.\n\nYou "
												   "never figured out why you "
												   "were in that building and "
												   "what the figure was, but "
												   "you will always remember "
												   "how "
												<< tom
												<< " saved your "
												   "life.\n\n\n\nEND OF "
												   "GAME\n\nBoss battle "
												   "chosen: Kitchen "
												   "Ghost\n\nPoints: ";

										}

										else {
											"sss.";
										}
									}
									if (boss == "b") {
										cout << "\n\n\n\n\nYou go into the "
												"Washroom. Suddenly, you hear "
												"a voice. \"Why, hello "
											 << dan
											 << "! Would you like to come with "
												"me and FLOAT! WE ALL FLOAT "
												"DOWN HERE!!\" Oh no! It's "
												"pennywise from the hit movie "
												"IT that you can currently see "
												"in theaters! You have no "
												"choice but to fight him! "
												"\n\n\n\n\n\n\n\n\n\n\n\n";
										int subscore;
										subscore = batheal2(100, 50, 0);
										// cout << subscore;

										if (subscore > 20) {
											cout << subscore;
											score = score + 100;
											cout << "Sorry, ending currently "
													"unfinished.";
											cout << "Congratulations! You beat "
													"pennny wise! "
													"Unfortunately, while you "
													"run away, he doesn't "
													"exactly seem dead. No, he "
													"chases after you. \"COME "
													"BACK HERE "
												 << dan
												 << " YOU NO GOOD HOOLIGAN!!! "
													"COME AND FLOAT WITH ME "
													"YOU MEATBAG!! Suddenly, "
													"you trip over a Draco. "
													"You find the one and only "
													"savior of music Lil Pump! "
													"\"Ayy, iss lil pump. now "
													"whatdafuk is dat clown "
													"bi***?\" \"Why, hello "
													"child! Would you like to "
													"come and float with me?\" "
													"Suddenly, lil pump spills "
													"lean on pennywise. Then "
													"pennywise starts to "
													"disintegrate and you are "
													"safe. You thank Lil Pump "
													"as he dies of xan "
													"overdose. You never "
													"figured out why you were "
													"in that building and what "
													"the figure was, but you "
													"will always remember how "
													"Lil Pump saved your "
													"life.\n\n\n\nEND OF "
													"GAME\n\nBoss battle "
													"chosen: Washroom "
													"Ghost\n\nPoints: ";
										}
									}

								} else {
									score = score - 10;
									cout << "\n\n\nSorry, you are incorrect, "
										 << dan << "! Goodbye!";
								}
							}

							else {
								score = score - 10;
								cout << "\n\n\nSorry, you are incorrect, "
									 << dan << "! Goodbye!";
							}
						}
						if (yessorno == "no") {
							score = score - 10;
							cout << "\n\n\"Ahhhh, well that's too bad. :'C. I "
									"really wanted to play with you! Well, "
									"goodbye!\"";
						}
					}
				}

				if (walkInput2 == "b") {
					cout << "You wait a minute. You hear someone coming down "
							"the stairs. Panicked, you run out the door- but "
							"unfortunately, some mysterious figures aproach "
							"you and put you out.";
				}
			}
		}

		// Second
		if (x == "no") {
			cout << "You wait a few minutes. Nothing seems to happen. Do you "
					"want to wait a lil more?\n";
			string xx;
			cin >> xx;
			if (xx == "no") {
				score = score - 10;
				main();
			}
			if (xx == "yes") {
				cout << "You wait a little while longer. A ghastly figure "
						"comes in. He tells you his name is... er... wait... "
						"What's his name?\n";
				string bob;
				cin >> bob;
				cout << "\nOk. So " << bob
					 << " tells you this: \"Hello. You have been specially "
						"selected for some research. Please do not worry; you "
						"shall be safe. Come with me and I will explain "
						"further\"\n\na) Go with him \nb) Refuse/Attack\n\n";
				string z;
				cin >> z;
				if (z == "a") {
				}
				if (z == "b") {
					cout << "\"I cannot take this for an answer, you useless "
							"meatbag!\"\n\n"
						 << bob << " knocks you out. You striked too early!!";
					score = score - 10;
				}
			}
		} else {
			cout << endl
				 << "GAME OVER. \n\nScore: " << score << "\n\nPlease Restart.";
		}
		return 0;
	}
}
