#pragma warning(disable: 4996)
#include <iostream>
#include <ctime>
#include "node.h"
#include"hashing.h"
#include "user_graph.h"
#include"tree.h"
#include"coloring.cpp"
using namespace std;



void design() 
{
    cout << endl << endl;
    cout << setw(49) << setfill(' ') << "";
    cout <<YELLOW<<"*" << setw(14) << setfill('=') << "" <<"*" << endl << endl;
    cout << BLUE << setw(66) << setfill(' ')<< "! Mini Instagram !" << endl << endl;
    cout << setw(49) << setfill(' ') << "";
    cout << YELLOW << "*" << setw(14) << setfill('=') << "" << "*" <<RESET<< endl << endl;
}

bool password_strength(string s)
{
    if (s.length() < 8) {
        return false;
    }

    bool hasDigit = false;
    bool hasSpecial = false;

    // Check for uppercase, lowercase, digits, and special characters
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            hasDigit = true;
        }
        else if (!(c >= 'A' && c <= 'Z') &&
            !(c >= 'a' && c <= 'z') &&
            !(c >= '0' && c <= '9')) {
            hasSpecial = true;
        }
    }

    // Check if password has at least one of each type
    if ( !hasDigit || !hasSpecial) {
        return false;
    }

    return true;
}

