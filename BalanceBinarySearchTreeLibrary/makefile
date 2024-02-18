# 自定义变量
TARGET=main
OBJ=$(patsubst %.c, %.o, $(wildcard ./*.c))

LDFALGS=-L./src_so
LIBS=-lSoMyAVLTree

# 使用$(TARGET) 必须要加$
$(TARGET):$(OBJ)
	$(CC) $^ $(LIBS) $(LDFALGS) -o $@
	
%.o:%.c
	$(CC) -c $^ -o $@


# 伪文件
.PHONY: clean show
clean:
	@rm -rf *.o $(TARGET)

show:
	@echo $(RM)
	@echo $(CC)
	@echo $(CXX)
	@echo $(wildcard ./*.c)
