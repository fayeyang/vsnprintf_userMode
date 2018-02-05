
CFLAGS=-g

src:=$(wildcard *.c)
objs:=$(patsubst %.c,%.o,$(src) )
objs+=$(src:.c=.o)

.PHONY:all
all:clean test
	@:
# 据我分析，@:作用是1个占位符，以避免该规则没有命令部分
# @:不执行任何操作，也不会输出任何信息

test:$(objs)
	echo $(.LIBPATTERNS)
	gcc $(CFLAGS) $^ -o $@

# 老版本make中的双后缀规则
#.c.o:
#	gcc -c -o $@ $<

#当前版本make中的模式规则
%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

#$(objs):$(src)
#	gcc -c $< -o $@

.PHONY:clean
clean:
	-rm *.o test







