###################################################
# Makefile (*.cppをコンパイルする場合)
# コンパイルしたいソースがあるフォルダと同じところに置く
# ディレクトリ階層図
# this
# |--- *.cpp          (コンパイルしたいソースファイル)
# |--- Makefile
# |--- run.exe        (生成される実行ファイル)
# |--- obj            (生成されるフォルダ)
#      |--- *.o       (生成されるオブジェクトファイル)
#      |--- *.d       (生成される依存関係ファイル)
#
# 実行コマンド
# make         (更新されたファイルのみコンパイル)
# make all     (クリーンしてビルド)
# make clean   (クリーン)
###################################################
AR       = ar
ARFLAGS  = rus

CXX      = g++
# CXXFLAGS = -g -std=c++11 -MMD -MP -Wall -Wextra -Winit-self -Wno-unused-parameter -O3 
# CXXFLAGS = -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTI -Wall -Wuninitialized -Wextra -Wcast-align -Wcast-qual -Wdelete-non-virtual-dtor -Wdisabled-optimization -Winit-self -Wmissing-include-dirs -Wold-style-cast -Wredundant-decls -Wswitch-enum -Wswitch-default -Wdouble-promotion -O3 -g -std=gnu++17
 CXXFLAGS = -fsanitize=address -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTI -Wall -Wuninitialized -Wextra -Wcast-align -Wcast-qual -Wdelete-non-virtual-dtor -Wdisabled-optimization -Winit-self -Wmissing-include-dirs -Wold-style-cast -Wredundant-decls -Wswitch-enum -Wswitch-default -Wdouble-promotion -O3 -g -std=gnu++17

RM       = rm -f
# LDFLAGS  =
LDFLAGS  = -fsanitize=address
LIBS     =
INCLUDE  = 
#実行ファイル
TARGET   = ./run
#オブジェクトファイル保存フォルダ
OBJDIR   = ./obj
#ソースファイル
SOURCES  = $(wildcard *.cpp)
#オブジェクトファイル
OBJECTS  = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
#依存関係ファイル
DEPENDS  = $(OBJECTS:.o=.d)
#実行ファイル作成
$(TARGET): $(OBJECTS) $(LIBS)
	$(CXX) -o $@ $^ $(LDFLAGS)
#ソースファイルをコンパイル
$(OBJDIR)/%.o: %.cpp
	@if [ ! -d $(OBJDIR) ];\
	then echo "mkdir -p $(OBJDIR)";mkdir -p $(OBJDIR);\
	fi
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

#クリーンしてビルド
.PHONY: all
all: clean $(TARGET)

#クリーン
.PHONY:clean
clean:
	$(RM) $(OBJECTS) $(DEPENDS) $(TARGET)

-include $(DEPENDS)
