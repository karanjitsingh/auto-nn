#include "Two048.h"

namespace Two048 {

	int * Game::getGridPointer(int m, int n, bool transpose) {
		if(!transpose)
			return &this->grid[m][n];
		else
			return &this->grid[n][m];
	}

	int Game::addRandom() {

		if(!this->emptyTilesCount)
			return 0;

		int tile = (rand() % 2 + 1) * 2;         // will result in 2 or 4
		int r = rand()%this->emptyTilesCount;
		int count = 0;

		for(int i=0;i<this->size;i++) {
			for(int j=0;j<this->size;j++) {
				if(grid[i][j] == 0 && (count++) == r) {
					grid[i][j] = tile;
					i = this->size;
					break;
				}
			}
		}

		this->emptyTilesCount--;

		return 1;

	}

	Game::Game(int n) {
		size = n;
		emptyTilesCount = this->size * this->size;
		currState.score = 0;
		grid = new int*[n];
		for(int i=0;i<n;i++) {
			grid[i] = new int[n];
		}


		// Board starts with two tiles
		addRandom();
		addRandom();
	}

	void Game::printGrid() {
		for(int i=0;i<this->size;i++) {
			for(int j=0;j<this->size;j++) {
				cout << this->grid[i][j] << ",";
			}
			cout << "\b\n";
		}
	}

	GameState Game::transition(Direction d) {

		int from, to, step;
		int transpose=d/2;

		switch(d) {
			case Up:
			case Left:
				step = 1;
				from = 0;
				to = this->size;
				break;
			case Down:
			case Right:
				step = -1;
				from = this->size-1;
				to = -1;
				break;
			default:
				throw "Invalid direction.";
		}

		this->emptyTilesCount = 0;

		int n,m;
		int * prevptr, * nextptr, * currptr;
		int nextIndex;
		bool rowMatch;

		currState.valid = false;

		for (n = from; n != to; n += step) {
			rowMatch = false;
			nextIndex = from;
			for (m = from; m != to; m += step) {

				currptr = getGridPointer(m,n,transpose);
				nextptr = getGridPointer(nextIndex, n, transpose);
				prevptr = getGridPointer(nextIndex - step, n, transpose);

				if (*currptr != 0) {
					if (nextIndex != from && *prevptr == *currptr && !rowMatch) {
						*prevptr *= 2;
						currState.score += *prevptr;
						*currptr = 0;
						rowMatch = true;            // there was at least one combination in the row
						currState.valid = true;      // move was successful
					} else {
						rowMatch = false;
						if (nextIndex != m) {
							currState.valid = true;      // move was successful
							*nextptr = *currptr;
							*currptr = 0;
						}
						nextIndex += step;
					}
				}
			}
			this->emptyTilesCount += to > from ? to - nextIndex : nextIndex - to;
		}

		if(currState.valid == true) {
			addRandom();
		}

		currState.halt = currState.full = this->emptyTilesCount == 0;

		// check if move is possible
		if(currState.full) {
			for(n = 0; n < this->size - 1; n++) {
				for(m = 0; m < this->size - 1; m++) {
					if(this->grid[m][n] == this->grid[m][n+1] || this->grid[m][n] == this->grid[m+1][n]) {
						currState.halt = false;
					}
				}
			}
		}

		return this->currState;
	};
}