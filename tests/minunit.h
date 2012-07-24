#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h
  
#include <stdio.h> 
#include <dbg.h>
#include <stdlib.h>
 
#define mu_suite_start() char *message = NULL 
 
#define mu_assert(test, message) if (!(test)) { log_err(message); return message; } 
#define mu_run_test(test) printf("\n");\
    message = test(); tests_run++; if (message) return message;
 
#define RUN_TESTS(name) int main(int argc, char *argv[]) {\
    argc = 1;\
        char *result = name();\
        exit(result != 0);\
}

int tests_run;

#endif
