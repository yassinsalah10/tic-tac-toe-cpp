# 🎮 Tic Tac Toe AI Game

**2nd Year Computer Engineering Project (2024)**  
Arab Academy for Science, Technology & Maritime Transport

A professional Windows-based Tic Tac Toe game featuring a custom GUI launcher, intelligent AI opponent using Minimax algorithm, and real-time BGI graphics rendering.

---

## 📸 Application Interface

### Main Launcher
![Launcher Interface](Screenshot%202026-09-25%20081451.png)

Professional GUI launcher with three game mode selections:
- **Easy AI (Green Button)** — Beatable opponent with basic strategy
- **Hard AI (Magenta Button)** — Unbeatable AI using Minimax algorithm
- **Two-Player Mode (Blue Button)** — Local multiplayer competition

Custom neon-styled interface with professional button graphics and responsive window management.

### Active Gameplay
![Gameplay Screen](Screenshot%202026-09-25%20081811.png)

Real-time game board rendering during active gameplay:
- Clean visual game state representation
- Real-time X/O placement
- Instant win/loss/draw detection
- Play again functionality for multiple rounds

---

## 🎯 Project Overview

This application demonstrates comprehensive software engineering principles through a complete game implementation. The project integrates graphics programming, artificial intelligence, GUI development, and multi-library C++ compilation.

**Core Features:**
- ✅ Professional Windows API-based launcher
- ✅ BGI Graphics Library for real-time rendering
- ✅ Three distinct game modes with different AI difficulty levels
- ✅ Minimax algorithm for unbeatable AI opponent
- ✅ Win tracking and score management
- ✅ Complete multi-file C++ architecture

---

## 🔬 Technical Architecture

### Minimax AI Algorithm

The Hard AI mode implements the Minimax game theory algorithm:
Algorithm: Minimax with Alpha-Beta Pruning

Generate all possible board states (recursive)
Score each terminal state:
AI Win: +10
Draw: 0
AI Loss: -10
Select move maximizing AI score / minimizing opponent score
Prune branches that cannot affect final decision

Result: Hard AI never loses


**Performance Metrics:**
- Worst Case: O(9!) game states
- Optimized: Alpha-beta pruning reduces to ~O(3^8)
- Real-time decision making

### System Architecture

┌─ Launcher Module (main.c)
│ └─ Windows API GUI
│
├─ Easy AI Mode (maineasyyyyyyyyyyy.cpp)
│ └─ Basic strategy algorithm
│
├─ Hard AI Mode (main.cpp)
│ └─ Minimax algorithm implementation
│
└─ Two-Player Mode (maintwoplayers.cpp)
└─ Local multiplayer gameplay


**Design Rationale:**
- Modular architecture enables independent compilation and testing
- Separate executables prevent dependency conflicts
- Clean code organization improves maintainability

### Graphics & Interface Implementation

- **Graphics Engine:** BGI (Graphics Library)
  - Real-time board rendering
  - Custom bitmap assets for buttons
  - Responsive window management

- **GUI Framework:** Windows API
  - Professional launcher interface
  - Event-driven button handling
  - Bitmap-based graphics assets

- **Visual Assets:** Custom BMP files
  - Professional button graphics (3 files)
  - Neon-styled background
  - Game state visualization

---

## 💻 Built With

| Component | Technology | Purpose |
|-----------|-----------|---------|
| **Language** | C/C++ | Core implementation |
| **Graphics** | BGI Library | Real-time rendering |
| **GUI** | Windows API | Launcher interface |
| **AI** | Minimax Algorithm | Hard mode opponent |
| **Compiler** | TDM-GCC 32-bit | Compilation |
| **IDE** | Code::Blocks | Development environment |
| **VCS** | Git / GitHub | Version control |

---

## 🏗️ Project Files

project4/
├── main.c # Launcher GUI (Windows API)
├── main.cpp # Hard AI mode (Minimax algorithm)
├── maineasyyyyyyyyyyy.cpp # Easy AI mode (basic strategy)
├── maintwoplayers.cpp # Two-player mode
├── 1.bmp # Background graphics
├── Delivering t77he00000 Future.bmp # Easy AI button
├── Delivering the Fu0000ture44.bmp # Hard AI button
├── Delivering the Fut00000000000ure.bmp # Two-Player button
├── project4.cbp # Code::Blocks project
└── bin/Debug/ # Compiled executables


---

## 🛠️ Build & Compilation

### Prerequisites
- Windows operating system
- TDM-GCC 32-bit compiler
- BGI Graphics Library
- Code::Blocks IDE (optional)

### Compilation Commands

**Launcher:**
```bash
g++ -o project4.exe main.c -luser32 -lgdi32 -lcomdlg32
```

