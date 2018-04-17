#define SKILLS

#define MAX_VOLTAGE 127
#define turnScale .01152
#define TICKS_PER_REV 1024

float distBreak = 15;
//LINEAR DRIVE GAINS
float distP = 26;
float distI = 0.25;
float distD = 180;
//STEADY DRIVE GAINS
float diffP = 8;
float diffI = 0.05;
float diffD = 0.3;
//TURN GAINS
float turnP = 6.5;
float turnI = 0.4;
float turnD = 35; // OLD 80, VCAT 30
