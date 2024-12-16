// 주어진 2차원 배열 형태의 미로에서 출발점부터 출구까지 도달하는 경로를 
// 탐색하는 프로그램을 작성하시오. 경로 탐색을 위해 스택을 사용하며,
// 미로에서 벽, 빈 공간, 출발점, 출구를 각각 0, 1, 5, 9로 표시합니다.

#include <iostream>
#define MAX_STACK_SIZE 100
#define T_WALL 0
#define T_START 5
#define T_EXIT 9
#define T_EMPTY 1
#define T_DONE 2

struct CPoint2D {
    int x, y;
    CPoint2D(int xx = 0, int yy = 0) : x(xx), y(yy) {}
    bool operator==(CPoint2D &p) {
        return (p.x == x && p.y == y);
    }
};

class CStack {
    CPoint2D m_data[MAX_STACK_SIZE];
    int m_top;

public:
    CStack() : m_top(0) {}
    bool IsEmpty() { return m_top == 0; }
    void Push(CPoint2D e) {
        if (m_top < MAX_STACK_SIZE)
            m_data[m_top++] = e;
    }
    CPoint2D Pop() {
        if (m_top > 0)
            return m_data[--m_top];
        return CPoint2D();  // 빈 스택일 경우 기본 값 반환
    }
};

class CMaze {
    int m_w, m_h;
    int **m_elem;
    CStack m_stack;
    CPoint2D m_start, m_exit;

public:
    CMaze(int w, int h) : m_w(w), m_h(h) {
        m_elem = new int*[m_h];
        for (int i = 0; i < m_h; ++i)
            m_elem[i] = new int[m_w];
    }

    void Load(int maze[10][20]) {
        for (int i = 0; i < m_h; ++i)
            for (int j = 0; j < m_w; ++j)
                m_elem[i][j] = maze[i][j];
    }

    void setBeginEnd() {
        for (int i = 0; i < m_h; i++) {
            for (int j = 0; j < m_w; j++) {
                if (m_elem[i][j] == T_START)
                    m_start = CPoint2D(j, i);
                else if (m_elem[i][j] == T_EXIT)
                    m_exit = CPoint2D(j, i);
            }
        }
        m_stack.Push(m_start);
    }

    void searchExit() {
        setBeginEnd();
        while (!m_stack.IsEmpty()) {
            CPoint2D pt = m_stack.Pop();
            int x = pt.x, y = pt.y;

            if (pt == m_exit) {
                std::cout << "Exit found at (" << x << ", " << y << ")\n";
                return;
            }

            m_elem[y][x] = T_DONE;
            push(x - 1, y);  // 왼쪽
            push(x + 1, y);  // 오른쪽
            push(x, y - 1);  // 위쪽
            push(x, y + 1);  // 아래쪽
        }
    }

    void push(int x, int y) {
        if (x >= 0 && x < m_w && y >= 0 && y < m_h && m_elem[y][x] == T_EMPTY)
            m_stack.Push(CPoint2D(x, y));
    }

    void Print() {
        for (int i = 0; i < m_h; i++) {
            for (int j = 0; j < m_w; j++) {
                if (m_elem[i][j] == T_WALL)
                    std::cout << "■";
                else if (m_elem[i][j] == T_START)
                    std::cout << "S";
                else if (m_elem[i][j] == T_EXIT)
                    std::cout << "E";
                else if (m_elem[i][j] == T_DONE)
                    std::cout << "x";
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int maze[10][20] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0},
        {5, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 9},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    CMaze mazeSolver(20, 10);
    mazeSolver.Load(maze);
    mazeSolver.searchExit();
    mazeSolver.Print();
    return 0;
}