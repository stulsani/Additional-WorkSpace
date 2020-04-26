#include<iostream>
#include<vector>

using namespace std;

class KnightTour {
private:
    int N;
    vector<vector<int> > board;
    vector<pair<int,int> > directions{{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
public:
    KnightTour(int n) {
        N = n;
        board.resize(N, vector<int> (N,0));
    }

    void KnightTourMoves() {
        if(solveKnightTourMoves({0,0}, 0)) {
          printSolution();
        } else {
            cout << "Solution doesn't exist" << endl;
        }
    }

    bool solveKnightTourMoves(pair<int,int> coordinates, int currStep) {
        if(currStep >= N * N) {
          board[coordinates.first][coordinates.second] = 0;
          return true;
        }
        if(!isSafe(coordinates)) return false;
        board[coordinates.first][coordinates.second] = currStep++;
        for(auto p : directions) {
            if(solveKnightTourMoves({coordinates.first + p.first, coordinates.second + p.second}, currStep)) {
                return true;
            }
        }
        board[coordinates.first][coordinates.second] = 0;
        return false;
    }

    bool isSafe(pair<int,int> c) {
        if(c.first < 0 || c.second < 0 || c.first >= N || c.second >= N || board[c.first][c.second]) return false;
        return true;
    }

    void printSolution() {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    KnightTour kt(3);
    kt.KnightTourMoves();
    return 0;
}
