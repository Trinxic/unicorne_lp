// Copyright 2023 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Board:
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP22
#define I2C1_SCL_PIN GP23

#define MASTER_LEFT

// Audio Buzzer:
#define AUDIO_PIN GP28
#define AUDIO_PWM_DRIVER PWMD6
#define AUDIO_INIT_DELAY
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
// #define STARTUP_SONG SONG(ODE_TO_JOY)  // AHHHHHHHHH

// Analog Sticks:
#define ANALOG_JOYSTICK_Y_AXIS_PIN GP26
#define ANALOG_JOYSTICK_X_AXIS_PIN GP27
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_INVERT_X

// OLEDs:
#define OLED_BRIGHTNESS 200
#define OLED_TIMEOUT 10000

// Tap Dance: (milliseconds)
#define TAPPING_TERM 175

// WPM:
#define SPLIT_WPM_ENABLE