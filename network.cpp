#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "profile.h"
#include "network.h"

Network::Network() {
  numUsers = 0;
  Profile profiles[MAX_USERS];
}

/*Network::Network() {

}*/

int Network::findID (std::string usrn) {
  std::string user;
  for (int i = 0;i < MAX_USERS;i++) {
    user = profiles[i].username;
    if (user == usrn) {
      return i;
    }
  }
  return -1;
}

bool Network::addUser(std::string usrn, std::string dspn) {
  std::string user;
  std::string display;
  if ((usrn != "") && (numUsers < 20)) {
    for (int i = 0;i < numUsers;i++) {
      user = profiles[i].username;
      display = profiles[i].displayname;
      if (user == usrn) {
        return false;
      }
      if (display == dspn) {
        return false;
      }
    }
    Profile newUser;
    newUser.username = usrn;
    newUser.displayname = dspn;
    profiles[numUsers] = newUser;
    numUsers += 1;
    return true;
  }
  return false;
}

bool Network::follow(std::string usrn1, std::string usrn2) {
  int index1, index2;
  index1 = findID(usrn1);
  index2 = findID(usrn2);
  if (index1 == -1 || index2 == -1) {
    return false;
  }
  else {
    following[index2][index1] = true;
    following[index1][index2] = true;
  }
  return true;
}

void Network::printDot() {
  std::cout << "diagraph {" << std::endl;
  for (int i = 0;i < numUsers;i++) {
    std::cout << "\t" << "\"@" << profiles[i].getUsername() << "\"" << std::endl;
  }
  std::cout << std::endl;
  std::vector<std::string> connections;
  std::string coordinate;
  for (int i = 0;i < numUsers;i++) {
    for (int j = 0;j < numUsers;j++) {
      coordinate = std::to_string(i) + ":" + std::to_string(j);
      if ((i != j) && (std::count(connections.begin(),connections.end(),coordinate) == false)) {
        connections.push_back(coordinate);
        std::cout << "\t" << "\"@" << profiles[i].getUsername() << "\" -> " << "\"@" << profiles[j].getUsername() << "\"" << std::endl;
      }
    }
  }
  std::cout << "}" << std::endl;
}

/*bool Network::isFollowing(std::string usrn1, std::string usrn2) {
  int index1, index2;
  index1 = findID(usrn1);
  index2 = findID(usrn2);
  return following[index1][index2];
}*/
