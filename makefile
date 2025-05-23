# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -O2

# Linker flags
LDFLAGS = -lsqlite3

# Arquivos fonte
SRC = src/entity/Wallet.cpp src/dao/SQLiteWalletDAO.cpp src/main.cpp

# Arquivos objeto
OBJ = $(SRC:.cpp=.o)

# Executável final
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
