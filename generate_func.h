#include <big_int.h>
#include <queue.h>

typedef struct Specialist
{
    big_int *time;
    int patient_n;
    int bonus;
    Queue *que;
} Specialist;

void read(char *fl, big_int **time, int *chance, 
          int *spec_n, big_int **time_s, int *pay_s,
          int *local_n, big_int **time_l, int *pay_l);
void print_patient(Patient pat);
void generate_patients(Queue *que1, Queue *que2, 
                       big_int *time, int spec_n, int local_n, int chance);
void generate_specialists(Specialist *specs, int spec_n);
void print_specialists(Specialist *specs, int spec_n);
