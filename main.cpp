#include <iostream>
#include "2048/Two048.cpp"


using namespace std;


int main() {

    Two048::Game game(4);

    game.printGrid();

    Two048::GameState state;

    for(int a=0;a<100;a++) {
        char b;
        cin >> b;
        switch(b) {
            case 'w':
                state = game.transition((Two048::Direction)(0));
                break;
            case 's':
                state = game.transition((Two048::Direction)(1));
                break;
            case 'a':
                state = game.transition((Two048::Direction)(2));
                break;
            case 'd':
                state = game.transition((Two048::Direction)(3));
                break;
        }
        game.printGrid();
        cout << "valid:" << state.valid << ",full:" << state.full << ",halt:" << state.halt << ",score:" << state.score;
    }

    return 0;
}
