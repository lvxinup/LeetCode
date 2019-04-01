#define  _CRT_SECURE_NO_WARNINGS 1

class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		for (int i = 0; i<board.size(); i++)
		{
			for (int j = 0; j<board.size(); j++)
			{
				if (i == 0 && j == 0)
				{
				}
				else if (i == 0)
				{
					board[i][j] += board[i][j - 1];
				}
				else if (j == 0)
				{
					board[i][j] += board[i - 1][j];
				}
				else
				{
					int boardup = board[i - 1][j];
					int boardleft = board[i][j - 1];
					if (boardup>boardleft)
						board[i][j] += boardup;
					else
						board[i][j] += boardleft;

				}
			}

		}
		return  board[board.size() - 1][board[0].size() - 1];
	}
};