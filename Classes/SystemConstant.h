#ifndef __SYSTEM_CONSTANT_H__
#define __SYSTEM_CONSTANT_H__

// set tag
#define NONPREY_TAG 0
#define PEAR_TAG 1
#define APPLE_TAG 2
#define BANANA_TAG 3
#define MELON_TAG 4
#define SQUIRREL_TAG 5
#define MONKEY_TAG 6
#define SMALL_TWO_TAG 7
#define SMALL_ONE_TAG 8
#define BIG_TWO_TAG 9
#define BIG_ONE_TAG 10

// set unit time (s)
const float TIME_PER_UNIT = 0.1f;

// set animation name in plist
const std::string SQUIRREL_ANIMATION_NAME = "squirrel";
const std::string MONKEY_ANIMATION_NAME = "monkey";
const std::string SMALL_TWO_ANIMATION_NAME = "smallbear2";
const std::string SMALL_ONE_ANIMATION_NAME = "smallbear1";
const std::string BIG_TWO_ANIMATION_NAME = "bear2";
const std::string BIG_ONE_ANIMATION_NAME = "bigbear1";

// the designed resolution size in pixels
const unsigned int DESIGN_RESOLUSION_WIDTH = 1920;
const unsigned int DESIGN_RESOLUTION_HEIGHT = 1080;

// the units of designed width
const float DESIGN_WIDTH_UNITS = 192.0f;

// the scaling factor from units to pixels
const float SCALING_FACTOR_FROM_UNITS_TO_PIXELS = DESIGN_RESOLUSION_WIDTH / DESIGN_WIDTH_UNITS;

// the size of all the preys (sprites)
// Always we do not need to use these constants, but when the preys do not have suitable size, we use them.
const float PEAR_SPRITE_WIDTH = 6 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float APPLE_SPRITE_WIDTH = 6 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float BANANA_SPRITE_WIDTH = 6 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float MELON_SPRITE_WIDTH = 6 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float SQUIRREL_SPRITE_WIDTH = 12 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float MONKEY_SPRITE_WIDTH = 12 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float SMALL_TWO_SPRITE_WIDTH = 12 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float SMALL_ONE_SPRITE_WIDTH = 12 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float BIG_TWO_SPRITE_WIDTH = 12 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float BIG_ONE_SPRITE_WIDTH = 12 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;

// the emergence number of preys in one unit time in different scenarios
const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_QUIET_FRUIT = 12;
const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_QUIET_OTHERANIMAL = 4;
const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_QUIET_BEAR = 3;

const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_NORMAL_FRUIT = 12;
const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_NORMAL_OTHERANIMAL = 4;
const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_NORMAL_BEAR = 3;

const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_MEDIUM_FRUIT = 15;
const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_MEDIUM_OTHERANIMAL = 6;
const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_MEDIUM_BEAR = 4;

const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_HARD_FRUIT = 20;
const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_HARD_OTHERANIMAL = 8;
const unsigned int EMERGENCE_NUMBER_PER_UNIT_TIME_HARD_BEAR = 6;

// the speed of preys
const float DEFAULT_QUIET_SPEED = 10 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;

const float PEAR_SPEED = 60 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float APPLE_SPEED = 60 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float BANANA_SPEED = 60 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float MELON_SPEED = 60 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float SQUIRREL_SPEED = 82 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float MONKEY_SPEED = 90 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float SMALL_TWO_SPEED = 102 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float SMALL_ONE_SPEED = 109 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float BIG_TWO_SPEED = 118 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float BIG_ONE_SPEED = 125 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;

const float NORMAL_SPEED_SCALING_FACTOR = 1.0f;
const float MEDIUM_SPEED_SCALING_FACTOR = 2.0f;
const float HARD_SPEED_SCALING_FACTOR = 4.0f;

