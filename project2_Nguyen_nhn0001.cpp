/* FILE NAME: project2_Nguyen_nhn0001.cpp
 * AUTHOR: Nhat Nguyen - nhn0001
 * Version: 2/22/2023
 * Edit using C++ online compiler/VS Code and compile using g++ in Linux bash shell/server.
 * Format using Dr. Li's project 2 hints
 * Learn assert funcntion from website programiz
 * Source: https://www.programiz.com/cpp-programming/assertions
 * Talked with Nathan Hunter about how to implement shoot functions.
 */

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;
/* 
* Input: A_alive indicates Aaron is alive true for alive, false for dead 
*   B_alive indicates Bob is alive 
*   C_alive indicates Charlie is alive 
* Return: true if at least two are alive otherwise return false 
*/
bool at_least_two_alive (bool A_alive, bool B_alive, bool C_alive);

/* 
* Call by reference 
* Strategy 1: Everyone shoots to kill the highest accuracy player alive 
* Input: B_alive indicates Bob is alive or dead 
*  C_alive indicates Aaron is alive or dead 
* Return: Change B_alive into false if Bob is killed 
*    Change C_alive into false if Charlie is killed 
*/
void Aaron_shoots1 (bool & B_alive, bool & C_alive);

/* 
* Call by reference 
* Input: A_alive indicates Aaron is alive or dead 
*  C_alive indicates Charlie is alive or dead 
* Return: Change A_alive into false if Aaron is killed 
*    Change C_alive into false if Charlie is killed 
*/
void Bob_shoots (bool & A_alive, bool & C_alive);

/* 
* Call by reference 
* Input: A_alive indicates Aaron is alive or dead 
*  B_alive indicates Bob is alive or dead 
* Return: Change A_alive into false if Aaron is killed 
*    Change B_alive into false if Bob is killed 
*/
void Charlie_shoots (bool & A_alive, bool & B_alive);

/* 
* Call by reference 
* Strategy 2: Aaron intentionally misses if both are alive 
* Input: B_alive indicates Bob is alive or dead 
*  C_alive indicates Aaron is alive or dead 
* Return: Change B_alive into false if Bob is killed 
*    Change C_alive into false if Charlie is killed 
*/
void Aaron_shoots2 (bool & B_alive, bool & C_alive);

//Simple method to implement pause function in linux 
void Press_any_key (void);

//TEST PROTOTYPES 
void test_at_least_two_alive (void);
void test_Aaron_shoots1 (void);
void test_Bob_shoots (void);
void test_Charlie_shoots (void);
void test_Aaron_shoots2 (void);

//VARIABLES 
const int TOTAL_RUNS = 10000;
const int a_chance = 33;
const int b_chance = 50;
int aaronWins1, bobWins, charlieWins = 0;
int aaronWins2 = 0, bobWins2 = 0, charlieWins2 = 0;
bool aaronAlive = true;
bool bobAlive = true;
bool charlieAlive = true;
bool aaron_a, bob_a, charlie_a;


