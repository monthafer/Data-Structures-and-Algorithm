#include <cstdlib>
#include <iostream>
#include <string>
#include "node.cpp"
#include "useful.h"

using namespace std;

void ask_and_move(bnode<string>*& current_ptr);
bnode<string>* beginning_tree();
void instruct();
void learn(bnode<string>* leaf_ptr);
void play(bnode<string>* current_ptr);

int main() {
    bnode<string>* taxonomy_root_ptr;
    taxonomy_root_ptr = beginning_tree();
    do {
        system("cls");
        instruct();
        play(taxonomy_root_ptr);
    } while (inquire("Shall we play again?"));
    cout << "Thank you for teaching me a thing or two." << endl;
    return EXIT_SUCCESS;
}

void ask_and_move(bnode<string>*& current_ptr) {
    cout << current_ptr -> data;
    if (inquire(" Please answer")) {
        current_ptr = current_ptr -> left;
    } else {
        current_ptr = current_ptr -> right;
    }
}

bnode<string>* beginning_tree() {
    bnode<string> *root_ptr;
    bnode<string> *child_ptr;

    const string root_question("Are you a mammal?");
    const string left_question("Are you bigger than a cat?");
    const string right_question("Do you live underwater?");
    const string animal1("Kangaroo");
    const string animal2("Mouse");
    const string animal3("Trout");
    const string animal4("Robin");

    root_ptr = new bnode<string>(root_question);

    child_ptr = new bnode<string>(left_question);
    child_ptr -> left = new bnode<string>(animal1);
    child_ptr -> right = new bnode<string>(animal2);
    root_ptr -> left = child_ptr;

    child_ptr = new bnode<string>(right_question);
    child_ptr -> left = new bnode<string>(animal3);
    child_ptr -> right = new bnode<string>(animal4);
    root_ptr -> right = child_ptr;

    return root_ptr;
}

void instruct() {
    cout << "Welcome to the Animal Guessing Game!" << endl;
    cout << "Think of an animal, and I will try to guess it." << endl;
    cout << "I will ask you questions, and you should answer with 'yes' or 'no'." << endl;
    cout << "If I don't guess correctly, please help me learn a new animal!" << endl;
    cout << endl;
}

void learn(bnode<string>* leaf_ptr) {
    string guess_animal;
    string correct_animal;
    string new_question;

    guess_animal = leaf_ptr -> data;
    cout << "\nI give up. What are you? " << endl;
    cout << "Animal: ";
    getline(cin, correct_animal);
    
    cout << "\nPlease type a yes/no question that will distinguish a ";
    cout << correct_animal << " from a " << guess_animal << "." << endl;
    cout << "Your question: ";
    getline(cin, new_question);

    leaf_ptr->data = new_question;
    cout << "\nAs a " << correct_animal << ", " << new_question << endl;
    if (inquire("Please answer")) {
        leaf_ptr -> left = new bnode<string>(correct_animal);
        leaf_ptr -> right = new bnode<string>(guess_animal);
    } else {
         leaf_ptr -> left = new bnode<string>(guess_animal);
         leaf_ptr -> right = new bnode<string>(correct_animal);
    }
}

void play(bnode<string>* current_ptr) {
    cout << "\nThink of an animal, then press the return key.";
    eat_line();
    while (!current_ptr->is_leaf()) {
        cout << endl;
        ask_and_move(current_ptr);
    }
    cout << ("\nMy guess is " + current_ptr->data);
    if (!inquire(". Am I right?")) {
        learn(current_ptr);
    } else {
        cout << "I knew it all along!" << endl;
    }
}