# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Пути к исходным файлам и заголовочным файлам
SRC_DIR = src
INCLUDE_DIR = include
MODELS_DIR = $(SRC_DIR)/models
TESTS_DIR = $(SRC_DIR)/tests

# Исходные файлы и объектные файлы
SRC = $(MODELS_DIR)/Product.cpp \
      $(MODELS_DIR)/Warehouse.cpp \
      $(MODELS_DIR)/Truck.cpp \
      $(MODELS_DIR)/Order.cpp \
      $(TESTS_DIR)/OrderTests.cpp \
      $(SRC_DIR)/main.cpp 
OBJ = $(SRC:.cpp=.o)

# Исполнительный файл
TARGET = logistics

# Пути для поиска заголовочных файлов
INCLUDES = -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/models -I$(INCLUDE_DIR)/tests

# Правило по умолчанию
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

# Правило для сборки объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Очистка объектных файлов и исполняемого файла
clean:
	rm -f $(OBJ) $(TARGET)

# Правило для компиляции с помощью команды make
.PHONY: all clean