int
main ()
{
  //Initializes Random number generator's seed and calls test functions 
  cout << "*** Welcome to Nguyen's Duel Simulator ***\n";
  srand (time (0));
  test_at_least_two_alive ();
  Press_any_key ();
  test_Aaron_shoots1 ();
  Press_any_key ();
  test_Bob_shoots ();
  Press_any_key ();
  test_Charlie_shoots ();
  Press_any_key ();
  test_Aaron_shoots2 ();
  Press_any_key ();

  //Starts strategy 1 and runs 10,000 times 
  cout << "Ready to test strategy 1 (run 10000 times):\n";
  Press_any_key ();
  for (int i = 0; i < TOTAL_RUNS; i++)
    {
      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;
      //generate the duel simulator
      while (at_least_two_alive (aaronAlive, bobAlive, charlieAlive))
	{
	  if (aaronAlive)
	    {
	      Aaron_shoots1 (bobAlive, charlieAlive);
	    }
	  if (bobAlive)
	    {
	      Bob_shoots (aaronAlive, charlieAlive);
	    }
	  if (charlieAlive)
	    {
	      Charlie_shoots (aaronAlive, bobAlive);
	    }
	}
      if (aaronAlive)
	{
	  aaronWins1++;
	}
      if (bobAlive)
	{
	  bobWins++;
	}
      if (charlieAlive)
	{
	  charlieWins++;
	}
    }
  cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast <
    double >(aaronWins1) / TOTAL_RUNS *
    100 << "%\n" << "Bob won " << bobWins << "/10000 duels or " << static_cast
    <
    double >(bobWins) / TOTAL_RUNS *
    100 << "%\n" << "Charlie won " << charlieWins << "/10000 duels or " <<
    static_cast < double >(charlieWins) / TOTAL_RUNS * 100 << "%\n" << endl;

  //Reinitializes variables and starts strategy 2 to run 10,000 times 
  cout << "Ready to test strategy 2 (run 10000 times):\n";
  Press_any_key ();
  for (int i = 0; i < TOTAL_RUNS; i++)
    {
      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;
      //generate the duel simulator
      while (at_least_two_alive (aaronAlive, bobAlive, charlieAlive))
	{
	  if (aaronAlive)
	    {
	      Aaron_shoots2 (bobAlive, charlieAlive);
	    }
	  if (bobAlive)
	    {
	      Bob_shoots (aaronAlive, charlieAlive);
	    }
	  if (charlieAlive)
	    {
	      Charlie_shoots (aaronAlive, bobAlive);
	    }
	}
      if (aaronAlive)
	{
	  aaronWins2++;
	}
      if (bobAlive)
	{
	  bobWins2++;
	}
      if (charlieAlive)
	{
	  charlieWins2++;
	}
    }
  cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast <
    double >(aaronWins2) / TOTAL_RUNS *
    100 << "%\n" << "Bob won " << bobWins2 << "/10000 duels or " <<
    static_cast <
    double >(bobWins2) / TOTAL_RUNS *
    100 << "%\n" << "Charlie won " << charlieWins2 << "/10000 duels or " <<
    static_cast < double >(charlieWins2) / TOTAL_RUNS * 100 << "%\n" << endl;

  if (aaronWins1 > aaronWins2)
    {
      cout << "Strategy 1 is better than strategy 2.\n";
    }
  else
    {
      cout << "Strategy 2 is better than strategy 1.\n";
    }

  return 0;
}

//Implementation of functions.
bool
at_least_two_alive (bool A_alive, bool B_alive, bool C_alive)
{
  //return true if at least ab, bc, or ac alive. False otherwise
  if (A_alive && B_alive)
    {
      return true;
    }
  else if (A_alive && C_alive)
    {
      return true;
    }
  else if (B_alive && C_alive)
    {
      return true;
    }
  return false;
}
//Test for at least two alive
void
test_at_least_two_alive (void)
{
  cout << "Unit Testing 1: Function - at_least_two_alive()\n";

  cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
  assert (1 == at_least_two_alive (true, true, true));
  cout << "\tCase passed ... \n";

  cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
  assert (1 == at_least_two_alive (false, true, true));
  cout << "\tCase passed ... \n";

  cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
  assert (1 == at_least_two_alive (true, false, true));
  cout << "\tCase passed ... \n";

  cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
  assert (1 == at_least_two_alive (true, true, false));
  cout << "\tCase passed ... \n";

  cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
  assert (0 == at_least_two_alive (false, false, true));
  cout << "\tCase passed ... \n";

  cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
  assert (0 == at_least_two_alive (false, true, false));
  cout << "\tCase passed ... \n";

  cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
  assert (0 == at_least_two_alive (true, false, false));
  cout << "\tCase passed ... \n";

  cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
  assert (0 == at_least_two_alive (false, false, false));
  cout << "\tCase passed ... \n";
}

 //Talked with Nathan Hunter about how to implement shoot functions.
 //shoot functions change the alive status of one person if shootResult match hit accuracy.
