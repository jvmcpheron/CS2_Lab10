# CS2_Lab10

## Introduction
Each connected component of an undirected graph is a set of vertices where it is possible to go from one vertex in the set to any other vertex in the set through the edges of the graph, and the connected components have the largest possible sets.  For example in this graph:

3-component.png 

There are three connected components:

V1, V2, V3, V4, V5, V6
V7, V8, V9
V10, V11, V12
A simple algorithm for finding the connected components of a graph is to find a vertex that is not in a connected component yet and to do a depth-first search from that vertex to find all of the other vertices in the component and assigning them all a component number.  So, in the graph above one might start with V1, then perform DFS on it and label all of the vertices V1-V6 as being part of component 1.  Then we would find another vertex that is not in a component (like V7) and perform DFS on it to label all of the vertices V7-V9 as part of component 2, and so on.

Using the code given in class write a program that takes in the description of an undirected graph and determines the connected components in that graph.

## What to Submit
Submit your solution as a CPP file. Give the file the name AssignmentTypeNumberLastNameFirstName.cpp (so, for example, my submission for Lab 3 would be named Lab3MaclinRichard.cpp). You should also include your first and last name in the file as a comment. Add a long comment in your code showing examples of the results produced from your code.