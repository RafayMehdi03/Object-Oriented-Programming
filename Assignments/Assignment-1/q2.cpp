#include <iostream>
#include <string>
using namespace std;
const int GRID_SIZE = 4;
class Ball {
private:
    int x, y;
public:
    Ball(int startX = 0, int startY = 0) : x(startX), y(startY) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void move(int dx, int dy) {
        int tempX = x + dx;
        int tempY = y + dy;
        if (tempX >= 0 && tempX < GRID_SIZE && tempY >= 0 && tempY < GRID_SIZE) {
            x = tempX;
            y = tempY;
        } else {
            cout << "Whoops! Invalid move. Ball stays at (" << x << ", " << y << ").\n";
        }
    }
};
class Goal {
public:
    bool isGoalReached(int ballX, int ballY) {
        return (ballX == 3 && ballY == 3);
    }
};
class Robot {
private:
    string name;
    int attempts;
public:
    Robot(string robotName) : name(robotName), attempts(0) {}
    void hitBall(Ball &ball, const string &direction) {
        if (direction == "up") ball.move(0, 1);
        else if (direction == "down") ball.move(0, -1);
        else if (direction == "left") ball.move(-1, 0);
        else if (direction == "right") ball.move(1, 0);
        else {
            cout << "Oops! Invalid direction. Please try up, down, left, or right.\n";
            return;
        }
        attempts++;
    }
    int getAttempts() const { return attempts; }
    string getName() const { return name; }
};
class Team {
private:
    string teamName;
    Robot *player;
public:
    Team(string name, Robot *robot) : teamName(name), player(robot) {}
    Robot* getPlayer() { return player; }
    string getTeamName() const { return teamName; }
};
class Game {
private:
    Team *teamOne, *teamTwo;
    Ball soccerBall;
    Goal net;
public:
    Game(Team *t1, Team *t2) : teamOne(t1), teamTwo(t2), soccerBall(0, 0) {}
    void play(Team *team) {
        Robot *player = team->getPlayer();
        string direction;
        cout << team->getTeamName() << " - It's your turn! Move the ball (up, down, left, right):\n";
        while (!net.isGoalReached(soccerBall.getX(), soccerBall.getY())) {
            cout << "Direction: ";
            cin >> direction;
            player->hitBall(soccerBall, direction);
            cout << "Ball is at: (" << soccerBall.getX() << ", " << soccerBall.getY() << ")\n";
        }
        cout << team->getTeamName() << " scored a goal in " << player->getAttempts() << " attempts.\n";
    }
    void startGame() {
        cout << "The exciting match is now underway!\n";
        play(teamOne);
        soccerBall = Ball(0, 0);  // Reset ball position for the second team
        play(teamTwo);
        declareWinner();
    }
    void declareWinner() {
        int score1 = teamOne->getPlayer()->getAttempts();
        int score2 = teamTwo->getPlayer()->getAttempts();
        if (score1 < score2) cout << teamOne->getTeamName() << " takes the victory with fewer attempts!\n";
        else if (score2 < score1) cout << teamTwo->getTeamName() << " takes the victory with fewer attempts!\n";
        else cout << "It's a draw! Both teams played equally well!\n";
    }
};
int main() {
    Robot playerA("Kylian Mbappé"), playerB("Erling Haaland");
    Team squadA("Paris Saint-Germain", &playerA), squadB("Manchester City", &playerB);
    Game footballMatch(&squadA, &squadB);
    footballMatch.startGame();
    return 0;
}