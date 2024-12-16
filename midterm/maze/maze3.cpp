// 사용자로부터 미로의 크기와 구성을 입력받아, 
// 미로 탐색을 수행하는 프로그램을 작성하시오. 
// 미로의 각 칸은 벽, 빈 공간, 출발점, 출구로 구성됩니다.

void CMaze::LoadFromUser() {
    std::cout << "Enter maze width and height: ";
    std::cin >> m_w >> m_h;
    
    Init(m_w, m_h);
    std::cout << "Enter maze structure (0: wall, 1: empty, 5: start, 9: exit):\n";
    for (int i = 0; i < m_h; ++i) {
        for (int j = 0; j < m_w; ++j) {
            std::cin >> m_elem[i][j];
        }
    }
}

int main() {
    CMaze mazeSolver;
    mazeSolver.LoadFromUser();
    mazeSolver.searchExit();
    mazeSolver.Print();
    return 0;
}