1.
                           (Shuriken) ---> (Ban Hammer)
                          /          \                 \ 
              (Slingshot) -> (Vine)   (Katana)          (Scythe)
             /      |                    |                |           
    (Boombox)       |       (Coil)    (Hyperlaser)    (Medkit)
             \      |      /      \                   |   
              (Skateboard)         (Subspace)_________/
3.

4. Breadth First and Depth First looks like it will have the same time complexity of O(V+E), but it will depend on many connections (edges) are between each object (vertex). Breadth First will go visit every adjascent Vertex, and if there are many edges, it will get more time complex which means O(1) for a array-like structure, and up to O(V^2). Depth First visits vertexes along a path from the starting vertex to the ending vertex. It will search and visit vertexes along a path before backtracking to the next path.
