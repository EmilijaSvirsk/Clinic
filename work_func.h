#include <generate_func.h>

void track_patient_happiness(Patient pat, int *pat_min, int *pat_mid, int *pat_max, big_int *time_s);

void specialist_work(big_int *index, big_int *time, Specialist *specs, int spec_n, big_int *time_s,
                     int *pat_min, int *pat_mid, int *pat_max);

void calculate_work(Queue *que, big_int *time,
                    Specialist *specs, int spec_n, big_int *time_s,
                    int *pat_min, int *pat_mid, int *pat_max);

void local_work(big_int *index, big_int *time,
                Specialist *specs, big_int *time_s,
                Specialist *local, big_int *time_l, int local_n,
                int *pat_min, int *pat_mid, int *pat_max);

void calculate_work_local(Queue *que, big_int *time,
                    Specialist *specs, int spec_n, big_int *time_s,
                    Specialist *local, int local_n, big_int *time_l,
                    int *pat_min, int *pat_mid, int *pat_max);

int calculate_specialists_wage(Specialist *specs, int spec_n, int pay_s);
