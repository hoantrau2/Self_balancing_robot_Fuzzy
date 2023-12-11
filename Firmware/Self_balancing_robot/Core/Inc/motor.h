/*
 * motor.h
 *
 *  Created on: Dec 10, 2023
 *      Author: NGOC HOAN && Hien Nguyen
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_



#endif /* INC_MOTOR_H_ */


#include <stdint.h>
#include "main.h"
#include <stm32f1xx_hal_tim.h>
#include "stm32f1xx_hal.h"
#include "SBR1_fis.h"

#define		MAX_CNT		    999 // AutoReload Register - MIN_CNT to receive the number amplifier of PWM (by with duty cycle)
#define 	MIN_CNT			140 // value to eliminate engine friction
#define 	VAL_MAX			1   // max value of duty cycle is 1 (normalized value)
#define		EPSILON			0
#define 	TIME_EXAMPLE	10 		// timer1 interrupted 10ms to read data mpu6050 and controller robot
#define 	ANGLE_THRESHOLD	70
#define 	K_THETA 			8.5
#define 	K_THETA_DOT			100
#define 	OFFSET			-2.7//angler MPU return when robot balance
// MIN_CNT; K_THETA; K_THETA_DOT; OFFSET:	 These parameters need to be tuned belong to your robot


typedef struct {
	float f_inp_fuzzy[2];
	float f_out_fuzzy;
	float f_K_theta;
	float f_K_theta_dot;
} Fuzzy_t;


extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;


void Init_tim_pwm();
void Forward (float duty);
void Reverse (float duty);
//static void Stop_motor();
//static void Set_duty(float duty, TIM_HandleTypeDef *htim, int channel); // duty 0-1
//static void Limit_val(float *value);
void Controller (double new_angle, double vec_angle, Fuzzy_t *fuzzy);

