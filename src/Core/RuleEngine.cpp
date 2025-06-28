#include <Core/RuleEngine.h>





std::vector<CaptureMove> RuleEngine::check_capture(const std::pair<int, int>& coordinate, const  std::vector<std::vector<int>>& int_grid, bool queen_take)
{
	std::vector<CaptureMove> coordinate_move;
	CaptureMove coordinate_elem;
	int size = int_grid.size();
	std::pair<int, int> enemy;
	std::pair<int, int> piece;
	if (int_grid[coordinate.first][coordinate.second] == 1 || int_grid[coordinate.first][coordinate.second] == 3) {
		enemy = { 2,4 };
		piece = { 3,1 };

	}
	else {
		enemy = { 1,3 };
		piece = { 4,2 };
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (int_grid[i][j] == piece.first) {

				if (i - 2 >= 0 && j - 2 >= 0 && (int_grid[i - 1][j - 1] == enemy.first || int_grid[i - 1][j - 1] == enemy.second) && int_grid[i - 2][j - 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i - 2,j - 2 };
					coordinate_elem.coordinate_take = { i - 1,j - 1 };
					coordinate_elem.queen_take = true;
					coordinate_move.push_back(coordinate_elem);
				}
				if (i + 2 < size && j - 2 >= 0 && (int_grid[i + 1][j - 1] == enemy.first || int_grid[i + 1][j - 1] == enemy.second) && int_grid[i + 2][j - 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i + 2,j - 2 };
					coordinate_elem.coordinate_take = { i + 1,j - 1 };
					coordinate_elem.queen_take = true;
					coordinate_move.push_back(coordinate_elem);
				}
				if (i + 2 < size && j + 2 < size && (int_grid[i + 1][j + 1] == enemy.first || int_grid[i + 1][j + 1] == enemy.second) && int_grid[i + 2][j + 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i + 2,j + 2 };
					coordinate_elem.coordinate_take = { i + 1,j + 1 };
					coordinate_elem.queen_take = true;
					coordinate_move.push_back(coordinate_elem);
				}
				if (j + 2 < size && i - 2 >= 0 && (int_grid[i - 1][j + 1] == enemy.first || int_grid[i - 1][j + 1] == enemy.second) && int_grid[i - 2][j + 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i - 2 ,j + 2 };
					coordinate_elem.coordinate_take = { i - 1,j + 1 };
					coordinate_elem.queen_take = true;
					coordinate_move.push_back(coordinate_elem);
				}

				for (int k = 1; k < 8; k++) {

					if (i + k + 1 < size && j + k + 1 < size && int_grid[i + k - 1][j + k - 1] == 0 && ((int_grid[i + k][j + k] == enemy.first || int_grid[i + k][j + k] == enemy.second))) {
						bool border = false;
						for (int l = 1; i + l < i + k && j + l < j + k; l++) {

							if (int_grid[i + l][j + l] != 0) {
								//cout << "Have boarder check if 1" << endl;
								border = true;
								break;
							}
						}
						for (int l = 1; i + k + l < size && j + k + l < size && !border; l++) {
							if (int_grid[i + k + 1][j + k + l] == 0) {
								coordinate_elem.coordinate_start = { i,j };
								coordinate_elem.coordinate_end = { i + k + l,j + k + l };
								coordinate_elem.coordinate_take = { i + k ,j + k };
								coordinate_elem.queen_take = true;
								coordinate_move.push_back(coordinate_elem);
							}
							else {
								break;
							}
						}
					}
					if (i - k - 1 >= 0 && j + k + 1 < size && int_grid[i - k + 1][j + k - 1] == 0 && (int_grid[i - k][j + k] == enemy.first || int_grid[i - k][j + k] == enemy.second)) {
						bool border = false;
						for (int l = 1; i - l > i - k && j + l < j + k; l++) {

							if (int_grid[i - l][j + l] != 0) {
								//cout << "Have boarder check if 2" << endl;
								border = true;
								break;
							}
						}
						for (int l = 1; i - k - l >= 0 && j + k + l < size && !border; l++) {
							if (int_grid[i - k - l][j + k + l] == 0) {
								coordinate_elem.coordinate_start = { i,j };
								coordinate_elem.coordinate_end = { i - k - l,j + k + l };
								coordinate_elem.coordinate_take = { i - k ,j + k };
								coordinate_elem.queen_take = true;
								coordinate_move.push_back(coordinate_elem);
							}
							else {
								break;
							}
						}
					}
					if (i - k - 1 >= 0 && j - k - 1 >= 0 && int_grid[i - k + 1][j - k + 1] == 0 && (int_grid[i - k][j - k] == enemy.first || int_grid[i - k][j - k] == enemy.second)) {

						bool border = false;
						for (int l = 1; i - l > i - k && j - l > j - k; l++) {

							if (int_grid[i - l][j - l] != 0) {
								//cout << "Have boarder check if 3" << endl;
								border = true;
								break;
							}
						}
						for (int l = 1; i - k - l >= 0 && j - k - l >= 0 && !border; l++) {
							if (int_grid[i - k - l][j - k - l] == 0) {
								coordinate_elem.coordinate_start = { i,j };
								coordinate_elem.coordinate_end = { i - k - l,j - k - l };
								coordinate_elem.coordinate_take = { i - k ,j - k };
								coordinate_elem.queen_take = true;
								coordinate_move.push_back(coordinate_elem);
								//take_queen = true;
							}
							else {
								break;
							}
						}
					}
					if (i + k + 1 < size && j - k - 1 >= 0 && int_grid[i + k - 1][j - k + 1] == 0 && (int_grid[i + k][j - k] == enemy.first || int_grid[i + k][j - k] == enemy.second)) {
						bool border = false;
						for (int l = 1; i + l < i + k && j - l > j - k; l++) {

							if (int_grid[i + l][j - l] != 0) {
								//cout << "Have boarder check if 4" << endl;
								border = true;
								break;
							}
						}
						for (int l = 1; i + k + l < size && j - k - l >= 0 && !border; l++) {
							if (int_grid[i + k + l][j - k - l] == 0) {
								coordinate_elem.coordinate_start = { i,j };
								coordinate_elem.coordinate_end = { i + k + l,j - k - l };
								coordinate_elem.coordinate_take = { i + k ,j - k };
								coordinate_elem.queen_take = true;
								coordinate_move.push_back(coordinate_elem);
								//take_queen = true;
							}
							else {
								break;
							}
						}
					}
				}
			}
			if (int_grid[i][j] == piece.second && !queen_take) {
				if (i - 2 >= 0 && j - 2 >= 0 && (int_grid[i - 1][j - 1] == enemy.first || int_grid[i - 1][j - 1] == enemy.second) && int_grid[i - 2][j - 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i - 2,j - 2 };
					coordinate_elem.coordinate_take = { i - 1,j - 1 };
					coordinate_move.push_back(coordinate_elem);
				}
				if (i + 2 < size && j - 2 >= 0 && (int_grid[i + 1][j - 1] == enemy.first || int_grid[i + 1][j - 1] == enemy.second) && int_grid[i + 2][j - 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i + 2,j - 2 };
					coordinate_elem.coordinate_take = { i + 1,j - 1 };
					coordinate_move.push_back(coordinate_elem);
				}
				if (i + 2 < size && j + 2 < size && (int_grid[i + 1][j + 1] == enemy.first || int_grid[i + 1][j + 1] == enemy.second) && int_grid[i + 2][j + 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i + 2,j + 2 };
					coordinate_elem.coordinate_take = { i + 1,j + 1 };
					coordinate_move.push_back(coordinate_elem);
				}
				if (j + 2 < size && i - 2 >= 0 && (int_grid[i - 1][j + 1] == enemy.first || int_grid[i - 1][j + 1] == enemy.second) && int_grid[i - 2][j + 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i - 2 ,j + 2 };
					coordinate_elem.coordinate_take = { i - 1,j + 1 };
					coordinate_move.push_back(coordinate_elem);
				}
			}






		}
	}
	return  coordinate_move;
}

