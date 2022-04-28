// author - Anurag Patil
// c++ 20-version
// Date - 27-04-2022

#include <iostream>
using namespace std;

const int max_chapters = 10;
struct Node {
    string name;
    int count;
    Node* child[max_chapters];
};

Node* newnode() {
    Node* newnode = new Node();
    return newnode;
}

Node* Insert(Node* temp) {
    int tchapters;
    temp = newnode();
    cout << "Enter the name of the book : ";
    cin >> temp -> name;
    cout << "Enter the number of chapters : ";
    cin >> tchapters;
    temp -> count = tchapters;
    for (int i=0; i<tchapters; ++i) {
        temp -> child[i] = newnode();
        cout << "Enter the name of the chapter :";
        cin >> temp -> child[i] -> name;

        cout << "Enter the number of Sections in the " << temp -> child[i] -> name << ":";
        cin >> temp -> child[i] -> count;
        int n = temp -> child[i] -> count;

        for (int j=0; j<n; ++j) {
            cout << "Enter the name of the Section" << j+1 << " :";
            temp -> child[i] -> child[j] = newnode();
            cin >> temp -> child[i] -> child[j] -> name;
        }
    }

    return temp;
}

void Display(Node* temp) {
    if (temp != NULL) {
        cout << "*********BOOK CONTENT*********"<<"\n";
        cout << "Name of the book : " << temp -> name << "\n";
        int nchapters;
        nchapters = temp -> count;
        for(int i=0; i<nchapters; ++i) {
            cout << "[" << i+1 << "]" << "  " << (temp -> child[i] -> name) << "\n";
            int n = temp -> child[i] -> count;
            for (int j=0; j<n; ++j) {
                cout << "       " << j+1 << "." << "  " << temp->child[i]->child[j]->name << "\n";
            }
        }
    }
    else{
    cout << "No book found!";
    }
}

int main() {

    Node* root = NULL;
    while(1) {
        cout << "1. Create a book" << "\n";
        cout << "2. display the book" << "\n";
        cout << "3. Exit" << "\n";

        int option;
        cout << "Enter any option : ";
        cin >> option;
        if (option == 1) {root = Insert(root);}
        else if (option == 2) {Display(root); exit(1);}
        else if (option == 3) exit(1);
        else {cout << "Invalid Option !"; exit(1);}
    }
    
    return 0;
}