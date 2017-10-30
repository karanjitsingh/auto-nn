#ifndef AUTO_NN_GAME_H_H
#define AUTO_NN_GAME_H_H

#include <iostream>

using namespace std;

namespace Two048 {

	struct GameState {
		bool full;
		bool valid;
		bool halt;
		int score;
	};

	enum Direction{Up, Down, Left, Right};

	class Game {

	private:

		int size;
		int emptyTilesCount;
		int ** grid;
		GameState currState;

		// Point to m,n element in grid with transposed option
		int * getGridPointer(int m, int n, bool transpose);

		int addRandom();

	public:

		Game(int n);
		void printGrid();

		GameState transition(Direction d);

		~Game() {
			for(int i=0;i<n;i++) {
				delete[] grid[i];
			}
			delete[] grid;
		}

	};


}

#endif //AUTO_NN_GAME_H_H
