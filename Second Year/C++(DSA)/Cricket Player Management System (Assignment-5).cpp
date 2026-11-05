// Assignment 5: Cricket Player Management Using Linked List
#include <iostream>
#include <string>
using namespace std;

struct PlayerNode{
    int playerID, age;
    string name, mobNo;
    PlayerNode* next;
    PlayerNode(int id, string n, string mob, int a){
        playerID = id;
        name = n;
        mobNo = mob;
        age = a;
        next = NULL;
    }
};

class CricketPlayerSystem{
private:
    PlayerNode* head;
public:
    CricketPlayerSystem(){
        head = NULL;
    }

    void addPlayer(){
        int id, a;
        string n, mob;
        cout<<"Enter Player ID: ";
        cin>>id;
        cout<<"Enter Player name: ";
        cin>>n;
        cout<<"Enter Player's Age: ";
        cin>>a;
        cout<<"Enter Player's Contact Number: ";
        cin>>mob;
        PlayerNode* newNode = new PlayerNode(id, n, mob, a);
        newNode->next = head;
        head = newNode;
        cout<<"\nPlayer Details Saved Successfully\n"<<endl;
        cout<<"\n======================================================\n"<<endl;
    }

    void deletePlayer() {
        if(head == NULL){
            cout<<"No Data of Players has been Recorded in the System"<<endl;
            cout<<"\n======================================================\n"<<endl;
            return;
        }
        int id;
        cout<<"Enter Player ID to delete: ";
        cin>>id;
        PlayerNode* temp = head;
        PlayerNode* prev = NULL;
        if(head->playerID == id){
            head = head->next;
            delete temp;
            cout<<"Player Deleted Successfully\n"<<endl;
            cout<<"\n======================================================\n"<<endl;
            return;
        }
        while(temp != NULL && temp->playerID != id){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"Player with ID "<<id<<" not found."<<endl;
            cout<<"\n======================================================\n"<<endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout<<"Player Deleted Successfully\n"<<endl;
        cout<<"\n======================================================\n"<<endl;
    }

    void displayPlayer(){
        if(head == NULL){
            cout<<"No Data of Players has been Recorded in the System"<<endl;
            cout<<"\n======================================================\n"<<endl;
            return;
        }
        PlayerNode* temp = head;
        int i = 1;
        cout<<"PLAYER'S LIST:"<<endl;
        while(temp != NULL){
            cout<<"\n========== Player "<<i<<" Details =========="<<endl;
            cout<<"\nID: "<<temp->playerID<<endl;
            cout<<"NAME: "<<temp->name<<endl;
            cout<<"AGE: "<<temp->age<<endl;
            cout<<"MOBILE NUMBER: "<<temp->mobNo<<endl;
            cout<<"=============================================="<<endl;
            temp = temp->next;
            i++;
        }
    }

    void searchPlayer(){
        if(head == NULL){
            cout<<"No Data of Players has been Recorded in the System"<<endl;
            cout<<"\n======================================================\n"<<endl;
            return;
        }
        string searchName;
        cout<<"Enter Player Name to search: ";
        cin>>searchName;
        PlayerNode* temp = head;
        while(temp != NULL){
            if(temp->name == searchName){
                cout<<"\nPlayer Found!"<<endl;
                cout<<"ID: "<<temp->playerID<<endl;
                cout<<"NAME: "<<temp->name<<endl;
                cout<<"AGE: "<<temp->age<<endl;
                cout<<"MOBILE NUMBER: "<<temp->mobNo<<endl;
                cout<<"\n======================================================\n"<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"Player with name "<<searchName<<" not found."<<endl;
        cout<<"\n======================================================\n"<<endl;
    }

    void updateMob(){
        if(head == NULL){
            cout<<"No Data of Players has been Recorded in the System"<<endl;
            cout<<"\n======================================================\n"<<endl;
            return;
        }
        int id;
        string newMob;
        PlayerNode* temp = head;
        cout<<"Enter Player's ID whose number is to be updated: ";
        cin>>id;
        while(temp != NULL){
            if(temp->playerID == id){
                cout<<"Enter New Mobile Number: ";
                cin>>newMob;
                temp->mobNo = newMob;
                cout<<"Mobile Number Updated Successfully!"<<endl;
                cout<<"\n======================================================\n"<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"Player with ID "<<id<<" not found."<<endl;
        cout<<"\n======================================================\n"<<endl;
    }
};

int main(){
    int choice;
    CricketPlayerSystem obj;
    cout<<"======================================================"<<endl;
    cout<<"========== Cricket Player Management System =========="<<endl;
    cout<<"======================================================"<<endl;
    do{
        cout<<"\nSelect your choice:"<<endl;
        cout<<"1. Add a New Player"<<endl;
        cout<<"2. Delete a Player"<<endl;
        cout<<"3. Display List of All Players"<<endl;
        cout<<"4. Search a Player by Name"<<endl;
        cout<<"5. Update Mobile No of Player"<<endl;
        cout<<"6. Exit the System"<<endl;

        cout<<"\nEnter your choice: ";
        cin>>choice;
        cout<<"\n======================================================\n"<<endl;
        switch(choice){
            case 1:{
                obj.addPlayer();
                break;
            }
            case 2:{
                obj.deletePlayer();
                break;
            }
            case 3:{
                obj.displayPlayer();
                break;
            }
            case 4:{
                obj.searchPlayer();
                break;
            }
            case 5:{
                obj.updateMob();
                break;
            }
            case 6:{
                cout<<"======================================================"<<endl;
                cout<<"\n\tE X I T I N G  P R O G R A M  !!!\n"<<endl;
                cout<<"======================================================"<<endl;
                break;
            }
            default:{
                cout<<"------------------------------------------------------"<<endl;
                cout<<"\tI N V A L I D  C H O I C E  !!!"<<endl;
                cout<<"------------------------------------------------------"<<endl;
                break;
            }
        }
    }while(choice != 6);
    return 0;
}