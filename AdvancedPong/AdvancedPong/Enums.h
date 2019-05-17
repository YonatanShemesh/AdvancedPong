#pragma once
//board
enum class difficult { BEST = 1, GOOD = 2, NOVICE = 3 };
enum class BoardPos { left, right };
enum class BallPosition { MISSED_REG, MISSED_BE, MISSED_BOMB, CENTER_HIT, CORNER_HIT, CENTER_HIT_BE, CORNER_HIT_BE, BOMB_HIT, AWAY };
//ball
enum class XDirection { Left, Right };
enum class YDirection { Up, Down };
//game
enum class Mode { H_H, H_C, C_C };
