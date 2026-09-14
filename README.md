# Math Quiz

A simple console-based Math Quiz game developed in C++.

## 🎮 About the Quiz

This is a console-based math quiz where the player answers a series of randomly generated mathematical questions.

Before starting the quiz, the player can choose:

- The number of questions
- The difficulty level
- The type of mathematical operation

After answering all questions, the quiz displays the final result, including the number of correct and wrong answers.

## 🕹️ How to Play

1. Choose the number of questions from **1 to 10**.
2. Choose the difficulty level:
   - `1` → Easy
   - `2` → Middle
   - `3` → Hard
   - `4` → Mix
3. Choose the question type:
   - `1` → Addition
   - `2` → Subtraction
   - `3` → Multiplication
   - `4` → Division
   - `5` → Mix
4. Answer each generated question.
5. The program immediately tells you whether your answer is correct or wrong.
6. At the end, your final result is displayed.
7. You can choose to play the quiz again.

## 📊 Difficulty Levels

| Level | Numbers Range |
|-------|---------------|
| Easy | 1 - 10 |
| Middle | 11 - 50 |
| Hard | 51 - 100 |
| Mix | Randomly selects Easy, Middle, or Hard |

## ➕ Operations

The quiz supports the following mathematical operations:

- Addition `+`
- Subtraction `-`
- Multiplication `*`
- Division `/`
- Mix — randomly selects an operation

## 🏆 Result

The quiz displays:

- Pass or Fail result
- Number of questions
- Selected difficulty level
- Selected question type
- Number of correct answers
- Number of wrong answers

The player **passes** when the number of correct answers is greater than or equal to the number of wrong answers.

## ✨ Features

- Randomly generated questions
- Multiple difficulty levels
- Multiple mathematical operations
- Mixed difficulty and operation modes
- Instant answer checking
- Displays the correct answer when the player is wrong
- Tracks correct and incorrect answers
- Pass / Fail result
- Option to restart the quiz
- Console color changes based on the answer result
- Sound notification for wrong answers

## 🛠️ Technologies Used

- C++
- Visual Studio
- Standard C++ Library

## 🚀 How to Run

1. Clone the repository:

```bash
git clone https://github.com/YOUR-USERNAME/Math_Quiz.git
```

2. Open the `.sln` file in Visual Studio.

3. Build the project.

4. Run the program.

## 📂 Project Structure

```text
Math_Quiz/
├── Math_Quiz.cpp
├── Math_Quiz.vcxproj
├── Math_Quiz.vcxproj.filters
├── Math_Quiz.sln
└── .gitignore
```

## 👨‍💻 Author

Mohannad Abu-Najie
