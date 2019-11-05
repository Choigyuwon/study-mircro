// app.c
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "timer.h"

int is_prime(int n) {
	int i;
	for(i=2;i<=n/2;i++)
		if((n%i)==0) return(0);
	return(1);
}
void app_prime(char *ap) {
	int t=2000,count=0,n;

	if(ap) t= atoi(ap);
	for(n=2; n<=t ;n++) {
		if(is_prime(n)) {
			count++;
			printf("%d is a prime number !!!\n",n);
		}
	}
	printf("count=%d\n",count);
}
void app_list(char *ap) {
	char buf[8],how='a';
	struct node *np;

	if(ap) how = *ap;
	while(1) {
		printf(">> ");
		if(fgets(buf,8,stdin) ==NULL)
			break;
		np=get_node();
		strcpy(np->data,buf);
		switch(how) {
			case 'h':insert_node_head(np); break;
			case 't':insert_node_tail(np); break;
			default:insert_node_ascn(np); break;
		}
	}
	tour_list();
	free_list();
}
void app_timer(char *ap) {
	char buf[8];
	int ms;
	struct task tsk;

	while(1) {
		printf(">> ");
		if(fgets(buf,8,stdin) ==NULL || (ms=atoi(buf))==0)
			break;
		insert_timer(&tsk,ms);
	}
	tour_timer();
	free_timer();
}
