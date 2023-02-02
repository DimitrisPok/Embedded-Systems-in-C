//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 2
//Submission number: 0267702620

#include <stdio.h>

enum DIRECTION {N,E,S,W};       //enumeration constant

typedef struct {                //structure definition with typedef
    int xpos;
    int ypos;                   //structure members
    enum DIRECTION dir;
} ROBOT;

void move(ROBOT *robot) {       //(move function) *robot is a pointer to ROBOT structure
    if (robot->dir == N) {      //structure pointer parameter used to access DIRECTION in struct
        robot->ypos += 1;       //increment ypos by 1
    } 
    else if (robot->dir == E) {
        robot->xpos += 1;       //increment xpos by 1
    } 
    else if (robot->dir == S) {
        robot->ypos -= 1;       //decrement ypos by 1
    } 
    else if (robot->dir == W) {
        robot->xpos -= 1;       //decrement xpos by 1
    }   
};

void turn(ROBOT *robot) {       //(turn, 90° clockwise) *robot is a pointer to ROBOT structure
    if (robot->dir == N) {      //if direction is N set it to E, and so on for the rest as well
        robot->dir = E;
    } 
    else if (robot->dir == E) {
        robot->dir = S;
    } 
    else if (robot->dir == S) {
        robot->dir = W;
    } 
    else if (robot->dir == W) {
        robot->dir = N;
    }
};

int main() {
    ROBOT robot = {0,0,N};      //robot starts at coordinates(x,y) 0,0 facing 'N'
        char instr;             //stores instructions 'm' & 't'
        while(1) {
                printf("Enter starting position (x y): ");             //requests starting coordinates
                scanf("%d%d", &robot.xpos, &robot.ypos);
                if(robot.xpos < 0 || robot.xpos > 99 ||
                   robot.ypos < 0 || robot.ypos > 99) {                //if entered coordinates
                        printf("Position out of range, try again\n");  //are out of range
                        continue;
                }
                printf("Enter string of instructions (m - move, t - turn): ");
                while(scanf(" %c", &instr) == 1 && instr != 'd') {     //as long as char read is not
                        if(instr == 'm') move(&robot);                 //equal to 'd' the program keeps
                        else if(instr == 't') turn(&robot);            //asking for instructions
                }
                printf("New position: (%d, %d)\n", robot.xpos, robot.ypos); //after char read = 'd' it 
        }                                                                   //prints the position
        return 0;
}