// the residence time of the fruits on the grass (ms)
const unsigned int PEAR_RESIDENCE_TIME = 30;
const unsigned int APPLE_RESIDENCE_TIME = 30;
const unsigned int BANANA_RESIDENCE_TIME = 20;
const unsigned int MELON_RESIDENCE_TIME = 20;

// the score that the player get from different preys
const unsigned int PEAR_SCORE = 5;
const unsigned int APPLE_SCORE = 5;
const unsigned int BANANA_SCORE = 10;
const unsigned int MELON_SCORE = 10;
const unsigned int SQUIRREL_SCORE = 20;
const unsigned int MONKEY_SCORE = 20;
const unsigned int SMALL_TWO_SCORE = 50;
const unsigned int SMALL_ONE_SCORE = 50;
const unsigned int BIG_TWO_SCORE = 100;
const unsigned int BIG_ONE_SCORE = 100;

// the HP of different preys
const float PEAR_HP = 1.0f;
const float APPLE_HP = 1.0f;
const float BANANA_HP = 1.0f;
const float MELON_HP = 1.0f;
const float SQUIRREL_HP = 2.0f;
const float MONKEY_HP = 2.0f;
const float SMALL_TWO_HP = 2.0f;
const float SMALL_ONE_HP = 2.0f;
const float BIG_TWO_HP = 3.0f;
const float BIG_ONE_HP = 3.0f;

// the capture probability of different preys
const float PEAR_CAPTURE_PROBABILITY = 1.0f;
const float APPLE_CAPTURE_PROBABILITY = 1.0f;
const float BANANA_CAPTURE_PROBABILITY = 1.0f;
const float MELON_CAPTURE_PROBABILITY = 1.0f;
const float SQUIRREL_CAPTURE_PROBABILITY = 1.0f;
const float MONKEY_CAPTURE_PROBABILITY = 1.0f;
const float SMALL_TWO_CAPTURE_PROBABILITY = 0.5f;
const float SMALL_ONE_CAPTURE_PROBABILITY = 0.5f;
const float BIG_TWO_CAPTURE_PROBABILITY = 0.2f;
const float BIG_ONE_CAPTURE_PROBABILITY = 0.2f;

// the damage of different kinds of nets
const float SMALL_NET_DAMAGE = 2.0f;
const float MEDIUM_NET_DAMAGE = 3.0f;
const float LARGE_NET_DAMAGE = 5.0f;

// the score consumption of different kinds of nets
const unsigned int SMALL_NET_SCORE_CONSUMPTION = 2;
const unsigned int MEDIUM_NET_SCORE_CONSUMPTION = 5;
const unsigned int LARGE_NET_SCORE_CONSUMPTION = 10;

// the required rank of player when using different kinds of nets
const unsigned int SMALL_NET_REQUIRED_RANK = 1;
const unsigned int MEDIUM_NET_REQUIRED_RANK = 2;
const unsigned int LARGE_NET_REQUIRED_RANK = 4;

// the speed of different kinds of nets
const float SMALL_NET_SPEED = 150 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float MEDIUM_NET_SPEED = 150 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float LARGE_NET_SPEED = 150 * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;

// the stride of animals
const float SQUIRREL_STRIDE = 19.2f * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float MONKEY_STRIDE = 19.2f * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float SMALL_TWO_STRIDE = 19.2f * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float SMALL_ONE_STRIDE = 19.2f * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float BIG_TWO_STRIDE = 12.0f * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;
const float BIG_ONE_STRIDE = 19.2f * SCALING_FACTOR_FROM_UNITS_TO_PIXELS;

// set the number of frames of the animation of the running annimals
const unsigned int SQUIRREL_FRAMES = 7;
const unsigned int MONKEY_FRAMES = 7;
const unsigned int SMALL_TWO_FRAMES = 7;
const unsigned int SMALL_ONE_FRAMES = 7;
const unsigned int BIG_TWO_FRAMES = 7;
const unsigned int BIG_ONE_FRAMES = 7;

#endif // !__SYSTEM_CONSTANT_H__

