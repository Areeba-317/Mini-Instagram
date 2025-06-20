# 📸 Mini-Instagram (Data Structures Project)  
  
A micro-version of Instagram built from scratch using core data structures implemented manually (no built-in libraries used!). This console-based app lets users connect, post, and message — all while exploring stacks, queues, graphs, hash maps, and trees under the hood.   
  
> 🔒 All data structures were implemented using **linked lists**, and this was built in **C++ using Visual Studio**.  
  
---  
  
## 🌟 Features & Functionalities  
  
### 👤 User Profiles  
- Unique **username**, password, city  
- Stores **personal posts** (text + timestamp)  

### 👥 Social Graph  
- Users are **nodes**  
- Friendships and follow requests are **edges**  
- Implemented using **Adjacency Lists**  
- Tracks pending requests, blocks, and active/accepted friendships  
  
### 💬 Messaging System  
- Real-time messaging simulated via **queues**  
- **Stacks** are used for conversation history between users  
  
### 📮 Friend Requests  
- Managed with a **Queue (FIFO)** for each user  
- Accept, reject, and notify users in real-time  
  
### 📢 Notifications  
- Each user has a **notifications queue** to store alerts (friend requests, messages, etc.)  
  
### 🗃️ Posts & Newsfeed  
- Personal posts and follower posts stored as **Stacks**  
- Newsfeed uses stack traversal to show the latest content on top  
  
### 🔎 Search Users  
- Efficient searching implemented using a **Binary Search Tree (BST)**  
- O(log n) search time for usernames  
  
### 🧭 Menu Functionality Includes:  
- Signup/Login with password strength and security question reset  
- Sending/canceling/accepting follow requests  
- Posting content and browsing personal/followers’ timelines  
- Messaging mutual followers  
- Viewing notifications and friend requests  
- Searching users  
- Displaying followers  
- Logging out  
  
---  
  
## 💡 Data Structures Used  

| Feature              | Data Structure     | Why?                           |
|----------------------|--------------------|--------------------------------|
| Users + Connections  | Graph (Adj. List)  | To represent social links      |
| Friend Requests      | Queue              | FIFO processing                |
| Notifications        | Queue              | Real-time, ordered display     |
| Posts & Messages     | Stack              | LIFO for latest-first view     |
| Login Auth           | Hash Table         | Fast username/password lookup  |
| User Search          | BST                | Sorted traversal/search        |
  
---  
  
## 🔧 Tech Stack  
  
- **Language**: C++  
- **IDE**: Visual Studio  
- **UI**: Console-based  
  
  
---  

## 🚀 How to Run It  
  
1. Open the `.cpp` files in **Visual Studio**.  
2. Make sure all `.cpp` and `.h` files are part of your solution.  
3. Build & Run then start interacting with the menu like you're on the OG Instagram
  
## 🤝 Project Collaboration  
  
This project was completed in collaboration with Rafay(https://github.com/rafay-7933455). We worked together on planning, execution, and analysis.   
  
### 🧠 Contribution Breakdown:  
- **Areeba** – Notifications, posts and newsfeed, search users, login auth
- **Rafay** – Messaging system, social graph, Friend requests

We collaborated on the entire workflow and shared responsibilities for interpretation, discussion, and project design.  
