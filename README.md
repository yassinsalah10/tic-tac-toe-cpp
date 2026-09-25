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