bool RuleEngine::is_move_checker(const std::pair<int, int>& coordinate_start, const std::pair<int, int>& coordinate_end, const  std::vector<std::vector<int>>& int_grid)
{
	if ((coordinate_start.first + 1 == coordinate_end.first && coordinate_start.second + 1 == coordinate_end.second) && int_grid[coordinate_start.first][coordinate_start.second] == 2) {
		return true;
	}
	else if ((coordinate_start.first - 1 == coordinate_end.first && coordinate_start.second + 1 == coordinate_end.second) && int_grid[coordinate_start.first][coordinate_start.second] == 2) {
		return true;
	}
	else if ((coordinate_start.first - 1 == coordinate_end.first && coordinate_start.second - 1 == coordinate_end.second) && int_grid[coordinate_start.first][coordinate_start.second] == 1) {
		return true;
	}
	else if ((coordinate_start.first + 1 == coordinate_end.first && coordinate_start.second - 1 == coordinate_end.second) && int_grid[coordinate_start.first][coordinate_start.second] == 1) {
		return true;
	}
	else if (int_grid[coordinate_start.first][coordinate_start.second] == 3 || int_grid[coordinate_start.first][coordinate_start.second] == 4) {

		for (int i = 1; i < 7; i++) {

			if (coordinate_start.first + i == coordinate_end.first && coordinate_start.second + i == coordinate_end.second) {

				for (int k = 1; coordinate_start.first + k < coordinate_start.first + i && coordinate_start.second + k < coordinate_start.second + i; k++) {
					if (int_grid[coordinate_start.first + k][coordinate_start.second + k] != 0) {
						//cout << "Have boarder if 1" << endl;
						return false;
					}
				}

				return true;
			}
			else if (coordinate_start.first - i == coordinate_end.first && coordinate_start.second - i == coordinate_end.second) {
				for (int k = 1; coordinate_start.first - k > coordinate_start.first - i && coordinate_start.second - k > coordinate_start.second - i; k++) {
					if (int_grid[coordinate_start.first - k][coordinate_start.second - k] != 0) {
						//cout << "Have boarder if 2" << endl;
						return false;
					}
				}
				return true;
			}
			else if (coordinate_start.first - i == coordinate_end.first && coordinate_start.second + i == coordinate_end.second) {
				for (int k = 1; coordinate_start.first - k > coordinate_start.first - i && coordinate_start.second + k < coordinate_start.second + i; k++) {
					if (int_grid[coordinate_start.first - k][coordinate_start.second + k] != 0) {
						//cout << "Have boarder if 3" << endl;
						return false;
					}
				}
				return true;
			}
			else if (coordinate_start.first + i == coordinate_end.first && coordinate_start.second - i == coordinate_end.second) {
				for (int k = 1; coordinate_start.first + k < coordinate_start.first + i && coordinate_start.second - k > coordinate_start.second - i; k++) {
					if (int_grid[coordinate_start.first + k][coordinate_start.second - k] != 0) {
						//cout << "Have boarder if 4" << endl;
						return false;
					}
				}
				return true;
			}
		}

	}
	return false;
}

