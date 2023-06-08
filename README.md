# Drunk-Knight-s-Path
The objective of this assignment is to practice object-oriented programming. You will write a class 
and a client program to walk a drunk knight’s path.
In the game of chess, a knight (馬) is a piece which moves like the letter L (「日」字) on a 
chessboard. That is, it moves two squares horizontally and one square vertically (2H1V) or 1H2V. A 
drunk knight’s path is a sequence of knight moves on a chessboard such that the knight never 
revisits a square and “turns back in a next move”. “Never turns back” means that a knight cannot 
move in the two directions that is behind itself. Figure 1 shows an example, where the knight has 
just moved from position B1 to C3. Its next destination can only be the five squares E2, E4, D5, B5, or
A4, but cannot be A2 and D1. Figure 2 shows a drunk knight’s path for a 6 × 6 board. Note that the 
knight can eventually end up in a square where it has no more possible moves but other squares 
remain unvisited. An example can be seen after 10 moves in Figure 2. (The knight can move to 
neither D0 nor E3, as they are turn-backs.) Your overall program will let users put a knight 
somewhere on a chessboard and moves it until no more moves can be made.
