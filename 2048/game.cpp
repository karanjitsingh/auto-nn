#include <iostream>

using namespace std;

namespace Two048 {

    struct GameState {
        bool full;          // Grid is full, can't add another random value
        bool valid;         // Move resulting in no change to grid
        bool halt;          // Game can't proceed further
        int score;
    };

    enum Direction{Up, Down, Left, Right};



    class Game {

    private:

        // Static constructor
        struct staticConstructor {
        public:
            staticConstructor() {
                srand(time(NULL));
                cout << "wtf";
            }
        };

        int ** grid;
        int score;
        int size;
        GameState currState;

        int addRandom() {
            return 1;
        }

    public:

        Game(int n) {
            // Call to static constructor, will be called only once
            static staticConstructor cons;

            size = n;
            currState.score = 0;
            grid = new int*[n];
            for(int i=0;i<n;i++) {
                grid[i] = new int[n];
            }

            score = 0;

            addRandom();
            addRandom();
        }

        GameState transition(Direction d) {

            switch(d) {
                case Up:
                    break;
                case Down:
                    break;
                case Left:
                    break;
                case Right:
                    break;
                default:
                    throw "Invalid direction.";
            }

            return this->currState;
        };
        
    };


}