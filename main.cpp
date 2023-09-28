/*
BLACKJACK program by Danny Vicario
2018-2019

I use the srand function for finding random numbers as card
chrono::seconds dura( 1); AND
 this_thread::sleep_for( dura ); are used to let console wait a second to pace it out a bit
 "Conversionf rom time_T to unsigned int" warning does not cause any problems in program as it only runs for 1 second
 //A select few comments might be legacy from an earlier version of the program where the variables were all different. Don't mind these

Posssible Changes:
Hearts/Clubs/Diamonds/Spades not incorporated
Kings/Queens/Jacks not incorporated
Maybe clean up code

Bugs:
None

*/


#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <string>
#include <time.h>
using namespace std;

int playerWins = 0; //Number of wins the player has. Whenever player wins, +1
int dealerWins = 0; //Number of wins the dealer has. Whenever dealer wins, +1
int playerMoney = 0; //Money player has
int dealerMoney = 0; //Unused as of now
int bet = 0; //amount of money player bets. Either is added or subtracted from playerMoney




int clrscr() //I don't think this is ever called but just incase its here
{
  cout << "\033[2J\033[1;1H";
  return 0;
}



/*Guacamole N i g g a playerWins
*/


/*
LEGACY CODE FOR CALCULATOR, UNRELATED TO BLACKJACK
//                                   CALCULATOR MY GOOD man
int add(int one, int two) {
  int total;
  total = one + two;
  return total;
}
int sub(int one, int two) {
  int total;
  total = one - two;
  return total;
}
int mul(int one, int two) {
  int total;
  total = one * two;
  return total;
}
int divi(int one, int two) {
  int total;
  total = one / two;
  return total;
}
int spe(int one, int two) {
  srand (time(NULL));
  int iSecret;
  int i2;
     
      iSecret = rand() % 100 + 1;
        i2 = rand() % 100 + 1;
  int t1;
   int t2;
    int t3;
     int t4;
  t1 = one + 34;
  t2 = t1 * iSecret;
  t3 = t2 + i2 - 22;
  t4 = two + one / 2 + t3;
  return t4;
  
}
//                                    CALCULATOR DONE
*/
int oppFirstCard() { //Creates the first card the opponent has. It's seperate from the opp() function to emulate real Blackjack by showing the player one of the dealer's cars
  srand (time(NULL));
int card1; // First card, added to i2 in first draw
card1 = rand() % 11 + 1;        // i1-i4 declare 4 different random values betweem 1 and 10 (i.e. cards)
  return card1;
}

int oppCard = 0;

int oppRandom(int card) {

/*
Okay, here's how the oppRandom function works. This will also explain how the opponent determines if they should hit or hold. 
(Shown in the if statements below) The opponent always draws two cards, which add up to a single value. The opponent has a possibility of 
hitting 3 more times. If the card values together are less than 11, then the opponent will hit no matter what. But if it's more than 11,
then should they hit? Well, the computer isn't human so the best thing we can do is use RNG. But obviously an opponent is more likely to
hit if they have 13 points than if they had 20 points. Basically, various random values are generated (ran, ran2, ran3, etc.). Three chance values
are generated, each for two_values, three_values, and four_values. (Note: card values and summary variables are made regardless of if the
opponent actually decides to hit.) So, for each chance value, the sum variables are put into this function. If the sum is a certain number, 
the chance value will be returned
EXAMPLE: --
two_values (card1 + card2) = 14
ran (RNG for two_values) = 73
oppRandom(14) = 40
73 > 40
Opponent hits. Gets a card3 value of 6, thus having a sum of 20
ran2(RNG for three_values): 47
oppRandom(20) = 95
47 !> 95
Opponent is done. Has a value of 20.

NOTE: chance values might need slight tweaking
*/
if (card < 11) {
  return 0;
}
if (card == 11) {
    return 5;
  }
  if (card == 12) {
    return 5;
  }
  if (card == 13) {
    return 10;
  }
  if (card == 14) {
    return 20;
  }
    if (card == 15) {
    return 40;
  }
    if (card == 16) {
    return 50;
  }
    if (card == 17) {
    return 75;
  }
    if (card == 18) {
    return 85;
  }
    if (card == 19) {
    return 90;
  }
    if (card == 20) {
    return 95;
  }
    if (card == 21) {
    return 100;
  }
    if (card > 21) {
      return 100;
    }

  return 50;
}

