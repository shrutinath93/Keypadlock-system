# Arduino Keypad Door Lock System 🔐🤖
An Arduino-based security system that uses a 4x4 Matrix Keypad, a Servo Motor, and an LCD display to create a password-protected locking mechanism with an integrated alarm system.

📌 Project Overview
The goal of this project is to simulate a digital door lock. It provides a secure way to access a room or a locker using a 4-digit code. If an incorrect code is entered 3 times, the system triggers a "LOCKED" state with an audible alarm.

🛠️ Components Used
Microcontroller: Arduino Uno

Input: 4x4 Matrix Keypad

Output: 16x2 LCD Display (Parallel Interface)

Actuator: SG90 Servo Motor (represents the lock bolt)

Feedback: Piezo Buzzer (for keypress, success, and alarm sounds)

✨ Key Features
Password Authentication: Secure 4-digit password (Default: 6949).

Security Alarm: Sounds a persistent buzzer and locks the system for 10 seconds after 3 failed attempts.

Timed Entry: Once unlocked, the user has 5 seconds to "get in" before the door automatically re-locks.

Visual & Audio Feedback: Real-time updates on the LCD and distinct beep patterns for correct/incorrect inputs.

⚙️ How it Works
Idle State: LCD displays "ENTER PASSWORD".

Input: As the user types, stars (*) appear on the screen to maintain privacy.

Validation: * If Correct: Servo rotates to 0° (Unlocked), buzzer beeps happily, and a countdown starts.

If Incorrect: LCD shows "WRONG!!!", buzzer sounds a long beep, and invalidcount increases.

Auto-Lock: After the countdown, the servo rotates back to 180° (Locked).

📂 File Structure
KeypadLock.ino: Main Arduino source code.

README.md: Project documentation.

👤 Author
Shruti Nath
First-year B.Tech Student, Mechanical Engineering
National Institute of Technology (NIT), Durgapur
