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

		// Static constructor
		struct staticConstructor {
		public:
			staticConstructor();
		};

		int size;
		int emptyTilesCount;
		int ** grid;
		GameState currState;

		int * getGridPointer(int m, int n, bool transpose);

		int addRandom();

	public:

		Game(int n);
		void printGrid();

		GameState transition(Direction d);

	};


}

#endif //AUTO_NN_GAME_H_H
