#include <iostream>
#include "BinaryNode.h"
#include "BinaryTree.h"
#include "BinSrchTree.h"

int main() {
    // 이진 탐색 트리 생성
    BinSrchTree bst;

    // 노드 삽입
    bst.insert(new BinaryNode(50));
    bst.insert(new BinaryNode(30));
    bst.insert(new BinaryNode(20));
    bst.insert(new BinaryNode(40));
    bst.insert(new BinaryNode(70));
    bst.insert(new BinaryNode(60));
    bst.insert(new BinaryNode(80));

    // 트리 출력 - 트리 순회
    std::cout << "\nTree Traversals:" << std::endl;
    bst.inorder();   // 중위순회
    bst.preorder();  // 전위순회
    bst.postorder(); // 후위순회
    bst.levelorder(); // 레벨 순서 순회

    // 탐색
    std::cout << "\n\nSearch Results:" << std::endl;
    bst.search(40); // 존재하는 키
    bst.search(90); // 존재하지 않는 키

    // 노드 삭제
    std::cout << "\n\nDeleting Nodes:" << std::endl;
    bst.remove(20); // 리프 노드 삭제
    bst.inorder();

    bst.remove(30); // 자식 1개 노드 삭제
    bst.inorder();

    bst.remove(50); // 자식 2개 노드 삭제 (루트 노드)
    bst.inorder();

    return 0;
}
