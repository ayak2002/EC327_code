# pa-4
This is the continuation of PA3. The game now includes a Virus object.

How the game works with Virus:

The virus seeks the closest active student and goes after it. If the student is within a distance 2 of the virus, the student gets infected if it has less antibodies than the resistance of the virus. If it has more, it loses two antibodies.
Whenever a virus infects a student, its resistance gets incremented by 2.
Everytime a virus takes 2 steps (speed of 2), it loses 1 unit of energy.

Because the virus seeks the closest student and moves towards it, this would mean that it would always get to a student and that Update() would always return 1 as soon as a virus finds a student. To solve this problem, whenever a virus encounters a student (a message saying that the student has either been infected or the student is resistant will be shown when this happens), the virus is moved away from the student to a random location and a message saying that the virus has been moved away from the student will be printed.
