# JarvisAlgorithm

Jarvis' algorithm - determining the convex envelope of a set of points located on the plane

The computational complexity is relatively small and amounts to O(kn), where n is the number of points in the set P, and k is the number of points in the envelope. In the worst case, the computational complexity may be O(n ^ 2) when k = n.
The algorithm determines the point with the minimum and maximum y coordinates.

Program input:
n - number of points in the coordinate system
n * (x, y) - n consecutive points with coordinates x and y

The program output is a set of points belonging to the envelope
