Write a C program that will get the size of the parking area, the number of cars parked,
and a sequence of locations occupied by the cars. The user will first input the size of
the parking area such as 20 which represents a 20 x 20 grid. Second, the user will give
the number of cars parked in this area, such as 15 indicating that there are 15 cars
parked in this area. Finally, the user will input each car’s location in X and Y axis, such
as 3 5 indicating that a car is parked at location X=3 and Y=5.
Your program will keep a two dimensional array that represents the grid, and the
array will be filled with 1 if the grid’s x
th and y
th position has a car parked, and 0
otherwise. Then it should calculate each empty slot’s distance to the surrounding
cars, and return the empty slot which has the LARGEST distance to the NEAREST car.
You are required to calculate the distance between two locations using Manhattan
distance (search how it is computed). If there are two locations that can potentially
be the best slots (based on these slots’ distances to the other cars), your program should return the one with the smaller X value. If they both have the
same X value, then your program should return the one with the smaller Y value.
Figure 1 represents a parking area of 5 x 5 and the cars parked in different locations.