bool RuleEngine::is_pat(const std::vector<std::vector<int>>& int_grid)
{
	bool found = false;

	for (int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (check_capture({ i,j },int_grid).size() != 0) {
				found = true;
				break;
			}
			else if (int_grid[i][j] == 1) {
				
				if (is_move_checker({ i,j }, { i - 1,j - 1 }, int_grid)|| is_move_checker({ i,j }, { i + 1,j - 1 }, int_grid)) {
					found = true;
				}

			}
			else if (int_grid[i][j] == 2) {

				if (is_move_checker({ i,j }, { i + 1,j + 1 }, int_grid)|| is_move_checker({ i,j }, { i - 1,j + 1 }, int_grid)) {
					found = true;
				}
				
			}
			else if (int_grid[i][j] == 3 || int_grid[i][j] == 4) {
				for (int k = 1; k <= 7 && !found; k++)
				{
					if (is_move_checker({ i,j }, { i + k,j + k }, int_grid)) {
						found = true;
					}
					else if (is_move_checker({ i,j }, { i - k,j - k }, int_grid)) {
						found = true;
					}
					else if (is_move_checker({ i,j }, { i + k,j - k }, int_grid)) {
						found = true;
					}
					else if (is_move_checker({ i,j }, { i - k,j + k }, int_grid)) {
						found = true;
					}
				}
			}
		}
	}
	return  !found;

}

