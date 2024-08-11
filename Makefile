# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Исходные файлы и объектные файлы
SRC = main.cpp Product.cpp Warehouse.cpp Truck.cpp Order.cpp
OBJ = $(SRC:.cpp=.o)

# Исполнительный файл
TARGET = logistics

# Правило по умолчанию
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правило для сборки объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка объектных файлов и исполняемого файла
clean:
	rm -f $(OBJ) $(TARGET)

# Правило для компиляции с помощью команды make
.PHONY: all clean