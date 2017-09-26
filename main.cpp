#include <iostream>
#include "2048/game.cpp"

using namespace std;


int main() {

    Two048::Game game(3);
    Two048::Game game2(3);


    game.transition(Two048::Up);
    cout << "bullshit";
    return 0;
}
