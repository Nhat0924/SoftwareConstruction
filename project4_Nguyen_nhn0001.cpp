/* 
 * FILE NAME: project4_Nguyen_nhn0001.cpp
 * AUTHOR: Nhat Nguyen - nhn0001
 * Version: 4/8/2023
 * Edit using C++ online compiler/VS Code and compile using g++ in Linux bash shell/AU server.
 * Format using Dr. Li's project 4 hints and sample codes
 * Learned #ifdef from StackOverflow article
 * Source: https://stackoverflow.com/questions/33117233/what-does-purpose-use-ifdef-and-if-in-c
 * Learned how to add a question to the linked list from AlphaCodingSkills article
 * Source: https://www.alphacodingskills.com/cpp/ds/cpp-insert-a-new-node-at-the-end-of-the-linked-list.php
 */

//Libary imports.
#include <iostream>
#include <cassert>
#include <string.h>

using namespace std;
//Structure for creating a linked list that holds a trivia question,answer and point amount.
struct triva_node {
  string question;
  string answer;
  int point;
  triva_node * next;
};
//Global variables
int num_of_questions;
int score = 0;
//creates a pointer to triva_node.
typedef triva_node * ptr_node;
//Prototypes
void init_question_list(ptr_node & q_list);
void add_question(ptr_node & q_list);
int ask_question(ptr_node q_list, int num_ask);
void Unit_Test(ptr_node & q_list);

//creates two versions.
//Learned how #ifdef works with StackOverflow.
//#define UNIT_TESTING
#define triva_quiz
int main() {
  ptr_node node_list = new triva_node;
  //Creates a new trivia game /
  //Sets up three original questions/
  //Sets up loop for user to input his or her own questions.
  //Quiz questions are stored in linked list.

  //Initialization
  #ifdef triva_quiz
  init_question_list(node_list);
  string user_input;

  cout << "*** Welcome to Nguyen's trivia quiz game ***\n";

  do {
    add_question(node_list);
    cout << "Continue? (Yes/No): ";
    getline(cin, user_input);

  } while (user_input.compare("Yes") == 0);
  cout << endl;

  //This is start of Trivia quiz game.
  ask_question(node_list, num_of_questions);
  cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
  #endif

  //Method for testing
  #ifdef UNIT_TESTING
  Unit_Test(node_list);
  #endif

  return 0;
}
//initializes the quiz to have these three questions inputted into the linked list.
void init_question_list(ptr_node & q_list) {
  //ptr_node cur_ptr;
  //ptr_node cur_ptr;
  string bob;
  ptr_node cur_ptr = new triva_node;
  cur_ptr -> question = "How long was the shortest war on record? (Hint: how many minutes)";
  cur_ptr -> answer = "38";
  cur_ptr -> point = 100;
  q_list = cur_ptr;
  q_list -> next = new triva_node;
  cur_ptr = q_list -> next;
  cur_ptr -> question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany?)";
  cur_ptr -> answer = "Bank of Germany";
  cur_ptr -> point = 100;
  cur_ptr -> next = new triva_node;
  cur_ptr = cur_ptr -> next;
  cur_ptr -> question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sport)";
  cur_ptr -> answer = "Wii Sport";
  cur_ptr -> point = 20;
  cur_ptr -> next = NULL;

  num_of_questions = 3;
}
//Learned how to add a question to the linked list from AlphaCodingSkills article
//Source: https://www.alphacodingskills.com/cpp/ds/cpp-insert-a-new-node-at-the-end-of-the-linked-list.php
//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node & q_list) {
  string answer;
  //gets data from user.
  ptr_node new_ptr = new triva_node;
  cout << "Enter a question: ";
  getline(cin, new_ptr -> question);
  cout << "Enter an answer: ";
  getline(cin, new_ptr -> answer);
  cout << "Enter award points: ";
  cin >> new_ptr -> point; // FIXME: cause problems
  cin.ignore();
  new_ptr -> next = NULL;

  triva_node * add = q_list;
  //Loop until reaching the end of the linked list
  while (add -> next != NULL) {
    add = add -> next;
  }
  //Add the new question to the linked list
  add -> next = new_ptr;
  num_of_questions++;
}
//Checks for null value
//Ask the user trivia questions and starts the game
int ask_question(ptr_node q_list, int num_ask) {
  string user_answer;

  ptr_node cur_ptr = q_list;
  if (q_list == NULL)
    return 0;
  if (num_ask <= 0) {
    cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
    return 1;
  } else if (num_of_questions < num_ask) {
    cout << "Warning - there is only " << num_of_questions << " trivia in the list." << endl;
    return 1;
  } else {
    for (int x = 0; x < num_ask; x++) {
      cout << "Question: " << cur_ptr -> question << endl;
      cout << "Answer: ";
      getline(cin, user_answer);
      if (user_answer.compare(cur_ptr -> answer) == 0) {
        cout << "Your answer is correct. You receive " << cur_ptr->point << " points." << endl;
        score += cur_ptr -> point;
        cout << "Your total points: " << score << "\n" << endl;
      } else {
        cout << "Your answer is wrong. The correct answer is: " << cur_ptr -> answer <<endl;
        cout << "Your total points: " << score << "\n" << endl;
      }

      cur_ptr = cur_ptr -> next;
    }

  }
  return 0;
}
//Test cases to check whether the methods work.
void Unit_Test(ptr_node & q_list) {
  cout << "*** This is a debugging version ***";
  ptr_node node_list = q_list;
  init_question_list(node_list);
  cout << "\nUnit Test Case 1: Ask no question. The program should give a warning message." << endl;
  ask_question(node_list, 0);
  cout << "Case 1 Passed\n\n";

  cout << "Unit Test Case 2: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
  ask_question(node_list, 1);
  assert(score == 0);
  cout << "Case 2.1 Passed\n\n";

  cout << "Unit Test Case 2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
  ask_question(node_list, 1);
  assert(score > 0);
  score = 0;
  cout << "Case 2.2 Passed\n\n";

  cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
  ask_question(node_list, 3);
  cout << "Case 3 Passed\n\n";

  cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
  ask_question(node_list, 5);
  cout << "Case 4 Passed";

  cout << "\n\n*** End of the Debugging Version ***\n";
}