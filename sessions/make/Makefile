OBJS = main.o sub.o rou.o
FLAGS = -O2 -g
program : ${OBJS}
	icpc -o $@ ${OBJS}
%.o : %.cxx
	@echo "Now compiling: $<"
	@icpc ${FLAGS} -c $<
run : program
	@for input in 1 3 5 7 ; do \
	    echo "running with input: $${input}" ; \
	    echo $${input} | ./program \
	 ; done

# main.o : main.cxx
# 	icpc -c $<
# sub.o : sub.cxx
# 	icpc -c $<
# rou.o : rou.cxx
# 	icpc -c $<

${OBJS} : sub.h

clean :
	rm -f program ${OBJS} *~
