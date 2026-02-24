# 🧠 Math Game Project (C++)

![C++](https://img.shields.io/badge/C++-Solutions-blue.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)
![Level](https://img.shields.io/badge/Level-Beginner-orange.svg)

Welcome to the **Math Game**, my second software project developed as part of **Dr. Mohammed Abu Hadhoud’s Roadmap**. This is a console-based application designed to challenge users' mental math skills through a customizable quiz system.

---

## 🚀 Key Features

* **Customizable Difficulty Levels:**
    * `Easy`: Numbers from 1 to 10.
    * `Medium`: Numbers from 10 to 50.
    * `Hard`: Numbers from 50 to 100.
    * `Mix`: A random variety of difficulties.
* **Multiple Operation Types:**
    * Supports **Addition (+)**, **Subtraction (-)**, **Multiplication (*)**, **Division (/)**, or a **Mix** of all operations.
* **Real-time Feedback:**
    * Instant validation of answers.
    * Automatic screen color changes (**Green** for correct, **Red** for incorrect) to enhance user interaction.
* **Comprehensive Results Summary:**
    * Detailed final report showing the number of questions, difficulty level, operation type, right/wrong answers, and a final "Pass/Fail" status.

---

## 🛠 Technical Implementation

This project focuses on clean code structure and logic, utilizing several core C++ concepts:

| Concept | Usage in Project |
| :--- | :--- |
| **Structs** | Used `stQuestion` and `stQuizz` to organize game data. |
| **Enums** | Defined `enQuestionLevel` and `enOperationType` for readable code. |
| **Randomization** | Utilized `srand()` and `rand()` for dynamic question generation. |
| **Modular Programming** | Logic is divided into small, reusable functions. |
| **System Commands** | Used `system("color")` and `system("cls")` for UI/UX. |

---

## 🎮 How to Play

1.  **Set Questions:** Choose how many questions you want to answer (from 1 to 10).
2.  **Select Level:** Choose between Easy, Medium, Hard, or Mix.
3.  **Choose Operation:** Select your preferred math operation or challenge yourself with the "Mix" mode.
4.  **Solve:** Enter your answer for each question.
5.  **Review:** Check your final score and see if you passed the challenge!

---

## 📝 Developer’s Note

> "This project was completed within my first two weeks of intensive learning. It marks a significant step in my understanding of logic and program flow. I plan to expand this in the future with more complex operations and advanced features."
>
> — **Ali Talal Ibrahem** (December 9, 2025)

---

## 📥 Installation & Running

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/YourUsername/Math-Game.git](https://github.com/YourUsername/Math-Game.git)
    ```
2.  **Compile the code:**
    ```bash
    g++ main.cpp -o MathGame
    ```
3.  **Run the application:**
    ```bash
    ./MathGame
    ```

---
