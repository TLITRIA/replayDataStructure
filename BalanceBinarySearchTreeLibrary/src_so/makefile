OBJS=$(patsubst %.c, %.o, $(wildcard ./*.c))
TARGET=libSoMyAVLTree.so

$(TARGET):$(OBJS)
	$(CC) -shared -fPIC $^ -o $@
	sudo cp $(TARGET) /usr/lib

# 模式匹配 %目标:%依赖
%.o:%.c
	$(CC) -c $^ -o $@

clean:
	$(RM) $(OBJS) $(TARGET)
	sudo $(RM) /usr/lib/$(TARGET)