void
Aaron_shoots1 (bool & B_alive, bool & C_alive)
{
  assert (aaronAlive);
  int shootResult = rand () % 100;
  if (shootResult <= a_chance && C_alive)
    {
      C_alive = false;
      return;
    }
  if (shootResult <= a_chance && B_alive)
    {
      B_alive = false;
      return;
    }
}
//Test function for Aaron shoot function
void
test_Aaron_shoots1 (void)
{
  cout <<
    "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

  bob_a = true;
  charlie_a = true;
  cout << "\tCase 1: Bob alive, Charlie alive\n"
    << "\t\tAaron is shooting at Charlie\n";
  Aaron_shoots1 (bob_a, charlie_a);

  bob_a = false;
  charlie_a = true;
  cout << "\tCase 2: Bob dead, Charlie alive\n"
    << "\t\tAaron is shooting at Charlie\n";
  Aaron_shoots1 (bob_a, charlie_a);

  bob_a = true;
  charlie_a = false;
  cout << "\tCase 3: Bob alive, Charlie dead\n"
    << "\t\tAaron is shooting at Bob\n";
  Aaron_shoots1 (bob_a, charlie_a);
}
//Bob shoots have a 50% chance of changing alive status for Aaron and Charlie
void
Bob_shoots (bool & A_alive, bool & C_alive)
{
  assert (bobAlive);
  int shootResult = rand () % 100;
  if (shootResult <= b_chance && C_alive)
    {
      C_alive = false;
      return;
    }
  if (shootResult <= b_chance && A_alive)
    {
      A_alive = false;
      return;
    }
}
//Test function for Bob shoot function.
void
test_Bob_shoots (void)
{
  cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

  aaron_a = true;
  charlie_a = true;
  cout << "\tCase 1: Aaron alive, Charlie alive\n"
    << "\t\tBob is shooting at Charlie\n";
  Bob_shoots (aaron_a, charlie_a);

  aaron_a = false;
  charlie_a = true;
  cout << "\tCase 2: Aaron dead, Charlie alive\n"
    << "\t\tBob is shooting at Charlie\n";
  Bob_shoots (aaron_a, charlie_a);

  aaron_a = true;
  charlie_a = false;
  cout << "\tCase 3: Aaron alive, Charlie dead\n"
    << "\t\tBob is shooting at Aaron\n";
  Bob_shoots (aaron_a, charlie_a);

}
//Charlie shoots will change alive state for both Aaron and Bob immediately.
void
Charlie_shoots (bool & A_alive, bool & B_alive)
{
  assert (charlieAlive);
  if (B_alive)
    {
      B_alive = false;
      return;
    }
  if (A_alive)
    {
      A_alive = false;
      return;
    }
}
//Test function for Charlie shoot function.
void
test_Charlie_shoots (void)
{
  cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

  aaron_a = true;
  charlie_a = true;
  cout << "\tCase 1: Aaron alive, Bob alive\n"
    << "\t\tCharlie is shooting at Bob\n";
  Charlie_shoots (aaron_a, charlie_a);

  aaron_a = false;
  charlie_a = true;
  cout << "\tCase 2: Aaron dead, Bob alive\n"
    << "\t\tCharlie is shooting at Bob\n";
  Charlie_shoots (aaron_a, charlie_a);

  aaron_a = true;
  charlie_a = false;
  cout << "\tCase 3: Aaron alive, Bob dead\n"
    << "\t\tCharlie is shooting at Aaron\n";
  Charlie_shoots (aaron_a, charlie_a);
}
//Aaron attempts new strategy by allowing Bob and Charlie to shoot each other.
void
Aaron_shoots2 (bool & B_alive, bool & C_alive)
{
  bool miss;

  // If Charlie and Bob are alive, miss the shot
  if (C_alive && B_alive)
    {
      miss = false;
    }
  else
    {
      miss = rand() % 100 <= a_chance;
    }

  if (miss && C_alive)
    {
      C_alive = false;
      return;
    }
  if (miss && B_alive)
    {
      B_alive = false;
      return;
    }
}
//Test function for Aaron new shoot function
void
test_Aaron_shoots2 (void)
{
  cout <<
    "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

  bob_a = true;
  charlie_a = true;
  cout << "\tCase 1: Bob alive, Charlie alive\n"
    << "\t\tAaron intentionally misses his first shot\n"
    << "\t\tBoth Bob and Charlie are alive.\n";
  Aaron_shoots2 (bob_a, charlie_a);

  bob_a = false;
  charlie_a = true;
  cout << "\tCase 2: Bob dead, Charlie alive\n"
    << "\t\tAaron is shooting at Charlie\n";
  Aaron_shoots2 (bob_a, charlie_a);

  bob_a = true;
  charlie_a = false;
  cout << "\tCase 3: Bob alive, Charlie dead\n"
    << "\t\tAaron is shooting at Bob\n";
  Aaron_shoots2 (bob_a, charlie_a);
}
//Implement the press any key.
void
Press_any_key (void)
{
  cout << "Press any key to continue...";
  cin.ignore ().get ();
}
