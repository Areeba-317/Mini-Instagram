#include"user_graph.h"
#include"hashing.h"
#include"coloring.cpp"

Graph::Graph(int c = 1) {
    capacity = c;
    no_of_users = 0;
    Users = new Node[capacity];
    /*for (int i = 0; i < capacity; i++) {
        Users[i] = nullptr;
    }*/
}
void Graph::AddBiDirectionalEdge(string user1_name, string user2_name) 
    {
        Node* user1 = findUser(user1_name);
        Node* user2 = findUser(user2_name);
        if ((user1 != nullptr) && (user2 != nullptr)) {
            //assume user1 has an edge towards 
            chat_stack* c = nullptr;
            edge* e = user2->edges;
            while (e) {
                if (e->user2->name == user1->name) {
                    c = e->chat;//to get address of chat_stck of first edge
                    e->status = "active";
                }
                e = e->nxt;
            }
            user1->add_edge(user2, "active", c);
            //edge* e = user2->edges;
            ////as it is the newly added edge so it will be at the last
            //while (e->user2 != user1) {
            //    e = e->nxt;
            //}
            //edge* e1 = e->user2->edges;
            //while (e1->user2 != user1) {
            //    e1 = e1->nxt;
            //}
            //e1->status = "active";
            //e->chat = e1->chat;
        }
        else cout<<UNDERLINE<<RED << "Error: Atleast one of the users does exits\n"<<RESET;

        /*
        if ((user1 != nullptr) && (user2 != nullptr)) {
            user1->add_edge(user2);
            user2->add_edge(user1);
        }
        else cout << "Error: Atleast one of the users does exits\n";*/
    }
void Graph::AddUniDirectionalEdge(string user1_name, string user2_name) {
    Node* user1 = findUser(user1_name);
    Node* user2 = findUser(user2_name);
    /*for (int i = 0; i < no_of_users; i++) {
        if (Users[i].name == user1_name) user1 = &Users[i];
        else if (Users[i].name == user2_name) user2 = &Users[i];
    }*/
    if ((user1 != nullptr) && (user2 != nullptr)) {
        user1->add_edge(user2, "pending", new chat_stack);
    }
    else cout << UNDERLINE << RED << "Error: Atleast one of the users does exits\n"<<RESET;
}
//void Graph::addUser(Node* user) {
//    // Check if the user already exists
//    for (int i = 0; i < no_of_users; i++) {
//        if (Users[i].name == user->name) {
//            std::cout << "User already exists.\n";
//            return;
//        }
//    }
//
//    // If the user doesn't exist, add them
//    if (no_of_users == capacity) {
//        // Double the capacity
//        capacity *= 2;
//        Node* newUsers = new Node[capacity];
//        for (int i = 0; i < no_of_users; i++) {
//            newUsers[i] = Users[i];
//        }
//        delete[] Users;
//        Users = newUsers;
//    }
//
//    Users[no_of_users] = *user; // Copy the user's data
//    no_of_users++;
//}
void Graph::addUser(Node* user) {
    // Check if the user already exists
    for (int i = 0; i < no_of_users; i++) {
        if (Users[i].name == user->name) {
            std::cout << UNDERLINE << RED << "User already exists.\n"<<RESET;
            return;
        }
    }

    // If the user doesn't exist, add them
    if (no_of_users == capacity) {
        // Double the capacity
        capacity *= 2;
        Node* newUsers = new Node[capacity];
        for (int i = 0; i < no_of_users; i++) {
            newUsers[i] = Users[i];
        }
        delete[] Users;
        Users = newUsers;
    }

    Users[no_of_users] = *user; // Copy the user's data
    no_of_users++;
}
void Graph::printUsers() {
    cout<<BG_BLUE<<YELLOW << "Users and their followers :\n"<<RESET;
    for (int i = 0; i < no_of_users; i++) {
        cout<<YELLOW << Users[i].name << ": "<<RESET;
        edge* cur = Users[i].edges;
        if (!cur) cout <<YELLOW<< "No Friends (Introvert)"<<RESET;
        while (cur) {
            cout << cur->user2->name << " ";
            cur = cur->nxt;
        }
        cout << endl;
    }
}

void Graph::printFollowers(Node* user)
{
    cout<<BG_BLUE<<YELLOW << "Followers: \n"<<RESET;
    //iterate through the list of users to find the passed user, and print the followers
    for (int i = 0; i < no_of_users; i++) {
        if (Users[i].name == user->name)
        {
            cout<<YELLOW << Users[i].name << ": "<<RESET;
            edge* cur = Users[i].edges;
            if (!cur) cout<<YELLOW << "No followers !"<<RESET;
            while (cur) {
                cout << cur->user2->name << " ";
                cur = cur->nxt;
            }
            cout << endl;
        }
    }
}

void Graph::checkFollowersForStack(Node* user, string s, HashTable &ht)
{
    //iterate through the list of users to find the friends
    for (int i = 0; i < no_of_users; i++) {
        if (Users[i].name == user->name)
        {
            edge* cur = Users[i].edges;
           // if (!cur) cout << "No followers !";
            while (cur) {
                //find the user from hashtable add the post to their stack
                ht.findUserByUsername(cur->user2->name)->addpost2(s);
                cur = cur->nxt;
            }
           
        }
    }

}

Node* Graph::findUser(string user_name) {
    Node* user = nullptr;
    for (int i = 0; i < no_of_users; i++) {
        if (user_name == Users[i].name) user = &Users[i];
    }
    return user;
}
Graph::~Graph() {
    delete[] Users;
}