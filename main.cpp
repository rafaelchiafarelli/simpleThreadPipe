/*
 * main.cpp
 *
 *  Created on: 11 de jan de 2020
 *      Author: skiafa
 */
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string>
#include <unistd.h>
#include <vector>
#include <mutex>

using namespace std;


//int fd[2];//File descriptor for creating a pipe

struct pipe_type{
	int p[2];
};



struct reader_type{
	char name[10];
	int position;
};

vector<pipe_type> notifier;
vector<reader_type> r_n;


void *reader(void *v)
{

 int     count = 0;

  //Delay in starting the reading from the pipe
  reader_type *r = (reader_type *)v;
	char    ch;
	int		iteration;
	int     result;
  while(1){

		int random_sleep = 30000 + rand() % 15000 + (-7500);
		printf ("begin n: %s c: %d i: %d t: %d \n",r->name,++count, iteration, random_sleep);
		result = read (notifier.at(r->position).p[0],&iteration,1);
		if (result != 1) {
		  perror("read");
		  exit(3);
		}
		printf ("end n: %s c: %d i: %d t: %d \n",r->name,++count, iteration, random_sleep);
		usleep (random_sleep);
  }
}

//This function continously writes Alphabet into fd[1]

void *writer(void *v)
{

    int     result;
    char    ch='A'; int     count = 0;

    while(1){
    	vector<pipe_type>::iterator it = notifier.begin();
    	int i=0;
    	while(it!=notifier.end())
    	{
    		printf("write to %d \n",i);
    		i++;

    		result = write (it->p[1], &count,1);

			if (result != 1){
			   perror ("write");
			   exit (2);
			}

			it++;
    	}

        printf ("%s: %d %c\n",(char *)v, ++count, ch);
		int random_sleep = rand() % 15000 + (-7500);

		usleep (10000 + random_sleep);

   }
}

int main()
{

	int             result;
	for(int i =0; i<15;i++){
		reader_type  r;


		pipe_type p;

		result = pipe(p.p);

		if (result < 0){
			perror("pipe ");
			exit(1);
		}
		notifier.push_back(p);

		sprintf(r.name,"r_g%d",i);
		r.position = i;
		r_n.push_back(r);

	}

   pthread_t       frame_grabber;
   pthread_t	   rest_grabber_1;
   pthread_t	   rest_grabber_2;
   pthread_t	   rest_grabber_3;
   pthread_t	   rest_grabber_4;
   pthread_t	   rest_grabber_5;
   pthread_t	   rest_grabber_6;
   pthread_t	   rest_grabber_7;
   pthread_t	   rest_grabber_8;
   pthread_t	   rest_grabber_9;
   pthread_t	   rest_grabber_10;
   pthread_t	   rest_grabber_11;
   pthread_t	   rest_grabber_12;
   pthread_t	   rest_grabber_13;
   pthread_t	   rest_grabber_14;
   pthread_t	   rest_grabber_15;

   pthread_create(&frame_grabber,NULL,writer,(void *)"f_g");

   pthread_create(&rest_grabber_1,NULL,reader,(void *)&r_n.at(0));
   pthread_create(&rest_grabber_2,NULL,reader,(void *)&r_n.at(1));
   pthread_create(&rest_grabber_3,NULL,reader,(void *)&r_n.at(2));
   pthread_create(&rest_grabber_4,NULL,reader,(void *)&r_n.at(3));
   pthread_create(&rest_grabber_5,NULL,reader,(void *)&r_n.at(4));
   pthread_create(&rest_grabber_6,NULL,reader,(void *)&r_n.at(5));
   pthread_create(&rest_grabber_7,NULL,reader,(void *)&r_n.at(6));
   pthread_create(&rest_grabber_8,NULL,reader,(void *)&r_n.at(7));
   pthread_create(&rest_grabber_9,NULL,reader,(void *)&r_n.at(8));
   pthread_create(&rest_grabber_10,NULL,reader,(void *)&r_n.at(9));
   pthread_create(&rest_grabber_11,NULL,reader,(void *)&r_n.at(10));
   pthread_create(&rest_grabber_12,NULL,reader,(void *)&r_n.at(11));
   pthread_create(&rest_grabber_13,NULL,reader,(void *)&r_n.at(12));
   pthread_create(&rest_grabber_14,NULL,reader,(void *)&r_n.at(13));
   pthread_create(&rest_grabber_15,NULL,reader,(void *)&r_n.at(14));


   pthread_join(frame_grabber,NULL);
   pthread_join(rest_grabber_1,NULL);
   pthread_join(rest_grabber_2,NULL);
   pthread_join(rest_grabber_3,NULL);
   pthread_join(rest_grabber_4,NULL);
   pthread_join(rest_grabber_5,NULL);
   pthread_join(rest_grabber_6,NULL);
   pthread_join(rest_grabber_7,NULL);
   pthread_join(rest_grabber_8,NULL);
   pthread_join(rest_grabber_9,NULL);
   pthread_join(rest_grabber_10,NULL);
   pthread_join(rest_grabber_11,NULL);
   pthread_join(rest_grabber_12,NULL);
   pthread_join(rest_grabber_13,NULL);
   pthread_join(rest_grabber_14,NULL);
   pthread_join(rest_grabber_15,NULL);

}

