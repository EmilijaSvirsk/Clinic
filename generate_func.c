#include <stdio.h>
#include <stdlib.h>
#include <generate_func.h>
#include <string.h>

void read(char *fl, big_int **time, int *chance, 
          int *spec_n, big_int **time_s, int *pay_s,
          int *local_n, big_int **time_l, int *pay_l)
{
    FILE *fp = fopen(fl, "r");
    char *time_str = (char*) calloc(100, sizeof(char));
    char *time_s_str = (char*) calloc(100, sizeof(char));
    char *time_l_str = (char*) calloc(100, sizeof(char));
    
    fscanf(fp, "%s%*[^\n]", time_str);
    assign_int(time, time_str);
    fscanf(fp, "%d%*[^\n]", chance);
    fscanf(fp, "%d%*[^\n]", spec_n);
    fscanf(fp, "%s%*[^\n]", time_s_str);
    assign_int(time_s, time_s_str);
    fscanf(fp, "%d%*[^\n]", pay_s);
    
    fscanf(fp, "%d%*[^\n]", local_n);
    fscanf(fp, "%s%*[^\n]", time_l_str);
    assign_int(time_l, time_l_str);
    fscanf(fp, "%d%*[^\n]", pay_l);
    
    fclose(fp);
    free(time_str);
    free(time_s_str);
}

void print_patient(Patient pat)
{
    print_int(pat.begin_t);
    printf(" - ");
    print_int(pat.end_t);
    printf(" spec=%d ill=%d health=%d\n", pat.spec, pat.illness, pat.healthy);
}

void generate_patients(Queue *que1, Queue *que2, 
                       big_int *time, int spec_n, int local_n, int chance)
{
    big_int *i = NULL;
    big_int *one = NULL;
    assign_int(&one, "1");
    big_int *minus = NULL;
    assign_int(&minus, "-1");
    for(assign_int(&i, "0"); !is_equal(i,time); i = add_int(i, one))
    {
        int num = rand() % 100;
        if(num <= chance)
        {
            Patient pat;
            pat.exist = 1;
            pat.spec = rand() % spec_n;
            pat.local = rand() % local_n; 
            pat.illness = rand() % spec_n;
            int healty = rand() % 100;
            if(rand() % 100 <= 20)
                pat.healthy = 1;
            else
                pat.healthy = 0;
            copy_int(i, &pat.begin_t);
            copy_int(minus, &pat.end_t);
            Enqueue(que1, pat);
            Enqueue(que2, pat);
        }
        else
        {
            Patient pat;
            pat.exist = 0;
            Enqueue(que1, pat);
            Enqueue(que2, pat);
        }
    }
    delete_int(i);
    delete_int(one);
    delete_int(minus);
}

void generate_specialists(Specialist *specs, int spec_n)
{
    big_int *minus = NULL;
    assign_int(&minus, "-1");
    for(int i = 0; i < spec_n; i++)
    {
        Specialist spec;
        copy_int(minus, &spec.time);
        spec.patient_n = 0;
        spec.bonus = 0;
        spec.que = (Queue*) calloc(1, sizeof(Queue));
        specs[i] = spec;
    }
    delete_int(minus);
}

void print_specialists(Specialist *specs, int spec_n)
{
    for(int i = 0; i < spec_n; i++)
    {
        print_int(specs[i].time);
        printf(" %d %d\n", specs[i].patient_n, specs[i].bonus);
    }
}
