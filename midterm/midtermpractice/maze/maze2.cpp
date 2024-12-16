// 미로를 탐색한 후, 출구까지 도달한 최적 경로를 출력하는 프로그램을 작성하시오.
// 최적 경로는 스택을 사용하여 추적할 수 있습니다.


void CMaze::addOptimalPath(CPoint2D &pt) {
    while (!m_optimal.IsEmpty()) {
        CPoint2D &prev = m_optimal.Peek();
        if (prev.isNeighbor(pt)) break;
        else m_optimal.Pop();
    }
    m_optimal.Push(pt);
}

void CMaze::PrintOptimal() {
    while (!m_optimal.IsEmpty()) {
        CPoint2D &opt = m_optimal.Pop();
        m_elem[opt.y][opt.x] = T_OPTIMAL;
    }
}

int main() {
    // Load maze and search exit code (same as 문제 1)
    
    mazeSolver.PrintOptimal();
    mazeSolver.Print();
    return 0;
}