int results(int got, int opp_cards) { //Displays final results of game. Also makes changes to playerMoney if applicable 
cout << "\nThe opponent has a total of " << opp_cards << " points.\n";
 if (opp_cards > 21 || got > opp_cards) { // If the opponent busted or the player's value is bigger than the opponent's then the player wins.
   cout << "Congratulations my good man, you have won the game!\n\n";
   playerWins += 1;
   playerMoney += bet;
   
 }
 if (opp_cards > got && opp_cards < 22) { // If the player's value is lower than the opponent's and the opponent got less than 21 (applicable for winning) then the player loses.
   cout << "Your opponent wins.\n\n";
   playerMoney -= bet;
   dealerWins += 1;
   
 }
 if (opp_cards == got) { // If the two values are the same, that's a tie
   cout << "Nobody wins, but nobody loses.\n\n";
 
 }

 return 0;
}

int opp(int got) {
  //The opponent does blackjack
  //The opp function is a very basic AI
  //The "bot" is a collection of simple algorithms designed to emulate what a human would do
	//10 Cards, their sums, random values, chance values and flags are initialized and calculated. Obviously in Blackjack you're not always gonna have a set
	//number of cards, but I'm initializing all just to make things easier. It's only a computer player after all

  cout << "\nThe opponent is drawing his cards.";
  
  
    srand (time(NULL)); //initializes rand()
  //CARD VARIABLES
  int card1 = oppCard; //First Card
  int card2 = rand() % 11 + 1; // Second card, added to i1 in first draw
  int card3 = rand() % 11 + 1; // Third possible card
  int card4 = rand() % 11 + 1; // Fourth possible card
  int card5 = rand() % 11 + 1; // Fifth possible card... you get the gist
  int card6 = rand() % 11 + 1;
  int card7 = rand() % 11 + 1;
  int card8 = rand() % 11 + 1;
  int card9 = rand() % 11 + 1;
  int card10 = rand() % 11 + 1;
  //SUM VARIABLES
  int two_values = card1 + card2; // the sum of the first two cards
  int three_values = two_values + card3; //the previous two cards plus the third card
  int four_values = three_values + card4; //sum of cards 1-3 plus card4
  int five_values = four_values + card5; //same thing happems
  int six_values = five_values + card6; 
  int seven_values = six_values + card7;
  int eight_values = seven_values + card8;
  int nine_values = eight_values + card9;
  int ten_values = nine_values + card10;

	int opp_cards; // Total cards at the end of an if statement, i.e. when the opponent decides to hold and has a total
  //RNG VARIABLES, between 1 and 100
  int ran = rand() % 100 + 1; // Random value 1
  int ran2 = rand() % 100 + 1; // Random value 2
  int ran3 = rand() % 100 + 1;
  int ran4 = rand() % 100 + 1;
  int ran5 = rand() % 100 + 1;
  int ran6 = rand() % 100 + 1;
  int ran7 = rand() % 100 + 1;
  int ran8 = rand() % 100 + 1;
  int ran9 = rand() % 100 + 1;
  //chance for individual sum values. See oppRandom for more info
  int chance = oppRandom(two_values);
  int chance2 = oppRandom(three_values);
  int chance3 = oppRandom(four_values);
  int chance4 = oppRandom(five_values);
  int chance5 = oppRandom(six_values);
  int chance6 = oppRandom(seven_values);
  int chance7 = oppRandom(eight_values);
  int chance8 = oppRandom(nine_values);
  int chance9 = oppRandom(ten_values);
  //card flags are ints with a value of 0 or 1. They determine if the opponent has actully hit, meaning the program will display that the opponent has hit. 
  //0 = not shown (default)
  //1 = will show
  int card3flag = 0; 
  int card4flag = 0; 
  int card5flag = 0; 
  int card6flag = 0; 
  int card7flag = 0; 
  int card8flag = 0; 
  int card9flag = 0;
  int card10flag = 0;


  int mkay; // i dont think this does anything but i'm worried if I remove it something will go wrong
     
        
        
    

        if (ran > chance || two_values < 12) { 
          //2 Cards
               //To emulate a human player, this algorithim will "hit" (add another random value, the "card") if the sum is less than 12.
			//Otherwise, the bot can stil hit if over the chance value, but will only do so if the random value called (ran) is bigger than the chance value.
			//Chance value depends on how many points the opponent currently has which was determined in initalization earlier.
			//Hit = continues to the next nested if loop, adding another card
			//Hold = goes to else, which turns on flags for cards that were hit and determines the final points value

 
// cout << "\nDEBUG MODE; ii = " << ii << "\nRandom value is " << ran2;
              if (ran2 > chance2 || three_values < 12) {
				  //3 cards
                //The opponent has now hit so the third card is added to tal
                 //same effect as first if; if total is less than 12 or the random value s bigger than chance
                      if (ran3 > chance3 || four_values < 12) { 
                        //4 Cards in total
                        //Another random value; if over chance this time cuz the dumb bot had enough chances
                          if(ran4 > chance4 || five_values < 13) {
                            //5 Cards
                             if(ran5 > chance5 || six_values < 13) {
                               //6 Cards
                               if (ran6 > chance6 || six_values < 13) {
                                 //7 Cards
                                    if (ran7 > chance7 || seven_values < 14) {
										//8 cards
                                        if (ran8 > chance8 || eight_values < 14) {
											//9 cards 
											//The opponent will only draw a limit of 10 cards so there are no further if functions to draw more cards
											//It's very very unlikely all 10 cards will be drawn in the first place
                                          card3flag = 1;
                                          card4flag = 1;
                                          card5flag = 1;
                                          card6flag = 1;
                                          card7flag = 1;
                                          card8flag = 1;
                                          card9flag = 1;
                                          card10flag = 1;
										  //the reason 10 is added because, if the opponent wants to hit, there are not more further cards so there shouldn't
										  //be any more if functions. Card 10 is simply added
                                          opp_cards = ten_values;
                                        }
                                        else {
                                        card3flag = 1;
                                        card4flag = 1;
                                        card5flag = 1;
                                        card6flag = 1;
                                        card7flag = 1;
                                        card8flag = 1;
                                        card9flag = 1;
                                        opp_cards = nine_values;
                                        }
                                    }
                                    else {
                                    card3flag = 1;
                                    card4flag = 1;
                                    card5flag = 1;
                                    card6flag = 1;
                                    card7flag = 1;
                                    card8flag = 1;
                                    opp_cards = eight_values;
                                    }
                               }
                               else {
                                 card3flag = 1;
                                card4flag = 1;
                                card5flag = 1;
                                card6flag = 1;
                                card7flag = 1;
                                opp_cards = seven_values;
                               }
                             }
                             else {
								  //6 Cards Final
                                card3flag = 1;
                                card4flag = 1;
                                card5flag = 1;
                                card6flag = 1;
                                opp_cards = six_values;
                             }



                          }
                          else {
							   //5 Cards Final
                        card3flag = 1;
                        card4flag = 1;
                        card5flag = 1;
                        opp_cards = five_values;
                          }
                      
                      }
                      
                      else {
						  //4 Cards Final
                          card3flag = 1;
                          card4flag = 1;
                          opp_cards = four_values;
                      }
              
              
// cout << "\nDEBUG MODE; iii = " << iii;
 // cout << "\nDEBUG MODE; iiii = " << iiii;
              }
              else {
				 //IF opponent doesn't want to hit, only the three values are his final points
                card3flag = 1;
                opp_cards = three_values;
              }
        }
       
       else {
		   //Card1 and 2 flags don't exist because 2 cards are drawn no matter what so we don't need flags for them
         opp_cards = two_values; // If the card value is over 15 and the random value doesn't draw a number higher than the goal, the algorithim will stop and the total will be stored in "done". this emulates the "Hold" option in the game
       } 
  
  
  //BUG: Immediately displays flag5, not anything else
  chrono::seconds dura( 1); // The game waits a few seconds before showing the results
 this_thread::sleep_for( dura );
 
 cout << " Opponent draws two cards, a " << card1 << " card and a " << card2 << " card. A total of " << two_values << ".\n";
  this_thread::sleep_for( dura );
  //If a card flag is 1, that means the opponent decided to hit and as a result the programw will display that
  if (card3flag == 1) {

     cout << "Opponent draws a " << card3 << " card. A total of " << three_values << ".\n";
      this_thread::sleep_for( dura );
  }
  else {
     
  }

 if (card4flag == 1) {

     cout << "Opponent draws a " << card4 << " card. A total of " << four_values << ".\n";
       this_thread::sleep_for( dura );
  }
  else {
     
  }

  if (card5flag == 1) {
   
     cout << "Opponent draws a " << card5 << " card. A total of " << five_values << ".\n";
       this_thread::sleep_for( dura );
  }
  else {
     
  }

    if (card6flag == 1) {
   
     cout << "Opponent draws a " << card6 << " card. A total of " << six_values << ".\n";
       this_thread::sleep_for( dura );
  }
  else {
     
  }

    if (card7flag == 1) {
   
     cout << "Opponent draws a " << card7 << " card. A total of " << seven_values << ".\n";
       this_thread::sleep_for( dura );
  }
  else {
     
  }

    if (card8flag == 1) {
   
     cout << "Opponent draws a " << card8 << " card. A total of " << eight_values << ".\n";
       this_thread::sleep_for( dura );
  }
  else {
     
  }
    if (card9flag == 1) {
   
     cout << "Opponent draws a " << card9 << " card. A total of " << nine_values << ".\n";
       this_thread::sleep_for( dura );
  }
  else {
     
  }
    if (card10flag == 1) {
   
     cout << "Opponent draws a " << card10 << " card. A total of " << ten_values << ".\n";
       this_thread::sleep_for( dura );
  }
  else {
     
  }


 cout << "\n...";
 this_thread::sleep_for( dura );  
 
 results(got, opp_cards);

 //INSERT FUNCTION
 
return 0;
}
int hitMe (int card_value) {
  srand (time(NULL));
   int mkay;
  card_value = card_value + rand() % 11 + 1;
  if (card_value < 22) { // If the  opponent chooses hit this function will go off. A random value between 1 and 10 is added. If it does not exceed 21 (here) than the player has another chance of either hitting or holding.
  //cout << "You recieve a " << card_value << " card.";
  cout << "\nYou have " << card_value << " as a total. What will you do?\n\n1) Hit Me \n2) Hold\n";
  cin >> mkay;
    if (mkay == 1) {
    hitMe(card_value);
    }
    if (mkay == 2) {
      int win;
    win = opp(card_value);
    if (win == 33) {
      return 33;
    }
    }
  }
  if (card_value > 21) { //If the player hits and goes over 21, that's a bust
    cout << "\nYou have " << card_value << " as a total. \n You've gone and busted my good man. Thanks for playing.\n\n";
    playerMoney -= bet;
    dealerWins += 1;
  }
return 0;
}