void main_functionality()
{
    int choice;
    HashTable ht;
    tree userTree;
    //declared the graph and gave its initial size
    Graph G(10);
   

    while (true) {
        cout<<BG_BLUE<<YELLOW << "Enter the operation you would like to perform: " <<RESET<< endl;
        cout<<YELLOW << " ->1. Sign up \n ->2. Log in \n ->3. Display users \n ->4. Search users "<<RESET << endl;
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1: {  // Sign up
            string username, password, city;
            cin.ignore();
            cout << BG_BLUE << YELLOW << "Enter a unique username: "<<RESET;
            getline(cin, username);
            cout << BG_BLUE << YELLOW << "Enter password: "<<RESET;
            cin >> password;
            if (!password_strength(password)) //checking strength of password
            {
                cout <<UNDERLINE<<RED<< "Password not strong enough !! " << endl << "Must be of min length 8, must contain at least one digit and special character ! " <<RESET<< endl << endl << endl;
                main_functionality();
            }
            cout << BG_BLUE << YELLOW << "Enter city: "<<RESET;
            cin >> city;

            cout << endl;
            ht.insertUser(username, password, city);  // Insert user into hash table
            cout << endl;
            userTree.insert(username); // Insert username into the tree
            //Here below two lines are used for adding nodes to the graph just when it is creted and added alogside to hash table
            Node* user = ht.findUser(username, password);
            G.addUser(user);
            break;
        }
        case 2: {  // Log in
            string username, password;
            cin.ignore();
            cout <<BG_BLUE<<YELLOW<< "Enter username: "<<RESET;
            getline(cin, username);
            cout <<BG_BLUE<<YELLOW<< "Enter password: "<<RESET;
            cin >> password;

            Node* user = ht.findUser(username, password);  // Find the user
            Node* user1 = G.findUser(username);

            cout << endl;

            if (user) {
                cout<<YELLOW << "Login successful !~" <<RESET<< endl;
                // Perform operations as logged-in user (e.g., add posts, view posts)
                int action;
                cout << endl;
                while (true) {
                    cout<<BG_BLUE<<YELLOW << "Choose an action:"<<RESET<<"\n";
                    cout <<YELLOW<< "1. Add post\n";
                    cout << "2. Delete recent post\n";
                    cout << "3. View recent post\n";
                    cout << "4. View all posts\n";
                    cout << "5. Log out\n";
                    cout << "6. Send follow req\n";
                    cout << "7. Send message\n";
                    cout << "8. Check notifications\n";
                    cout << "9. Check Follow requests\n";
                    cout << "10. Display People you are following\n";
                    cout << "11. Display Timeline""\n";
                    cout << "12. See Messages" << RESET << "\n";
                    cin >> action;

                    if (action == 1) {
                        string s;
                        s = user->addpost();  // Add a post
                        G.checkFollowersForStack(user, s, ht);
                    }
                    else if (action == 2) {
                        user->del_recent_post();  // Delete a recent post
                    }
                    else if (action == 3) {
                        user->view_recent();  // View the most recent post
                    }
                    else if (action == 4) {
                        user->view_all();  // View all posts
                    }
                    else if (action == 5) {
                        cout << endl;
                        cout<<YELLOW << "Logging out..."<<RESET<<"\n";
                        break;  // Log out and go back to the main menu
                    }
                    else if (action == 6)
                    {
                        string username;
                        cout<<BG_BLUE<<YELLOW << "Enter username of who you would like to send friend request to: "<<RESET << endl;
                        cin >> username;
                        if (username == user->name) cout << RED << "You can not send friend request to yourself\n";
                        else {
                            if (ht.findUserByUsername(username))
                            {
                                G.AddUniDirectionalEdge(user->name, ht.findUserByUsername(username)->name);
                                ht.findUserByUsername(username)->add_follower(user->name);
                                ht.findUserByUsername(username)->add_follower_notif(user->name);
                            }
                            else
                            {
                                cout << endl;
                                cout << UNDERLINE << RED << "User does not exist bro" << RESET << endl;
                            }
                        }
                    }
                    else if (action == 7)
                    {
                        string username;
                        cout << BG_BLUE << YELLOW << "Enter username of friend you would like to send message to: "<<RESET << endl;
                        cin >> username;
                        if (ht.findUserByUsername(username))
                        {
                           //implement message logic here rafay boss
                            Node* user2 = G.findUser(username);
                            user1->sendMsg(user2);
                            ht.findUserByUsername(username)->add_message_notif(user->name);
                        }
                        else
                        {
                            cout<<UNDERLINE<<RED << "User does not exist bro"<<RESET << endl;
                        }
                    }
                    else if (action == 8)
                    {
                        //check if notification queue is empty
                        if (!user->check_notifs_empty())
                        {
                            user->display_notif_queue();
                        }
                        else
                        {
                            cout << UNDERLINE << RED << "There are no notifications at the moment ! "<<RESET << endl;
                        }
                    }
                    else if (action == 9)
                    {
                        int choice2;
                        
                            while (true)
                            {
                                //first check if follow req queue is empty 
                                if (!user->check_if_empty()) {
                                    user->display_requests();
                                    cout <<YELLOW<< "1. Accept request\n";
                                    cout << "2. Decline request\n";
                                    cout << "3. Accept All\n";
                                    cout << "4. Don't follow back\n";
                                    cout << "0. Exit\n"<<RESET;

                                    cin >> choice2;
                                    if (choice2 == 0)
                                    {
                                        break;
                                    }
                                    else if (choice2 == 1)
                                    {
                                        //if request accepted, add a relation from B to A and dequeue
                                        G.AddBiDirectionalEdge(user->name, user->accept_req());
                                        cout <<YELLOW<< "Friend request accepted ! " <<RESET<< endl;
                                    }
                                    else if (choice2 == 2)
                                    {
                                        //if declined, simply dequeue
                                        Node* user_temp_G = G.findUser(user->fq.front->username);
                                        user_temp_G->deleteEdge(user1);
                                        user->decline_req();
                                        cout << YELLOW << "Friend request declined ! " << endl;
                                    }
                                    else if (choice2 == 3)
                                    {
                                        //jab tak queue khali nahi hoti accept karte jao bhaiiii
                                        while (!user->check_if_empty())
                                        {
                                            G.AddUniDirectionalEdge(user->name, user->accept_req());
                                           
                                        }
                                        cout <<YELLOW<< "All Friend requests accepted ! "<<RESET << endl;
                                    }
                                    else if (choice2 == 4)
                                    {//Changed below
                                        //don't follow back logic
                                        user->accept_req();//Just to dequeue the request from follow requests queue
                                    }
                                }
                                else
                                {
                                    cout<<UNDERLINE<<RED << "There are no follow requests at the moment ! " <<RESET<< endl;
                                    break;
                                }

                            }
                        
                    }
                    else if (action == 10)
                    {
                        //print the followers of the current user
                        G.printFollowers(user);
                    }
                    else if (action == 11)
                    {
                        //view all the posts in the timeline stack for friends
                        user->view_all2();
                    }
                    else if (action == 12) {
                        //changed
                        string user2_name = "";
                        cout<<BG_BLUE<<YELLOW << "Enter the user_name of the user you want to see chat of: "<<RESET;
                        cin >> user2_name;
                        Node* user2 = G.findUser(user2_name);
                        user1->SeeMsgz(user2);
                        }
                    else {
                        cout<<UNDERLINE<<RED << "Invalid choice. Try again.\n"<<RESET;
                    }
                }
            }
            else {
                cout << endl;
                cout<<UNDERLINE<<RED << "Invalid username or password!" <<RESET<< endl;
            }
            break;

        }
        case 3: {  // Display all users
            cout<<BG_BLUE<<YELLOW << "Displaying all users:"<<RESET << endl;
            userTree.display(); // Display users in sorted order
            G.printUsers();
            break;
        }
        case 4: {  // Search for a user
            string username;
            cout << BG_BLUE << YELLOW << "Enter the username to search: "<<RESET;
            cin >> username;

            string result = userTree.search(username);
            if (!result.empty()) {
                cout << BG_BLUE << YELLOW << "User found: " <<RESET<<YELLOW<< result <<RESET<< endl;
            }
            else {
                cout<<UNDERLINE<<RED << "User not found!" <<RESET<< endl;
            }
            break;
        }
        
        default:
            cout << UNDERLINE << RED << "Invalid option. Please try again."<<RESET << endl;
        }
    }
}


int main() {
   
    design();
    main_functionality();
    
}