std::vector<Move> RuleEngine::get_all_move(const std::vector<std::vector<int>>& int_grid, bool color)
{
	std::vector<Move> move;
	Move move_elem;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::vector<CaptureMove> c_move;

			if (int_grid[i][j] == 1 || int_grid[i][j] == 3 && color) {
				 c_move = check_capture({ i,j }, int_grid);
			}
			else {
				 c_move = check_capture({ i,j }, int_grid);
			}
			if (c_move.size() != 0) {
				for (int i = 0; i < c_move.size(); i++) {
					move_elem.coordinate_start = c_move[i].coordinate_start;
					move_elem.coordinate_end = c_move[i].coordinate_end;
					move.push_back(move_elem);
				}
				
			}
			else if (int_grid[i][j] == 1 && color) {

				if (is_move_checker({ i,j }, { i - 1,j - 1 }, int_grid) && i - 1 >=0 && j - 1 >= 0 && int_grid[i-1][j-1]==0) {
					move_elem.coordinate_start = { i,j };
					move_elem.coordinate_end = { i - 1,j - 1 };
					move.push_back(move_elem);
				}
				else if (is_move_checker({ i,j }, { i + 1,j - 1 }, int_grid) && i + 1 <8 && j -1 >=0 && int_grid[i + 1][j - 1] == 0) {
					move_elem.coordinate_start = { i,j };
					move_elem.coordinate_end = { i + 1,j - 1 };
					move.push_back(move_elem);
				}

			}
			else if (int_grid[i][j] == 2 && !color) {

				if (is_move_checker({ i,j }, { i + 1,j + 1 }, int_grid) && i + 1 <8 && j + 1 < 8 && int_grid[i + 1][j + 1] == 0) {
					move_elem.coordinate_start = { i,j };
					move_elem.coordinate_end = { i + 1,j+ 1 };
					move.push_back(move_elem);
				}
				else if (is_move_checker({ i,j }, { i - 1,j + 1 }, int_grid) && i-1>=0 && j+1<8 && int_grid[i - 1][j + 1] == 0) {
					move_elem.coordinate_start = { i,j };
					move_elem.coordinate_end = { i - 1,j + 1 };
					move.push_back(move_elem);
				}
			}
			else if (int_grid[i][j] == 3 && color) {
				for (int k = 1; k <= 7; k++)
				{
					if (is_move_checker({ i,j }, { i + k,j + k }, int_grid) && i +k< 8 && j + k < 8 && int_grid[i + k][j + k] == 0) {
						move_elem.coordinate_start = { i,j };
						move_elem.coordinate_end = { i + k,j + k };
						move.push_back(move_elem);
					}
					else if (is_move_checker({ i,j }, { i - k,j - k }, int_grid) && i - k >=0  && j - k >= 0 && int_grid[i - k][j - k] == 0) {
						move_elem.coordinate_start = { i,j };
						move_elem.coordinate_end = { i - k,j -  k };
						move.push_back(move_elem);
					}
					else if (is_move_checker({ i,j }, { i + k,j - k }, int_grid) && i + k < 8 && j - k >=0 && int_grid[i + k][j - k] == 0) {
						move_elem.coordinate_start = { i,j };
						move_elem.coordinate_end = { i + k,j - k };
						move.push_back(move_elem);
					}
					else if (is_move_checker({ i,j }, { i - k,j + k }, int_grid) && i - k>=0 && j + k < 8 && int_grid[i - k][j + k] == 0) {
						move_elem.coordinate_start = { i,j };
						move_elem.coordinate_end = { i - k,j + k };
						move.push_back(move_elem);
					}
				}
			}
			else if (int_grid[i][j] == 4 && !color) {
				for (int k = 1; k <= 7; k++)
				{
					if (is_move_checker({ i,j }, { i + k,j + k }, int_grid) && i + k < 8 && j + k < 8) {
						move_elem.coordinate_start = { i,j };
						move_elem.coordinate_end = { i + k,j + k };
						move.push_back(move_elem);
					}
					else if (is_move_checker({ i,j }, { i - k,j - k }, int_grid) && i - k >= 0 && j - k >= 0) {
						move_elem.coordinate_start = { i,j };
						move_elem.coordinate_end = { i - k,j - k };
						move.push_back(move_elem);
					}
					else if (is_move_checker({ i,j }, { i + k,j - k }, int_grid) && i + k < 8 && j - k >= 0) {
						move_elem.coordinate_start = { i,j };
						move_elem.coordinate_end = { i + k,j - k };
						move.push_back(move_elem);
					}
					else if (is_move_checker({ i,j }, { i - k,j + k }, int_grid) && i - k >= 0 && j + k < 8) {
						move_elem.coordinate_start = { i,j };
						move_elem.coordinate_end = { i - k,j + k };
						move.push_back(move_elem);
					}
				}
			}
		}
	}
	return move;

}




