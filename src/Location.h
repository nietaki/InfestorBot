#ifndef LOCATION_H_
#define LOCATION_H_
/*
 constants
 */
const int TDIRECTIONS = 4;
const char CDIRECTIONS[4] = { 'N', 'E', 'S', 'W' };
const int DIRECTIONS[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } }; //{N, E, S, W}


/*
 struct for representing locations in the grid.
 */
struct Location {
		int row, col;

		Location() {
			row = col = 0;
		};

		Location(int r, int c) {
			row = r;
			col = c;
		};

		Location getBordering(int dir){
			return Location(row + DIRECTIONS[dir][0], col + DIRECTIONS[dir][1]);
		}
};
#endif //LOCATION_H_