int start_blackjack() { //Starts  up the game
  srand (time(NULL));  
  int card_1; //randomly generated first card
  int card_2; //randomly generated second card
  oppCard = oppFirstCard();

  int first_value; //card 1 + card 2
  int decision; 
     
      card_1 = rand() % 11 + 1;
        card_2 = rand() % 11 + 1;
        first_value = card_1 + card_2;
  cout << "\n-----------------\n";
  cout << "You recieve two cards. One is a " << card_1 << " and the other is a " << card_2 << ".";
  cout << "\nYou have " << first_value << " as a total. The dealer has a visble " << oppCard << " value. What will you do?\n\n1) Hit Me \n2) Hold\n";
  cin >> decision;
  if (decision == 1) {
   
    hitMe(first_value);
  }
  if (decision == 2) {
    opp(first_value);
  }
  
return 0;  
}

////////////////////////////////////////////////////////////////////////////////

int main () {
  cout << "Hello and welcome to Blackjack!\n";
  cout << "HOW TO PLAY: Enter in an integer for how many games you'd like to play. For a single game, you'll be given a value from two cards and can see one of the opponent's card values. You can hit or hold, hitting gives you a random card between 1 and 10. Once you go over 21, you're out! But once you choose hold, the opponent will go through an algorithm where his cards are chosen.\n\n";
  cout << "There are currently no Jacks, Kings or Queens. This is more about the numbers part of blackjack\n";
  //cout << "POINTS: \n";
  cout << "\nHow many games would you like to play?\n\n\n";
   int input;
  cin >> input;
  cout << "\nHow much money do you have? $";
  cin >> playerMoney; 
 int startingMoney = playerMoney;
  //cout << "\n\n\nType in \"start\" to start \n";

  

 
  int i;
  for (i = 0; i < input; i++) {
          if (playerMoney < 1) {
            cout << "\nSorry, you ran out of money. Your session is over and you're gonna go home broke, bud";
            break;
          }
      cout << "\nYou have $" << playerMoney;
      cout << "\nHow much money do you want to bet? $";
      
      cin >> bet;
          if (bet > playerMoney) {
            cout << "\nYou don't have that much money stoopid! For safety reasons, we gotta end this. Sorry, come back next time.";
            break;
          }
      start_blackjack();
      chrono::seconds dura(1);
      this_thread::sleep_for( dura );
  }

  cout << "\n\n\n\n\nFINAL RESULTS:";
  cout << "\nGames: " << i;
  cout << "\nPlayer wins: " << playerWins;
  cout << "\nDealer wins: " << dealerWins;
  cout << "\nTies: " << i - (playerWins + dealerWins);
  cout << "\nRemaining Money: $" << playerMoney << "\n";
 /*
  if (playerMoney > startingMoney){
    cout << "\nYou started with " << startingMoney << ", giving a net gain of " << playerMoney - startingMoney;
  }
  if (startingMoney < playerMoney) {
  cout << "\nYou started with " << startingMoney << ", giving a net loss of " << startingMoney - playerMoney;
  }
*/

  
  
  
 
  


  
  
  
  
  
  
  
  
  
  /* cout << "TYPE A #";
  int num;
  cin >> num;
  */
  


  return 0;
} 



