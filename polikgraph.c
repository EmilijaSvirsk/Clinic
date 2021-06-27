#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <work_func.h>

void print_results(char *fl, int wage, int local_n)
{
    FILE *fp = fopen(fl, "w");
    
    fprintf(fp, "%d\n", local_n);
    fprintf(fp, "%d\n", wage);
    
    fclose(fp);
}

int main()
{
    char *fl_read = (char*) calloc(20, sizeof(char));
    strcpy(fl_read, "duomgraph.txt");
    char *fl_write = (char*) calloc(20, sizeof(char));
    strcpy(fl_write, "rezgraph.txt");
    
    big_int *time = NULL;
    int chance;
    
    int spec_n; 
    big_int *time_s = NULL; 
    int pay_s;
    Queue *que = calloc(1, sizeof(Queue));
    
    int local_n; 
    big_int *time_l = NULL; 
    int pay_l;
    Queue *que_local = calloc(1, sizeof(Queue));
    
    read(fl_read, &time, &chance, &spec_n, &time_s, &pay_s, &local_n, &time_l, &pay_l);
    free(fl_read);
    generate_patients(que, que_local, time, spec_n, local_n, chance);
    
    Specialist *specs_local = (Specialist*) calloc(spec_n, sizeof(Specialist));
    generate_specialists(specs_local, spec_n);
    Specialist *local = (Specialist*) calloc(local_n, sizeof(Specialist));
    generate_specialists(local, local_n);
    int pat_min_l = 0;
    int pat_mid_l = 0;
    int pat_max_l = 0;
    calculate_work_local(que_local, time, 
                         specs_local, spec_n, time_s, 
                         local, local_n, time_s, 
                         &pat_min_l, &pat_mid_l, &pat_max_l);
    int wage_l = calculate_specialists_wage(local, local_n, pay_l) +
                 calculate_specialists_wage(specs_local, spec_n, pay_s) +
                 spec_n * pay_s*2 + local_n * pay_l*2;
    print_results(fl_write, wage_l, local_n);
    free(que_local);
    free(specs_local);
    free(local);
    
    delete_int(time);
    delete_int(time_s);
    delete_int(time_l);
} 
