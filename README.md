# Clinic

A simulation of clinic's reception with a set number of workers and randomly generated patients written in C and a graph is drawn by python.

Task:
The work day is represented by a number of ticks and there is a known chance that a patient will show up during the tick. 
The patient has a randomly generated number of an illness and a chance to be healthy. They are sent to a random worker and if
the patient is healthy or their illness number coincides with the worker's number, they are released after a set amount of ticks.
If not, then after a set amount of time they are sent to the worker that has the right number. If the worker is busy at the time, the patient is
put in the queue, until their time comes. The workers are paid for the number of patients they have received plus a set bonus (in case they did not 
receive any patients that day). If the workers are working overtime, they get a double pay for a released patient.
 
 Option 1
 The clinic has workers in specific areas, that work faster than proffesional workers at the clinic and have a lower income. 
 All the patients go to their area's worker, however that worker cannot cure the illness. Thus, if the patient is healthy, they are
 released, if not, they are immediatelly sent to the right proffesional worker at the clinic.
 
 Option 2
 The clinic does not have any area workers and the patients go right away to the proffesionals.
 
 Find which option is more efficient and costs less.
 
 Example:
800 ticks
30 chance that a patient will show up
100 proffesional workers
20 ticks a proffesional worker spends on one patient
50 money a proffesional worker gets per patient
80 area workers
10 ticks an area worker spends on one patient
25 money an area worker gets per patient

Solution1 (compare the two options):
run on the console
$ make -f makefile2
$ ./polik
in created file rez.txt:
Only specialists
Patient happiness: min = 18, mid = 98, max = 128
Specialist wage = 32400

With local workers
Patient happiness: min = 13, mid = 8, max = 223
Specialist wage = 30225

Solution2 (find the most efficient area worker number):
run on the console
$ make -f makefile2
$ python3 graph.py
the drawn graph will show how cost fluctuates by lowering the number of area workers.
