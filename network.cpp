#include <iostream>
#include <string>
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
  if ((usrn != "") && (numUsers < 20)) {
    for (int i = 0;i < numUsers;i++) {
      user = profiles[i].username;
      if (user == usrn) {
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
