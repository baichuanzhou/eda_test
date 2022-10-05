#ifndef TCUBE_H
#define TCUBE_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Cube;	// 声明, 引入其他文件的自定义类型 -- Cube

//	自定义类型 -- 立方体集合
//	私有变量: 立方体集合T, 容器
//			 立方体集合的立方个数size, int
//			 友元函数, 重载运算符 <<




class T_Cube {

public:
    T_Cube(int num);	// constructor

    T_Cube();

    // ~T_Cube();	// destroyer

    bool judgeContain(Cube& cube);	// 判断立方体是否被包含

    bool judgeContain(T_Cube& otherTCube);	// 函数重载, 判断立方体集合是否被包含

    bool isEmpty() const;	// 判断立方体集合是否为空

    void printContain(T_Cube& otherTCube);	// 打印立方体集合是否被包含

    void absorb();	// 吸收运算

    vector<Cube> absorbHelper(vector<Cube> TCube);

    void shrink();	// 卡诺图化简

    void addCube(const Cube& cube);	// 向立方体集合中加入一个新的立方体

    void addDC(const Cube& cube);

    T_Cube originalContains();

    T_Cube crossCube(const Cube& cube);	// 立方体与立方体集合相交

    T_Cube crossCube(T_Cube& otherTCube);	// 函数重载, 立方体集合之间相交

    T_Cube operator+(const T_Cube& otherTCube);	// 重载运算符+, 立方体集合之间相加(未包含吸收, 下同)

    T_Cube operator+(const Cube& cube);	// 重载运算符+, 立方体集合与立方体相加

    T_Cube& operator+=(const Cube& cube);	// 重载运算符+=, 立方体集合与立方体, 返回引用值

    T_Cube& operator+=(const T_Cube& otherTCube);	// 重载运算符+=, 立方体集合之间, 返回引用值

    T_Cube& operator=(const T_Cube& otherTCube);	// 重载运算符=

    T_Cube operator-(const Cube& cube);	// 重载运算符-, 如果立方体集合中包含立方体便减去(锐积用)

    T_Cube& operator-=(const Cube& cube);	// 重载运算符-=

    T_Cube operator-(const T_Cube& otherTCube);	// 重载运算符-, 立方体集合之间相减

    T_Cube& operator-=(const T_Cube& otherTCube);	// 重载运算符-=

    T_Cube operator*(const T_Cube& otherTCube);

    T_Cube& operator*=(const T_Cube& otherTCube);

    T_Cube operator*(const Cube& otherCube);

    T_Cube& operator*=(const Cube& otherCube);

private:
    T_Cube(vector<Cube> TCube);

    vector<Cube> T;
    vector<Cube> DC;
    int size;
    int cubeDimension;
    int dcSize;
    friend std::ostream& operator<<(std::ostream& out, const T_Cube& t_cube);
    friend class Cube;
};
#endif // TCUBE_H