#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <work_func.h>

void track_patient_happiness(Patient pat, int *pat_min, int *pat_mid, int *pat_max, big_int *time_s)
{
    big_int *time = subtract_int(pat.end_t, pat.begin_t);
    big_int *two = NULL;
    assign_int(&two, "2");
    big_int *double_time = multiply_int(time_s, two);
    big_int *half_time = divide_int(time_s, two);
    
    if(!check_if_bigger(time, double_time))
        ++(*pat_max);
    else if(!check_if_bigger(time, add_int(double_time, half_time)))
        ++(*pat_mid);
    else
        ++(*pat_min);
    
    delete_int(time);
    delete_int(two);
    delete_int(double_time);
    delete_int(half_time);
}

void specialist_work(big_int *index, big_int *time, Specialist *specs, int spec_n, big_int *time_s,
                     int *pat_min, int *pat_mid, int *pat_max)
{
    big_int *zero = NULL;
    assign_int(&zero, "0");
    big_int *one = NULL;
    assign_int(&one, "1");
    big_int *minus = NULL;
    assign_int(&minus, "-1");
    for(int i = 0; i < spec_n; i++)
        {
            if(!is_equal(specs[i].time, minus))
            {
                specs[i].time = subtract_int(specs[i].time, one);
                if(is_equal(specs[i].time, zero))
                {
                    ++specs[i].patient_n;
                    if(!check_if_bigger(time, index))
                        ++specs[i].bonus;
                    
                    Patient pat;
                    Dequeue(specs[i].que, &pat);
                    if(pat.illness == i || pat.healthy == 1)
                    {
                        copy_int(index, &pat.end_t);
                        track_patient_happiness(pat, pat_min, pat_mid, pat_max, time_s);
                        //print_patient(pat);
                    }
                    else
                    {
                        Enqueue(specs[pat.illness].que, pat);
                        if(is_equal(specs[pat.illness].time, minus))
                            specs[pat.illness].time = add_int(time_s, one);
                    }
                    
                    if(Queue_isEmpty(*specs[i].que) == 1)
                        copy_int(minus, &specs[i].time);
                    else
                        copy_int(time_s, &specs[i].time);
                }
            }
        }
    delete_int(zero);
    delete_int(one);
    delete_int(minus);
}

void calculate_work(Queue *que, big_int *time,
                    Specialist *specs, int spec_n, big_int *time_s,
                    int *pat_min, int *pat_mid, int *pat_max)
{
    big_int *i = NULL;
    big_int *one = NULL;
    assign_int(&one, "1");
    big_int *minus = NULL;
    assign_int(&minus, "-1");
    for(assign_int(&i, "0"); !is_equal(i,time); i = add_int(i, one))
    {
        Patient pat;
        Dequeue(que, &pat);
        if(pat.exist == 1)
        {
            Enqueue(specs[pat.spec].que, pat); 
            if(is_equal(specs[pat.spec].time, minus))
                specs[pat.spec].time = add_int(time_s, one);
        }
        
        specialist_work(i, time, specs, spec_n, time_s, pat_min, pat_mid, pat_max);
    }
    
    big_int *after_t = NULL;
    copy_int(time, &after_t);
    int done = 0;
    while(done == 0)
    {
        done = 1;
        for(int i = 0; i < spec_n; i++)
            if(!is_equal(specs[i].time, minus))
                done = 0;
        if(done == 0)
            specialist_work(after_t, time, specs, spec_n, time_s, pat_min, pat_mid, pat_max);
        after_t = add_int(after_t, one);
    }
    delete_int(after_t);
    delete_int(one);
    delete_int(i);
    delete_int(minus);
}

void local_work(big_int *index, big_int *time,
                Specialist *specs, big_int *time_s,
                Specialist *local, big_int *time_l, int local_n,
                int *pat_min, int *pat_mid, int *pat_max)
{
    big_int *zero = NULL;
    assign_int(&zero, "0");
    big_int *one = NULL;
    assign_int(&one, "1");
    big_int *minus = NULL;
    assign_int(&minus, "-1");
    for(int i = 0; i < local_n; i++)
        {
            if(!is_equal(local[i].time, minus))
            {
                local[i].time = subtract_int(local[i].time, one);
                if(is_equal(local[i].time, zero))
                {
                    ++local[i].patient_n;
                    if(!check_if_bigger(time, index))
                        ++local[i].bonus;
                    
                    Patient pat;
                    Dequeue(local[i].que, &pat);
                    if(pat.healthy == 1)
                    {
                        copy_int(index, &pat.end_t);
                        track_patient_happiness(pat, pat_min, pat_mid, pat_max, time_l);
                        //print_patient(pat);
                    }
                    else
                    {
                        Enqueue(specs[pat.illness].que, pat);
                        if(is_equal(specs[pat.illness].time, minus))
                            specs[pat.illness].time = add_int(time_s, one);
                    }
                    
                    if(Queue_isEmpty(*local[i].que) == 1)
                        copy_int(minus, &local[i].time);
                    else
                        copy_int(time_l, &local[i].time);
                }
            }
        }
    delete_int(zero);
    delete_int(one);
    delete_int(minus);
}

void calculate_work_local(Queue *que, big_int *time,
                    Specialist *specs, int spec_n, big_int *time_s,
                    Specialist *local, int local_n, big_int *time_l,
                    int *pat_min, int *pat_mid, int *pat_max)
{
    big_int *i = NULL;
    big_int *one = NULL;
    assign_int(&one, "1");
    big_int *minus = NULL;
    assign_int(&minus, "-1");
    for(assign_int(&i, "0"); !is_equal(i,time); i = add_int(i, one))
    {
        Patient pat;
        Dequeue(que, &pat);
        if(pat.exist == 1)
        {
            Enqueue(local[pat.local].que, pat); 
            if(is_equal(local[pat.local].time, minus))
                local[pat.local].time = add_int(time_l, one);
        }
        local_work(i, time, specs, time_s, local, time_l, local_n, pat_min, pat_mid, pat_max);
        specialist_work(i, time, specs, spec_n, time_s, pat_min, pat_mid, pat_max);
    }
    
    big_int *after_t = NULL;
    copy_int(time, &after_t);
    int done = 0;
    while(done == 0)
    {
        done = 1;
        for(int i = 0; i < local_n; i++)
            if(!is_equal(local[i].time, minus))
                done = 0;
        if(done == 0)
            local_work(after_t, time, specs, time_s, local, time_l, local_n, pat_min, pat_mid, pat_max);
        
        for(int i = 0; i < spec_n; i++)
            if(!is_equal(specs[i].time, minus))
                done = 0;
        if(done == 0)
            specialist_work(after_t, time, specs, spec_n, time_s, pat_min, pat_mid, pat_max);
        
        after_t = add_int(after_t, one);
    }
    delete_int(after_t);
    delete_int(one);
    delete_int(i);
    delete_int(minus);
}

int calculate_specialists_wage(Specialist *specs, int spec_n, int pay_s)
{
    int wage = 0;
    for(int i = 0; i < spec_n; i++)
    {
        wage += (specs[i].patient_n + specs[i].bonus) * pay_s;
    }
    return wage;
} 
