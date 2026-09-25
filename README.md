## 🎯 Project Highlights

### Hard AI - The Unbeatable Opponent
The Hard mode uses the **Minimax algorithm** - a game theory algorithm 
that evaluates every possible move and chooses the optimal one.

**Result:** The Hard AI never loses. Ever.

### Smart GUI Launcher
Built with Windows API, the launcher features:
- Professional button layout with custom bitmap graphics
- Responsive window sizing
- Clean, modern interface

### Complete Game Implementation
All three modes track wins, allow multiple rounds, and provide 
a smooth gaming experience.

---

## 🔬 Technical Deep Dive

### Minimax Algorithm Explained
The Hard AI uses Minimax to:
1. Generate all possible board states
2. Score each state (winning = +10, losing = -10, draw = 0)
3. Choose moves that maximize AI's score / minimize player's score
4. Never make a losing move

**Time Complexity:** O(9!) worst case, optimized with pruning

### Graphics Implementation
- **BGI Library:** Handles all graphics rendering
- **Window API:** Manages GUI launcher and window events
- **Bitmap Assets:** Professional button graphics (3 custom BMP files)

### Multi-File Architecture
Launcher (main.c)
├── Easy AI (maineasyyyyyyyyyyy.cpp)
├── Hard AI (main.cpp)
└── Two-Player (maintwoplayers.cpp)

Each mode is a separate executable for:
- Better organization
- Independent compilation
- Cleaner code structure

---

## 📸 Screenshots & Gameplay

### Launcher Interface
![Launcher](Screenshot%202026-09-25%20081451.png)

The custom launcher with three game mode buttons:
- **Easy AI (Green)** - Basic strategy, beatable
- **Hard AI (Magenta)** - Minimax algorithm, unbeatable  
- **Two-Player (Blue)** - Local multiplayer

---

## 🧠 How I Built This

### What Went Well
✅ Graphics integration was smoother than expected  
✅ BGI library documentation was helpful  
✅ Minimax algorithm works perfectly  

### Challenges Faced
❌ Linking multiple C++ libraries  
❌ Windows API complexity for GUI  
❌ Optimizing Minimax for speed  
❌ Code::Blocks debugging configuration  

### How I Solved Them
1. **Linking Issues:** Used proper compiler flags and library paths
2. **Windows API:** Studied Microsoft documentation and examples
3. **Minimax Performance:** Implemented alpha-beta pruning
4. **Debugging:** Compiled from CMD instead of IDE

---

## 🎓 Learning Outcomes

Through this project, I learned:

| Skill | What I Learned |
|-------|---|
| **Game AI** | Minimax algorithm, game theory concepts |
| **Graphics** | BGI library, real-time rendering, bitmap handling |
| **GUI Development** | Windows API, event handling, button layouts |
| **C++ Advanced** | Multi-file projects, library linking, compilation flags |
| **Problem Solving** | Debugging complex dependencies, optimization |
| **Version Control** | Git, GitHub, professional documentation |

---

## 📝 Project Use & Collaboration

**Acknowledgments:**
- Collaborated with classmates on design approach
- Used AI tools (ChatGPT, Claude) for:
  - Explaining complex concepts
  - Debugging compilation errors
  - Optimizing algorithm efficiency
  - Learning BGI documentation

**Core Implementation:**
All game logic, AI algorithm, graphics integration, and creative 
decisions are my own original work.

---

## 🚀 How to Improve This Project

Future enhancements could include:
- Network multiplayer (play with friends online)
- Difficulty levels with algorithm variations
- Score leaderboard system
- Modern graphics with OpenGL
- Mobile version (Android/iOS)
- Elo rating system for AI vs players

---

## 📞 Questions & Feedback

Have suggestions? Found a bug? Want to contribute?

Feel free to:
- Open an Issue
- Submit a Pull Request
- Contact me on LinkedIn: linkedin.com/in/yassin-salah

---

## 📜 License

This project was created for educational purposes as part of 
2nd Year Computer Engineering coursework at Arab Academy for 
Science, Technology & Maritime Transport.
