#include <iostream>
#include <string>
#include "profile.h"

Profile::Profile(std::string usrn, std::string dspn) {
  username = usrn;
  displayname = dspn;
}

Profile::Profile() {
  //Default Profile constructor (username="", displayname="")
  username = "";
  displayname = "";
}

std::string Profile::getUsername() {
  std::string usrn = username;
  return usrn;
}

std::string Profile::getFullName() {
  std::string full = displayname + " (@" + username + ")";
  return full;
}

void Profile::setDisplayName(std::string dspn) {
  displayname = dspn;
}
