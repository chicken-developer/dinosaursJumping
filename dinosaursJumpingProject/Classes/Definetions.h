//Definitions.h

//Dino
#define GRAVITY -1000.0f
#define DINO_JUMPING_TOLERANCE 3
#define DINO_SPEED_Y_MIN -500.0f
#define DINO_SPEED_Y_MAX 400.0f
#define DINO_SPEED_X_INITIAL 300.0f
#define DINO_SPEED_X_INCREASING_RATE 5
#define DINO_X 120.0f

//Cactus
#define CACTUS_NUMBER 5
#define CACTUS_INTIAL_X 735
#define CACTUS_SPEED_RATIO 1

//Cloud
#define CLOUD_SPEED_RATIO 0.4f
#define CLOUD_Y_MIN 600
#define CLOUD_Y_MAX 800
#define CLOUD_SPACING_MIN 100
#define CLOUD_SPACING_MAX 500
#define CLOUD_NUMBEr 10

//zOrder
#define CACTUS_ZORDER 3
#define DINO_ZORDER 4
#define GROUND_ZORDER 5
#define CLOUD_ZORDER 6
#define SCORE_ZORDER 7
#define ROAD_ZORDER 4

//Ground road
#define GROUND_HEIGHT 350
#define ROAD_SPEED_RATIO 1
#define ROAD_2_PROBABILITY 30

//Title
#define TITLE_INITIAL_Y 150
#define TITLE_HIDDEN_Y 100
#define TITLE_ANIMATION_TIME 0.2f

//Storage 
#define STORE_HIGH_SCORE "HIGH_SCORE"

//Score
#define SCORE_TEXT "%d - SCORES"
#define HIGH_SCORE "HIGH - %d"
#define SCORE_RATE 6
#define SCORE_INTIAL_HIGH 60
#define FAKE_HIGHSCORE 100

//Sound
#define SOUND_JUMP "jump.mp3"
#define SOUND_OVER "over.mp3"
#define SOUND_NEW_HIGH "newhigh.mp3"
#define SOUND_HIT_GROUND "hitgr.mp3"