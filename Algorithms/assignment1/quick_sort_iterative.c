#include "common.h"
#include "quick.h"

// #define DEBUG 1

int main() {
	int n;
	lli *ary;
	int ite_i;
	llu swap_comparision=0;


    struct rusage usageInfo;
    struct timeval startUser, startSys, endUser, endSys;
    long long int time_taken_q_i = 0;
	
	// seeding random 
	srand(time(0));
	
	scanf("%d", &n);
	ary = MALLOC(lli, n);

	for(ite_i=0; ite_i<n; ite_i++){
		ary[ite_i] = rand()%MODULO;
	}

#ifdef DEBUG
    for(ite_i=0; ite_i<n; ite_i++){
		printf("%lld ", ary[ite_i]);
	}
    printf("\n");
#endif
	
	if (0 != getrusage(RUSAGE_SELF, &usageInfo))
		perror("getrusage: ");
	startUser = usageInfo.ru_utime;
	startSys = usageInfo.ru_stime;

    quick_sort_iterative(ary, 0, n-1, &swap_comparision);

	if (0 != getrusage(RUSAGE_SELF, &usageInfo))
		perror("getrusage: ");
	endUser = usageInfo.ru_utime;
	endSys = usageInfo.ru_stime;

	time_taken_q_i += (DURATION(startUser, endUser) + DURATION(startSys, endSys));

#ifdef DEBUG
	for(ite_i=0; ite_i<n; ite_i++){
		printf("%lld ", ary[ite_i]);
	}
    printf("\n");
#endif

	printf(
            "No.Elements: %d\nTime Taken: %LF\nNo. of Comparision and Swap: %llu\n", 
            n, 
            (long double)((long double)time_taken_q_i/(long double)(LOOPCOUNT)),
			swap_comparision
        );
	check_increasing_sequence(ary, n);
	return 0;
}
