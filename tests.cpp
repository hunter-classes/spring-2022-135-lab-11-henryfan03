#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Profile Default Constructor") {
  Profile p0;
  CHECK(p0.getUsername() == "");
}

TEST_CASE("getUsername() cases") {
  Profile p1("marco", "Marco");
  CHECK(p1.getUsername() == "marco");
  p1.setDisplayName("Marco Rossi");
  CHECK(p1.getUsername() == "marco");
  Profile p2("tarma1", "Tarma Roving");
  CHECK(p2.getUsername() == "tarma1");
  }

TEST_CASE("getFullName() Cases") {
  Profile p1("marco", "Marco");
  CHECK(p1.getFullName() == "Marco (@marco)");
  p1.setDisplayName("Marco Rossi");
  CHECK(p1.getFullName() == "Marco Rossi (@marco)");
  Profile p2("tarma1", "Tarma Roving");
  CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");
}

/*TEST_CASE("Network Default Constructor") {
  Network networktest;
  Network empty;
  CHECK(networktest.numUsers == empty.numUsers);
}*/

TEST_CASE("Network Adduser") {
  Network nw;
  CHECK(nw.addUser("mario", "Mario") == true);
  CHECK(nw.addUser("mario 2", "Mario2") == true);
  CHECK(nw.addUser("mario", "Mario2") == false);
  CHECK(nw.addUser("mario 2", "Mario2") == false);
  CHECK(nw.addUser("mario-2", "Mario2") == false);
  CHECK(nw.addUser("mario3", "Mario3") == true);
  CHECK(nw.addUser("mario4", "Mario4") == true);
  CHECK(nw.addUser("mario5", "Mario5") == true);
  CHECK(nw.addUser("mario6", "Mario6") == true);
  CHECK(nw.addUser("mario7", "Mario7") == true);
  CHECK(nw.addUser("mario8", "Mario8") == true);
  CHECK(nw.addUser("mario9", "Mario9") == true);
  CHECK(nw.addUser("mario10", "Mario10") == true);
}

TEST_CASE("Networking Following") {
  Network nw;
  // add three users
  CHECK(nw.addUser("mario", "Mario") == true);
  CHECK(nw.addUser("luigi", "Luigi") == true);
  CHECK(nw.addUser("yoshi", "Yoshi") == true);
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");

  // make them follow each other
  CHECK(nw.follow("mario", "luigi") == true);
  CHECK(nw.follow("mario", "yoshi") == true);
  CHECK(nw.follow("luigi", "mario") == true);
  CHECK(nw.follow("luigi", "yoshi") == true);
  CHECK(nw.follow("yoshi", "mario") == true);
  CHECK(nw.follow("yoshi", "luigi") == true);
  nw.follow("mario", "luigi");
  nw.follow("mario", "yoshi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");
  nw.follow("yoshi", "luigi");

  // add a user who does not follow others
  nw.addUser("wario", "Wario");

  /*CHECK(isFollowing("mario", "luigi") == true);
  CHECK(isFollowing("mario", "yoshi") == true);
  CHECK(isFollowing("luigi", "mario") == true);
  CHECK(isFollowing("luigi", "yoshi") == true);
  CHECK(isFollowing("yoshi", "mario") == true);
  CHECK(isFollowing("yoshi", "luigi") == true);
  CHECK(isFollowing("mario", "wario") == false);
  CHECK(isFollowing("wario", "luigi") == false);*/
}