**Easy AI Mode:**
```bash
g++ -I C:\TDM-GCC-32\include -o easy_ai.exe maineasyyyyyyyyyyy.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 C:\TDM-GCC-32\lib\libbgi.a
```

**Hard AI Mode:**
```bash
g++ -I C:\TDM-GCC-32\include -o hard_ai.exe main.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 C:\TDM-GCC-32\lib\libbgi.a
```

**Two-Player Mode:**
```bash
g++ -I C:\TDM-GCC-32\include -o twoplayers.exe maintwoplayers.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 C:\TDM-GCC-32\lib\libbgi.a
```

### Running the Application

```bash
cd C:\GameProjects\project4
project4.exe
```

---

## 📊 Project Specifications

| Metric | Value |
|--------|-------|
| **Development Duration** | 2 weeks |
| **Year Completed** | 2024 |
| **Total Lines of Code** | 2000+ |
| **Code Modules** | 4 executable files |
| **Executable Size** | ~160KB per module |
| **Game Modes** | 3 distinct modes |
| **Hard AI Record** | 0 losses |

---

## 🎓 Technical Competencies Demonstrated

| Competency | Implementation |
|------------|-----------------|
| **Algorithm Design** | Minimax with alpha-beta pruning |
| **Graphics Programming** | BGI library integration, real-time rendering |
| **GUI Development** | Windows API, event handling, bitmap graphics |
| **C++ Advanced** | Multi-file projects, complex compilation, library linking |
| **Software Architecture** | Modular design, separation of concerns |
| **Problem Solving** | Library debugging, compiler configuration, optimization |
| **Version Control** | Git, GitHub, professional documentation |
| **Performance Optimization** | Algorithm pruning, decision tree optimization |

---

## 🧠 Development Process

### Challenges & Solutions

| Challenge | Solution |
|-----------|----------|
| **Multi-library compilation** | Proper compiler flags and library paths established |
| **Minimax performance** | Alpha-beta pruning optimization implemented |
| **Windows API complexity** | Microsoft documentation study and best practices applied |
| **Compiler configuration** | Command-line compilation workflow developed |
| **Linking errors** | Systematic dependency management and flag organization |

### Learning Outcomes

Through this project, I gained proficiency in:

✓ Game theory algorithms and implementations  
✓ Graphics library integration and real-time rendering  
✓ Windows GUI programming and event handling  
✓ Complex C++ project architecture and compilation  
✓ Software optimization techniques  
✓ Professional debugging and problem-solving  
✓ Technical documentation and version control  

---

## 🤝 Development Collaboration

**Acknowledgments:**
- Collaborated with classmates on architectural design discussions
- Utilized AI tools (ChatGPT, Claude) for:
  - Technical documentation comprehension
  - Compilation error debugging
  - Algorithm optimization strategies
  - Library integration guidance

**Core Development:**
All fundamental work represents original development:
- ✅ Game logic implementation
- ✅ AI algorithm implementation
- ✅ Graphics integration
- ✅ GUI architecture
- ✅ Problem solving and debugging
- ✅ Technical decision making

This demonstrates professional engineering practice: leveraging available tools while maintaining ownership of core technical contributions.

---

## 🚀 Future Enhancement Roadmap

**Potential Improvements:**

Phase 1 (Short-term):
- [ ] Network-based multiplayer capability
- [ ] Difficulty level variations
- [ ] Score leaderboard system

Phase 2 (Medium-term):
- [ ] Modern graphics framework (OpenGL/DirectX)
- [ ] Cross-platform compatibility
- [ ] Mobile version (Android/iOS)

Phase 3 (Long-term):
- [ ] Competitive ranking system
- [ ] Machine learning AI variants
- [ ] Advanced algorithm implementations

---

## 📋 Project Metadata

| Metadata | Value |
|----------|-------|
| **Academic Institution** | Arab Academy for Science, Technology & Maritime Transport |
| **Academic Level** | 2nd Year Computer Engineering |
| **Project Year** | 2024 |
| **Author** | Yassin Salah |
| **License** | Educational Use |
| **Repository** | github.com/yassinsalah10/tic-tac-toe-cpp |

---

## 📄 License & Attribution

This project was created for educational purposes as part of 2nd year computer engineering coursework at Arab Academy for Science, Technology & Maritime Transport.

**Usage:** Available for academic review and educational reference.

---

## 📞 Professional Inquiry

For technical discussions, code reviews, or collaboration opportunities:

📧 Professional Inquiries Welcome  
🔗 GitHub: github.com/yassinsalah10/tic-tac-toe-cpp  
💼 LinkedIn: linkedin.com/in/yassin-salah  

---

**Last Updated:** September 2026  
**Project Status:** Complete & Documented
