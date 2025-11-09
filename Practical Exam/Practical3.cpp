/*Consider the playlist in a music player. Implement a playlist feature in music player application
using singly linked list. Each song in the playlist is represented as a node in the linked list. Each
node contains information about the song (such as title or artist or duration, etc.).
The playlist should allow users to:
a. Add songs
b. Remove songs
c. Display the entire playlist
d. Play specific songs*/

#include<iostream>
using namespace std;

class Song{
public:
    string title;
    Song *next;

    Song(string nm){
        title = nm;
        next = nullptr;
    }
};

class List{

    Song *head;

public: 
    List(){
        head = nullptr;
    }

    void addSongs(){

        string s;
        cout<< "Enter Song Name: ";
        cin >> s;

        Song *newSong = new Song(s);

        if(!head){
            head = newSong;
        }
        else{
            Song *temp = head;

            while(temp->next){
                temp = temp->next;
            }

            temp->next = newSong;
        }

        cout << endl << "Added: " << s << endl;
    }

    void removeSong(){
        Song *temp = head;
        Song *prev = NULL;

        string title;
        cout << "Enter Song Title to remove: ";
        cin >> title;

        while(temp && temp->title != title){
            prev = temp;
            temp = temp->next;
        }

        if(!temp)
        {
            cout << "Song not Found...!!!";
            return;
        }
        
        if(!prev){
            head = temp->next;
            delete temp;
        }
        else{
            prev->next = temp->next;
            delete temp;
        }

        cout << "Deleted " << title << endl;
    }

    void displaySong(){

        if(!head){
            cout << "List is Empty..!!";
            return;
        }

        Song *temp = head;
        cout << "Songs List: " << endl;

        while(temp){
            cout << temp->title << endl;
            temp = temp->next;
        }
    }

    void specificSong(){

        if(!head){
            cout << "List is Empty..!!";
            return;
        }

        string title;
        cout << "Enter Song Title to Play: ";
        cin >> title;

        Song *temp = head;

        while(temp){
            if(temp->title == title){
                cout << "Playing Song: " << temp->title << endl;
                return;
            }
            temp = temp->next;
        }
    }
};

int main(){

    int n;
    List l;

    do{

        cout << "--------------------------------------------Choice-------------------------------------------" << endl;
        cout << "1. Add Song \t 2. Remove Song \t 3. Display Songs \t 4. Specific Song \t 0. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> n;

        switch(n){

            case 1:
            l.addSongs();
            break;

            case 2:
            l.removeSong();
            break;

            case 3:
            l.displaySong();
            break;

            case 4:
            l.specificSong();
            break;

            case 0:
            cout << "Exiting....";
            break;

            default:
            cout << "Invalid input..!!";
            break;
        }

    }while(n != 0);

    return 0;
}