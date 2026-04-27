1. Since Dijkstra's Algorithm finds the shortest path, it will first go from A to C, and mark C as complete. A will then go from A to B, marking it as complete, since C has already been marked as complete. Because of this, the algorithm will see 0 + 2 (A->C) (2) as the shortest path, but fail to see that the distance 0 + 17 - 25 (A->B->C) (-8) is the actual shortest path. 

```
      ___17___ (B)
    /          /
(A)          -25
    \_2_(C)_/
```
