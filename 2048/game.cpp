#include <iostream>

using namespace std;

namespace Two048 {

    struct state GridState() {
        bool full,
        bool valid
    } state;

    class Game {
        
    private:
        int ** grid;
        int score;
        
        
    public:
        
        static enum Direction{Up, Down, Left, Right};
        
        Game(int n) {
            this.score = 0;
            this.grid = new int*[n];
            for(int i=0;i<n;i++) {
                grid[i] = new int[n];
            }
            
            this.state.full = false;
            this.state.valid = true;
        }
        
    }
}