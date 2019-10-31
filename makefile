all:shmsend shmreceive

shmsend:shm_a.o
	gcc $< -o $@

shmreceive:shm_b.o
	gcc $< -o $@

%.o:%.c
	gcc $< -c -o $@ 
.PHONY:
clean: 
	rm shmsend shmreceive *.o
